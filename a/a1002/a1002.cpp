#include <cstdio>
const int maxn = 1111;
double p[maxn] = {};
int main()
{
    int b;
    double c;

    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %lf", &b, &c);
        p[b] += c;
    }

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %lf", &b, &c);
        p[b] += c;
    }

    int count = 0;
    for (int i = 0; i <= maxn; i++)
    {
        if (p[i] != 0)
            count++;
    }

    printf("%d", count);
    for (int i = maxn; i >= 0; i--)
    {
        if (p[i] != 0)
        {
            printf(" %d %.1f", i, p[i]);
        }
    }
}

//g++ a1002/*.cpp -o 3.out && ./3.out