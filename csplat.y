%{
#include "stdio.h"

int yylex (void);

void yyerror (char const *err) { fprintf(stderr, "yyerror: %s\n", err); exit(-1); }

%}

%define parse.error custom

%token NUM IDENTIFIER L_PAREN R_PAREN LC RC RB LB WHEN ELSE WHILST DO STOP READ WRITE VOID INT RETURN ASSIGN QM ESCAPE SEMICOLON COMMA

%left ADD SUB MUL DIV REL

%union {
   int num;
   char* identifier;
}

//%type<num> NUM stmt exp
//%type<identifier> IDENTIFIER

%%

program: stmts { printf("program -> stmts\n");}

stmts: stmts stmt {printf("stmts -> stmt\n");}
|stmt {printf("stmts -> stmt\n");}

add_exp: mul_exp { printf("add_exp -> mul_exp\n");}
| add_exp ADD add_exp { printf("add_exp -> add_exp ADD add_exp\n");}
| add_exp SUB add_exp { printf("add_exp -> add_exp SUB add_exp\n");}

mul_exp: exp { printf("mul_exp -> exp\n");}
| mul_exp MUL mul_exp { printf("mul_exp -> mul_exp MUL mul_exp\n");}
| mul_exp DIV mul_exp { printf("mul_exp -> mul_exp DIV mul_exp\n");}

exp: NUM { printf("exp -> NUM\n");}
| SUB exp { printf("exp -> SUB exp\n");}
| L_PAREN add_exp R_PAREN { printf("exp -> L_PAREN add_exp R_PAREN\n");}
| rel_exp {printf("exp -> rel_exp\n");}
| function_call {printf("exp -> function_call\n");}
| IDENTIFIER {printf("exp -> IDENTIFIER\n");}
| IDENTIFIER LB add_exp RB {printf("exp -> IDENTIFIER LB add_exp RB\n");}

rel_exp: exp REL exp {printf("rel_exp -> exp REL exp\n");}

stmt: assignment {printf("stmt -> assignment\n");}
| WRITE L_PAREN param_list R_PAREN SEMICOLON {printf("stmt -> WRITE L_PAREN param_list R_PAREN SEMICOLON\n");}
| READ L_PAREN param_list R_PAREN SEMICOLON {printf("stmt -> READ L_PAREN param_list R_PAREN SEMICOLON\n");}
| declaration {printf("stmt -> declaration\n");}
| when_stmt {printf("stmt -> when_stmt\n");}
| whilst_stmt {printf("stmt -> whilst_stmt\n");}
| dowhilst_stmt {printf("stmt -> dowhilst_stmt\n");}
| function {printf("stmt -> function\n");}
| return_stmt {printf("stmt -> return_stmt\n");}

return_stmt: RETURN SEMICOLON {printf("return_stmt -> RETURN SEMICOLON\n");}
| RETURN add_exp SEMICOLON {printf("return_stmt -> RETURN add_exp SEMICOLON\n");}

when_stmt: WHEN L_PAREN add_exp R_PAREN LC stmts RC { printf("when_stmt -> WHEN L_PAREN add_exp R_PAREN LC stmts RC\n");}
| WHEN L_PAREN add_exp R_PAREN LC stmts RC ELSE LC stmts RC { printf("when_stmt -> WHEN L_PAREN add_exp R_PAREN LC stmts RC ELSE LC stmts RC\n");}
| WHEN L_PAREN add_exp R_PAREN LC stmts RC ELSE when_stmt { printf("when_stmt -> WHEN L_PAREN add_exp R_PAREN LC stmts RC ELSE when_stmt\n");}

whilst_stmt: WHILST L_PAREN add_exp R_PAREN LC stmts RC { printf("whilst_stmt -> WHILST add_exp LC stmts RC\n");}
| WHILST L_PAREN add_exp R_PAREN LC RC { printf("whilst_stmt -> WHILST add_exp LC RC\n");}

dowhilst_stmt: DO LC stmts RC WHILST exp { printf("dowhilst_stmt -> DO LC stmts RC WHILST exp\n");}
| DO LC RC WHILST exp { printf("dowhilst_stmt -> DO LC RC WHILST exp\n");}

function: type IDENTIFIER QM param_type_list QM LC stmts RC {printf("function -> type IDENTIFIER QM param_type_list QM LC stmts RC\n");}

function_call: IDENTIFIER QM param_list QM {printf("function_call -> IDENTIFIER QM add_exp QM\n");}

param_type_list: type IDENTIFIER COMMA param_type_list {printf("param_type_list -> type IDENTIFIER COMMA param_type_list\n");}
| type IDENTIFIER LB RB COMMA param_type_list {printf("param_type_list -> type IDENTIFIER LB RB COMMA param_type_list\n");}
| type IDENTIFIER {printf("param_list -> type IDENTIFIER\n");}
| type IDENTIFIER LB RB {printf("param_list -> type IDENTIFIER LB RB\n");}

param_list: add_exp COMMA {printf("param_list -> add_exp COMMA\n");}
| add_exp {printf("param_list -> add_exp\n");}
| {printf("param_list -> 'epsilon'\n");}

type: VOID {printf("type -> VOID\n");}
| INT {printf("type -> INT\n");}

declaration: type IDENTIFIER SEMICOLON {printf("declaration -> type IDENTIFIER SEMICOLON\n");}
| type IDENTIFIER LB add_exp RB SEMICOLON {printf("declaration -> type IDENTIFIER LB add_exp RB SEMICOLON\n");}

assignment: IDENTIFIER ASSIGN add_exp SEMICOLON {printf("assignment -> IDENTIFIER ASSIGN add_exp\n");}
| IDENTIFIER LB add_exp RB ASSIGN add_exp SEMICOLON {printf("assignment -> IDENTIFIER LB add_exp RB ASSIGN add_exp\n");}

%%

static int yyreport_syntax_error(const yypcontext_t *ctx) {
	yysymbol_kind_t tokenCausingError = yypcontext_token(ctx);
	yysymbol_kind_t expectedTokens[YYNTOKENS];
	int numExpectedTokens = yypcontext_expected_tokens(ctx, expectedTokens, YYNTOKENS);
	
	fprintf(stderr, "\n-- Syntax Error --\n");
	fprintf(stderr, "%llu line, %llu column\n", current_line, current_column);
	if (yysymbol_name(tokenCausingError) == "REL") {
		for (int i = 0; i < numExpectedTokens; i++) {
			if (yysymbol_name(expectedTokens[i]) == "ASSIGN") {
				printf("Assignment operator was expected. Found '=' instead\n");
			}
		}
	} else {
		fprintf(stderr, "Token causing error: %s\n", yysymbol_name(tokenCausingError));
		for (int i = 0; i < numExpectedTokens; ++i) {
			fprintf(stderr, " expected token (%d/%d): %s\n", i+1, numExpectedTokens, yysymbol_name(expectedTokens[i]));
		}
	}
	return 0;
}
