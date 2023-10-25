#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> stack;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int doTask;
        cin >> doTask;
        if (doTask == 1)
        {
            int pushNum;
            cin >> pushNum;
            stack.push(pushNum);
        }
        else if (doTask == 2)
        {
            if (!stack.empty())
            {
                stack.pop();
            }
        }
        else if (doTask == 3)
        {
            if (!stack.empty())
            {
                cout << stack.top() << endl;
            }else{
                cout << "EMPTY" << endl;
            }
        }
        else if (doTask == 4)
        {
            cout << stack.size() << endl;
        }
    }
}