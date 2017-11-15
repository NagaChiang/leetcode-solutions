class Solution
{
    
public:
    
    vector<string> findWords(vector<string>& words)
    {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        vector<string> rows { row1, row2, row3 };
        
        vector<string> keyboardWords = vector<string>();
        for (string word : words)
        {
            for (string row : rows)
            {
                if (IsComposedOf(word, row))
                {
                    keyboardWords.push_back(word);
                    break;
                }
            }
        }
        
        return keyboardWords;
    }
    
    bool IsComposedOf(string word, string row)
    {
        bool isComposedOf = true;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = tolower(word[i]);
            if (row.find(ch) == string::npos)
            {
                isComposedOf = false;
                break;   
            }
        }
        
        return isComposedOf;
    }
};
