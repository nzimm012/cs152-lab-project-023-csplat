%{
#include "stdio.h"

int yylex (void);

void yyerror (char const *err) { fprintf(stderr, "yyerror: %s\n", err); exit(-1); }

%}

%define parse.error custom

%token NUM IDENTIFIER L_PAREN R_PAREN LC RC RB LB WHEN ELSE WHILST DO STOP READ WRITE VOID INT RETURN ASSIGN QM ESCAPE

%left ADD SUB MUL DIV REL

%union {
   int num;
}

//%type<num> NUM stmt exp

%%

program: stmts { printf("program -> stmts\n");}
| program stmt { printf("program -> program stmt\n");}

stmts: add_exp ASSIGN { printf("stmts -> add_exp ASSIGN\n");}
| exp { printf("stmts -> exp\n");}
| add_exp REL NUM { printf("stmts -> add_exp REL NUM\n");}

add_exp: mul_exp { printf("add_exp -> mul_exp\n");}
| add_exp ADD add_exp { printf("add_exp -> add_exp ADD add_exp\n");}
| add_exp SUB add_exp { printf("add_exp -> add_exp SUB add_exp\n");}

mul_exp: exp { printf("mul_exp -> exp\n");}
| mul_exp MUL mul_exp { printf("mul_exp -> mul_exp MUL mul_exp\n");}
| mul_exp DIV mul_exp { printf("mul_exp -> mul_exp DIV mul_exp\n");}

exp: NUM { printf("exp -> NUM\n");}
| SUB exp { printf("exp -> SUB exp\n");}
| L_PAREN add_exp R_PAREN { printf("exp -> L_PAREN add_exp R_PAREN\n");}

stmt: when_stmt { printf("stmt -> when_stmt\n");}

when_stmt: WHEN L_PAREN exp R_PAREN LC stmts RC { printf("when_stmt -> WHEN L_PAREN exp R_PAREN LC stmts RC\n");}
| WHEN L_PAREN exp R_PAREN LC stmts RC ELSE LC stmts RC { printf("when_stmt -> WHEN L_PAREN exp R_PAREN LC stmts RC ELSE LC stmts RC\n");}



%%

static int yyreport_syntax_error(const yypcontext_t *ctx) {
	yysymbol_kind_t tokenCausingError = yypcontext_token(ctx);
	yysymbol_kind_t expectedTokens[YYNTOKENS];
	int numExpectedTokens = yypcontext_expected_tokens(ctx, expectedTokens, YYNTOKENS);
	
	fprintf(stderr, "\n-- Syntax Error --\n");
	fprintf(stderr, "%llu line, %llu column\n", current_line, current_column);
	fprintf(stderr, "Token causing error: %s\n", yysymbol_name(tokenCausingError));
	for (int i = 0; i < numExpectedTokens; ++i) {
		fprintf(stderr, " expected token (%d/%d): %s\n", i+1, numExpectedTokens, yysymbol_name(expectedTokens[i]));
	}
	return 0;
}