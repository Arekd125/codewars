// Given an n x n array, return the array elements arranged from outermost elements to the middle element,
//  traveling clockwise.

// array = [[1,2,3],
//          [4,5,6],
//          [7,8,9]]
// snail(array) #=> [1,2,3,6,9,8,7,4,5]
// For better understanding, please follow the numbers of the next array consecutively:

// array = [[1,2,3],
//          [8,9,4],
//          [7,6,5]]
// snail(array) #=> [1,2,3,4,5,6,7,8,9]
// This image will illustrate things more clearly:

#include <vector>
#include <iostream>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map);
void show_vector(std::vector<int> &result);
int main()
{
    std::vector<int> result;
    std::vector<std::vector<int>> a ;
    std::vector<std::vector<int>> b = {{1}};
    std::vector<std::vector<int>> c = {{1, 2}, {4, 3}};
    std::vector<std::vector<int>> d = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    std::vector<std::vector<int>> e =
        {{1, 2, 3, 4},
         {12, 13, 14, 5},
         {11, 16, 15, 6},
         {10, 9, 8, 7}};
    std::vector<std::vector<int>> f =
        {{1, 2, 3, 4, 5},
         {16, 17, 18, 19, 6},
         {15, 24, 25, 20, 7},
         {14, 23, 22, 21, 8},
         {13, 12, 11, 10, 9}};

    result = snail(a);
    show_vector(result);
    result = snail(b);
    show_vector(result);
    result = snail(c);
    show_vector(result);
    result = snail(d);
    show_vector(result);
    result = snail(e);
    show_vector(result);
    result = snail(f);
    show_vector(result);
}

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map)
{
    std::vector<int> result{};
    size_t n{snail_map.size()}; // <-> size_t n{snail_map[0].size()};
    int row = 0;
    int col = 0;

    if (snail_map.empty())
    {
        return result;
    }

    for (size_t i = 0; i < n; i++)
    {
        result.push_back(snail_map[row][col++]);
    }
    col--;

    while (n!=0)
    {
         n--;
        if (n == 0)
            return result;
        for (size_t i = 0; i < n; i++)
        {
            result.push_back(snail_map[++row][col]);
        }

        for (size_t i = 0; i < n; i++)
        {
            result.push_back(snail_map[row][--col]);
        }

        n--;
        if (n == 0)
            return result;
        for (size_t i = 0; i < n; i++)
        {
            result.push_back(snail_map[--row][col]);
        }
        for (size_t i = 0; i < n; i++)
        {
            result.push_back(snail_map[row][++col]);
        }
    }
  return result;
}

void show_vector(std::vector<int> &result)
{

    for (size_t n : result)
        std::cout << n << " ";
    std::cout << std::endl;
}
