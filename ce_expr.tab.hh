/* A Bison parser, made by GNU Bison 3.3.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_CE_EXPR_CE_EXPR_TAB_HH_INCLUDED
# define YY_CE_EXPR_CE_EXPR_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef CE_EXPRDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define CE_EXPRDEBUG 1
#  else
#   define CE_EXPRDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define CE_EXPRDEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined CE_EXPRDEBUG */
#if CE_EXPRDEBUG
extern int ce_exprdebug;
#endif
/* "%code requires" blocks.  */
#line 40 "ce_expr.yy" /* yacc.c:1927  */


#include "config.h"

#include <cassert>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <stack>
#include <memory>

// #define DODS_DEBUG

#include "debug.h"
#include "escaping.h"

#include "DDS.h"
#include "ConstraintEvaluator.h"

#include "BaseType.h"

#include "Byte.h"
#include "Int16.h"
#include "UInt16.h"
#include "Int32.h"
#include "UInt32.h"
#include "Float32.h"
#include "Float64.h"
#include "Str.h"
#include "Url.h"
#include "Array.h"
#include "Structure.h"
#include "Sequence.h"
#include "Grid.h"

#include "Error.h"

#include "util.h"
#include "parser.h"
#include "ce_parser.h"
#include "expr.h"
#include "RValue.h"
using std::cerr;
using std::endl;
using namespace libdap ;

#define EVALUATOR(arg) (static_cast<ce_parser_arg*>(arg)->get_eval())
#define DDS(arg) (static_cast<ce_parser_arg*>(arg)->get_dds())

#define YYERROR_VERBOSE 0

int ce_exprlex(void);           /* the scanner; see expr.lex */

// NB: never pass a variable name or other string from the CE to these functions.
// Only string literals are allowed. This is to prevent information in the CE that
// could be an attack from being transferred to the error response and then
// rendered/run by a browser (an XSS attack). jhrg 4/14/20
void ce_exprerror(const string &s);
// Some automatic invocations of yyerror pass ce_parser_arg. It is ignored in this
// function, however. jhrg 4/14/20
void ce_exprerror(ce_parser_arg *arg, const string &s);
void no_such_ident(const string &thing);

void no_such_func();

// dim_slice and slices are defined in expr.h
dim_slice *make_array_slice(value &v1, value &v2, value &v3);
dim_slice *make_array_slice(value &v1, value &v2);
dim_slice *make_array_slice(value &v1);

slices *make_array_slices(dim_slice *ds);
slices *append_array_slices(slices *s, dim_slice *ds);

void delete_array_slices(slices *s);
bool bracket_projection(DDS &table, const char *name, slices *s);

void process_sequence_slice(BaseType *variable, slices *s);

void process_array_slices(BaseType *variable, slices *s);
void process_grid_slices(BaseType *variable, slices *s);
void process_sequence_slices(BaseType *variable, slices *s);

/* Replace these with method calls. jhrg 8/31/06 */
bool is_array_t(BaseType *variable);
bool is_grid_t(BaseType *variable);
bool is_sequence_t(BaseType *variable);

BaseType *make_variable(ConstraintEvaluator &eval, const value &val);
bool_func get_function(const ConstraintEvaluator &eval, const char *name);
btp_func get_btp_function(const ConstraintEvaluator &eval, const char *name);
proj_func get_proj_function(const ConstraintEvaluator &eval, const char *name);

template<class arg_list, class arg_type>
arg_list make_fast_arg_list(unsigned long vector_size_hint, arg_type arg_value);

template<class arg_list, class arg_type>
arg_list make_fast_arg_list(arg_list int_values, arg_type arg_value);

template<class t, class T>
rvalue *build_constant_array(vector<t> *values, DDS *dds);


#line 163 "ce_expr.tab.hh" /* yacc.c:1927  */

/* Token type.  */
#ifndef CE_EXPRTOKENTYPE
# define CE_EXPRTOKENTYPE
  enum ce_exprtokentype
  {
    SCAN_STR = 258,
    SCAN_WORD = 259,
    SCAN_EQUAL = 260,
    SCAN_NOT_EQUAL = 261,
    SCAN_GREATER = 262,
    SCAN_GREATER_EQL = 263,
    SCAN_LESS = 264,
    SCAN_LESS_EQL = 265,
    SCAN_REGEXP = 266,
    SCAN_STAR = 267,
    SCAN_HASH_BYTE = 268,
    SCAN_HASH_INT16 = 269,
    SCAN_HASH_UINT16 = 270,
    SCAN_HASH_INT32 = 271,
    SCAN_HASH_UINT32 = 272,
    SCAN_HASH_FLOAT32 = 273,
    SCAN_HASH_FLOAT64 = 274
  };
#endif

/* Value type.  */
#if ! defined CE_EXPRSTYPE && ! defined CE_EXPRSTYPE_IS_DECLARED

union CE_EXPRSTYPE
{
#line 156 "ce_expr.yy" /* yacc.c:1927  */

    bool boolean;
    int op;
    std::string *str;       // Strings - quoted or things that must be strings given the grammar

    char id[ID_MAX];        // Return identifiers

    libdap::dods_byte byte_value;
    libdap::dods_int16 int16_value;
    libdap::dods_uint16 uint16_value;
    libdap::dods_int32 int32_value;
    libdap::dods_uint32 uint32_value;
    libdap::dods_float32 float32_value;
    libdap::dods_float64 float64_value;

    libdap::byte_arg_list byte_values;
    libdap::int16_arg_list int16_values;
    libdap::uint16_arg_list uint16_values;
    libdap::int32_arg_list int32_values;
    libdap::uint32_arg_list uint32_values;
    libdap::float32_arg_list float32_values;
    libdap::float64_arg_list float64_values;
#if 0
    libdap::value val;               // value is defined in expr.h
#endif
    libdap::bool_func b_func;
    libdap::btp_func bt_func;

    libdap::dim_slice *dim_slice_ptr;
    libdap::slices *slices_ptr;

    libdap::rvalue *rval_ptr;
    libdap::rvalue_list *r_val_l_ptr;

#line 230 "ce_expr.tab.hh" /* yacc.c:1927  */
};

typedef union CE_EXPRSTYPE CE_EXPRSTYPE;
# define CE_EXPRSTYPE_IS_TRIVIAL 1
# define CE_EXPRSTYPE_IS_DECLARED 1
#endif


extern CE_EXPRSTYPE ce_exprlval;

int ce_exprparse (ce_parser_arg *arg);

#endif /* !YY_CE_EXPR_CE_EXPR_TAB_HH_INCLUDED  */
