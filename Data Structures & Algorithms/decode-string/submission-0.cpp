class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string currStr = "";
        int num = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            else if (ch == '[') {
                countStack.push(num);
                stringStack.push(currStr);

                num = 0;
                currStr = "";
            }
            else if (ch == ']') {
                int count = countStack.top();
                countStack.pop();

                string prevStr = stringStack.top();
                stringStack.pop();

                for (int i = 0; i < count; i++) {
                    prevStr += currStr;
                }

                currStr = prevStr;
            }
            else {
                currStr += ch;
            }
        }

        return currStr;
    }
};