#include <cstdio>

struct student
{
    char name[100];
    int hh, mm, ss;
} p0, p_min, p_max;

bool dd_compare(student s1, student s2)
{
    if (s1.hh != s2.hh)
        return s1.hh > s2.hh;
    else if (s1.mm != s2.mm)
        return s1.mm > s2.mm;
    else
        return s1.ss > s2.ss;
}

int main()
{
    p_max.hh = 0, p_max.mm = 0, p_max.ss = 0;
    p_min.hh = 24, p_min.mm = 60, p_max.ss = 60;
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d:%d:%d", p0.name, &p0.hh, &p0.mm, &p0.ss);
        if (dd_compare(p_min, p0))
            p_min = p0;

        scanf("%d:%d:%d", &p0.hh, &p0.mm, &p0.ss);
        if (dd_compare(p0, p_max))
            p_max = p0;
    }

    printf("%s %s\n", p_min.name, p_max.name);
}

//g++ a1006/*.cpp -o 3_2.out && ./3_2.out