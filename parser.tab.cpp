/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VOID = 258,
     INT = 259,
     BYTE = 260,
     B = 261,
     BOOL = 262,
     CONST = 263,
     TRUE = 264,
     FALSE = 265,
     RETURN = 266,
     WHILE = 267,
     BREAK = 268,
     CONTINUE = 269,
     SC = 270,
     COMMA = 271,
     LBRACE = 272,
     RBRACE = 273,
     ID = 274,
     NUM = 275,
     STRING = 276,
     LPAREN = 277,
     RPAREN = 278,
     NOT = 279,
     OR = 280,
     AND = 281,
     RELOPLEFT = 282,
     RELOPNONASSOC = 283,
     MINUS = 284,
     PLUS = 285,
     DIV = 286,
     MULT = 287,
     IF = 288,
     ELSE = 289,
     ASSIGN = 290
   };
#endif
/* Tokens.  */
#define VOID 258
#define INT 259
#define BYTE 260
#define B 261
#define BOOL 262
#define CONST 263
#define TRUE 264
#define FALSE 265
#define RETURN 266
#define WHILE 267
#define BREAK 268
#define CONTINUE 269
#define SC 270
#define COMMA 271
#define LBRACE 272
#define RBRACE 273
#define ID 274
#define NUM 275
#define STRING 276
#define LPAREN 277
#define RPAREN 278
#define NOT 279
#define OR 280
#define AND 281
#define RELOPLEFT 282
#define RELOPNONASSOC 283
#define MINUS 284
#define PLUS 285
#define DIV 286
#define MULT 287
#define IF 288
#define ELSE 289
#define ASSIGN 290




/* Copy the first part of user declarations.  */
#line 1 "parser.ypp"

    #include <iostream>
    #include "hw3_output.hpp"
    #include "Semantics.h"
    #include "register.h"
    #include "bp.hpp"
    using namespace std;
    int yylex();
    extern int yylineno;
    extern std::string curFuncName;
    extern char *yytext;
    void yyerror(const char* err);

    CodeBuffer& buffer = CodeBuffer::instance();
    extern RegisterManager registerManager;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 193 "parser.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  116

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    11,    12,    24,    26,
      28,    29,    31,    33,    37,    41,    43,    46,    51,    56,
      63,    68,    71,    74,    78,    85,    96,    97,   105,   108,
     111,   113,   118,   122,   124,   128,   130,   132,   134,   135,
     137,   141,   145,   149,   153,   157,   159,   161,   163,   166,
     168,   170,   172,   175,   180,   185,   189,   193,   198,   199,
     200,   201,   202,   203
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    56,    38,    -1,    -1,    39,    38,    -1,
      -1,    -1,    42,    19,    40,    57,    22,    43,    23,    17,
      41,    46,    18,    -1,    52,    -1,     3,    -1,    -1,    44,
      -1,    45,    -1,    45,    16,    44,    -1,    53,    52,    19,
      -1,    47,    -1,    46,    47,    -1,    17,    58,    46,    18,
      -1,    53,    52,    19,    15,    -1,    53,    52,    19,    35,
      54,    15,    -1,    19,    35,    54,    15,    -1,    50,    15,
      -1,    11,    15,    -1,    11,    54,    15,    -1,    33,    22,
      58,    49,    23,    47,    -1,    33,    22,    58,    49,    23,
      47,    34,    60,    58,    47,    -1,    -1,    12,    59,    22,
      54,    48,    23,    47,    -1,    13,    15,    -1,    14,    15,
      -1,    54,    -1,    19,    22,    51,    23,    -1,    19,    22,
      23,    -1,    54,    -1,    54,    16,    51,    -1,     4,    -1,
       5,    -1,     7,    -1,    -1,     8,    -1,    22,    54,    23,
      -1,    54,    32,    54,    -1,    54,    31,    54,    -1,    54,
      30,    54,    -1,    54,    29,    54,    -1,    19,    -1,    50,
      -1,    20,    -1,    20,     6,    -1,    21,    -1,     9,    -1,
      10,    -1,    24,    54,    -1,    54,    26,    55,    54,    -1,
      54,    25,    55,    54,    -1,    54,    28,    54,    -1,    54,
      27,    54,    -1,    22,    52,    23,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    53,    54,    56,    56,    56,    63,    64,
      66,    67,    69,    70,    72,    76,    77,    79,    80,    83,
      86,    87,    88,    89,    90,    94,   103,   103,   108,   109,
     111,   113,   114,   116,   117,   119,   120,   121,   123,   124,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   146,   148,
     150,   152,   154,   156
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "BYTE", "B", "BOOL",
  "CONST", "TRUE", "FALSE", "RETURN", "WHILE", "BREAK", "CONTINUE", "SC",
  "COMMA", "LBRACE", "RBRACE", "ID", "NUM", "STRING", "LPAREN", "RPAREN",
  "NOT", "OR", "AND", "RELOPLEFT", "RELOPNONASSOC", "MINUS", "PLUS", "DIV",
  "MULT", "IF", "ELSE", "ASSIGN", "$accept", "program", "funcs",
  "funcDecl", "@1", "@2", "retType", "formals", "formalsList",
  "formalDecl", "statements", "statement", "@3", "ifExp", "call",
  "expList", "type", "typeAnnotation", "exp", "BoolMarkerM", "m_glob",
  "m_funcNewScope", "m_newScope", "m_newScopeWhile", "m_elseEndScope", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    40,    41,    39,    42,    42,
      43,    43,    44,    44,    45,    46,    46,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    48,    47,    47,    47,
      49,    50,    50,    51,    51,    52,    52,    52,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    55,    56,
      57,    58,    59,    60
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     0,    11,     1,     1,
       0,     1,     1,     3,     3,     1,     2,     4,     4,     6,
       4,     2,     2,     3,     6,    10,     0,     7,     2,     2,
       1,     4,     3,     1,     3,     1,     1,     1,     0,     1,
       3,     3,     3,     3,     3,     1,     1,     1,     2,     1,
       1,     1,     2,     4,     4,     3,     3,     4,     0,     0,
       0,     0,     0,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      59,     0,     3,     1,     9,    35,    36,    37,     2,     3,
       0,     8,     4,     5,    60,     0,    38,    39,     0,    11,
      12,     0,     0,    38,     0,     6,    13,    14,    38,     0,
      62,     0,     0,    61,     0,     0,    38,    15,     0,     0,
      50,    51,    22,    45,    47,    49,     0,     0,    46,     0,
       0,    28,    29,    38,     0,     0,    61,     7,    16,    21,
       0,    48,     0,     0,    52,    23,    58,    58,     0,     0,
       0,     0,     0,     0,     0,    38,    32,     0,    33,     0,
       0,     0,     0,    40,     0,     0,    56,    55,    44,    43,
      42,    41,    26,    17,    31,     0,    20,     0,    30,    18,
       0,    57,    54,    53,     0,    34,    38,     0,    38,    24,
      19,    27,    63,    61,    38,    25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     8,     9,    14,    28,    10,    18,    19,    20,
      36,    37,   104,    97,    48,    77,    11,    39,    78,    84,
       2,    15,    53,    50,   113
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -55
static const yytype_int16 yypact[] =
{
     -55,     5,   212,   -55,   -55,   -55,   -55,   -55,   -55,   212,
      11,   -55,   -55,   -55,   -55,    13,    -2,   -55,   -16,   -55,
      23,    70,    21,    37,    29,   -55,   -55,   -55,    88,    22,
     -55,    41,    45,   -55,   -11,    40,     1,   -55,    49,    70,
     -55,   -55,   -55,    54,    77,   -55,   106,    48,   -55,   107,
      60,   -55,   -55,    88,   157,    48,   -55,   -55,   -55,   -55,
      66,   -55,    68,   159,   143,   -55,   -55,   -55,    48,    48,
      48,    48,    48,    48,    48,    76,   -55,    69,   133,   116,
      48,   -12,    48,   -55,    48,    48,   177,   182,   -15,   -15,
     -55,   -55,   143,   -55,   -55,    48,   -55,    74,   143,   -55,
      48,   143,   166,   172,    75,   -55,    88,   125,    88,    72,
     -55,   -55,   -55,   -55,    88,   -55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -55,   -55,    94,   -55,   -55,   -55,   -55,   -55,    81,   -55,
      55,   -35,   -55,   -55,   -28,    17,   -17,    10,   -19,    47,
     -55,   -55,   -54,   -55,   -55
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -11
static const yytype_int8 yytable[] =
{
      38,    58,    80,    99,    24,     3,    17,    22,    38,    17,
      49,    54,    29,    30,    31,    32,    72,    73,    33,    57,
      34,   -10,    60,   100,    55,    38,    21,    63,    64,    62,
      13,    40,    41,    21,    35,    16,    79,    42,    25,    23,
      58,    43,    44,    45,    46,    17,    47,    38,    27,    86,
      87,    88,    89,    90,    91,    92,    51,    40,    41,   114,
      52,    98,    56,   101,    59,   102,   103,    43,    44,    45,
      46,   109,    47,   111,     5,     6,    54,     7,    38,   115,
      38,   107,    74,    61,    17,    81,    38,    29,    30,    31,
      32,    82,    94,    33,    93,    34,    17,   106,   108,    29,
      30,    31,    32,    12,    26,    33,   112,    34,    75,    35,
       5,     6,   105,     7,    85,    40,    41,     0,     0,     0,
       0,    35,    65,     0,     0,    43,    44,    45,    46,     0,
      47,    96,    66,    67,    68,    69,    70,    71,    72,    73,
     110,    66,    67,    68,    69,    70,    71,    72,    73,    95,
      66,    67,    68,    69,    70,    71,    72,    73,    66,    67,
      68,    69,    70,    71,    72,    73,    40,    41,    66,    67,
      68,    69,    70,    71,    72,    73,    43,    44,    45,    46,
      76,    47,    83,     0,    66,    67,    68,    69,    70,    71,
      72,    73,    67,    68,    69,    70,    71,    72,    73,    68,
      69,    70,    71,    72,    73,    69,    70,    71,    72,    73,
     -11,    70,    71,    72,    73,     4,     5,     6,     0,     7
};

static const yytype_int8 yycheck[] =
{
      28,    36,    56,    15,    21,     0,     8,    23,    36,     8,
      29,    22,    11,    12,    13,    14,    31,    32,    17,    18,
      19,    23,    39,    35,    35,    53,    16,    46,    47,    46,
      19,     9,    10,    23,    33,    22,    55,    15,    17,    16,
      75,    19,    20,    21,    22,     8,    24,    75,    19,    68,
      69,    70,    71,    72,    73,    74,    15,     9,    10,   113,
      15,    80,    22,    82,    15,    84,    85,    19,    20,    21,
      22,   106,    24,   108,     4,     5,    22,     7,   106,   114,
     108,   100,    22,     6,     8,    19,   114,    11,    12,    13,
      14,    23,    23,    17,    18,    19,     8,    23,    23,    11,
      12,    13,    14,     9,    23,    17,    34,    19,    53,    33,
       4,     5,    95,     7,    67,     9,    10,    -1,    -1,    -1,
      -1,    33,    15,    -1,    -1,    19,    20,    21,    22,    -1,
      24,    15,    25,    26,    27,    28,    29,    30,    31,    32,
      15,    25,    26,    27,    28,    29,    30,    31,    32,    16,
      25,    26,    27,    28,    29,    30,    31,    32,    25,    26,
      27,    28,    29,    30,    31,    32,     9,    10,    25,    26,
      27,    28,    29,    30,    31,    32,    19,    20,    21,    22,
      23,    24,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    26,    27,    28,    29,    30,    31,    32,    27,
      28,    29,    30,    31,    32,    28,    29,    30,    31,    32,
      28,    29,    30,    31,    32,     3,     4,     5,    -1,     7
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    56,     0,     3,     4,     5,     7,    38,    39,
      42,    52,    38,    19,    40,    57,    22,     8,    43,    44,
      45,    53,    23,    16,    52,    17,    44,    19,    41,    11,
      12,    13,    14,    17,    19,    33,    46,    47,    50,    53,
       9,    10,    15,    19,    20,    21,    22,    24,    50,    54,
      59,    15,    15,    58,    22,    35,    22,    18,    47,    15,
      52,     6,    52,    54,    54,    15,    25,    26,    27,    28,
      29,    30,    31,    32,    22,    46,    23,    51,    54,    54,
      58,    19,    23,    23,    55,    55,    54,    54,    54,    54,
      54,    54,    54,    18,    23,    16,    15,    49,    54,    15,
      35,    54,    54,    54,    48,    51,    23,    54,    23,    47,
      15,    47,    34,    60,    58,    47
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 51 "parser.ypp"
    {(yyval) = new program();;}
    break;

  case 3:
#line 53 "parser.ypp"
    {(yyval) = new funcs();;}
    break;

  case 4:
#line 54 "parser.ypp"
    {(yyval) = new funcs();;}
    break;

  case 5:
#line 56 "parser.ypp"
    {curFuncName = (yyvsp[(2) - (2)])->val;;}
    break;

  case 6:
#line 56 "parser.ypp"
    {addFunction(dynamic_cast<retType*>((yyvsp[(1) - (8)])), (yyvsp[(2) - (8)]), dynamic_cast<formals*>((yyvsp[(6) - (8)])));;}
    break;

  case 7:
#line 56 "parser.ypp"
    {(yyval) = new funcDecl(
                                                                                    dynamic_cast<retType*>((yyvsp[(1) - (11)])),
                                                                                    (yyvsp[(2) - (11)]),
                                                                                    dynamic_cast<formals*>((yyvsp[(6) - (11)])),
                                                                                    dynamic_cast<statements*>((yyvsp[(10) - (11)])));
                                                                                    ;}
    break;

  case 8:
#line 63 "parser.ypp"
    {(yyval) = new retType(dynamic_cast<type*>((yyvsp[(1) - (1)])));;}
    break;

  case 9:
#line 64 "parser.ypp"
    {(yyval) = new retType((yyvsp[(1) - (1)]));;}
    break;

  case 10:
#line 66 "parser.ypp"
    {(yyval) = new formals();;}
    break;

  case 11:
#line 67 "parser.ypp"
    {(yyval) = new formals(dynamic_cast<formalsList*>((yyvsp[(1) - (1)])));;}
    break;

  case 12:
#line 69 "parser.ypp"
    {(yyval) = new formalsList(dynamic_cast<formalsDecl*>((yyvsp[(1) - (1)])));;}
    break;

  case 13:
#line 70 "parser.ypp"
    {(yyval) = new formalsList(dynamic_cast<formalsDecl*>((yyvsp[(1) - (3)])), dynamic_cast<formalsList*>((yyvsp[(3) - (3)])));;}
    break;

  case 14:
#line 72 "parser.ypp"
    {(yyval) = new formalsDecl(dynamic_cast<typeAnnotation*>((yyvsp[(1) - (3)]))
                                                        ,dynamic_cast<type*>((yyvsp[(2) - (3)])),
                                                        (yyvsp[(3) - (3)]));;}
    break;

  case 15:
#line 76 "parser.ypp"
    {(yyval) = new statements(dynamic_cast<statement*>((yyvsp[(1) - (1)])));;}
    break;

  case 16:
#line 77 "parser.ypp"
    {(yyval) = new statements(dynamic_cast<statements*>((yyvsp[(1) - (2)])), dynamic_cast<statement*>((yyvsp[(2) - (2)])));;}
    break;

  case 17:
#line 79 "parser.ypp"
    {(yyval) = new statement(dynamic_cast<statements*>((yyvsp[(3) - (4)])));;}
    break;

  case 18:
#line 80 "parser.ypp"
    {(yyval) = new statement(dynamic_cast<typeAnnotation*>((yyvsp[(1) - (4)])),
                                                        dynamic_cast<type*>((yyvsp[(2) - (4)])),
                                                        (yyvsp[(3) - (4)]));;}
    break;

  case 19:
#line 83 "parser.ypp"
    {(yyval) = new statement(dynamic_cast<typeAnnotation*>((yyvsp[(1) - (6)])),
                                                                   dynamic_cast<type*>((yyvsp[(2) - (6)])),
                                                                   (yyvsp[(3) - (6)]),dynamic_cast<exp*>((yyvsp[(5) - (6)])));;}
    break;

  case 20:
#line 86 "parser.ypp"
    {(yyval) = new statement((yyvsp[(1) - (4)]), "ASSIGN", dynamic_cast<exp*>((yyvsp[(3) - (4)])));;}
    break;

  case 21:
#line 87 "parser.ypp"
    {(yyval) = new statement(dynamic_cast<call*>((yyvsp[(1) - (2)])));;}
    break;

  case 22:
#line 88 "parser.ypp"
    {(yyval) = new statement((yyvsp[(1) - (2)]));;}
    break;

  case 23:
#line 89 "parser.ypp"
    {(yyval) = new statement((yyvsp[(1) - (3)]), dynamic_cast<exp*>((yyvsp[(2) - (3)])));;}
    break;

  case 24:
#line 90 "parser.ypp"
    {(yyval) = new statement("IF",
                                                                    dynamic_cast<exp*>((yyvsp[(4) - (6)])),
                                                                    dynamic_cast<statement*>((yyvsp[(6) - (6)])),
                                                                    (yyvsp[(1) - (6)])->lineNum);;}
    break;

  case 25:
#line 94 "parser.ypp"
    {(yyval) = new statement("IF",
                                                                                                            dynamic_cast<exp*>((yyvsp[(4) - (10)])),
                                                                                                            dynamic_cast<statement*>((yyvsp[(6) - (10)])),
                                                                                                            "ELSE",
                                                                                                            dynamic_cast<statement*>((yyvsp[(10) - (10)])),
                                                                                                            (yyvsp[(1) - (10)])->lineNum);
                                                                                                            (yyvsp[(4) - (10)])->backPatchIf((yyvsp[(8) - (10)])->nextInstruction);
                                                                                                            buffer.bpatch((yyvsp[(8) - (10)])->nextList, buffer.genLabelNextLine());
                                                                                                            ;}
    break;

  case 26:
#line 103 "parser.ypp"
    {(yyvsp[(4) - (4)])->loadExp(); (yyvsp[(4) - (4)])->emitWhileExp((yyvsp[(4) - (4)])->NodeRegister);;}
    break;

  case 27:
#line 103 "parser.ypp"
    {(yyval) = new statement("WHILE",
                                                                                                             dynamic_cast<exp*>((yyvsp[(4) - (7)])),
                                                                                                             dynamic_cast<statement*>((yyvsp[(7) - (7)])),
                                                                                                             (yyvsp[(1) - (7)])->lineNum);
                                                                        (yyvsp[(7) - (7)])->endWhile((yyvsp[(2) - (7)])->nextInstruction,dynamic_cast<exp*>((yyvsp[(4) - (7)])));;}
    break;

  case 28:
#line 108 "parser.ypp"
    {(yyval) = new statement((yyvsp[(1) - (2)]));;}
    break;

  case 29:
#line 109 "parser.ypp"
    {(yyval) = new statement((yyvsp[(1) - (2)]));;}
    break;

  case 30:
#line 111 "parser.ypp"
    {(yyvsp[(1) - (1)])->loadExp();(yyvsp[(1) - (1)])->ifCode();(yyval) = new exp(dynamic_cast<exp*>((yyvsp[(1) - (1)])));(yyval)->nextInstruction = buffer.genLabel();;}
    break;

  case 31:
#line 113 "parser.ypp"
    {(yyval) = new call((yyvsp[(1) - (4)]), dynamic_cast<expList*>((yyvsp[(3) - (4)])));(yyvsp[(1) - (4)])->emitCallCode(dynamic_cast<expList*>(yyvsp[(3) - (4)]));(yyval)->NodeRegister = (yyvsp[(1) - (4)])->NodeRegister; ;}
    break;

  case 32:
#line 114 "parser.ypp"
    {(yyval) = new call((yyvsp[(1) - (3)]));(yyvsp[(1) - (3)])->emitCallCode(nullptr); (yyval)->NodeRegister = (yyvsp[(1) - (3)])->NodeRegister;;}
    break;

  case 33:
#line 116 "parser.ypp"
    {(yyvsp[(1) - (1)])->loadExp();(yyval) = new expList(dynamic_cast<exp*>((yyvsp[(1) - (1)])));;}
    break;

  case 34:
#line 117 "parser.ypp"
    {(yyvsp[(1) - (3)])->loadExp();(yyval) = new expList(dynamic_cast<exp*>((yyvsp[(1) - (3)])),dynamic_cast<expList*>((yyvsp[(3) - (3)])));;}
    break;

  case 35:
#line 119 "parser.ypp"
    {(yyval) = new type((yyvsp[(1) - (1)]));;}
    break;

  case 36:
#line 120 "parser.ypp"
    {(yyval) = new type((yyvsp[(1) - (1)]));;}
    break;

  case 37:
#line 121 "parser.ypp"
    {(yyval) = new type((yyvsp[(1) - (1)]));;}
    break;

  case 38:
#line 123 "parser.ypp"
    {(yyval) = new typeAnnotation();;}
    break;

  case 39:
#line 124 "parser.ypp"
    {(yyval) = new typeAnnotation((yyvsp[(1) - (1)]));;}
    break;

  case 40:
#line 127 "parser.ypp"
    {(yyvsp[(2) - (3)])->loadExp();(yyval) = new exp(dynamic_cast<exp*>((yyvsp[(2) - (3)])));;}
    break;

  case 41:
#line 128 "parser.ypp"
    {buffer.emit(registerManager.createArithmeticOp(dynamic_cast<exp*>((yyvsp[(1) - (3)])), dynamic_cast<exp*>((yyvsp[(3) - (3)])), "mul"));(yyval) = new exp(dynamic_cast<exp*>((yyvsp[(1) - (3)])), "MULT", dynamic_cast<exp*>((yyvsp[(3) - (3)])),(yyvsp[(2) - (3)])->lineNum);(yyval)->NodeRegister = registerManager.getCurrentRegisterName();;}
    break;

  case 42:
#line 129 "parser.ypp"
    {buffer.emit(registerManager.createArithmeticOp(dynamic_cast<exp*>((yyvsp[(1) - (3)])), dynamic_cast<exp*>((yyvsp[(3) - (3)])), "sdiv"));(yyval) = new exp(dynamic_cast<exp*>((yyvsp[(1) - (3)])), "DIV", dynamic_cast<exp*>((yyvsp[(3) - (3)])),(yyvsp[(2) - (3)])->lineNum);(yyval)->NodeRegister = registerManager.getCurrentRegisterName();;}
    break;

  case 43:
#line 130 "parser.ypp"
    {buffer.emit(registerManager.createArithmeticOp(dynamic_cast<exp*>((yyvsp[(1) - (3)])), dynamic_cast<exp*>((yyvsp[(3) - (3)])), "add"));(yyval) = new exp(dynamic_cast<exp*>((yyvsp[(1) - (3)])), "PLUS", dynamic_cast<exp*>((yyvsp[(3) - (3)])),(yyvsp[(2) - (3)])->lineNum);(yyval)->NodeRegister = registerManager.getCurrentRegisterName();;}
    break;

  case 44:
#line 131 "parser.ypp"
    {buffer.emit(registerManager.createArithmeticOp(dynamic_cast<exp*>((yyvsp[(1) - (3)])), dynamic_cast<exp*>((yyvsp[(3) - (3)])), "sub"));(yyval) = new exp(dynamic_cast<exp*>((yyvsp[(1) - (3)])), "MINUS", dynamic_cast<exp*>((yyvsp[(3) - (3)])),(yyvsp[(2) - (3)])->lineNum);(yyval)->NodeRegister = registerManager.getCurrentRegisterName();;}
    break;

  case 45:
#line 132 "parser.ypp"
    {(yyval) = new exp((yyvsp[(1) - (1)]),"ID");(yyval)->NodeRegister = registerManager.getVarRegister((yyval)->NodeId, (yyval)->NodeRegister);;}
    break;

  case 46:
#line 133 "parser.ypp"
    {(yyval) = new exp(dynamic_cast<call*>((yyvsp[(1) - (1)])));;}
    break;

  case 47:
#line 134 "parser.ypp"
    {(yyval) = new exp((yyvsp[(1) - (1)]), 0, false);;}
    break;

  case 48:
#line 135 "parser.ypp"
    {(yyval) = new exp((yyvsp[(1) - (2)]), 0, true);;}
    break;

  case 49:
#line 136 "parser.ypp"
    {(yyval) = new exp((yyvsp[(1) - (1)]),"STRING");;}
    break;

  case 50:
#line 137 "parser.ypp"
    {(yyval) = new exp(true);;}
    break;

  case 51:
#line 138 "parser.ypp"
    {(yyval) = new exp(false);;}
    break;

  case 52:
#line 139 "parser.ypp"
    {(yyval) = new exp("NOT", dynamic_cast<exp*>((yyvsp[(2) - (2)])),(yyvsp[(1) - (2)])->lineNum);;}
    break;

  case 53:
#line 140 "parser.ypp"
    {(yyval) = new exp(dynamic_cast<exp*>((yyvsp[(1) - (4)])), "AND", dynamic_cast<exp*>((yyvsp[(4) - (4)])),(yyvsp[(2) - (4)])->lineNum,dynamic_cast<Marker*>((yyvsp[(3) - (4)])));;}
    break;

  case 54:
#line 141 "parser.ypp"
    {(yyval) = new exp(dynamic_cast<exp*>((yyvsp[(1) - (4)])), "OR", dynamic_cast<exp*>((yyvsp[(4) - (4)])),(yyvsp[(2) - (4)])->lineNum,dynamic_cast<Marker*>((yyvsp[(3) - (4)])));;}
    break;

  case 55:
#line 142 "parser.ypp"
    {(yyval) = new exp(dynamic_cast<exp*>((yyvsp[(1) - (3)])), (yyvsp[(2) - (3)])->val, dynamic_cast<exp*>((yyvsp[(3) - (3)])),(yyvsp[(2) - (3)])->lineNum);;}
    break;

  case 56:
#line 143 "parser.ypp"
    {(yyval) = new exp(dynamic_cast<exp*>((yyvsp[(1) - (3)])), (yyvsp[(2) - (3)])->val, dynamic_cast<exp*>((yyvsp[(3) - (3)])),(yyvsp[(2) - (3)])->lineNum);;}
    break;

  case 57:
#line 144 "parser.ypp"
    {(yyval) = new exp(dynamic_cast<type*>((yyvsp[(2) - (4)])), dynamic_cast<exp*>((yyvsp[(4) - (4)])),(yyvsp[(1) - (4)])->lineNum);;}
    break;

  case 58:
#line 146 "parser.ypp"
    {(yyval) = new Marker();;}
    break;

  case 59:
#line 148 "parser.ypp"
    {m_glob();;}
    break;

  case 60:
#line 150 "parser.ypp"
    {curFuncName = yytext;m_newScope();;}
    break;

  case 61:
#line 152 "parser.ypp"
    {m_newScope();;}
    break;

  case 62:
#line 154 "parser.ypp"
    {m_newScopeWhile();(yyval) = new Node(); (yyval)->nextInstruction = buffer.genLabelNextLine();;}
    break;

  case 63:
#line 156 "parser.ypp"
    {m_endScope();(yyval) = new Node(); (yyval)->elseCode();;}
    break;


/* Line 1267 of yacc.c.  */
#line 1845 "parser.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 157 "parser.ypp"


void yyerror (const char* err) {
    output::errorSyn(yylineno);
    exit(0);
}
int main() {
    buffer.startProgram();
    yyparse();
    buffer.printGlobalBuffer();
    buffer.printCodeBuffer();
    return 0;
}

