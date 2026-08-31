class Solution {
public:
    bool isValid(string s) {
        stack<char> chars;

        if (s.empty())
        {
            return true;
        }

        if (s.size() == 1)
        {
            return false;
        }

        for (char c: s)
        {
            if (!chars.empty())
            {
                if ((c == ')' && chars.top() == '(') ||
                    (c == '}' && chars.top() == '{') ||
                    (c == ']' && chars.top() == '['))
                {
                    chars.pop();
                    continue;
                }
            }
            chars.push(c);
        }

        return chars.empty();
    }
};
