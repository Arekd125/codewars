// Move the first letter of each word to the end of it, then add "ay" to the end of the word. Leave punctuation marks untouched.

// Examples
// pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
// pigIt('Hello world !');     // elloHay orldway !

std::string pig_it(std::string str)
{

    std::string result;
    char letter;
    for (size_t i = 0; i < str.size(); i++ )
    {
        if (str[i] == ' ' || str[i] == '!' || str[i] == '?' || str[i] == ',' || str[i] == '.')
            result.push_back(str[i]);      
        else if (str[i] != ' ')
        {
            letter = str[i++];
            while (str[i] != ' ' &&  i<str.size() )
            {
                result.push_back(str[i++]);
            } 
            result.push_back(letter);
            result += "ay";
            i--;    
        }        
    }
    return result;
}
