#pragma once
#include <iostream>
#include <math.h>

class Helper{
public:
  static int congruencial(int root,int a,int m,int c){
    return ((root*a + c)%m);
  }
  static void clearScreen(){
    std::cout << std::string(100, '\n');
  }
};
