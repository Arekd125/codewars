// There is an array with some numbers. All numbers are equal except for one. Try to find it!

// find_uniq(std::vector<float>{1, 1, 1, 2, 1, 1});  // --> 2
// find_uniq(std::vector<float>{0, 0, 0.55, 0, 0});  // --> 0.55
// It’s guaranteed that array contains at least 3 numbers.

// The tests contain some very huge arrays, so think about performance.

// This is the first kata in series:

// Find the unique number (this kata)

float find_uniq(const std::vector<float> &v)
{

    if (v[0] != v[1])
        if (v[0] != v[2])
            return v[0];
        else
            return v[1];
    else
        for (auto i = 2; i < v.size(); i++)
        {
            if (v[0] != v[i])
                return v[i];
        }
}