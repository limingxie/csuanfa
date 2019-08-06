#include <stdio.h>
#include <string.h>

int main()
{
    char str[50];
    gets(str);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i -1])
        {
            printf("false\n");
            return;
        }
    }

    printf("yes\n");
    return 0;
}

//gcc ./codeup_5901/*.c -o a.out && ./a.out