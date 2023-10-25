#include <iostream>
#include <stack>

using namespace std;

int priority(char c)
{
    switch (c)
    {
    case '^':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}
int main()
{
    stack<char> stack;

    char answer[101];
    int i = 0;
    int x = 0;
    char c[101];
    gets(c);
    while (true)
    {
        if (c[x] == '\0')
        {
            answer[i++] = stack.top();
            stack.pop();
            break;
        }

        if (c[x] == '(')
        {
            stack.push(c[x]);
        }
        else if (c[x] == ')')
        {
            while (stack.top() != '(')
            {
                if (!stack.empty())
                {
                    answer[i++] = stack.top();
                    stack.pop();
                }
            }
            stack.pop();
        }
        else if (priority(c[x]) == 0)
        {
            answer[i++] = c[x];
        }
        else if (stack.empty())
        {
            stack.push(c[x]);
        }
        else if (priority(c[x]) > priority(stack.top()))
        {
            stack.push(c[x]);
        }
        else if (priority(c[x]) <= priority(stack.top()))
        {
            answer[i++] = stack.top();
            stack.pop();
            stack.push(c[x]);
        }
        x++;
    }
    cout << answer;
}