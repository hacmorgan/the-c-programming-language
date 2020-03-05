#include <stdio.h>

int main()
{
  char c;
  short s;
  int i;
  long l;
  float f;
  double d;

  printf("The size of a char is: %ld bytes\n", sizeof(c));
  printf("The size of a short is: %ld bytes\n", sizeof(s));
  printf("The size of a int is: %ld bytes\n", sizeof(i));
  printf("The size of a long is: %ld bytes\n", sizeof(l));
  printf("The size of a float is: %ld bytes\n", sizeof(f));
  printf("The size of a double is: %ld bytes\n", sizeof(d));
  
}
