// An isogram is a word that has no repeating letters, consecutive or non-consecutive.
//  Implement a function that determines whether a string that contains only letters is an isogram.
//   Assume the empty string is an isogram. Ignore letter case.

// Example: (Input --> Output)

// "Dermatoglyphics" --> true "aba" --> false "moOse" --> false (ignore letter case)

// isIsogram "Dermatoglyphics" = true
// isIsogram "moose" = false
// isIsogram "aba" = false

bool is_isogram(std::string str)
{
    int size_str = str.length();

    if (str.empty())
        return true;

    for (int i = 0; i < size_str; i++)
        str[i] = tolower(str[i]);

    for (int i = 0; i < size_str; i++)
        for (int j = size_str; i < j; j--)
            if (str[i] == str[j])
                return false;

    return true;
}