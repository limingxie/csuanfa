#include <cstdio>
#include <cstring>

int w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main()
{
    int n;
    scanf("%d", &n);

    int flag = true;
    
    char s[20];
    for (int l = 1; l <= n; l++)
    {
        scanf("%s", s);
        int last = 0;
        for (int i = 0; i < 17; i++)
        {
            last = last + (s[i] - '0') * w[i];
        }

        if (m[last % 11] != s[17])
        {
            flag = false;
            printf("%s\n", s);
        }
    }

    if (flag == true)
    {
        printf("All passed\n");
    }
}

//g++ b1031/*.cpp -o b.out && ./b.out