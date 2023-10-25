#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int min = 0;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        scanf("%d", &x);
        if (min == 0 || x <= min)
        {
            min = x;
        }
       
        if (max == 0 || x >= max)
        {
            max = x;
        }
      
    }
    printf("%d\n", min);
    printf("%d", max);

    return 0;
}