/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "csplat.y"

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

int yylex (void);

void yyerror (char const *err) { fprintf(stderr, "yyerror: %s\n", err); exit(-1); }

static char* genTempName() {
	static unsigned long long counter;
	static char buff[4096]; sprintf(buff, "temp%llu", counter++);
	return strdup(buff);
}

static char* genLabelName() {
	static unsigned long long lbcounter;
	static char lbbuff[4096]; sprintf(lbbuff, "label%llu", lbcounter++);
	return strdup(lbbuff);
}

typedef struct { char **data; size_t len; } Vec;

static void VecPush(Vec *vec, char *cstring) {
	if ( !(vec->data = realloc(vec->data, sizeof(char *)*(vec->len + 1)))) {
		printf("bad_alloc\n"); exit(-1);
	}
	vec->data[vec->len++] = cstring;
}

static Vec vec;

int variableExists(char *var) {
	for (int i = 0; i < vec.len; ++i) {
		if (0 == strcmp(vec.data[i], var)) {
			return 1;
		}
	}
	return 0;
}

void printSemanticError() {
	fprintf(stderr, "Error line %llu: ", current_line);
}


#line 119 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    IDENTIFIER = 259,              /* IDENTIFIER  */
    L_PAREN = 260,                 /* L_PAREN  */
    R_PAREN = 261,                 /* R_PAREN  */
    LC = 262,                      /* LC  */
    RC = 263,                      /* RC  */
    RB = 264,                      /* RB  */
    LB = 265,                      /* LB  */
    WHEN = 266,                    /* WHEN  */
    ELSE = 267,                    /* ELSE  */
    WHILST = 268,                  /* WHILST  */
    DO = 269,                      /* DO  */
    STOP = 270,                    /* STOP  */
    READ = 271,                    /* READ  */
    WRITE = 272,                   /* WRITE  */
    VOID = 273,                    /* VOID  */
    INT = 274,                     /* INT  */
    RETURN = 275,                  /* RETURN  */
    ASSIGN = 276,                  /* ASSIGN  */
    QM = 277,                      /* QM  */
    ESCAPE = 278,                  /* ESCAPE  */
    SEMICOLON = 279,               /* SEMICOLON  */
    COMMA = 280,                   /* COMMA  */
    ADD = 281,                     /* ADD  */
    SUB = 282,                     /* SUB  */
    MUL = 283,                     /* MUL  */
    DIV = 284,                     /* DIV  */
    REL = 285                      /* REL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 55 "csplat.y"

   char* identifier;

#line 203 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_L_PAREN = 5,                    /* L_PAREN  */
  YYSYMBOL_R_PAREN = 6,                    /* R_PAREN  */
  YYSYMBOL_LC = 7,                         /* LC  */
  YYSYMBOL_RC = 8,                         /* RC  */
  YYSYMBOL_RB = 9,                         /* RB  */
  YYSYMBOL_LB = 10,                        /* LB  */
  YYSYMBOL_WHEN = 11,                      /* WHEN  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_WHILST = 13,                    /* WHILST  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_STOP = 15,                      /* STOP  */
  YYSYMBOL_READ = 16,                      /* READ  */
  YYSYMBOL_WRITE = 17,                     /* WRITE  */
  YYSYMBOL_VOID = 18,                      /* VOID  */
  YYSYMBOL_INT = 19,                       /* INT  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_QM = 22,                        /* QM  */
  YYSYMBOL_ESCAPE = 23,                    /* ESCAPE  */
  YYSYMBOL_SEMICOLON = 24,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 25,                     /* COMMA  */
  YYSYMBOL_ADD = 26,                       /* ADD  */
  YYSYMBOL_SUB = 27,                       /* SUB  */
  YYSYMBOL_MUL = 28,                       /* MUL  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_REL = 30,                       /* REL  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_33_1 = 33,                      /* $@1  */
  YYSYMBOL_34_2 = 34,                      /* $@2  */
  YYSYMBOL_stmts = 35,                     /* stmts  */
  YYSYMBOL_add_exp = 36,                   /* add_exp  */
  YYSYMBOL_mul_exp = 37,                   /* mul_exp  */
  YYSYMBOL_exp = 38,                       /* exp  */
  YYSYMBOL_rel_exp = 39,                   /* rel_exp  */
  YYSYMBOL_stmt = 40,                      /* stmt  */
  YYSYMBOL_return_stmt = 41,               /* return_stmt  */
  YYSYMBOL_when_stmt = 42,                 /* when_stmt  */
  YYSYMBOL_whilst_stmt = 43,               /* whilst_stmt  */
  YYSYMBOL_dowhilst_stmt = 44,             /* dowhilst_stmt  */
  YYSYMBOL_function = 45,                  /* function  */
  YYSYMBOL_46_3 = 46,                      /* $@3  */
  YYSYMBOL_function_call = 47,             /* function_call  */
  YYSYMBOL_param_type_list = 48,           /* param_type_list  */
  YYSYMBOL_param_list = 49,                /* param_list  */
  YYSYMBOL_type = 50,                      /* type  */
  YYSYMBOL_declaration = 51,               /* declaration  */
  YYSYMBOL_assignment = 52                 /* assignment  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    63,    63,    63,    63,    65,    66,    68,    71,    77,
      84,    87,    93,   100,   106,   112,   115,   118,   121,   129,
     141,   147,   148,   151,   154,   155,   156,   157,   158,   159,
     161,   164,   168,   169,   170,   172,   176,   178,   179,   181,
     181,   185,   187,   188,   189,   190,   192,   193,   194,   196,
     197,   199,   203,   213,   218
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "NUM", "IDENTIFIER", "L_PAREN",
  "R_PAREN", "LC", "RC", "RB", "LB", "WHEN", "ELSE", "WHILST", "DO",
  "STOP", "READ", "WRITE", "VOID", "INT", "RETURN", "ASSIGN", "QM",
  "ESCAPE", "SEMICOLON", "COMMA", "ADD", "SUB", "MUL", "DIV", "REL",
  "$accept", "program", "$@1", "$@2", "stmts", "add_exp", "mul_exp", "exp",
  "rel_exp", "stmt", "return_stmt", "when_stmt", "whilst_stmt",
  "dowhilst_stmt", "function", "$@3", "function_call", "param_type_list",
  "param_list", "type", "declaration", "assignment", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-85)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -85,    48,   187,   -85,    46,     6,    12,    43,    50,    60,
     -85,   -85,    15,   187,   -85,   -85,   -85,   -85,   -85,   -85,
      59,   -85,   -85,    11,    11,    11,    11,    58,    66,    69,
     -85,     0,    11,   -85,    11,    55,    89,    38,   -85,   -85,
     -85,   -85,     3,    25,    64,     2,    17,    67,    91,    78,
      80,    11,    11,    20,   -85,   -85,    11,    11,    11,    11,
      11,    95,    74,   -85,    82,   -85,    94,   113,    11,   110,
     111,   116,    31,    88,   112,   -85,   -85,   -85,   -85,   -85,
     -85,   123,   -85,   133,    11,   187,   108,    38,    11,   -85,
     -85,   -85,   -85,   -85,   124,   127,    -1,    70,   125,   -85,
     142,    38,   -85,   140,   143,    74,   -85,   139,   -85,   187,
     129,   -85,    42,   159,    74,   187,   -85,   -85,   -85,   176,
     -85
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     0,     0,     0,
      49,    50,     0,     3,     6,    29,    25,    26,    27,    28,
       0,    24,    21,     0,     0,     0,     0,     0,     0,     0,
      13,    18,     0,    30,     0,     0,     7,    10,    16,    17,
       4,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,    14,    31,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    53,     0,     0,     0,     0,
       0,     0,     0,    47,     0,    15,     8,     9,    11,    12,
      20,     0,    39,     0,     0,     0,     0,    38,     0,    23,
      22,    19,    46,    41,     0,     0,    44,     0,     0,    36,
       0,    37,    52,     0,     0,     0,    54,    32,    35,     0,
      45,    42,     0,     0,     0,     0,    34,    40,    43,     0,
      33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -85,   -85,   -85,   -85,   -26,   -20,    72,   -27,   -85,   -13,
     -85,    45,   -85,   -85,   -85,   -85,   -85,   -84,   -85,   -60,
     -85,   -85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    40,    13,    35,    36,    37,    38,    14,
      15,    16,    17,    18,    19,    95,    39,    82,    74,    20,
      21,    22
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      41,    48,    83,    43,    44,    45,    46,    54,    66,   104,
      51,    25,    53,    61,    30,    31,    32,    26,    30,    31,
      32,   111,    52,    67,   105,    62,    75,    63,    56,    57,
     118,    72,    73,    80,    64,    41,    76,    77,    34,    33,
      91,    87,    34,    56,    57,    83,    56,    57,     3,   115,
      27,    56,    57,     5,    83,    28,    23,    56,    57,    98,
     100,   101,     4,    42,    97,    29,    47,    24,    60,     5,
      49,     6,     7,    50,     8,     9,    10,    11,    12,    55,
      68,    56,    57,   113,    70,    41,    71,    41,    65,   119,
      56,    57,    10,    11,   106,     4,    56,    57,    81,    69,
      41,    85,     5,    84,     6,     7,    41,     8,     9,    10,
      11,    12,     4,    92,    56,    57,    99,    58,    59,     5,
      86,     6,     7,    88,     8,     9,    10,    11,    12,     4,
      78,    79,    94,   107,    93,    89,     5,    96,     6,     7,
      90,     8,     9,    10,    11,    12,     4,   109,   102,   103,
     108,   112,   110,     5,   114,     6,     7,   116,     8,     9,
      10,    11,    12,     4,     0,     0,     0,   117,     0,     0,
       5,     0,     6,     7,     0,     8,     9,    10,    11,    12,
       4,     0,     0,     0,   120,     0,     0,     5,     0,     6,
       7,     4,     8,     9,    10,    11,    12,     0,     5,     0,
       6,     7,     0,     8,     9,    10,    11,    12
};

static const yytype_int8 yycheck[] =
{
      13,    27,    62,    23,    24,    25,    26,    34,     6,    10,
      10,     5,    32,    10,     3,     4,     5,     5,     3,     4,
       5,   105,    22,     6,    25,    22,     6,    24,    26,    27,
     114,    51,    52,    60,     9,    48,    56,    57,    27,    24,
       9,    68,    27,    26,    27,   105,    26,    27,     0,     7,
       7,    26,    27,    11,   114,     5,    10,    26,    27,    85,
      86,    88,     4,     4,    84,     5,     8,    21,    30,    11,
       4,    13,    14,     4,    16,    17,    18,    19,    20,    24,
      13,    26,    27,   109,     6,    98,     6,   100,    24,   115,
      26,    27,    18,    19,    24,     4,    26,    27,     3,     8,
     113,     7,    11,    21,    13,    14,   119,    16,    17,    18,
      19,    20,     4,    25,    26,    27,     8,    28,    29,    11,
       7,    13,    14,    13,    16,    17,    18,    19,    20,     4,
      58,    59,     9,     8,    22,    24,    11,     4,    13,    14,
      24,    16,    17,    18,    19,    20,     4,     7,    24,    22,
       8,    12,     9,    11,    25,    13,    14,   112,    16,    17,
      18,    19,    20,     4,    -1,    -1,    -1,     8,    -1,    -1,
      11,    -1,    13,    14,    -1,    16,    17,    18,    19,    20,
       4,    -1,    -1,    -1,     8,    -1,    -1,    11,    -1,    13,
      14,     4,    16,    17,    18,    19,    20,    -1,    11,    -1,
      13,    14,    -1,    16,    17,    18,    19,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    33,     0,     4,    11,    13,    14,    16,    17,
      18,    19,    20,    35,    40,    41,    42,    43,    44,    45,
      50,    51,    52,    10,    21,     5,     5,     7,     5,     5,
       3,     4,     5,    24,    27,    36,    37,    38,    39,    47,
      34,    40,     4,    36,    36,    36,    36,     8,    35,     4,
       4,    10,    22,    36,    38,    24,    26,    27,    28,    29,
      30,    10,    22,    24,     9,    24,     6,     6,    13,     8,
       6,     6,    36,    36,    49,     6,    36,    36,    37,    37,
      38,     3,    48,    50,    21,     7,     7,    38,    13,    24,
      24,     9,    25,    22,     9,    46,     4,    36,    35,     8,
      35,    38,    24,    22,    10,    25,    24,     8,     8,     7,
       9,    48,    12,    35,    25,     7,    42,     8,    48,    35,
       8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    33,    34,    32,    35,    35,    36,    36,    36,
      37,    37,    37,    38,    38,    38,    38,    38,    38,    38,
      39,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      41,    41,    42,    42,    42,    43,    43,    44,    44,    46,
      45,    47,    48,    48,    48,    48,    49,    49,    49,    50,
      50,    51,    51,    52,    52
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     3,     2,     1,     1,     3,     3,
       1,     3,     3,     1,     2,     3,     1,     1,     1,     4,
       3,     1,     5,     5,     1,     1,     1,     1,     1,     1,
       2,     3,     7,    11,     9,     7,     6,     6,     5,     0,
       9,     4,     4,     6,     2,     4,     2,     1,     0,     1,
       1,     3,     6,     4,     7
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




/* The kind of the lookahead of this context.  */
static yysymbol_kind_t
yypcontext_token (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;

static yysymbol_kind_t
yypcontext_token (const yypcontext_t *yyctx)
{
  return yyctx->yytoken;
}



/* User defined function to report a syntax error.  */
static int
yyreport_syntax_error (const yypcontext_t *yyctx);

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 63 "csplat.y"
         { printf("func main\n"); }
#line 1383 "y.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 63 "csplat.y"
                                          { printf("endfunc\n"); }
#line 1389 "y.tab.c"
    break;

  case 4: /* program: $@1 stmts $@2  */
#line 63 "csplat.y"
                                                                   {}
#line 1395 "y.tab.c"
    break;

  case 5: /* stmts: stmts stmt  */
#line 65 "csplat.y"
                  {}
#line 1401 "y.tab.c"
    break;

  case 6: /* stmts: stmt  */
#line 66 "csplat.y"
      {}
#line 1407 "y.tab.c"
    break;

  case 7: /* add_exp: mul_exp  */
#line 68 "csplat.y"
                 {
	(yyval.identifier) = (yyvsp[0].identifier);
}
#line 1415 "y.tab.c"
    break;

  case 8: /* add_exp: add_exp ADD add_exp  */
#line 71 "csplat.y"
                      {
	char* name = genTempName();
	printf(". %s\n", name);
	printf("+ %s, %s, %s\n", name, (yyvsp[-2].identifier), (yyvsp[0].identifier));
	(yyval.identifier) = name;
}
#line 1426 "y.tab.c"
    break;

  case 9: /* add_exp: add_exp SUB add_exp  */
#line 77 "csplat.y"
                      {
	char* name = genTempName();
	printf(". %s\n", name);
	printf("- %s, %s, %s\n", name, (yyvsp[-2].identifier), (yyvsp[0].identifier));
	(yyval.identifier) = name;
}
#line 1437 "y.tab.c"
    break;

  case 10: /* mul_exp: exp  */
#line 84 "csplat.y"
             {
	(yyval.identifier) = (yyvsp[0].identifier);
}
#line 1445 "y.tab.c"
    break;

  case 11: /* mul_exp: mul_exp MUL mul_exp  */
#line 87 "csplat.y"
                      {
	char* name = genTempName();
	printf(". %s\n", name);
	printf("* %s, %s, %s\n", name, (yyvsp[-2].identifier), (yyvsp[0].identifier));
	(yyval.identifier) = name;
}
#line 1456 "y.tab.c"
    break;

  case 12: /* mul_exp: mul_exp DIV mul_exp  */
#line 93 "csplat.y"
                      {
	char* name = genTempName();
	printf(". %s\n", name);
	printf("/ %s, %s, %s\n", name, (yyvsp[-2].identifier), (yyvsp[0].identifier));
	(yyval.identifier) = name;
}
#line 1467 "y.tab.c"
    break;

  case 13: /* exp: NUM  */
#line 100 "csplat.y"
         {
	char* name = genTempName();
	printf(". %s\n", name);
	printf("= %s, %s\n", name, (yyvsp[0].identifier));
	(yyval.identifier) = (yyvsp[0].identifier);
}
#line 1478 "y.tab.c"
    break;

  case 14: /* exp: SUB exp  */
#line 106 "csplat.y"
          {
	char* name = genTempName();
	printf(". %s\n", name);
	printf("- %s, 0, %s\n", name, (yyvsp[0].identifier));
	(yyval.identifier) = name;
}
#line 1489 "y.tab.c"
    break;

  case 15: /* exp: L_PAREN add_exp R_PAREN  */
#line 112 "csplat.y"
                          {
	(yyval.identifier) = (yyvsp[-1].identifier);
}
#line 1497 "y.tab.c"
    break;

  case 16: /* exp: rel_exp  */
#line 115 "csplat.y"
          {
	(yyval.identifier) = (yyvsp[0].identifier);
}
#line 1505 "y.tab.c"
    break;

  case 17: /* exp: function_call  */
#line 118 "csplat.y"
                {
	(yyval.identifier) = (yyvsp[0].identifier);
}
#line 1513 "y.tab.c"
    break;

  case 18: /* exp: IDENTIFIER  */
#line 121 "csplat.y"
             {
	if (!variableExists((yyvsp[0].identifier))) {
		printSemanticError();
		fprintf(stderr, "Undefined variable '%s'\n", (yyvsp[0].identifier));
		exit(-1);
	}
	(yyval.identifier) = (yyvsp[0].identifier);
}
#line 1526 "y.tab.c"
    break;

  case 19: /* exp: IDENTIFIER LB add_exp RB  */
#line 129 "csplat.y"
                           {
	if (!variableExists((yyvsp[-3].identifier))) {
		printSemanticError();
		fprintf(stderr, "Undefined variable '%s'\n", (yyvsp[-3].identifier));
		exit(-1);
	}
	char* name = genTempName();
	printf(". %s\n", name);
	printf("=[] %s, %s, %s\n", name, (yyvsp[-3].identifier), (yyvsp[-1].identifier));
	(yyval.identifier) = name;
}
#line 1542 "y.tab.c"
    break;

  case 20: /* rel_exp: exp REL exp  */
#line 141 "csplat.y"
                     {
	char* name = genTempName();
	printf(". %s\n", name);
	printf("%s %s, %s, %s\n", (yyvsp[-1].identifier), name, (yyvsp[-2].identifier), (yyvsp[0].identifier));
}
#line 1552 "y.tab.c"
    break;

  case 21: /* stmt: assignment  */
#line 147 "csplat.y"
                 {}
#line 1558 "y.tab.c"
    break;

  case 22: /* stmt: WRITE L_PAREN IDENTIFIER R_PAREN SEMICOLON  */
#line 148 "csplat.y"
                                             {
	printf(".> %s\n", (yyvsp[-2].identifier));
}
#line 1566 "y.tab.c"
    break;

  case 23: /* stmt: READ L_PAREN IDENTIFIER R_PAREN SEMICOLON  */
#line 151 "csplat.y"
                                            {
	printf(".< %s\n", (yyvsp[-2].identifier));
}
#line 1574 "y.tab.c"
    break;

  case 24: /* stmt: declaration  */
#line 154 "csplat.y"
              {}
#line 1580 "y.tab.c"
    break;

  case 25: /* stmt: when_stmt  */
#line 155 "csplat.y"
            {}
#line 1586 "y.tab.c"
    break;

  case 26: /* stmt: whilst_stmt  */
#line 156 "csplat.y"
              {}
#line 1592 "y.tab.c"
    break;

  case 27: /* stmt: dowhilst_stmt  */
#line 157 "csplat.y"
                {}
#line 1598 "y.tab.c"
    break;

  case 28: /* stmt: function  */
#line 158 "csplat.y"
           {}
#line 1604 "y.tab.c"
    break;

  case 29: /* stmt: return_stmt  */
#line 159 "csplat.y"
              {}
#line 1610 "y.tab.c"
    break;

  case 30: /* return_stmt: RETURN SEMICOLON  */
#line 161 "csplat.y"
                              {
	printf("ret 0\n");
}
#line 1618 "y.tab.c"
    break;

  case 31: /* return_stmt: RETURN add_exp SEMICOLON  */
#line 164 "csplat.y"
                           {
	printf("ret %s\n", (yyvsp[-1].identifier));
}
#line 1626 "y.tab.c"
    break;

  case 32: /* when_stmt: WHEN L_PAREN add_exp R_PAREN LC stmts RC  */
#line 168 "csplat.y"
                                                    { }
#line 1632 "y.tab.c"
    break;

  case 33: /* when_stmt: WHEN L_PAREN add_exp R_PAREN LC stmts RC ELSE LC stmts RC  */
#line 169 "csplat.y"
                                                            { }
#line 1638 "y.tab.c"
    break;

  case 34: /* when_stmt: WHEN L_PAREN add_exp R_PAREN LC stmts RC ELSE when_stmt  */
#line 170 "csplat.y"
                                                          { }
#line 1644 "y.tab.c"
    break;

  case 35: /* whilst_stmt: WHILST L_PAREN add_exp R_PAREN LC stmts RC  */
#line 173 "csplat.y"
{ 
	printf("1231231\n");
}
#line 1652 "y.tab.c"
    break;

  case 36: /* whilst_stmt: WHILST L_PAREN add_exp R_PAREN LC RC  */
#line 176 "csplat.y"
                                       { }
#line 1658 "y.tab.c"
    break;

  case 37: /* dowhilst_stmt: DO LC stmts RC WHILST exp  */
#line 178 "csplat.y"
                                         { }
#line 1664 "y.tab.c"
    break;

  case 38: /* dowhilst_stmt: DO LC RC WHILST exp  */
#line 179 "csplat.y"
                      { }
#line 1670 "y.tab.c"
    break;

  case 39: /* $@3: %empty  */
#line 181 "csplat.y"
                                             { printf("func %s\n", (yyvsp[-2].identifier)); }
#line 1676 "y.tab.c"
    break;

  case 40: /* function: type IDENTIFIER QM param_type_list $@3 QM LC stmts RC  */
#line 181 "csplat.y"
                                                                                         {
	printf("endfunc\n");
}
#line 1684 "y.tab.c"
    break;

  case 41: /* function_call: IDENTIFIER QM param_list QM  */
#line 185 "csplat.y"
                                           {}
#line 1690 "y.tab.c"
    break;

  case 42: /* param_type_list: type IDENTIFIER COMMA param_type_list  */
#line 187 "csplat.y"
                                                       {}
#line 1696 "y.tab.c"
    break;

  case 43: /* param_type_list: type IDENTIFIER LB RB COMMA param_type_list  */
#line 188 "csplat.y"
                                              {}
#line 1702 "y.tab.c"
    break;

  case 44: /* param_type_list: type IDENTIFIER  */
#line 189 "csplat.y"
                  {}
#line 1708 "y.tab.c"
    break;

  case 45: /* param_type_list: type IDENTIFIER LB RB  */
#line 190 "csplat.y"
                        {}
#line 1714 "y.tab.c"
    break;

  case 46: /* param_list: add_exp COMMA  */
#line 192 "csplat.y"
                          {}
#line 1720 "y.tab.c"
    break;

  case 47: /* param_list: add_exp  */
#line 193 "csplat.y"
          {}
#line 1726 "y.tab.c"
    break;

  case 48: /* param_list: %empty  */
#line 194 "csplat.y"
  {}
#line 1732 "y.tab.c"
    break;

  case 49: /* type: VOID  */
#line 196 "csplat.y"
           {}
#line 1738 "y.tab.c"
    break;

  case 50: /* type: INT  */
#line 197 "csplat.y"
      {}
#line 1744 "y.tab.c"
    break;

  case 51: /* declaration: type IDENTIFIER SEMICOLON  */
#line 199 "csplat.y"
                                       {
	VecPush(&vec, (yyvsp[-1].identifier));
	printf(". %s\n", (yyvsp[-1].identifier));
}
#line 1753 "y.tab.c"
    break;

  case 52: /* declaration: type IDENTIFIER LB NUM RB SEMICOLON  */
#line 203 "csplat.y"
                                      {
	VecPush(&vec, (yyvsp[-4].identifier));
	if (atoi((yyvsp[-2].identifier)) <= 0) {
		printSemanticError();
		fprintf(stderr, "Array size must be greater than zero!\n");
		exit(-1);
	}
	printf(".[] %s, %s\n", (yyvsp[-4].identifier), (yyvsp[-2].identifier));
}
#line 1767 "y.tab.c"
    break;

  case 53: /* assignment: IDENTIFIER ASSIGN add_exp SEMICOLON  */
#line 213 "csplat.y"
                                                {
	char* name = genTempName();
	printf(". %s\n", name);
	printf("= %s, %s\n", name, (yyvsp[-1].identifier));
}
#line 1777 "y.tab.c"
    break;

  case 54: /* assignment: IDENTIFIER LB add_exp RB ASSIGN add_exp SEMICOLON  */
#line 218 "csplat.y"
                                                    {
	printf("[]= %s, %s, %s\n", (yyvsp[-6].identifier), (yyvsp[-4].identifier), (yyvsp[-1].identifier));
}
#line 1785 "y.tab.c"
    break;


#line 1789 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        if (yyreport_syntax_error (&yyctx) == 2)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 222 "csplat.y"


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
