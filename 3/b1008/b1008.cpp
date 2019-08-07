#include <cstdio>

int main()
{
    int a[110];
    int b[110];
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    m = m % n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[(i + m) % n] = a[i];
    }

    for (int i = 1; i < n; i++)
    {
        printf("%d", b[i]);
        printf(" ");
    }
    if (b[0] != 0)
    {
        printf("%d\n", b[0]);
    }
}

//g++ b1008/*.cpp -o 3.out && ./3.out