#include <cstdio>
#include <cstring>

int main()
{
    char s[100];
    scanf("%s", s);
    int slen = strlen(s);

    int n1, n2;
    n1 = (slen + 2) / 3;
    n2 = slen + 2 - 2 * n1;

    for (int i = 0; i <= n1 - 2; i++)
    {
        printf("%c", s[i]);
        for (int j = 0; j < n2 -2 ; j++)
        {
            printf(" ");
        }
        
        printf("%c", s[slen - i - 1]);
        printf("\n");
    }

    for (int i = n1 - 1; i <= slen - n1; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0; 
}

//g++ a1031/*.cpp -o 3.out && ./3.out
