#include <iostream>
#include <stack>

using namespace std;
int accumulate(char top, int a, int b, int c)
{
    int sum = 0;
    switch (top)
    {
    case 'A':
        sum += a;
        break;
    case 'B':
        sum += b;
        break;
    case 'C':
        sum += c;
        break;

    default:

        break;
    }
    return sum;
}

bool checkIsABC(char top)
{
    if (top == 'A' || top == 'B' || top == 'C')
    {
        return true;
    }
    return false;
}
int main()
{
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    string s;
    cin >> s;

    stack<char> stack;

    for (int i = 0; i < s.length(); i++)
    {
        stack.push(s[i]);
    }

    int result = 0;
    for (int i = s.length() - 1; !stack.empty(); i--)
    {
        if (stack.size() == 1)
        {
            if (stack.top() == '[')
            {
                result += 10 * result / 100;
            }
            else if (stack.top() == '(')
            {
                result += 7 * result / 100;
            }else if (stack.top() == '{'){
                result += 5 * result / 100;
            }
        }
        if (stack.top() == ']')
        {
            stack.pop(); // pop a close bracket
            if (!checkIsABC(stack.top()))
            {
                continue;
            }
            int sum = 0;
            while (stack.top() != '[' && checkIsABC(stack.top()))
            {
                if (!stack.empty())
                {
                    char top = stack.top();
                    sum += accumulate(top, a, b, c);
                    stack.pop();
                }
            }
            // cout << stack.top();
            stack.pop(); // pop a open bracket
            result += (10 * sum / 100) + sum;
        }
        else if (stack.top() == ')')
        {
            stack.pop(); // pop a close bracket
            if (!checkIsABC(stack.top()))
            {
                continue;
            }
            int sum = 0;
            while (stack.top() != '(' && checkIsABC(stack.top()))
            {
                if (!stack.empty())
                {
                    char top = stack.top();
                    sum += accumulate(top, a, b, c);
                    stack.pop();
                }
            }
            // cout << stack.top();
            stack.pop(); // pop a open bracket
            // cout << (7 * sum / 100) << endl;
            result += (7 * sum / 100) + sum;
        }
        else if (stack.top() == '}')
        {
            stack.pop(); // pop a close bracket
            if (!checkIsABC(stack.top()))
            {
                continue;
            }
            int sum = 0;
            while (stack.top() != '{' && checkIsABC(stack.top()))
            {
                if (!stack.empty())
                {
                    char top = stack.top();
                    sum += accumulate(top, a, b, c);
                    stack.pop();
                }
            }
            // cout << stack.top();
            stack.pop(); // pop a open bracket
            // cout << (5 * sum / 100) << endl;
            result += (5 * sum / 100) + sum;
        }
        else
        {
            result += accumulate(stack.top(), a, b, c);
            stack.pop();
        }
    }
    cout << result;
}