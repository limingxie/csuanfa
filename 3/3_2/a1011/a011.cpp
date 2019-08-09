#include <cstdio>

struct tt
{
    double t[3];
    int max;

} p1, p2, p3;

int max(int a, int b, int c)
{
    if (a >= b && a >= c)
    {
        return 0;
    }
    else if (b >= a && b >= c)
    {
        return 1;
    }
    else if (c >= a && c >= b)
    {
        return 2;
    }
    else 
    {
        return 0;
    }
}
char result(int i)
{
    if (i == 0)
    {
        return 'W';
    }
    else if (i == 1)
    {
        return 'T';
    }
    else
    {
        return 'L';
    }
}

int main()
{

    scanf("%lf %lf %lf", &p1.t[0], &p1.t[1], &p1.t[2]);
    scanf("%lf %lf %lf", &p2.t[0], &p2.t[1], &p2.t[2]);
    scanf("%lf %lf %lf", &p3.t[0], &p3.t[1], &p3.t[2]);

    p1.max = max(p1.t[0], p1.t[1], p1.t[2]);
    p2.max = max(p2.t[0], p2.t[1], p2.t[2]);
    p3.max = max(p3.t[0], p3.t[1], p3.t[2]);

printf("%c %c %c ", result(p1.max), result(p2.max), result(p3.max));


double aa = (p1.t[p1.max] * p2.t[p2.max] * p3.t[p3.max] * 0.65 - 1) * 2;
printf("%.2f", aa);
    // printf("%c %c %c %f", result(p1.max), result(p2.max), result(p3.max),   );
}

//g++ a1011/*.cpp -o 3_2.out && ./3_2.out