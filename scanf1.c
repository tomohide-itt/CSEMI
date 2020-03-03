#include <stdio.h>

int main(){
  double a, b;

  printf( "input a>" );
  scanf( "%lf", &a );
  printf( "input b>" );
  scanf( "%lf", &b );

  printf( "a+b=%f\n", a+b );
  printf( "a-b=%f\n", a-b );
  printf( "a*b=%f\n", a*b );
  printf( "a/b=%f\n", a/b );

  return 0;
}
