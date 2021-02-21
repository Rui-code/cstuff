#include "advanced_pointers.h"

enum {
  SUM_TWO = 0,
  SUB_TWO,
  MUL_TWO,
  DIV_TWO
};

int main(int argc, char *argv[])
{
  // array[4] of function pointers
  int (*operation[4])(int, int) = {
    sum_two,
    sub_two,
    mul_two,
    div_two
  };

  // pointer to array[4] of function pointer
  int (*(*pfa)[4])(int, int) = &operation;
  
  int result_sum_p = (*(*pfa + SUM_TWO))(3, 2);
  int result_sub_p = (*(*pfa + SUB_TWO))(3, 2);
  int result_mul_p = (*(*pfa + MUL_TWO))(3, 2);
  int result_div_p = (*(*pfa + DIV_TWO))(3, 0);
  
  int result_sum   = (*operation[SUM_TWO])(3, 2);
  int result_sub   = (*operation[SUB_TWO])(3, 2);
  int result_mul   = (*operation[MUL_TWO])(3, 2);
  int result_div   = (*operation[DIV_TWO])(3, 0);

  // DEBUG
  // printf("%d\n", SUM_TWO);
  // printf("%d\n", SUB_TWO);
  // printf("%d\n", MUL_TWO);
  // printf("%d\n", DIV_TWO);
  
  printf("Array version:\n\n");
  printf("result sum: %d\nresult sub: %d\nresult mul: %d\nresult div: %d\n\n",
	 result_sum, result_sub, result_mul, result_div);

  printf("Pointer version:\n\n");
  printf("result sum: %d\nresult sub: %d\nresult mul: %d\nresult div: %d\n",
	 result_sum_p, result_sub_p, result_mul_p, result_div_p);

  return 0;
}

int sum_two(int a, int b)
{
  return a + b;
}

int sub_two(int a, int b)
{
  return a - b;
}

int mul_two(int a, int b)
{
  return a * b;
}

int div_two(int a, int b)
{
  return b == 0 ? 0 : (int) a / b;
}
