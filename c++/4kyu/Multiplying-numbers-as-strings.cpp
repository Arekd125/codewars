// This is the first part. You can solve the second part here when you are done with this. Multiply two numbers! Simple!

// The arguments are passed as strings.
// The numbers may be way very large
// Answer should be returned as a string
// The returned "number" should not start with zeros e.g. 0123 is invalid
// Note: 100 randomly generated tests!

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiply(string a, string b)
{
    vector<int> aa;
    vector<int> bb;
    vector<vector<int>> aabb(a.size() + b.size(), vector<int>(b.size() + a.size(), 0));

    for (size_t i = 0; i < a.size(); i++)
        aa.emplace(aa.begin(), (static_cast<int>(a[i]) - 48));

    for (size_t i = 0; i < b.size(); i++)
        bb.emplace(bb.begin(), (static_cast<int>(b[i]) - 48));

    for (size_t i = 0; i < aa.size(); i++)
        for (size_t j = 0; j < bb.size(); j++)
            aabb[i][j] = aa[i] * bb[j];

    //////////////////////////////////////////////////////////////// do poprawy
    aa.clear();
    aa.emplace(aa.begin(), 0);
    for (size_t i = 0; i < aabb.size(); i++)
    {
        int n = 0;
        int row = i;
        for (size_t j = 0; j <= i; j++)
            aa[0] += aabb[row--][j];
        if (aa[0] > 9)
        {
            aa.emplace(aa.begin(), (static_cast<int>(aa[0] / 10)));
            aa[1] = (aa[1] % 10);
        }
        else
            aa.emplace(aa.begin(), 0);
        //////////////////////////////////////////////////////////////////////
    }
    int n = 0;
    string result;
    while (aa[n++] == 0);
    for (size_t i = n - 1; i < aa.size(); i++)
        result += to_string(aa[i]);
    if (result.empty())
        return "0";

    return result;
}

int main()
{
     cout <<"a: "<< multiply("2", "3") << endl;
     cout <<"b: "<< multiply("30", "69") << endl; 
     cout <<"d: "<< multiply("2", "0") << endl;
     cout <<"e: "<< multiply("0", "30") << endl;
     cout <<"f: "<< multiply("0000001", "3") << endl;
     cout <<"g: "<< multiply("1009", "03") << endl;
     cout <<"h: "<< multiply("98765", "56894") << endl;
     cout <<"i: " << multiply("1020303004875647366210", "2774537626200857473632627613") << endl; 
     cout <<"j: " << multiply("58608473622772837728372827", "7586374672263726736374") << endl;
     cout <<"k: "<< multiply("9007199254740991", "9007199254740991") << endl;
}
