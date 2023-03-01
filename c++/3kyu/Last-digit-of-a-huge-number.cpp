// For a given list [x1, x2, x3, ..., xn] compute the last (decimal) digit of x1 ^ (x2 ^ (x3 ^ (... ^ xn))).

// E. g., with the input [3, 4, 2], your code should return 1 because 3 ^ (4 ^ 2) = 3 ^ 16 = 43046721.

// Beware: powers grow incredibly fast. For example, 9 ^ (9 ^ 9) has more than 369 millions of digits.
// lastDigit has to deal with such numbers efficiently.

// Corner cases: we assume that 0 ^ 0 = 1 and that lastDigit of an empty list equals to 1.

// This kata generalizes Last digit of a large number; you may find useful to solve it beforehand.

#include <list>
#include <iostream>
#include <math.h>
// unsigned int power1(int n, int p) {
//  unsigned int ans = 1;
//   for (int i = 0; i < p; i++) {
//     ans *= n;
//     ans%=1000;
//   }
//   return ans;
// }

using namespace std;
int last_digit(list<int> array)
{

  if (array.empty())
    return 1;
  if (array.size() == 1)
    return (array.front() % 10);
  // if (array.size() == 2)
  //   return ((int)pow(array.front() % 10, array.back())) % 10;
  unsigned int a = 0, b = 0, c = 0, rezult; // a^(..cb)

  rezult = (array.back());
  array.pop_back();
  //  cout<<endl;
  //  cout<<rezult<<" ";
  while (!array.empty())
  {
    //  rezult = rezult ;
    // if (a%10==0 && rezult==0 && a>0)
    //   rezult =4;
    a = array.back();
    array.pop_back();
    // cout<<a<<" ";
    if (rezult == 0)
      rezult = 1;
    else if (a == 0 && rezult != 0)
      rezult = 0;
    else if (rezult < 10)
      rezult = pow(a % 10, rezult);
    else
    {
      a = a % 10;
      b = rezult % 10;
      // cout<<"b "<<b<<" ";
      c = (rezult / 10) % 10;
      if (c == 0)
        c = 10;

      rezult = pow(a, c);
      rezult = pow(rezult % 10, 10);
      b = pow(a, b);
    //  b = b % 10;
      rezult = (rezult % 10 * b % 100);
      if (a == 0)
        rezult = 100;
    }
    // cout<<endl;
   // cout << "a: " << a << " b: " << b << " c: " << c << " rezul: " << rezult << endl;
  }
  return rezult % 10;
}

int main()
{
  cout << last_digit({82242, 254719, 736371}) << " 8" << endl;
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