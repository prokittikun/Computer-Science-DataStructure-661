#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> queue;

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
            queue.push(pushNum);
        }
        else if (doTask == 2)
        {
            if (!queue.empty())
            {
                queue.pop();
            }
        }
        else if (doTask == 3)
        {
            if (!queue.empty())
            {
                cout << queue.front() << endl;
            }else{
                cout << "EMPTY" << endl;
            }
        }
        else if (doTask == 4)
        {
            cout << queue.size() << endl;
        }
    }
}