class Solution {
private:
    static constexpr char bracketPairs[3][2] = {
        {'(',')'},
        {'[',']'},
        {'{','}'},
    };
    
public:
    bool isValid(string s) {
        vector<char> stack;
        for (char c : s) {
            if (isOpenBracket(c)) {
                stack.push_back(c);
                continue;
            }
            
            if (isCloseBracket(c)) {
                if (!stack.empty() && isValidBracketPair(stack.back(), c)) {
                    stack.pop_back();
                } else {
                    return false;
                }
            }
        }
        
        return stack.empty();
    }
    
private:
    static bool isOpenBracket(char c) {
        for (const char* pair : bracketPairs) {
            if (c == pair[0]) {
                return true;
            }
        }
        
        return false;
    }
    
    static bool isCloseBracket(char c) {
        for (const char* pair : bracketPairs) {
            if (c == pair[1]) {
                return true;
            }
        }
        
        return false;
    }
    
    static bool isValidBracketPair(char open, char close) {
        for (const char* pair : bracketPairs) {
            if (open == pair[0] && close == pair[1]) {
                return true;
            }
        }
        
        return false;
    }
};