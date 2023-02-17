// Move the first letter of each word to the end of it, then add "ay" to the end of the word. Leave punctuation marks untouched.

// Examples
// pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
// pigIt('Hello world !');     // elloHay orldway !

std::string pig_it(std::string str)
{
    char letter = str.at(0);
    std::string ay = "ay";
    std::string result;
    for (size_t i = 1; i < str.size(); i++)
    {
        if (str[i] == ' ' && (str[i + 1] != '!' || str[i + 1] != '?' || str[i + 1] != ',' || str[i + 1] != '.'))
        {
            result.push_back(letter);
            result += ay;
            letter = str[i + 1];
            result.push_back(str[i++]);
        }
        else
            result.push_back(str[i]);
    }
    result.push_back(letter);
    result += ay;
    return result;
}

std::string pig_it(std::string str)
{
    char letter = str.at(0);
    std::string ay = "ay";
    std::string result;
    for (size_t i = 1; i <= str.size(); i++)
    {
        if (str[i] == ' ' || i == npos)
        {
            result.push_back(letter);
            result += ay;
            if (str[i + 1] == '!' || str[i + 1] == '?' || str[i + 1] == ',' || str[i + 1] == '.')
            {
                result.push_back(str[i]);
                result.push_back(str[i++]);
            }
            else
            {
                letter = str[i + 1];
                result.push_back(str[i++]);
            }
        }
        else
            result.push_back(str[i]);
    }
    result.push_back(letter);
    result += ay;
    return result;
}

std::string pig_it(std::string str)
{
    char letter = str.at(0);
    std::string ay = "ay";
    std::string result;

    for (size_t i = 1; i < str.size(); i++)
    {
        if (str[i] == '!' || str[i] == '?' || str[i] == ',' || str[i] == '.')
        {
            result.push_back(str[i]);
            if (str[i + 1] == ' ')
                result.push_back(str[i++]);
        }

        else if ((str[i] == ' ') &&
                 (str[i + 1] != '!' || str[i + 1] != '?' || str[i + 1] != ',' || str[i + 1] != '.') &&
                 (str[i - 1] != '!' || str[i - 1] != '?' || str[i - 1] != ',' || str[i - 1] != '.'))
        {
            result.push_back(letter);
            result += ay;
            if (str[i + 1] == '!' || str[i + 1] == '?' || str[i + 1] == ',' || str[i + 1] == '.')
            {
                result.push_back(str[i]);
                //  result.push_back(str[i++]);
            }
            else
            {
                letter = str[i + 1];
                result.push_back(str[i++]);
            }
        }
        else if (i == 0)
            i++;
        else
            result.push_back(str[i]);
    }
    if (str[str.size()] != '!' || str[str.size()] != '?' || str[str.size()] != ',' || str[str.size()] != '.')
    {
        result.push_back(letter);
        result += ay;
    }
    return result;
}

std::string pig_it(std::string str)
{
    // size_t found=str.find_first_not_of("!?,. ");
    std::string result;
    // size_t found=str.find(' ');
    char letter;
    std::string ay = "ay";
    if (str[0] == ' ' && str[0] == '!' && str[0] == '?' && str[0] == ',' && str[0] == '.')
    {
        result.push_back(str[0]);
    }
    else
        letter = str[0];

    for (size_t i = 1; i < str.size(); i++)
    {

        if (str[i] != ' ' && str[i] != '!' && str[i] != '?' && str[i] != ',' && str[i] != '.')
    }
    return result;
}