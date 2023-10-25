#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *bracket;
    bracket = (char *)malloc(1001 * sizeof(char));
    scanf("%s", bracket);
    int bracketOpen = 0;
    int bracketClose = 0;

    for (int i = 0; bracket[i] != '\0'; i++)
    {
        if (bracket[i] == '(')
        {
            bracketOpen++;
        }
        else if(bracket[i] == ')')
        {
            bracketClose++;
        }
    }
    if (bracketOpen == bracketClose)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}