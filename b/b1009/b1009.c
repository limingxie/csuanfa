#include <stdio.h>
#include <string.h>

int main()
{
    char v[50][100];
    char str[100];
    gets(str);
    int len = strlen(str);
    int num = 0, h = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            v[num][h++] = str[i];
        }
        else
        {
            v[num][h++] = '\0';
            num++;
            h = 0;
        }
    }

    for (int i = num; i >= 0; i--)
    {
        printf("%s", v[i]);
        if (i != 0)
            printf(" ");
    }
    return 0;
}

//gcc ./b1009/*.c -o a.out && ./a.out