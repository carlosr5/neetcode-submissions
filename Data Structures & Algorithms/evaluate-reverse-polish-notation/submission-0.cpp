class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // We can assume valid inputs based on problem description.
        // Have a stack take in the string of tokens.
        // Push items until you see an operator.
        // When you see an operator, apply to bottom items of stack,
        // then pop to mark that those numbers have been operated on.
        // Push resulting value back to stack and repeat.

        stack<string> token_stack;
        stringstream ss;
        int token_idx = 0;
        int final_result = INT_MIN;

        do
        {
            if (token_idx < tokens.size())
            {
                string s = tokens[token_idx++];
                token_stack.push(s);
            }

            // Process the stack based on the operation
            int result = INT_MIN;
            string top_temp = token_stack.top();

            if(top_temp.size() != 1)
            {
                continue;
            }

            char top = token_stack.top().c_str()[0];

            if(top == '+' || top == '*' || top == '-' || top == '/')
            {
                // Pop the operator
                token_stack.pop();

                // Pop the two numbers to operate on
                int num2 = stoi(token_stack.top());
                token_stack.pop();

                int num1 = stoi(token_stack.top());
                token_stack.pop();

                if (top == '+')
                {
                    int temp_result = num1 + num2;
                    token_stack.push(to_string(temp_result));
                }
                else if (top == '-')
                {
                    int temp_result = num1 - num2;
                    token_stack.push(to_string(temp_result));
                }
                else if (top == '*')
                {
                    int temp_result = num1 * num2;
                    token_stack.push(to_string(temp_result));
                }
                else if (top == '/')
                {
                    int temp_result = num1 / num2;
                    token_stack.push(to_string(temp_result));
                }
            }
        } while(!token_stack.empty() && token_idx < tokens.size());

        final_result = stoi(token_stack.top());
        
        return final_result;
    }
};
