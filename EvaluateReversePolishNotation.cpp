class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        int x, y;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                y = s.top();
                s.pop();
                x = s.top();
                s.pop();
                s.push(x + y);
            }
            else if (tokens[i] == "-")
            {
                y = s.top();
                s.pop();
                x = s.top();
                s.pop();
                s.push(x - y);
            }
            else if (tokens[i] == "*")
            {
                y = s.top();
                s.pop();
                x = s.top();
                s.pop();
                s.push(x * y);
            }
            else if (tokens[i] == "/")
            {
                y = s.top();
                s.pop();
                x = s.top();
                s.pop();
                s.push(x / y);
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
