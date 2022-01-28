#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/structures.h"

int table_size = 0;
int tree_size = 0;

extern void NewSymbol(Symbol* ident, char* id, char* type, char* decl, int line, int column, int scope, int params, int reg){
    strcpy(ident[table_size].id, id);
    strcpy(ident[table_size].type, type);
    strcpy(ident[table_size].decl, decl);
    ident[table_size].line = line;
    ident[table_size].column = column;
    ident[table_size].scope = scope;
    ident[table_size].params = params;
    ident[table_size].reg = reg;
    table_size++;
}

extern void UpdateParams(Symbol* ident, int params){
    for(int i=0; i<table_size; i++){
        if(ident[i].params == -1){
            ident[i].params = params;
        }
    }
}

extern int CheckParams(Symbol* ident, char* id, int scope){
    if(scope == -1){
        for(int i=0; i<table_size; i++){
            if(!strcmp(ident[i].id, id)){
                return ident[i].params;
            }
        }
    } else {
        for(int i=0; i<table_size; i++){
            if(!strcmp(ident[i].id, id) && ident[i].scope == scope){
                return ident[i].params;
            }
        }
    }
    return 0;
}

extern int CheckParamsType(Symbol* ident, int param, int scope){
    for(int i=0; i<table_size; i++){
        if(ident[i].scope == scope && ident[i].params == param){
            if(!strcmp(ident[i].type, "int")){
                return 1;
            } else if(!strcmp(ident[i].type, "float")){
                return 2;
            } else if(!strcmp(ident[i].type, "int list")){
                return 3;
            } else if(!strcmp(ident[i].type, "float list")){
                return 4;
            }
        }
    }
    return 0;
}

extern int CheckType(Symbol* ident, char* id, int scope, int check){
    if(check){
        for(int i=0; i<table_size; i++){
            if(!strcmp(ident[i].id, id) && ident[i].scope == scope){
                if(!strcmp(ident[i].type, "int")){
                    return 1;
                } else if(!strcmp(ident[i].type, "float")){
                    return 2;
                } else if(!strcmp(ident[i].type, "int list")){
                    return 3;
                } else if(!strcmp(ident[i].type, "float list")){
                    return 4;
                }
            }
        }
        for(int i=0; i<table_size;i++){
            if(!strcmp(ident[i].id, id)){
                if(!strcmp(ident[i].type, "int")){
                    return 1;
                } else if(!strcmp(ident[i].type, "float")){
                    return 2;
                } else if(!strcmp(ident[i].type, "int list")){
                    return 3;
                } else if(!strcmp(ident[i].type, "float list")){
                    return 4;
                }
            }
        }
    } else {
        for(int i=0; i<table_size; i++){
            if(!strcmp(ident[i].id, id)){
                if(!strcmp(ident[i].type, "int")){
                    return 1;
                } else if(!strcmp(ident[i].type, "float")){
                    return 2;
                } else if(!strcmp(ident[i].type, "int list")){
                    return 3;
                } else if(!strcmp(ident[i].type, "float list")){
                    return 4;
                }
            }
        }
    }
    return 0;
}

extern int CheckScope(Symbol* ident, char* id, int scope){
    int check = 0;
    while(!check && scope >= 0){
        for(int i=0; i<table_size; i++){
            if(!strcmp(ident[i].id, id) && ident[i].scope == scope){
                return scope;
            }
        }
        scope--;
    }
    return 0;
}

extern int SearchTable(Symbol* ident, char* id, int funct, int decl, int stack[], int scope_position){
    if(funct){
        for(int i=0; i<table_size; i++){
            if(!strcmp(ident[i].id, id) && (!strcmp(ident[i].decl, "function") || !strcmp(ident[i].decl, "function"))){
                if(i+1 == table_size){
                    return ident[i].scope + 1;
                } else {
                    return ident[i+1].scope + 1;
                }
            }
        }
    }else if(decl){
        for(int i=0; i<table_size; i++){
            if(!strcmp(ident[i].id, id) && ident[i].scope == stack[scope_position] && (!strcmp(ident[i].decl, "variable"))){
                return 1;
            }
        }
    }else{
        for(int i=0; i<table_size; i++){
            if(!strcmp(ident[i].id, id)){
                for(int j=0; j<=scope_position; j++){
                    if(ident[i].scope == stack[j]){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

extern void PrintTable(Symbol* ident){
    printf("\n");
    printf("##########################################################################################\n");
    printf("#                                #                      #                                #\n");
    printf("##################################  TABELA DE SÍMBOLOS  ##################################\n");
    printf("#                                #                      #                                #\n");
    printf("##########################################################################################\n");
    printf("#             ID             | Escopo | Linha | Coluna |    Tipo    | Função ou Variável #\n");
    printf("##########################################################################################\n");

    for(int i=0; i<table_size; i++){
        printf("# %26s | %6d | %5d | %6d | %10s | %18s #\n", ident[i].id, ident[i].scope, ident[i].line, ident[i].column, ident[i].type, ident[i].decl);
        printf("##########################################################################################\n");
    }
}

extern TreeNode* NewNode(char* value, int type, int ret, char* tac_code){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->t1 = NULL;
    node->t2 = NULL;
    node->t3 = NULL;
    node->t4 = NULL;
    strcpy(node->value, value);
    node->type = type;
    node->ret = ret;
    strcpy(node->tac_code, tac_code);
    Nodes[tree_size] = node;
    tree_size++;
    return node;
}

extern void PrintTree(TreeNode* node, int depth){
    if(!node){
        return;
    }

    if(node->type == 0){
        for(int i=0; i<depth; i++){
            printf("    ");
        }
        printf("%s ->\n", node->value);
    }
    if(node->type == 1){
        for(int i=0; i<depth; i++){
            printf("    ");
        }
        printf("%s -> int\n", node->value);
    }
    if(node->type == 2){
        for(int i=0; i<depth; i++){
            printf("    ");
        }
        printf("%s -> float\n", node->value);
    }
    if(node->type == 3){
        for(int i=0; i<depth; i++){
            printf("    ");
        }
        printf("%s -> int list\n", node->value);
    }
    if(node->type == 4){
        for(int i=0; i<depth; i++){
            printf("    ");
        }
        printf("%s -> float list\n", node->value);
    }
    

    if(node->t1){
        PrintTree(node->t1, depth+1);
    }
    if(node->t2){
        PrintTree(node->t2, depth+1);
    }
    if(node->t3){
        PrintTree(node->t3, depth+1);
    }
    if(node->t4){
        PrintTree(node->t4, depth+1);
    }
}

extern void DestroyTree(){
    for(int i=0; i<tree_size; i++){
        if(Nodes[i]){
            free(Nodes[i]);
        }
    }
}

extern void CreateTac(char* file_name, char* tac_table, char* tac_code){
    char tac_name[64];
    strcpy(tac_name, file_name);
    tac_name[strlen(tac_name)] = '\0';
    tac_name[strlen(tac_name)-1] = '\0';
    strcat(tac_name, "tac");

    FILE* fp = fopen(tac_name, "w");

    
    fprintf(fp, ".table\n");
    fprintf(fp, "%s\n", tac_table);
    fprintf(fp, ".code\n");
    fprintf(fp, "%s", tac_code);

    fclose(fp);
}