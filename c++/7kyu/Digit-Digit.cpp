// Welcome. In this kata, you are asked to square every digit of a number and concatenate them.

// For example, if we run 9119 through the function, 811181 will come out, because 92 is 81 and 12 is 1. (81-1-1-81)

// Example #2: An input of 765 will/should return 493625 because 72 is 49, 62 is 36, and 52 is 25. (49-36-35)

// Note: The function accepts an integer and returns an integer.

// Happy Coding!

#include <math.h>
int square_digits(int num)
{
    std::vector<int> numb;
    int result = 0;
    if (num == 0)
        return 0;
    while (num != 0)
    {
        numb.push_back(num % 10);
        num = num / 10;
    }

    size_t n = numb.size();
    result += (pow(numb[n - 1], 2));
    for (size_t i = n - 1; i > 0; i--)
    {
        if (numb[i - 1] > 3)
            result *= 100;
        else
            result *= 10;
        result += (pow(numb[i - 1], 2));
    }
    return result;
}