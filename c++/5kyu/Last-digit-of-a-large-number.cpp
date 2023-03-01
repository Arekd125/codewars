// Define a function that takes in two non-negative integers a end b
// and returns the last decimal digit of a^b
// Note that
// a and b may be very large!

// You may assume that the input will always be valid.

// Examples
// last_digit("4", "1")            // returns 4
// last_digit("4", "2")            // returns 6
// last_digit("9", "7")            // returns 9
// last_digit("10","10000000000")  // returns 0
#include <iostream>
#include <string>
#include <math.h>

int last_digit(const std::string &str1, const std::string &str2)
{
  unsigned int a, b, c; // a^(..cb)
  ///////////////////////////// <-a base
  if (str1.size() == 1)
    a = stoi(str1);
  else
    a = (static_cast<int>(str1[str1.size() - 1]) - 48);
  ///////////////////////////// <-b exponent
  if (str2.size() == 1)
  {
    int b = stoi(str2);
    if (b == 0)
      return 1;
    a = pow(a, b);
    return a % 10;
  }
  b = (static_cast<int>(str2[str2.size() - 1]) - 48);
  ////////////////////////////// <-c  exponent
  c = (static_cast<int>(str2[str2.size() - 2]) - 48);
  if (c == 0)
    c = 10;

  unsigned int rezult = pow(a, c);
  rezult = pow(rezult % 10, 10);
  a = pow(a, b);
  rezult = rezult % 10 * a % 10;
  return rezult % 10;
}

int main()
{
   std::cout<< last_digit("4", "1")<<" 4"<<std::endl;
   std::cout<< last_digit("4", "2")<<" 6"<<std::endl;
   std::cout<< last_digit("9", "7")<<" 9"<<std::endl;
   std::cout<< last_digit("11", "10000000000")<<" 0"<<std::endl;
   std::cout<< last_digit("1606938044258990275541962092341162602522202993782792835301376", "2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376")<<" 6"<<std::endl;
   std::cout<< last_digit("3715290469715693021198967285016729344580685479654510946723", "68819615221552997273737174557165657483427362207517952651")<<" 7"<<std::endl;
}