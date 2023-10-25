#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *text;
    char vowel[] = {'a', 'e', 'i', 'o', 'u'};

    text = (char *)malloc(101 * sizeof(char));
    fgets(text, 101, stdin);
    int next = 0;
    char *decode;
    decode = (char *)malloc(101 * sizeof(char));
    int k = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (next == 0)
        {
            decode[k++] = text[i];
        }
        else
        {
            next--;
        }
        if (strchr(vowel, text[i]) && text[i + 1] == 'p' && text[i + 2] == text[i])
        {
            next = 2;
        }
    }
    decode[k] = '\0';
    printf("%s", decode);
}