// Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

// move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0}

#include <vector>

std::vector<int> move_zeroes(const std::vector<int> &input)
{
    int numb_zeros = 0;
    std::vector<int> result;
    for (unsigned i = 0; i < input.size(); i++)
        if (input[i] != 0)
        {
            result.push_back(input[i]);
        }
        else
            numb_zeros++;
    for (int i = 0; i < numb_zeros; i++)
        result.push_back(0);
    return result;
}