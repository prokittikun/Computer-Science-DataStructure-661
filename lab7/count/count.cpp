#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int find;
    cin >> find;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(array[i] == find){
            count++;
        }
    }
    cout << count;
    
}