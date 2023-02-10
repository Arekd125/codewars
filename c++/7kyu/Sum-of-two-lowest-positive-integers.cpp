// Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 positive integers. No floats or non-positive integers will be passed.

// For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

// [10, 343445353, 3453445, 3453545353453] should return 3453455.

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
  long x = numbers.at(0);
  long y = numbers.at(1);
  int sizenumb = numbers.size();
  for (int i = 2; i < sizenumb; i++)
    if ( (x > numbers[i] || y > numbers[i] ) && y<x)
    { 
      x = numbers[i];
    }
    else if (y > numbers[i] )
    {
      y = numbers[i];
    }
  return x + y;