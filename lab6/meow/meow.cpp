#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int strLen = 0;
        cin >> strLen;
        char str[strLen + 1];
        cin >> str;
        string answer = "";
        int x = 0;
        for (int i = 0; i < strLen; i++)
        {
            if (answer == "")
            {
                answer += tolower(str[i]);
            }
            else if (answer[x] != tolower(str[i]))
            {
                answer += tolower(str[i]);
                x++;
            }
        }
        if (answer == "meow")
        {
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}