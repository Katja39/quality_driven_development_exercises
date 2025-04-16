#include <cassert>
#include <iostream>

void asserts() 
{
   std::cout << "x=5" << std::endl;
   int x = 5;
   assert(x == 5);  // ok
   std::cout << "is x=10?" << std::endl;
   assert(x == 10); //Assertion failed
}