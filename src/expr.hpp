#ifndef __MY_EXPR_STRUCT__
#define __MY_EXPR_STRUCT__

#include <type_traits>
#include <utility>
#include <cstring>
using std::forward;

namespace parser
{
  int cl(int n1, char op, int n2);
  class Expr
  {
    private:
      char * n;
    public:
    Expr(char * && x, std::true_type);
    Expr(char * & x, std::false_type);
    ~Expr();
    int getn(short idx);
    char gets(int idx);
    void printn();
    char getop(int idx);
  };
  int eval(Expr * lhs);
}   

#endif
