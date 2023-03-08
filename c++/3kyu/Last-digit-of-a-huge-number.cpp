// For a given list [x1, x2, x3, ..., xn] compute the last (decimal) digit of x1 ^ (x2 ^ (x3 ^ (... ^ xn))).

// E. g., with the input [3, 4, 2], your code should return 1 because 3 ^ (4 ^ 2) = 3 ^ 16 = 43046721.

// Beware: powers grow incredibly fast. For example, 9 ^ (9 ^ 9) has more than 369 millions of digits.
// lastDigit has to deal with such numbers efficiently.

// Corner cases: we assume that 0 ^ 0 = 1 and that lastDigit of an empty list equals to 1.

// This kata generalizes Last digit of a large number; you may find useful to solve it beforehand.

#include <list>
#include <iostream>
#include <math.h>

using namespace std;
unsigned long long power(int a, int expo)
{
  int n = 0;
  unsigned long long rezult = 1;
  while (expo > 0) ///  a^b
  {
    unsigned long long  b = expo % 10;
    b= pow(a, b % 10);
    for (size_t i = 0; i < n; i++)
    {
      //  cout << i << " ";
      b = pow(b % 10, 10);
    }
    rezult *=b%100;
    n++;
    expo = expo / 10;
    // cout << expo << " ";
  }

  return rezult;
}

int last_digit(list<int> array)
{

  if (array.empty())
    return 1;
  if (array.size() == 1)
    return (array.front() % 10);
  unsigned long long base, rezult;

  rezult = (array.back());
  array.pop_back();

  while (!array.empty())
  {
    base = array.back() ;
    array.pop_back();

    if (base == 0)
      if (rezult == 0)
        rezult = 1;
      else
        rezult = 0;
   
    else if( base%10==0 || base%10==1)
    {
      rezult=100;
    }
    else
    rezult = power(base%1000, rezult);
    

  }
  return rezult % 10;
}

int main()
{
  cout <<"_1_ "<< last_digit({2,2,101,2}) << " 1" << endl;
  // cout <<"_2_ "<< last_digit({}) << " 1" << endl;                       //  Equals(1));
  // cout <<"_3_ "<< last_digit({0, 0}) << " 1" << endl;                   //  Equals(1));
  // cout <<"_4_ "<< last_digit({0, 0, 0}) << " 0" << endl;                //  Equals(0));
  // cout <<"_5_ "<< last_digit({1, 2}) << " 1" << endl;                   //  Equals(1));
  // cout <<"_6_ "<< last_digit({3, 4, 5}) << " 1" << endl;                //  Equals(1));
  // cout <<"_7_ "<< last_digit({4, 3, 6}) << " 4" << endl;                //  Equals(4));
  // cout <<"_8_ "<< last_digit({7, 6, 21}) << " 1" << endl;               //  Equals(1));
  // cout <<"_9_ "<< last_digit({12, 30, 21}) << " 6" << endl;             // Equals(6));
  // cout <<"_1_ "<< last_digit({2, 2, 2, 0}) << " 4" << endl;             // Equals(4));
  // cout <<"_2_ "<< last_digit({937640, 767456, 981242}) << " 0" << endl; //  Equals(0));
  // cout <<"_3_ "<< last_digit({123232, 694022, 140249}) << " 6" << endl; //  Equals(6));
  // cout <<"_4_ "<< last_digit({499942, 898102, 846073}) << " 6" << endl; //  Equals(6));
}