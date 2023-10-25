#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int pole[n];
    for (int index = 0; index < n; index++)
    {
        scanf("%d", &pole[index]);
    }
    int wire = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1, x = 0; j < n; j++, x++)
        {
            if(x == 0){
                wire += 1;
                continue;
            }
            int check = 0;
            for (int x = i+1; x < j; x++)
            {
                if(pole[i] > pole[x] && pole[x] < pole[j]){
                    check = 1;
                }else{
                    check = 0;
                    break;
                }
            }
            if(check == 1) wire += 1;
            
        }
        
    }
    printf("%d", wire);

    return 0;
}