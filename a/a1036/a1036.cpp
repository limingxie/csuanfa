#include <cstdio>

struct tt
{
    char name[15];
    char id[15];
    int ss;

} p0, pm, pf;

int main()
{
    int n = 0;
    scanf("%d", &n);

    char m;

    pm.ss = 101;
    pf.ss = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %c %s %d", p0.name, &m, p0.id, &p0.ss);
        if (m == 'M')
        {
            if (pm.ss > p0.ss)
            {
                pm = p0;
            }
        }
        else
        {
            if (pf.ss < p0.ss)
                pf = p0;
        }
    }

    if (pf.ss == -1)
    {
        printf("Absent\n");
    }
    else
    {
        printf("%s %s\n", pf.name, pf.id);
    }
    if (pm.ss == 101)
    {
        printf("Absent\n");
    }
    else
    {
        printf("%s %s\n", pm.name, pm.id);
    }
    if (pf.ss == -1 || pm.ss == 101)
    {
        printf("NA\n");
    }
    else
    {
        printf("%d", pf.ss - pm.ss);
    }
}

//g++ a1036/*.cpp -o 3_2.out && ./3_2.out