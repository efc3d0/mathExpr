#include "expr.cpp"
int
main(void)
{
  auto f = parser::Expr("1+2+3+4*2", std::true_type());
  return 0;
}
