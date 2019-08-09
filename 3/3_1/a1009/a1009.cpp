#include <cstdio>
const int maxn = 2222;
double p[maxn] = {};
double r[2222] = {};
int main()
{
    int b;
    double c;

    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %lf", &b, &c);
        p[b] = c;
    }

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %lf", &b, &c);
        for (int i = 0; i < maxn; i++)
        {
            if (p[i] != 0 && p[i] != 0.0)
            {
                r[i + b] += p[i] * c;
            }
        }
    }

    int count = 0;
    for (int i = 0; i <= maxn; i++)
    {
        if (r[i] != 0.0)
            count++;
    }

    printf("%d", count);
    for (int i = maxn; i >= 0; i--)
    {
        if (r[i] != 0.0)
        {
            printf(" %d %.1f", i, r[i]);
        }
    }
}

//g++ a1009/*.cpp -o 3_1.out && ./3_1.out
/* 
2 2 1.5 1 0.5
2 1 2.4 0 3.2
*/