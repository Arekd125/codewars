// The goal of this exercise is to convert a string to a new string where each character in the new string is "(" if
//  that character appears only once in the original string, or ")"
//  if that character appears more than once in the original string.
//   Ignore capitalization when determining if a character is a duplicate.

// Examples
// "din"      =>  "((("
// "recede"   =>  "()()()"
// "Success"  =>  ")())())"
// "(( @"     =>  "))(("
// Notes
// Assertion messages may be unclear about what they display in some languages.
// If you read "...It Should encode XXX", the "XXX" is the expected result, not the input!

#include <string>
std::string duplicate_encoder(const std::string &word)
{
    std::string result(word.size(), '(');
    std::string word2 = word;
    for (size_t i = 0; i < word.size(); i++)
        word2[i] = tolower(word2[i]);
    for (size_t i = 0; i < word.size(); i++)
        for (size_t j = word.size(); j > i; j--)
            if (word2[j] == word2[i])
            {
                result[j] = ')';
                result[i] = ')';
            }
    return result;
}