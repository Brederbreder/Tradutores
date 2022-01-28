%define lr.type canonical-lr
%define parse.error verbose
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "../lib/structures.h"

    extern int lines;
    extern int columns;
    extern int errors;
    int errors_sem = 0;
    int errors_sin = 0;

    extern int yylex();
    extern int yyparse();
    extern int yylex_destroy();
    extern void yyerror(const char* message);
    extern void ScopeChange(int op);
    extern FILE* yyin;

    extern Symbol Table[1000];
    extern TreeNode* Nodes[1000];
    extern TreeNode* Tree;

    int scope;
    int scope_position;
    int params;
    int param;
    int param_errors;
    int arg_return;
    int args;
    int main_error;
    int call_scope;
    int scope_id;
    int type_return;

    int stack[1000];
    char tac_table[10000];
    char tac_code[10000];

    int reg;
    int str;
    int loop;
    int if_start;
    int ifs;

    char reg_num[6];
    char str_num[6];
    char loop_num[6];
    char for_loop1[6];
    char for_loop2[6];
    char for_loop3[6];
    char for_loop4[6];
    char if_loop[6];
    char else_loop[6];
    char end_loop1[6];
    char end_loop2[6];
    char end_loop3[6];
    char end_loop4[6];
    char list_loop1[6];
    char list_loop2[6];
    char list_loop3[6];
    char list_loop4[6];
    char finish_loop[6];
    char tac[1000];
    char cur_ret[100];
    char int_list[1000];
    char float_list[1000];
%}

%union {
    struct TreeNode* node;
    struct Token{
        char id[100];
        int line;
        int column;
    } token;
}

%token <token> INT
%token <token> FLOAT
%token <token> LIST
%token <token> TYPE
%token <token> READ 
%token <token> WRITE
%token <token> STRING
%token <token> ID
%token <token> NIL_RW
%token <token> REL_OP
%token <token> ASSIGN_OP
%token <token> LIST_CONSTRUC
%token <token> FOR_RW IF_RW RETURN_RW
%token <token> ';' '{' '}' '(' ')' ','
%right <token> ELSE_RW
%token <token> LIST_BIN_OP
%token <token> LIST_UN_OP
%token <token> ADD_OP
%token <token> MUL_OP
%token <token> LOG_OP

%type <node> start
%type <node> prog
%type <node> prog_block
%type <node> funct_decl
%type <node> params
%type <node> param
%type <node> decl
%type <node> funct
%type <node> block
%type <node> statement
%type <node> flow_control
%type <node> if_else_statement
%type <node> expression
%type <node> list_op;
%type <node> for_statement
%type <node> return_statement
%type <node> ass_op
%type <node> operation
%type <node> read
%type <node> write
%type <node> op_un
%type <node> log_op
%type <node> add_op
%type <node> rel_op
%type <node> mul_op
%type <node> value
%type <node> function_call
%type <node> id
%type <node> function_params

%% 

start:
    prog {
        Tree = $$;
    }
;

prog:
    prog prog_block {
        $$ = NewNode("prog", 0, 0, " ");
        $$->t1 = $1;
        $$->t2 = $2;
    }

    | prog_block {
        $$ = $1;
    }
;

prog_block:
    decl {
        $$ = $1;
    }

    | funct_decl {
        $$ = $1;
    }
;

decl:

    TYPE ID ';'{
        strcat(tac_table, $1.id);
        strcat(tac_table, " ");
        strcat(tac_table, $2.id);
        strcat(tac_table, "_");
        sprintf(reg_num, "s%d", stack[scope_position]);
        strcat(tac_table, reg_num);
        strcat(tac_table, "\n");
        if(SearchTable(Table, $2.id, 0, 1, stack, scope_position)){
            printf("Semantic error, variable %s is already declared. Error position, Line = %d, Column = %d\n", $2.id, $2.line, $2.column);
            errors_sem++;
        }
        NewSymbol(Table, $2.id, $1.id, "variable", $2.line, $2.column, stack[scope_position], 0, reg);
        $$ = NewNode(strcat(strcat($1.id, " variable "), $2.id), CheckType(Table, $2.id, stack[scope_position], 1), 0, " ");
    }

    | TYPE LIST ID ';'{
        strcat(tac_table, $1.id);
        strcat(tac_table, " ");
        strcat(tac_table, $3.id);
        strcat(tac_table, "_");
        sprintf(reg_num, "s%d", stack[scope_position]);
        strcat(tac_table, reg_num);
        strcat(tac_table, "[100] = ");
        if(!strcmp($1.id, "int")){
            strcat(tac_table, int_list);
        } else {
            strcat(tac_table, float_list);
        }
        strcat(tac_table, "\nint ");
        strcat(tac_table, $3.id);
        strcat(tac_table, "_");
        sprintf(reg_num, "s%d", stack[scope_position]);
        strcat(tac_table, reg_num);
        strcat(tac_table, "_size = 0\n");
        if(SearchTable(Table, $3.id, 0, 1, stack, scope_position)){
            printf("Semantic error, variable %s is already declared. Error position, Line = %d, Column = %d\n", $3.id, $3.line, $3.column);
            errors_sem++;
        }
        NewSymbol(Table, $3.id, strcat($1.id, " list"), "variable", $3.line, $3.column, stack[scope_position], 0, reg);
        $$ = NewNode(strcat(strcat($1.id, " "), $3.id), CheckType(Table, $3.id, stack[scope_position], 1), 0, " ");
    }
;

funct_decl:
    funct '(' {
        ScopeChange(1);
    } params {
        UpdateParams(Table, params);
        params = 0;
    } ')' '{' block '}' {
        $$ = NewNode("function", 0, 0, " ");
        $$->t1 = $1;
        $$->t2 = $4;
        $$->t3 = $8;
        if($$->t3->ret){
            if($$->t1->type == 1){
                if($$->t3->type == 1){
                    $$->type = $$->t1->type;
                } else if($$->t3->type == 2){
                    $$->type = $$->t1->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t3->type, $2.line, $2.column);
                    errors_sem++;
                }
            } else if($$->t1->type == 2){
                if($$->t3->type == 1){
                    $$->type = $$->t1->type;
                } else if($$->t3->type == 2){
                    $$->type = $$->t3->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t3->type, $2.line, $2.column);
                    errors_sem++;
                }
            } else if($$->t1->type == 4){
                if($$->t3->type == 3){
                    $$->type = $$->t1->type;
                } else if($$->t3->type == 4){
                    $$->type = $$->t3->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Columns = %d\n", $$->t1->type, $$->t3->type, $2.line, $2.column);
                    errors_sem++;
                }
            } else if($$->t1->type == 3){
                if($$->t3->type == 3){
                    $$->type = $$->t1->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Columns = %d\n", $$->t1->type, $$->t3->type, $2.line, $2.column);
                    errors_sem++;
                }
            }
        }   
        ScopeChange(0);
    }

    | funct '(' {
        UpdateParams(Table, params);
    } ')' '{' {
        ScopeChange(1);
    } block '}' {
        $$ = NewNode("function", 0, 0, " ");
        $$->t1 = $1;
        $$->t2 = $7;
        if($$->t2->ret == 2){
            if($$->t1->type == 1){
                if($$->t2->type == 1){
                    $$->type = $$->t1->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                    errors_sem++;
                }
            } else if($$->t1->type == 2){
                if($$->t2->type == 1){
                    $$->type = $$->t1->type;
                } else if($$->t2->type == 2){
                    $$->type = $$->t2->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                    errors_sem++;
                }
            } else if($$->t1->type == 4){
                if($$->t2->type == 3){
                    $$->type = $$->t1->type;
                } else if($$->t2->type == 4){
                    $$->type = $$->t2->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Columns = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                    errors_sem++;
                }
            } else if($$->t1->type == 3){
                if($$->t2->type == 3){
                    $$->type = $$->t1->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Columns = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                    errors_sem++;
                }
            }
        } else {
            strcat(tac_code, "return\n");
        }
        ScopeChange(0);
    }
;

funct:

    TYPE ID {
        strcat(tac_code, "_");
        strcat(tac_code, $2.id);
        strcat(tac_code, ":\n");
        if(!strcmp($2.id, "main")){
            main_error = 0;
        }
        if(SearchTable(Table, $2.id, 1, 0, stack, scope_position)){
            printf("Semantic error, function %s is already declared. Error position, Line = %d, Column = %d\n", $2.id, $2.line, $2.column);
            errors_sem++;
        }
        NewSymbol(Table, $2.id, $1.id, "function", $2.line, $2.column, stack[scope_position], -1, -1);
        $$ = NewNode(strcat(strcat($1.id, " function "), $2.id), CheckType(Table, $2.id, stack[scope_position], 1), 0, " ");
    }

    | TYPE LIST ID {
        strcat(tac_code, "_");
        strcat(tac_code, $3.id);
        strcat(tac_code, ":\n");
        if(!strcmp($3.id, "main")){
            main_error = 0;
        }
        if(SearchTable(Table, $3.id, 1, 0, stack, scope_position)){
            printf("Semantic error, function %s is already declared. Error position, Line = %d, Column = %d\n", $3.id, $3.line, $3.column);
            errors_sem++;
        }
        NewSymbol(Table, $3.id, strcat($1.id, " list"), "function", $3.line, $3.column, scope, -1, -1);
        $$ = NewNode(strcat(strcat($1.id, " function "), $3.id), CheckType(Table, $3.id, stack[scope_position], 1), 0, " ");
    }
;

params:

    params ',' param {
        $$ = NewNode("params", 0, 0, " ");
        $$->t1 = $1;
        $$->t2 = $3;
        params++;
    }

    | param {
        $$ = $1;
        params++;
    }
;

param:

    TYPE ID {
        NewSymbol(Table, $2.id, $1.id, "param", $2.line, $2.column, stack[scope_position], params + 1, reg);
        $$ = NewNode(strcat(strcat($1.id, " variable "), $2.id), CheckType(Table, $2.id, stack[scope_position], 1), 0, " ");
    }

    | TYPE LIST ID {
        NewSymbol(Table, $3.id, strcat($1.id, " list"), "list param", $3.line, $3.column, stack[scope_position], params + 1, reg);
        $$ = NewNode(strcat(strcat($1.id, " "), $3.id), CheckType(Table, $3.id, stack[scope_position], 1), 0, " ");
    }

;

block:
    block statement {
        $$ = NewNode("block", 0, 0, " ");
        $$->t1 = $1;
        $$->t2 = $2;
        if($$->t1->ret || $$->t2->ret){
            $$->ret = 1;
        }
        $$->type = $$->t2->type;
    }

    | statement {
        $$ = $1;
    }

    | block decl {
        $$ = NewNode("block", 0, 0, " ");
        $$->t1 = $1;
        $$->t2 = $2;
        if($$->t1->ret || $$->t2->ret){
            $$->ret = 1;
        }
        $$->type = $$->t2->type;
    }

    | decl {
        $$ = $1;
    }
;

statement:

    expression ';' {
        $$ = $1;
    }

    | ass_op ';' {
        $$ = $1;
    }

    | '{' {
        ScopeChange(1);
    } block '}' {
        $$ = $3;
        ScopeChange(0);
    }

    | flow_control {
        $$ = $1;
    }
;

ass_op:

    id ASSIGN_OP operation {
        $$ = NewNode("assign operation", 0, 0, " ");
        $$->t1 = $1;
        $$->t2 = $3;

        if($$->t1->type == 1){
            if($$->t2->type == 1){
                $$->type = $$->t1->type;
                strcat(tac_code, "mov ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, ", ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\n");
            } else if($$->t2->type == 2){
                $$->type = $$->t1->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\nfltoint $800, $800\nmov ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, ", $800\n");
            } else {
                printf("Semantic error, type assignment error assigning %d to %d. Error position, Line = %d, Column = %d\n", $$->t2->type, $$->t1->type, $2.line, $2.column);
                errors_sem++;
            }
        } else if($$->t1->type == 2){
            if($$->t2->type == 1){
                $$->type = $$->t1->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\ninttofl $800, $800\n mov ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, ", $800\n");
            } else if($$->t2->type == 2){
                $$->type = $$->t2->type;
                strcat(tac_code, "mov ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, ", ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\n");
            } else {
                printf("Semantic error, type assingment error assigning %d to %d. Error position, Line = %d, Column = %d\n", $$->t2->type, $$->t1->type, $2.line, $2.column);
            }
        } else if($$->t1->type == 3){
            if($$->t2->type == 3){
                $$->type = $$->t1->type;
                strcat(tac_code, "mov $400, &");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\nmov $500, &");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\nmov $600, 0\nmov $601, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "_size\n");
                sprintf(loop_num, "Jump%d", loop);
                loop++;
                strcat(tac_code, loop_num);
                strcat(tac_code, ":\n");
                strcat(tac_code, "mov $603, $500[$600]\n");
                strcat(tac_code, "mov $400[$600], $603\n");
                strcat(tac_code, "sub $602, $601, $600\n");
                strcat(tac_code, "add $600, $600, 1\nbrnz ");
                strcat(tac_code, loop_num);
                strcat(tac_code, ", $602\nmov ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "_size, $601\n");
            } else if($$->t2->type == 4){
                $$->type = $$->t1->type;
                strcat(tac_code, "mov $400, &");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\nmov $500, &");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\nmove $600, 0\nmov $601, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "_size\n");
                sprintf(loop_num, "Jump%d", loop);
                loop++;
                strcat(tac_code, loop_num);
                strcat(tac_code, ":\nmov $603, $500[$600]\n");
                strcat(tac_code, "fltoint $603, $603\n");
                strcat(tac_code, "mov $400[$600], $603\n");
                strcat(tac_code, "sub $602, $601, $600\n");
                strcat(tac_code, "add $600, $600, 1\nbrnz ");
                strcat(tac_code, loop_num);
                strcat(tac_code, ", $602\nmov ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "_size, $601\n");
            } else {
                printf("Semantic error, type assingment error assigning %d to %d. Error position, Line = %d, Column = %d\n", $$->t2->type, $$->t1->type, $2.line, $2.column);
            }
        } else if($$->t1->type == 4){
            if($$->t2->type == 3){
                $$->type = $$->t1->type;
                strcat(tac_code, "mov $400, &");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\nmov $500, &");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\nmov $600, 0\n");
                strcat(tac_code, "mov $601, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "_size\n");
                sprintf(loop_num, "Jump%d", loop);
                loop++;
                strcat(tac_code, loop_num);
                strcat(tac_code, ":\nmov $603, $500[$600]\n");
                strcat(tac_code, "inttofl $603, $603\n");
                strcat(tac_code, "mov $400[$600], $603\n");
                strcat(tac_code, "sub $602, $601, $600\n");
                strcat(tac_code, "add $600, $600, 1\nbrnz ");
                strcat(tac_code, loop_num);
                strcat(tac_code, ", $602\nmov ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "_size, $601\n");
            } else if($$->t2->type == 4){
                $$->type = $$->t2->type;
                strcat(tac_code, "$mov $400, &");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\nmov $500, &");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\nmov $600, 0\nmov $601, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "_size\n");
                sprintf(loop_num, "Jump%d", loop);
                loop++;
                strcat(tac_code, loop_num);
                strcat(tac_code, ":\nmov $603, $500[$600]\n");
                strcat(tac_code, "mov $400[$600], $603\n");
                strcat(tac_code, "sub $602, $601, $600\n");
                strcat(tac_code, "add $600, $600, 1\nbnrz ");
                strcat(tac_code, loop_num);
                strcat(tac_code, ", $602\nmov ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "_size, $601\n");
            } else {
                printf("Semantic Error, type assignment error assigning %d to %d. Error position, Line = %d, Column = %d\n", $$->t2->type, $$->t1->type, $2.line, $2.column);
                errors_sem++;
            }
        }
    }
;

expression:

    operation {
        $$ = $1;
    }

    | write {
        $$ = $1;
    }

    | read {
        $$ = $1;
    }
;

operation:

    log_op {
        $$ = NewNode("Operation", 0, 0, " ");
        $$->t1 = $1;
        $$->type = $$->t1->type;
        strcpy($$->tac_code, $$->t1->tac_code);
        strcpy($$->value, $$->t1->value);
        if(if_start){
            strcat(tac_code, "brz ");
            strcat(tac_code, if_loop);
            strcat(tac_code, ", ");
            strcat(tac_code, $$->t1->tac_code);
            strcat(tac_code, "\n");
            if_start = 0;
        }
    }
;

log_op:

    log_op LOG_OP rel_op {
        $$ = NewNode("logic operation", 0, 0, " ");
        $$->t1 = $1;
        $$->t2 = $3;

        if($$->t1->type == 1){
            if($$->t2->type == 1){
                $$->type = 1;
                if(!strcmp($2.id, "&&")){
                    strcat(tac_code, "and ");
                } else {
                    strcat(tac_code, "or ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, ", ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\n");
                strcat(tac_code, reg_num);
                reg++;
            } else if($$->t2->type == 2){
                $$->type = 1;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\nfltoint $800, $800\n");
                if(!strcmp($2.id, "&&")){
                    strcat(tac_code, "and ");
                } else {
                    strcat(tac_code, "or ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, ", $800\n");
                strcpy($$->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error on logic operation with types %d and %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                errors_sem++;
            }
        } else if($$->t1->type == 2){
            if($$->t2->type == 1){
                $$->type = 1;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\nfltoint $800, $800\n");
                if(!strcmp($2.id, "&&")){
                    strcat(tac_code, "and ");
                } else {
                    strcat(tac_code, "or ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $800, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\n");
                strcpy($$->tac_code, reg_num);
                reg++;
            } else if($$->t2->type == 2){
                $$->type = 1;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\nmov $801, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\nfltoint $800, $800\n");
                strcat(tac_code, "fltoint $801, $801\n");
                if(!strcmp($2.id, "&&")){
                    strcat(tac_code, "and ");
                } else {
                    strcat(tac_code, "or ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $800, $801\n");
                strcpy($$->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error on logic operation with type %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $2.line, $2.column);
                errors_sem++;
            }
        } else{
            printf("Semantic error, type error on logic operation with type %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $2.line, $2.column);
            errors_sem++;
        }
    }

    | rel_op {
        $$ = $1;
    }
;

rel_op:

    rel_op REL_OP list_op {
        $$ = NewNode("relative operation", 0, 0, " ");
        $$->t1 = $1;
        $$->t2 = $3;

        if($$->t1->type == 1){
            if($$->t2->type == 1){
                $$->type = 1;
                if(!strcmp($2.id, "==") || !strcmp($2.id, "!=")){
                    strcat(tac_code, "seq ");
                } else if(!strcmp($2.id, ">=") || !strcmp($2.id, "<")){
                    strcat(tac_code, "slt ");
                } else {
                    strcat(tac_code, "sleq ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, ", ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\n");
                if(!strcmp($2.id, ">=") || !strcmp($2.id, "!=") || !strcmp($2.id, ">")){
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, "\n");
                }
                strcpy($$->tac_code, reg_num);
                reg++;
            } else if($$->t2->type == 2){
                $$->type = 1;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\nfltoint $800, $800\n");
                if(!strcmp($2.id, "==") || !strcmp($2.id, "!=")){
                    strcat(tac_code, "seq ");
                } else if(!strcmp($2.id, ">=") || !strcmp($2.id, "<")){
                    strcat(tac_code, "slt ");
                } else {
                    strcat(tac_code, "sleq ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, ", $800, 1\n");
                if(!strcmp($2.id, ">=") || !strcmp($2.id, "!=") || !strcmp($2.id, ">")){
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, "\n");
                }
                strcpy($$->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error in relational operation with types %d and %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                errors_sem++;
            }
        } else if($$->t1->type == 2){
            if($$->t2->type == 1){
                $$->type = 1;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\nfltoint $800, $800\n");
                if(!strcmp($2.id, "==") || !strcmp($2.id, "!=")){
                    strcat(tac_code, "seq ");
                } else if(!strcmp($2.id, ">=") || !strcmp($2.id, "<")){
                    strcat(tac_code, "slt ");
                } else {
                    strcat(tac_code, "sleq ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $800, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\n");
                if(!strcmp($2.id, ">=") || !strcmp($2.id, "!=") || !strcmp($2.id, ">")){
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, "\n");
                }
                strcpy($$->tac_code, reg_num);
                reg++;
            } else if($$->t2->type == 2){
                $$->type = 1;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\nmov $801, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\nfltoint $800, $800\n");
                strcat(tac_code, "fltoint $801, $801\n");
                if(!strcmp($2.id, "==") || !strcmp($2.id, "!=")){
                    strcat(tac_code, "seq ");
                } else if(!strcmp($2.id, ">=") || !strcmp($2.id, "<")){
                    strcat(tac_code, "slt ");
                } else {
                    strcat(tac_code, "sleq ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $800, $801\n");
                if(!strcmp($2.id, ">=") || !strcmp($2.id, "!=") || !strcmp($2.id, ">")){
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, "\n");
                }
                strcpy($$->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error in relational operation with types %d and %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                errors_sem++;
            }
        } else if($$->t1->type == 3 && (!strcmp($2.id, "==") || !strcmp($2.id, "!="))){
            if($$->t2->type == 3){
                $$->type = 1;
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, "mov $400, &");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\nmov $500, &");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\nmov $600, 0\nmov $601, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "_size\nmov $602, ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "_size\nmov ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", 0\n");
                strcat(tac_code, "sub $603, $601, %602\n");
                sprintf(list_loop1, "Jump%d", loop);
                loop++;
                strcat(tac_code, "brnz ");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ", $603\nmov ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", 1\n");
                sprintf(loop_num, "Jump%d", loop);
                loop++;
                strcat(tac_code, loop_num);
                strcat(tac_code, ":\nmov $700, $500[$600]\n");
                strcat(tac_code, "mov $701, $400[$600]\nseq ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $701, $700\nbrz ");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ", ");
                strcat(tac_code, reg_num);
                strcat(tac_code, "\nsub $602, $601, $600\n");
                strcat(tac_code, "add $600, $600, 1\n brnz ");
                strcat(tac_code, loop_num);
                strcat(tac_code, ", $602\n");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ":\n");
                if(!strcmp($2.id, "!=")){
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, "\n");
                }
                strcpy($$->tac_code, reg_num);
                reg++;
            } else if($$->t2->type == 4) {
                $$->type = 1;
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, "mov $400, &");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\nmov $500, &");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\nmov $600, 0\nmov $601, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "_size\nmov $602, ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "_size\nmov ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", 0\n");
                strcat(tac_code, "sub $603, $601, %602\n");
                sprintf(list_loop1, "Jump%d", loop);
                loop++;
                strcat(tac_code, "brnz ");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ", $603\nmov ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", 1\n");
                sprintf(list_loop1, "Jump%d", loop);
                loop++;
                strcat(tac_code, loop_num);
                strcat(tac_code, ":\nmov $700, $500[$600]\n");
                strcat(tac_code, "fltoint $700, $700\n");
                strcat(tac_code, "mov $701, $400[$600]\nseq ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $701, $700\nbrz ");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ", ");
                strcat(tac_code, reg_num);
                strcat(tac_code, "\nsub $602, $601, $600\n");
                strcat(tac_code, "add $600, $600, 1\nbrnz ");
                strcat(tac_code, loop_num);
                strcat(tac_code, ", $602\n");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ":\n");
                if(!strcmp($2.id, "!=")){
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, "\n");
                }
                strcpy($$->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error in relational operation with types %d and %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                errors_sem++;
            }
        } else if($$->t1->type == 4 && (!strcmp($2.id, "==") || !strcmp($2.id,"!="))){
            if($$->t2->type == 3 || $$->t2->type == 4){
                $$->type = 1;
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, "mov $400, &");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\nmov $500, &");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\nmov $600, 0\n");
                strcat(tac_code, "mov $601, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "_size\n");
                strcat(tac_code, "mov $602, ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "_size\nmov ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", 0\nsub $603, $601, $602\n");
                sprintf(list_loop1, "Jump%d", loop);
                loop++;
                strcat(tac_code, "brnz ");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ", $603\nmov ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", 1\n");
                sprintf(loop_num, "Jump%d", loop);
                loop++;
                strcat(tac_code, loop_num);
                strcat(tac_code, ":\nmov $700, $400[$600]\n");
                strcat(tac_code, "fltoint $700, $700\n");
                strcat(tac_code, "mov $701, $500[$600]\nseq ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $701, $700\nrbz ");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ", ");
                strcat(tac_code, reg_num);
                strcat(tac_code, "\nsub $602, $601, $600\n");
                strcat(tac_code, "add &600, $600, 1\nbrnz ");
                strcat(tac_code, loop_num);
                strcat(tac_code, ", $602\n");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ":\n");
                if(!strcmp($2.id, "!=")){
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, "\n");
                }
                strcpy($$->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error in relational operation with types %d and %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                errors_sem++;
            } 
        } else {
                printf("Semantic error, type error in relational operation with types %d and %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                errors_sem++;
            }
    }

    | list_op {
        $$ = $1;
    }
;

list_op:

    add_op LIST_BIN_OP list_op {
        $$ = NewNode("list function", 0, 0, " ");
        $$->t1 = $1;
        $$->t2 = $3;
        if(!strcmp($2.id, ">>")){
            strcat(tac_code, "mov $500, &");
            strcat(tac_code, $$->t2->tac_code);
            strcat(tac_code, "\n");
            strcat(tac_code, "mov $600, 0\n");
            strcat(tac_code, "mov $601, ");
            strcat(tac_code, $$->t2->tac_code);
            strcat(tac_code, "_size\n");
            sprintf(loop_num, "Jump%d", loop);
            loop++;
            strcat(tac_code, loop_num);
            strcat(tac_code, ":\n");
            strcat(tac_code, "mov $603, $500[$600]\n");
            strcat(tac_code, "param $603\n");
            strcat(tac_code, "call _");
            strcat(tac_code, $$->t1->value);
            strcat(tac_code, ", 1\n");
            strcat(tac_code, "pop $605\n");
            strcat(tac_code, "mov $500[600], $605\n");
            strcat(tac_code, "add $600, $600, 1\n");
            strcat(tac_code, "sub $602, $601, $600\nbrnz ");
            strcat(tac_code, loop_num);
            strcat(tac_code, ", $602\n//");
        } else {
            strcat(tac_code, "mov $500, &");
            strcat(tac_code, $$->t2->tac_code);
            strcat(tac_code, "\nmov $600, 0\n");
            strcat(tac_code, "mov $601, ");
            strcat(tac_code, $$->t2->tac_code);
            strcat(tac_code, "_size\n");
            sprintf(list_loop1, "Jump%d", loop);
            loop++;
            sprintf(loop_num, "Jump%d", loop);
            loop++;
            sprintf(list_loop2, "Jump%d", loop);
            loop++;
            sprintf(list_loop3, "Jump%d", loop);
            loop++;
            sprintf(list_loop4, "Jump%d", loop);
            loop++;
            strcat(tac_code, list_loop1);
            strcat(tac_code, ":\nmov $603, $500[$600]\n");
            strcat(tac_code, "param $603\n");
            strcat(tac_code, "call _");
            strcat(tac_code, $$->t1->value);
            strcat(tac_code, ", 1\n");
            strcat(tac_code, "pop $605\nbrnz ");
            strcat(tac_code, list_loop2);
            strcat(tac_code, ", $605\n");
            strcat(tac_code, "add $600, $600, 1\n");
            strcat(tac_code, list_loop3);
            strcat(tac_code, ":\nsub $602, $601, $600\nbrnz ");
            strcat(tac_code, list_loop1);
            strcat(tac_code, ", $602\njump ");
            strcat(tac_code, list_loop4);
            strcat(tac_code, "\n");
            strcat(tac_code, list_loop2);
            strcat(tac_code, ":\nmov $610, $600\n");
            strcat(tac_code, "add $611, $610, 1\n");
            strcat(tac_code, loop_num);
            strcat(tac_code, "\nmov $613, $600[$611]\n");
            strcat(tac_code, "mov $500[$610], $613\n");
            strcat(tac_code, "add $610, $610, 1\n");
            strcat(tac_code, "add $611, $611, 1\n");
            strcat(tac_code, "sub $612, $601, $610\nbrnz ");
            strcat(tac_code, loop_num);
            strcat(tac_code, ", $612\n");
            strcat(tac_code, "sub $601, $601, 1\nsub ");
            strcat(tac_code, $$->t2->tac_code);
            strcat(tac_code, "_size, 1\njump ");
            strcat(tac_code, list_loop3);
            strcat(tac_code, "\n");
            strcat(tac_code, list_loop4);
            strcat(tac_code, ":\n");
        }
        
        if($$->t1->type == 1 || $$->t1->type == 2){
            if($$->t2->type == 3 || $$->t2->type == 4){
                $$->type = $$->t2->type;
            } else {
                printf("Semantic error, error type with type %d with list function with %d type. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                errors_sem++;
            }
        } else {
            printf("Semantic error, error type with type %d with list function with %d type. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
            errors_sem++;
        }
        strcpy($$->tac_code, $$->t2->tac_code);
    }

    | add_op LIST_CONSTRUC list_op {
        $$ = NewNode("list operation", 0, 0, " ");
        $$->t1 = $1;
        $$->t2 = $3;

        sprintf(loop_num, "Jump%d", loop);
        loop++;
        sprintf(list_loop1, "Jump%d", loop);
        loop++;
        strcat(tac_code, "mov $500, &");
        strcat(tac_code, $$->t1->tac_code);
        strcat(tac_code, "\nmov $601, ");
        strcat(tac_code, $$->t2->tac_code);
        strcat(tac_code, "_size\nbrz ");
        strcat(tac_code, list_loop1);
        strcat(tac_code, ", $601\nsub $602, $601, 1\n");
        strcat(tac_code, loop_num);
        strcat(tac_code, ":\nmov $604, $500[$602]\n");
        strcat(tac_code, "mov $500[$601], $604");
        strcat(tac_code, "sub $602, $602, 1\n");
        strcat(tac_code, "sub $601, $601, 1\nbrnz ");
        strcat(tac_code, loop_num);
        strcat(tac_code, ", $601\n");
        strcat(tac_code, list_loop1);
        strcat(tac_code, ":\nmov $500[0], ");
        strcat(tac_code, $$->t1->tac_code);
        strcat(tac_code, "\nadd ");
        strcat(tac_code, $$->t2->tac_code);
        strcat(tac_code, "_size, ");
        strcat(tac_code, $$->t2->tac_code);
        strcat(tac_code, "_size, 1\n");
        strcpy($$->tac_code, $$->t2->tac_code);

        if($$->t1->type == 1 || $$->t1->type == 2){
            if($$->t2->type == 3 || $$->t2->type == 4){
                $$->type = $$->t2->type;
            } else {
                printf("Semantic error, error type with type %d with list constructor with %d type. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                errors_sem++;
            }
        } else {
            printf("Semantic error, error type with type %d with list constructor with %d type. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
            errors_sem++;
        }

    }

    | add_op {
        $$ = $1;
    }
;

add_op:

    add_op ADD_OP mul_op {
        $$ = NewNode("additive operation", 0, 0, " ");
        $$->t1 = $1;
        $$->t2 = $3;

        if($$->t1->type == 1){
            if($$->t2->type == 1){
                $$->type = $$->t1->type;
                if(!strcmp($2.id, "+")){
                    strcat(tac_code, "add ");
                } else {
                    strcat(tac_code, "sub ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, ", ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\n");
                strcpy($$->tac_code, reg_num);
                reg++;
            } else if($$->t2->type == 2){
                $$->type = $$->t2->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\ninttofl $800, $800\n");
                if(!strcmp($2.id, "+")){
                    strcat(tac_code, "add ");
                } else {
                    strcat(tac_code, "sub ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, ", $800\n");
                strcpy($$->tac_code, reg_num);
                reg++;
            } else{
                printf("Semantic error, type error in additive operation with types %d and %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                errors_sem++;
            }
        } else if($$->t1->type == 2){
            if($$->t2->type == 1){
                $$->type = $$->t2->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\ninttofl $800, $800\n");
                if(!strcmp($2.id, "+")){
                    strcat(tac_code, "add ");
                } else {
                    strcat(tac_code, "sub ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, ", $800\n");
                strcpy($$->tac_code, reg_num);
                reg++;
            } else if($$->t2->type == 2){
                $$->type = $$->t2->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\nmov $801, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\n");
                if(!strcmp($2.id, "+")){
                    strcat(tac_code, "add ");
                } else {
                    strcat(tac_code, "sub ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $801, $800\n");
                strcpy($$->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error in additive operation with types %d and %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                errors_sem++;
            }
        } else {
            printf("Semantic error, type error in additive operation with types %d and %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                errors_sem++;
        }
    }

    | ADD_OP mul_op {
        $$ = NewNode("neg", 0, 0, " ");
        $$->t1 = $2;
        sprintf(reg_num, "$%d", reg);
        strcat(tac_code, "minus ");
        strcat(tac_code, reg_num);
        strcat(tac_code, ", ");
        strcat(tac_code, $$->t1->tac_code);
        strcat(tac_code, "\n");
        strcpy($$->tac_code, reg_num);
        reg++;

        if($$->t1->type > 2){
            printf("Semantic error, type error in negative operation with type %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $1.line, $1.column);
            errors_sem++;
        } else {
            $$->type = $$->t1->type;
        }
    }

    | mul_op {
        $$ = $1;
    }
;

mul_op:

    mul_op MUL_OP op_un {
        $$ = NewNode("multiplicative operation", 0, 0, " ");
        $$->t1 = $1;
        $$->t2 = $3;

        if($$->t1->type == 1){
            if($$->t2->type == 1){
                $$->type = $$->t1->type;
                if(!strcmp($2.id, "*")){
                    strcat(tac_code, "mul ");
                } else {
                    strcat(tac_code, "div ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, ", ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\n");
                strcpy($$->tac_code, reg_num);
                reg++;
            } else if($$->t2->type == 2){
                $$->type = $$->t2->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\ninttofl $800, $800\n");
                if(!strcmp($2.id, "*")){
                    strcat(tac_code, "mul ");
                } else {
                    strcat(tac_code, "div ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $800, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\n");
                strcpy($$->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error in multiplicative operation with types %d and %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                errors_sem++;
            }
        } else if($$->t1->type == 2){
            if($$->t2->type == 1){
                $$->type = $$->t1->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\ninttofl $800, $800\n");
                if(!strcmp($2.id, "*")){
                    strcat(tac_code, "mul ");
                } else {
                    strcat(tac_code, "div ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $800, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\n");
                strcpy($$->tac_code, reg_num);
                reg++;
            } else if($$->t2->type == 2){
                $$->type = $$->t2->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, $$->t1->tac_code);
                strcat(tac_code, "\nmov $801, ");
                strcat(tac_code, $$->t2->tac_code);
                strcat(tac_code, "\n");
                if(!strcmp($2.id, "*")){
                    strcat(tac_code, "mul ");
                } else {
                    strcat(tac_code, "div ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $800, $801\n");
                strcpy($$->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error in multiplicative operation with types %d and %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
                errors_sem++;
            }
        } else {
            printf("Semantic error, type error in multiplicative operation with types %d and %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $$->t2->type, $2.line, $2.column);
            errors_sem++;
        }
    }

    | op_un {
        $$ = $1;
    }
;

op_un:

    LIST_UN_OP op_un {
        $$ = NewNode("unary operation", 0, 0, " ");
        $$->t1 = $2;
        sprintf(reg_num, "$%d", reg);
        strcpy($$->tac_code, reg_num);
        reg++;
        if($$->t1->type != 0){
            if(!strcmp($1.id, "!")){
                if($$->t1->type < 3){
                    $$->type = 1;
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, $$->t1->tac_code);
                } else {
                    $$->type = $$->t1->type;
                    strcat(tac_code, "mov $500, &");
                    strcat(tac_code, $$->t1->tac_code);
                    strcat(tac_code, "\nmov $600, 0\n");
                    strcat(tac_code, "mov $605, 1\n");
                    strcat(tac_code, "mov $601, ");
                    strcat(tac_code, $$->t1->tac_code);
                    strcat(tac_code, "_size\n");
                    sprintf(loop_num, "Jump%d", loop);
                    loop++;
                    strcat(tac_code, "brz ");
                    strcat(tac_code, list_loop1);
                    strcat(tac_code, ", ");
                    strcat(tac_code, $$->t1->tac_code);
                    strcat(tac_code, "_size\n");
                    sprintf(loop_num, "Jump%d", loop);
                    loop++;
                    strcat(tac_code, loop_num);
                    strcat(tac_code, ":\nmov $603, $500[$605]\n");
                    strcat(tac_code, "mov $500[$600], $603\n");
                    strcat(tac_code, "add $600, $600, 1\n");
                    strcat(tac_code, "add $605, $605, 1\n");
                    strcat(tac_code, "sub $602, $601, $600\nbrnz ");
                    strcat(tac_code, loop_num);
                    strcat(tac_code, ", $602\nsub ");
                    strcat(tac_code, $$->t1->tac_code);
                    strcat(tac_code, "_size, ");
                    strcat(tac_code, $$->t1->tac_code);
                    strcat(tac_code, "_size, 1\n");
                    strcpy($$->tac_code, $$->t1->tac_code);
                    strcat(tac_code, list_loop1);
                    strcat(tac_code, ":\n");
                }
            } else {
                if($$->t1->type < 3){
                    printf("Semantic error, type error on unary operator with type %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $1.line, $1.column);
                    errors_sem++;
                } else if(!strcmp($1.id, "%")){
                    $$->type = $$->t1->type;
                    strcat(tac_code, "mov $500, &");
                    strcat(tac_code, $$->t1->tac_code);
                    strcat(tac_code, "\nmov $600, 0\n");
                    strcat(tac_code, "mov $605, 1\n");
                    strcat(tac_code, "mov $601, ");
                    strcat(tac_code, $$->t1->tac_code);
                    strcat(tac_code, "_size\n");
                    sprintf(loop_num, "Jump%d", loop);
                    loop++;
                    strcat(tac_code, "brz ");
                    strcat(tac_code, list_loop1);
                    strcat(tac_code, ", ");
                    strcat(tac_code, $$->t1->tac_code);
                    strcat(tac_code, "_size\n");
                    sprintf(loop_num, "Jump%d", loop);
                    loop++;
                    strcat(tac_code, loop_num);
                    strcat(tac_code, ":\nmov $603, $500[$605]\n");
                    strcat(tac_code, "mov $500[$600], $603\n");
                    strcat(tac_code, "add $600, $600, 1\n");
                    strcat(tac_code, "add $605, $605, 1\n");
                    strcat(tac_code, "sub $602, $601, $600\nbrnz ");
                    strcat(tac_code, loop_num);
                    strcat(tac_code, ", $602\nsub ");
                    strcat(tac_code, $$->t1->tac_code);
                    strcat(tac_code, "_size, ");
                    strcat(tac_code, $$->t1->tac_code);
                    strcat(tac_code, "_size, 1\n");
                    strcpy($$->tac_code, $$->t1->tac_code);
                    strcat(tac_code, list_loop1);
                    strcat(tac_code, ":\n");
                } else {
                    $$->type = $$->t1->type - 2;
                    strcat(tac_code, "mov $500, &");
                    strcat(tac_code, $$->t1->tac_code);
                    strcat(tac_code, "\nmov ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", $500[0]\n");
                }
            }
        } else {
            printf("Semantic error, type error on unary operator with type %d. Error position, Line = %d, Column = %d\n", $$->t1->type, $1.line, $1.column);
            errors_sem++;
        }
    }

    | value {
        $$ = $1;
    }
;

write:

    WRITE '(' operation ')' {
        $$ = NewNode("write", 0, 0, " ");
        $$->t1 = $3;
        if($$->t1->type == 0){
            sprintf(loop_num, "Jump%d", loop);
            loop++;
            sprintf(reg_num, "$%d", reg);
            reg++;
            strcat(tac_code, "mov $1000, ");
            sprintf(tac_code, "%ld", strlen($$->t1->value)-2);
            strcat(tac_code, str_num);
            strcat(tac_code, "\nmov $999, 0\n");
            strcat(tac_code, loop_num);
            strcat(tac_code, ":\nmov ");
            strcat(tac_code, reg_num);
            strcat(tac_code, ", &");
            strcat(tac_code, $$->t1->tac_code);
            strcat(tac_code, "\nmov ");
            strcat(tac_code, reg_num);
            strcat(tac_code, ", ");
            strcat(tac_code, reg_num);
            strcat(tac_code, "[$999]\nprint ");
            strcat(tac_code, reg_num);
            strcat(tac_code, "\nsub $1000, $1000, 1\n");
            strcat(tac_code, "add $999, $999, 1\nbrnz ");
            strcat(tac_code, loop_num);
            strcat(tac_code, ", $1000\n");
        } else {
            strcat(tac_code, "print ");
            strcat(tac_code, $$->t1->tac_code);
            strcat(tac_code, "\n");
        }
        if(!strcmp($1.id, "writeln")){
            strcat(tac_code, "print '\\n' \n");
        }
    }
;

read:

    READ '(' id ')' {
        $$ = NewNode("read", 0, 0, " ");
        $$->t1 = $3;
        strcat(tac_code, "scanf $665\n");
        if($$->t1->type == 1){
            strcat(tac_code, "fltoint $665, $665\n");
        }
        strcat(tac_code, "mov ");
        strcat(tac_code, $$->t1->tac_code);
        strcat(tac_code, ", $665\n");
    }
;

flow_control:

    {
        sprintf(if_loop, "Jump%d", loop);
        if_start = 1;
        loop++;
        ifs++;
    } if_else_statement {
        $$ = $2;
    } 

    | for_statement {
        $$ = $1;
    }

    | return_statement ';' {
        $$ = $1;
    }
;

if_else_statement:

    IF_RW '(' operation ')' statement %prec ELSE_RW {
        $$ = NewNode("if", 0, 0, " ");
        $$->t1 = $3;
        $$->t2 = $5;
        $$->type = $$->t2->type;
        strcat(tac_code, if_loop);
        strcat(tac_code, ":\n");
        ifs++;
    }

    | IF_RW '(' operation ')' statement ELSE_RW {
        if(ifs == 0){
            sprintf(end_loop1, "Jump%d", loop);
            strcat(tac_code, "jump ");
            strcat(tac_code, end_loop1);
            strcat(tac_code, "\n");
            strcat(tac_code, if_loop);
            strcat(tac_code, ":\n");
            loop++;
        } else if(ifs == 1) {
            sprintf(end_loop2, "Jump%d", loop);
            strcat(tac_code, "jump ");
            strcat(tac_code, end_loop2);
            strcat(tac_code, "\n");
            strcat(tac_code, if_loop);
            strcat(tac_code, "\n");
            loop++;
        } else if(ifs == 2) {
            sprintf(end_loop3, "Jump%d", loop);
            strcat(tac_code, "jump ");
            strcat(tac_code, end_loop3);
            strcat(tac_code, "\n");
            strcat(tac_code, if_loop);
            strcat(tac_code, ":\n");
            loop++;
        } else {
            sprintf(end_loop4, "Jump%d", loop);
            strcat(tac_code, "jump ");
            strcat(tac_code, end_loop4);
            strcat(tac_code, "\n");
            strcat(tac_code, if_loop);
            strcat(tac_code, ":\n");
        }
    } statement {
        $$ = NewNode("if else", 0, 0, " ");
        $$->t1 = $3;
        $$->t2 = $5;
        $$->t3 = $8;
        $$->type = $$->t3->type;
        if(ifs == 0){
            strcat(tac_code, end_loop1);
        } else if(ifs == 1) {
            strcat(tac_code, end_loop2);
        } else if(ifs == 2) {
            strcat(tac_code, end_loop3);
        } else if(ifs == 3) {
            strcat(tac_code, end_loop4);
        }
        strcat(tac_code, ":\n");
        ifs--;
    }

;

for_statement:

    FOR_RW '(' ass_op ';' {
        sprintf(for_loop1, "Jump%d", loop);
        loop++;
        sprintf(for_loop2, "Jump%d", loop);
        loop++;
        sprintf(for_loop3, "Jump%d", loop);
        loop++;
        sprintf(for_loop4, "Jump%d", loop);
        loop++;
        strcat(tac_code, for_loop1);
        strcat(tac_code, ":\n");
    } operation {
        strcat(tac_code, "jump ");
        strcat(tac_code, for_loop2);
        strcat(tac_code, "\n");
        strcat(tac_code, for_loop4);
        strcat(tac_code, ":\n");
    } ';' ass_op ')' {
        strcat(tac_code, "jump ");
        strcat(tac_code, for_loop1);
        strcat(tac_code, "\n");
        strcat(tac_code, for_loop3);
        strcat(tac_code, ":\n");
    } statement {
        $$ = NewNode("for", 0, 0, " ");
        $$->t1 = $3;
        $$->t2 = $6;
        $$->t3 = $9;
        $$->t4 = $12;
        $$->type = $$->t4->type;
        strcat(tac_code, "jump ");
        strcat(tac_code, for_loop4);
        strcat(tac_code, "\n");
        strcat(tac_code, for_loop2);
        strcat(tac_code, ":\nbrnz ");
        strcat(tac_code, for_loop3);
        strcat(tac_code, ", ");
        strcat(tac_code, $$->t2->tac_code);
        strcat(tac_code, "\n");
    }
;

return_statement:
    RETURN_RW operation {
        $$ = NewNode("return", 0, 1, " ");
        $$->t1 = $2;
        $$->type = $$->t1->type;
        strcat(tac_code, "return ");
        strcat(tac_code, $$->t1->tac_code);
        strcat(tac_code, "\n");
        if($$->t1->type > 2){
            strcpy(cur_ret, $$->t1->tac_code);
            type_return = $$->t1->type;
        }
    }
;

value:

    id {
        $$ = $1;
    }

    | function_call {
        $$ = $1;
    }

    | '(' operation ')' {
        $$ = $2;
    }

    | INT {
        $$ = NewNode($1.id, 1, 0, $1.id);
    }

    | FLOAT {
        $$ = NewNode($1.id, 1, 0, $1.id);
    }

    | NIL_RW {
        $$ = NewNode("nil", 3, 0, $1.id);
    }

    | STRING {
        strcat(tac_table, "char ");
        sprintf(str_num, "_s%d", str);
        strcat(tac_table, str_num);
        strcat(tac_table, "[] = ");
        strcat(tac_table, $1.id);
        strcat(tac_table, "\n");
        str++;
        $$ = NewNode($1.id, 0, 0, str_num);
    }
;

function_call:

    ID '(' {
        call_scope = SearchTable(Table, $1.id, 1, 1, stack, scope_position);
    } function_params ')' {
        if(!call_scope){
            printf("Semantic error, function %s not declared. Error position, Line = %d, Column = %d\n", $1.id, $1.line, $1.column);
            errors_sem++;
        } else if(CheckParams(Table, $1.id, -1) != args){
            printf("Semantic error, function %s with wrong number of arguments. Error position, Line = %d, Column = %d\n", $1.id, $1.line, $1.column);
            errors_sem++;
        } else if(param_errors){
            printf("Semantic error, function %s with wrong types of arguments. Error position, Line = %d, Column = %d\n", $1.id, $1.line, $1.column);
            param_errors = 0;
            errors_sem++;
        }
        $$ = NewNode("function call", CheckType(Table, $1.id, stack[scope_position], 0), 0, " ");
        $$->t2 = $4;

        strcat(tac_code, "call _");
        strcat(tac_code, $1.id);
        strcat(tac_code, ", ");
        sprintf(str_num, "%d", args);
        strcat(tac_code, str_num);
        strcat(tac_code, "\n");
        
        if(type_return > 2){
            strcpy($$->tac_code, cur_ret);
        } else {
            sprintf(reg_num, "$%d", reg);
            reg++;
            strcat(tac_code, "pop ");
            strcat(tac_code, reg_num);
            strcat(tac_code, "\n");
            strcat(tac_code, reg_num);
        }
        args = 0;
    }

    | ID '(' ')' {
        if(!SearchTable(Table, $1.id, 1, 1, stack, scope_position)){
            printf("Semantic error, function %s not declared. Error position, Line = %d, Column = %d\n", $1.id, $1.line, $1.column);
            errors_sem++;
        } else if(CheckParams(Table, $1.id, -1) != args){
            printf("Semantic error, function %s with wrong number of arguments. Error position, Line = %d, Column = %d\n", $1.id, $1.line, $1.column);
            errors_sem++;
        }
        args = 0;
        $$ = NewNode("function call", CheckType(Table, $1.id, stack[scope_position], 0), 0, " ");
        strcat(tac_code, "call _");
        strcat(tac_code, $1.id);
        strcat(tac_code, ", 0\n");
    }
;

id:

    ID {
        if(!SearchTable(Table, $1.id, 0, 0, stack, scope_position)){
            printf("Semantic error, variable %s not declared. Error position, Line = %d, Column = %d\n", $1.id, $1.line, $1.column);
            errors_sem++;
        }
        param = CheckParams(Table, $1.id, stack[scope_position]);
        sprintf(reg_num, "#%d", param - 1);
        scope_id = CheckScope(Table, $1.id, stack[scope_position]);
        sprintf(str_num, "_s%d", scope_id);
        strcpy(tac, $1.id);
        strcat(tac, str_num);
        if(param){
            $$ = NewNode($1.id, CheckType(Table, $1.id, stack[scope_position], 1), 0, reg_num);
        } else {
            $$ = NewNode($1.id, CheckType(Table, $1.id, stack[scope_position], 1), 0, tac);
        }
        
    }
;

function_params:

    function_params ',' operation {
        $$ = NewNode("params", 0, 0, " ");
        $$->t1 = $1;
        $$->t2 = $3;
        args++;
        strcat(tac_code, "param ");
        strcat(tac_code, $$->t2->tac_code);
        strcat(tac_code, "\n");

        if($$->t2->type < 3 && CheckParamsType(Table, args, call_scope - 1) > 2){
            param_errors = 1;
        } else if($$->t2->type > 2 && CheckParamsType(Table, args, call_scope - 1) < 3){
            param_errors = 1;
        }
    }

    | operation {
        args++;
        $$ = NewNode("params", 0, 0, " ");
        $$->t1 = $1;
        strcat(tac_code, "param ");
        strcat(tac_code, $$->t1->tac_code);
        strcat(tac_code, "\n");

        if($$->t1->type < 3 && CheckParamsType(Table, args, call_scope - 1) > 2){
            param_errors = 1;
        } else if($$->t1->type > 2 && CheckParamsType(Table, args, call_scope - 1) < 3){
            param_errors = 1;
        }
    }
;

%%

extern void ScopeChange(int op){
    if(op){
        scope++;
        scope_position++;
        stack[scope_position] = scope;
    } else {
        stack[scope_position] = 0;
        scope_position--;
    }
}

void yyerror(const char* message){
    printf("\nSyntax error %s. Error position, Line = %d, Column = %d\n", message, lines, columns);
    errors_sin++;
}

int main(int argc, char** argv){
    ++argv, --argc;

    if(argc > 0){
        yyin = fopen(argv[0], "r");
    }else{
        yyin = stdin;
    }
    yyparse();
    if(main_error){
        printf("Semantic error, main function not found\n");
        errors_sem++;
    }
    printf("Analysis ended with %d semantic errors, %d syntax errors and %d lexical errors.\n", errors_sem, errors_sin, errors);
    if(!errors_sin){
        PrintTree(Tree, 0);
    }

    PrintTable(Table);
    DestroyTree();

    strcat(tac_code, "\nmain:\ncall _main, 0");

    if(errors_sem + errors_sin == 0){
        CreateTac(argv[0], tac_table, tac_code);
    }

    fclose(yyin);
    yylex_destroy();
    return 0;
}