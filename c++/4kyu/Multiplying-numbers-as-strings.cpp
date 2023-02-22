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
    vector<vector<int>> aabb(a.size(), vector<int>(b.size(), 0));
    // int aabb[80][80];
    int ab;

    for (size_t i = 0; i < a.size(); i++)
    {

        aa.emplace(aa.begin(), (static_cast<int>(a[i]) - 48));
    }
    for (size_t i = 0; i < b.size(); i++)
    {

        bb.emplace(bb.begin(), (static_cast<int>(b[i]) - 48));
    }

    for (size_t i = 0; i < aa.size(); i++)
    {
        for (size_t j = 0; j < bb.size(); j++)
        {
            aabb[i][j] = aa[i] * bb[j];
            cout << aabb[i][j] << " ";
        }
        cout << endl;
    }
    //////////////////////////////////////////////////////////////// do poprawy
    aa.clear();
    aa.push_back(aabb[0][0]);

    if (aa[0] > 9)
    {
        aa.push_back(static_cast<int>(aa[0] / 10));
        aa[0] = (aa[0] % 10);
    }
    else
       aa.push_back(0);
    for (size_t i = 1; i < aabb.size(); i++)
    {
          //int col = 0;
        int row = i;
        //  cout<<"aa"<<aa[i]<<endl;
        for (size_t j = 0; j <aabb[0].size(), j<=i; j++)
        {
            aa[i] += aabb[row--][j];
        }
        if (aa[i] > 9)
        {
            aa.push_back(static_cast<int>(aa[i] / 10));
            aa[i] = (aa[i] % 10);
        }
        else
             aa.push_back(0);
        //////////////////////////////////////////////////////////////////////
    }
    for (size_t i = 0; i < aa.size(); i++)
    {
        cout << aa[i] << "";
    }


    return " ";
}

int main()
{
    // cout << "a: " << endl;
    // cout << multiply("25", "25") << endl;
    // cout <<"a: "<< multiply("2", "3") << endl;
    // cout <<"b: "<< multiply("30", "69") << endl; //2070
    // cout <<"c: "<< multiply("11", "85") << endl;
    // cout <<"d: "<< multiply("2", "0") << endl;
    // cout <<"e: "<< multiply("0", "30") << endl;
    // cout <<"f: "<< multiply("0000001", "3") << endl;
    // cout <<"g: "<< multiply("1009", "03") << endl;
    // cout <<"h: "<< multiply("98765", "56894") << endl;
    // cout <<"i: "<< multiply("1020303004875647366210", "2774537626200857473632627613") << endl;
    cout << "j: " << multiply("58608473622772837728372827", "7586374672263726736374") << endl;
    // cout <<"k: "<< multiply("9007199254740991", "9007199254740991") << endl;
}
