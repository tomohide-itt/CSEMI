#include <iostream>

int main(){
  double a, b;

  std::cout << "input a>";
  std::cin >> a;
  std::cout << "input b>";
  std::cin >> b;

  std::cout << "a+b=" << a+b << std::endl;
  std::cout << "a-b=" << a-b << std::endl;
  std::cout << "a*b=" << a*b << std::endl;
  std::cout << "a/b=" << a/b << std::endl;

  return 0;
}
