#include <stdio.h>

int a(int n) {
    int val;
    if (n == 1) {
        val = 2;
        printf("%d\n", val);
        return val;
    } else {
        val = a(n-1) + 3;
        printf("%d\n", val);
        return val;
    }
}

int main() {
    int x = a(5);
    return 0;
}