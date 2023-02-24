#include <list>
#include <iostream>
#include <math.h>

using namespace std;
int last_digit(list<int> array) {

  if(array.empty())
    return 1;
   array.reverse();
    int result=*(array.begin());
    
    for( list<int>::iterator it=array.begin();  it!=array.end();  )
     {result= pow (*(++it),result%10 );
      cout<<"result: "<<result<<endl;;}
  return result;
    }


int main()
{
    list<int> array {3,4,5};


    cout<< last_digit(array);
}