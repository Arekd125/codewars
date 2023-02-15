// This time no story, no theory. The examples below show you how to write function accum:

// Examples:
// accum("abcd") -> "A-Bb-Ccc-Dddd"
// accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
// accum("cwAt") -> "C-Ww-Aaa-Tttt"
// The parameter of accum is a string which includes only letters from a..z and A..Z.

class Accumul
{
public:
    static std::string accum(const std::string &s)
    {
        std::string temp;
        for (unsigned i = 0; i < s.length(); i++)
        {
            temp += toupper(s[i]);
            temp.append(i, tolower(s[i]));
            temp += "-";
        }
        temp.pop_back();
        return temp;
    }
};