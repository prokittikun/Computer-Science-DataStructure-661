#include <stdio.h>

int An(int n, int sum){
    if(n == 1) return sum;

    return An(n-1, sum+3);
}
int main(){
    printf("%d", An(5,2));
}