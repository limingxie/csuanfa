#include <cstdio>
#include <cstring>

int main()
{
    char num[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    char s[110];
    scanf("%s", s);

    int slen = strlen(s);
    int sum = 0;
    for (int i = 0; i < slen; i++)
    {
        sum = sum + (s[i] - '0');
    }

    if (sum == 0 )
    {
        printf("%s", num[0]);
        return 0;
    }

    char r[10];
    int a = 0;
    while (sum != 0)
    {
        r[a] = sum % 10;
        sum = sum / 10;
        a++;
    }

    for (int i = a - 1; i >= 0; i--)
    {
        printf("%s", num[r[i]]);
        if (i != 0)
        {
            printf(" ");
        }
    }

    return 0;
}

//g++ a1005/*.cpp -o a.out && ./a.out