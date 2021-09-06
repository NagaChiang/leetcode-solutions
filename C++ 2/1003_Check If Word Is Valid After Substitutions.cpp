class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        for (char c : s) {
            if (c == 'c') {
                if (charStack.empty() || charStack.top() != 'b') {
                    return false;
                }

                charStack.pop();
                if (charStack.empty() || charStack.top() != 'a') {
                    return false;
                }

                charStack.pop();
            } else {
                charStack.push(c);
            }
        }

        return charStack.empty();
    }
};