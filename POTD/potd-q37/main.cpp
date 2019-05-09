#include <iostream>
#include "functions.h"
#include <string>
#include <tgmath.h>

int main() {
  std::cout << samesies(-99999, -99999) << std::endl;
  std::string a="44444";
  std::cout << validUsername(a) << std::endl;
  std::cout <<arrayIndex(-4)<< std::endl;
  std::cout <<countPrimes(6)<< std::endl;
  //std::cout <<factorial(-1)<< std::endl;
  std::cout <<absolutely(std::pow(2,33))<< std::endl;
  std::cout <<magnaCalca(1,5)<< std::endl;
  return 0;
}
