#include <cstdio>

int result[100010] = {0};

int main()
{
    int n, id, score;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &id, &score);
        result[id] += score;
    }

    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        if (result[k] <= result[i])
        {
            k = i;
        }
    }

        printf("%d %d\n", k, result[k]);
    
    return 0;
}

//g++ b1032/*.cpp -o b1032.out && ./b1032.out