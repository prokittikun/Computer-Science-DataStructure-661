#include <iostream>
#include <algorithm>
using namespace std;

// int findKillCount(int *monster, int left, int right, int find, int sum)
// {
//     int mid = left + (right - left) / 2;

//     if (monster[mid] == find)
//     {
//         return sum + 1;
//     }else if(find > monster[mid] && find < (mid+1 <= right && monster[mid+1] > find)){
//         return mid;
//     }else if(mid == 0){
//         return 0;
//     }
//     else if (monster[mid] > find)
//     {
//         return findKillCount(monster, left, mid, find, sum);
//     }
//     else if (monster[mid] < find)
//     {
//         return findKillCount(monster, mid, right, find, sum + mid + 1);
//     }
//     else
//     {
//         return 0;
//     }
// }

int binarySearch(int arr[], int left, int right, int target) {
    int low = left, high = right, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result + 1;
}

int main()
{
    int n;
    cin >> n;
    int monsterHealth[n];
    for (int i = 0; i < n; i++)
    {
        cin >> monsterHealth[i];
    }
    sort(monsterHealth, monsterHealth + n);
    int weaponCount;
    cin >> weaponCount;
    for (int i = 0; i < weaponCount; i++)
    {
        int weaponDamage = 0;
        cin >> weaponDamage;
        int kill = binarySearch(monsterHealth, 0, n - 1, weaponDamage);
        cout << kill << endl;
    }
    return 0;
}