class Solution
{
    
public:
    
    string reverseWords(string s)
    {
        string word;
        string reversed;
        stringstream stream;
        stream << s;
        while (stream >> word)
        {
            if (reversed.length() > 0)
                reversed += " ";
            
            for (int i = word.length() - 1; i >= 0; i--)
                reversed += word[i];
        }
        
        return reversed;
    }
};
