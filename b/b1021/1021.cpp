#include <cstdio>
#include <cstring>

int main()
{
    char s[1010];
    scanf("%s", s);

    int count[10] = {0};

    int slen = strlen(s);
    for (int i = 0; i < slen; i++)
    {
        count[s[i] - '0']++;
    }

    for (int i = 0; i < 10; i++)
    {
        if (count[i] != 0)
        {
            printf("%d:%d\n", i, count[i]);
        }
    }
    return 0;
}

//g++ b1021/*.cpp -o b.out && ./b.out