#include <iostream>
using namespace std;

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binarySearch(int *arr, int target, int left, int right, int round) {
    int middle = (left + right) / 2;
    
    if (arr[left] == target || arr[right] == target || arr[middle] == target) {
        return round;
    } else if (left == middle - 1) {
        return -1;
    } else {
        if (target < arr[middle]) {
            return binarySearch(arr, target, left, middle, round + 1);
        } else {
            return binarySearch(arr, target, middle, right, round + 1);
        }
    }
}

void bubbleSort(int *arr, int size) {
    int bubbleSortRound = 1;
    
    while (true) {
        int swapCount = 0;
        
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapCount++;
            }
        }
        
        // printArray(arr, size);
        
        if (swapCount == 0) {
            break;
        }
    }
}

int main() {
    int arr[17] = {1, 15, 5, 7, 10, 9, 10, 3, 45, 155, 56, 18, 88, 23, 99, 111, 100};
    
    cout << "Array: ";
    printArray(arr, 17);
    
    bubbleSort(arr, 17);
    
    int target = 5;
    int searchRound = binarySearch(arr, target, 0, 16, 1);
    if (searchRound != -1) {
        cout << "Binary Search found" << target << " in " << searchRound << " rounds." << endl;
    } else {
        cout << "Binary Search " << target << " not found in the array." << endl;
    }
    
    return 0;
}
