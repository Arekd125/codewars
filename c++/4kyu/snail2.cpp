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
    std::vector<std::vector<int>> a = {{}};
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

    result = snail(e);
    show_vector(result);
}

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map)
{
    std::vector<int> result;
    size_t n{snail_map.size()};
    size_t k{n - 1};
    int  row= 0;
    int  col = 0;
    int  row2 =4;

    

    for (int i = 0; i < n; i++)
    {
        result.push_back(snail_map[row][col++]);
    }
    col--;
     

    do
    {
        for (int i = 0; i <k; i++)
    {
        result.push_back(snail_map[++row][col]);
    }
   
    for (int i = 0; i <k; i++)
    {
        result.push_back(snail_map[row][--col]);
    }
    k--;
    for (int i = 0; i <k; i++)
    {
        result.push_back(snail_map[--row][col]);
    }
    for (int i = 0; i < k; i++)
    {
        result.push_back(snail_map[row][++col]);
        
    }
    k--;
    } while (k!=0);
    

    
    // for (int i = k; i >1; i--)
    // {
    //     result.push_back(snail_map[k][i]);
    // }
         
    //  k--    ;
    // for (int i = k; i >=0; i--)
    // {
    //     result.push_back(snail_map[k][i]);
    // }
    
    // z++;
    // for (int i = k; i >= 1; i--) // LEFT
    // {
    //     result.push_back(snail_map[i][0]);
    // }

    return result;
}

void show_vector(std::vector<int> &result)
{

    for (size_t n : result)
        std::cout << n << " ";
}
