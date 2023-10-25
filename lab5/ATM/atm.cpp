#include <iostream>
#include <queue>

using namespace std;

int main()
{

    queue<int> q;
    int n = 0, x = 0;
    cin >> n >> x;
    int data[n];

    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
        q.push(i);
    }

    while (!q.empty())
    {
        int first = q.front();
        if(data[first] > x){
            data[first] = data[first]-x;
            q.pop();
            q.push(first);
        }else{
            data[first] = 0;
        }
        if(data[first] == 0){
            cout << first+1 << " ";
            q.pop();
        }
    }
}