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
int last_digit(list<int> array)
{

  if (array.empty())
    return 1;
  if (array.size() == 1)
    return (array.front() % 10);
  if (array.size() == 2)
    return ((int)pow(array.front() % 10, array.back())) % 10;

  unsigned int exponent = (array.back());
  array.pop_back();

  while (!array.empty())
  {
    unsigned int base = (array.back()) % 100;
    array.pop_back();

    if (exponent > 9)
      exponent = (exponent % 4) + 4;

    exponent = pow(base, exponent);
  }

  return exponent % 10;
}

int main()
{
  cout << last_digit({}) << " 1" << endl;                       //  Equals(1));
  cout << last_digit({0, 0}) << " 1" << endl;                   //  Equals(1));
  cout << last_digit({0, 0, 0}) << " 0" << endl;                //  Equals(0));
  cout << last_digit({1, 2}) << " 1" << endl;                   //  Equals(1));
  cout << last_digit({3, 4, 5}) << " 1" << endl;                //  Equals(1));
  cout << last_digit({4, 3, 6}) << " 4" << endl;                //  Equals(4));
  cout << last_digit({7, 6, 21}) << " 1" << endl;               //  Equals(1));
  cout << last_digit({12, 30, 21}) << " 6" << endl;             // Equals(6));
  cout << last_digit({2, 2, 2, 0}) << " 4" << endl;             // Equals(4));
  cout << last_digit({937640, 767456, 981242}) << " 0" << endl; //  Equals(0));
  cout << last_digit({123232, 694022, 140249}) << " 6" << endl; //  Equals(6));
  cout << last_digit({499942, 898102, 846073}) << " 6" << endl; //  Equals(6));
}