#ifndef _EXPR_H_
#define _EXPR_H_

#include <string.h>

#include "config.h"
#include "global.h"

#include "memory.h"

/*
Expr_t usage:

Construction:
  Use `expr_make_atom` or `expr_make_empty_list`. Adding children to a list is
  done with `expr_add_to_list`.

Destruction:
  Destroying an expr is done with `expr_free`.
*/

enum ExprType {ExprAtom, ExprList};

// https://benpaulhanna.com/writing-a-game-in-c-parsing-s-expressions.html
struct Expr {
  struct Expr* _next;
//   struct Expr* _prev;
  enum ExprType _type;
  union {
    struct Expr* _list;
    char* _symbol;
  };
};
typedef struct Expr* Expr_t;

Expr_t  _expr_make_empty        (ErrorCode_t*);
void    _expr_set_as_atom       (Expr_t, char*);
void    _expr_set_as_list       (Expr_t);

void    expr_add_to_list        (ErrorCode_t*, Expr_t list, Expr_t child);
Expr_t  expr_make_atom          (ErrorCode_t*, char*);
Expr_t  expr_make_empty_list    (ErrorCode_t*);

Expr_t  expr_get_next           (Expr_t);
// Expr_t  expr_get_prev           (Expr_t);
BOOL    expr_is_list            (Expr_t);
Expr_t  expr_get_list           (Expr_t);
char*   expr_get_symbol         (Expr_t);

BOOL    expr_is_equal           (Expr_t, Expr_t);

char*   expr_to_string          (Expr_t);

void    expr_free               (Expr_t*);

#endif