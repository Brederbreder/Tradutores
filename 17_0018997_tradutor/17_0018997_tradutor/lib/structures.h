#ifndef __STRUCTURES_H__
#define __STRUCTURES_H__

typedef struct Symbol {
        char id[100];
        char type[100];
        char decl[100];
        int line;
        int column;
        int scope;
        int params;
        int reg;
} Symbol;

typedef struct TreeNode{
    struct TreeNode* t1;
    struct TreeNode* t2;
    struct TreeNode* t3;
    struct TreeNode* t4;
    char value[100];
    int type;
    int ret;
    char tac_code[100];
} TreeNode;

Symbol Table[1000];
TreeNode* Nodes[1000];
TreeNode* Tree;

extern void NewSymbol(Symbol* ident, char* id, char* type, char* decl, int line, int column, int scope, int params, int reg);
extern void UpdateParams(Symbol* ident, int params);
extern int CheckParams(Symbol* ident, char* id, int scope);
extern int CheckParamsType(Symbol* ident, int param, int scope);
extern int CheckType(Symbol* ident, char* id, int scope, int check);
extern int CheckScope(Symbol* ident, char* id, int scope);
extern int SearchTable(Symbol* ident, char* id, int funct, int decl, int stack[], int scope_position);
extern void PrintTable(Symbol* ident);

extern TreeNode* NewNode(char* value, int type, int ret, char* tac_code);
extern void PrintTree(TreeNode* node, int depth);
extern void DestroyTree();

extern void CreateTac(char* file_name, char* tac_table, char* tac_code);

#endif