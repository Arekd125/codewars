// Write a function to convert a name into initials.This kata strictly takes two words with one space in between them.

//     The output should be two capital letters with a dot separating them.

//     It should look like this :

//     Sam Harris = > S.H

//                        patrick feeney = > P.F

#include <string>

std::string
abbrevName(std::string name)
{
    auto second = name.find(" ", 1);
    std::string test = "";
    test += toupper(name.at(0));
    test += ".";
    test += toupper(name.at(second + 1));
    return test;
}