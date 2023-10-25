#include <iostream>
#include <math.h>

using namespace std;

int checkPrime(int n)
{
    int prime = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            prime += 1;
        }
    }
    return prime;
}

int makePrime(string n, int index){
    string newStr = n.replace(index, 0, "");
    int x = stoi(n);

    return x+1
}
int main()
{
    string n;
    cin >> n;
    cout << makePrime(n);
    // cout << checkPrime(277);
}