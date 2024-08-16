#include "expr.hpp"

parser::Expr::Expr(char * && x, std::true_type)
{
  this->n = new char[strlen(x) + 4];
  strcpy(this->n, x);
}

parser::Expr::Expr(char * & x, std::false_type)
{
  this->n = new char[strlen(x) + 4];
  strcpy(this->n, x);
}

char parser::Expr::getop(int idx)
{
  return n[idx];
}

parser::Expr::~Expr()
{
  delete[] n;
}

int parser::Expr::getn(short idx)
{
  return n[idx] - '0';
}

char parser::Expr::gets(int idx)
{
  return n[idx];
}

int parser::cl(int n1, char op, int n2)
{
  if(op=='+')
    return n1+n2;
  else if (op=='-')
    return n1-n2;
  else if(op=='/')
    return n1/n2;
  else if(op=='*')
    return n1*n2;
  return 0;
}

int parser::eval(Expr * lhs)
{
  int res = lhs->getn(0);
  int idx = 1;

  while (lhs->gets(idx) != '\0')
  {
    char op = lhs->getop(idx);
    idx++;
    int num = lhs->getn(idx);
    idx++;
    res=cl(res, op, num);
  }

  return res;
}
