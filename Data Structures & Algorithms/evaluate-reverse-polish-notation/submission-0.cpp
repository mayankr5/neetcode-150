class Solution {
public:
    int evalRPN(vector<string>& tokens) {
                vector<int> stk;

        for (string token : tokens) {

            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                int b = stk.back();
                stk.pop_back();

                int a = stk.back();
                stk.pop_back();

                if (token == "+")
                    stk.push_back(a + b);
                else if (token == "-")
                    stk.push_back(a - b);
                else if (token == "*")
                    stk.push_back(a * b);
                else
                    stk.push_back(a / b);

            } else {
                stk.push_back(stoi(token));
            }
        }

        return stk.back();
    }
};
