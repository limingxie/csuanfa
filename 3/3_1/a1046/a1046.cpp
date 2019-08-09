#include <cstdio>
// #include <algorithm>
// using namespace std;

int min(int a, int b)
{
    if (a <= b)
        return a;
    else
        return b;
}

int main()
{
    int c = 0;
    scanf("%d", &c);

    int a[100005];
    int d[100005];
    int sum = 0;
    for (int i = 1; i <= c; i++)
    {
        d[i] = sum;
        scanf("%d", &a[i]);
        sum += a[i];
    }

    int n = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int f1, f2;
        scanf("%d %d", &f1, &f2);
        if (f1 > f2)
        {
            // swap(f1, f2);
            int t;
            t = f1;
            f1 = f2;
            f2 = t;
        }

        printf("%d\n", min(d[f2] - d[f1], sum - (d[f2] - d[f1])));
    }
}

//g++ a1046/*.cpp -o 3.out && ./3.out