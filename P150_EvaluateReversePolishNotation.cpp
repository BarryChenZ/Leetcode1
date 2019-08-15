class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> temp;
        int size = tokens.size();
        for(int i = 0; i < size; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num1 = temp.top();
                temp.pop();
                int num2 = temp.top();
                temp.pop();
                int ans;
                if (tokens[i] == "+") {
                     ans = num2 + num1;
                } 
                else if (tokens[i] == "-") {
                    ans = num2 - num1;
                } 
                else if (tokens[i] == "/") {
                    ans = num2 / num1;
                } 
                else {
                    ans = num2 * num1;
                }
                temp.push(ans);
            }
            else{
                stringstream ss;
                int num;
                ss << tokens[i]; ss >> num;
                temp.push(num);
            }
        }
        return temp.top();
    }
};
