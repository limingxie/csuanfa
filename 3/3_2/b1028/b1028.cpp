#include <cstdio>

struct student
{
    char name[100];
    int yy, mm, dd;
} p0, p_max, p_min;

bool yy_compare(student s1, student s2)
{
    bool flag = false;
    if (s1.yy > s2.yy)
    {
        flag = true;
    }
    else if (s1.yy == s2.yy)
    {
        if (s1.mm > s2.mm)
        {
            flag = true;
        }
        else if (s1.mm == s2.mm)
        {
            if (s1.dd >= s2.dd)
            {
                flag = true;
            }
        }
    }
    return flag;
}

bool yy_chk(student s)
{
    bool flag = true;
    if (s.yy > 2014)
    {
        flag = false;
    }
    else if (s.yy == 2014)
    {
        if (s.mm > 9)
        {
            flag = false;
        }
        else if (s.mm == 9)
        {
            if (s.dd > 6)
            {
                flag = false;
            }
        }
    }

    if (s.yy < 1814)
    {
        flag = false;
    }
    else if (s.yy == 1814)
    {
        if (s.mm < 9)
        {
            flag = false;
        }
        else if (s.mm == 9)
        {
            if (s.dd < 6)
            {
                flag = false;
            }
        }
    }

    return flag;
}

int main()
{
    
    int n = 0;
    scanf("%d", &n);

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d/%d/%d", p0.name, &p0.yy, &p0.mm, &p0.dd);
        if (yy_chk(p0))
        {
            if (yy_compare(p0, p_min))
            {
                p_min = p0;
            }
            if (p_max.yy == 0)
            {
                p_max = p0;
            }
            else if (yy_compare(p_max, p0))
            {
                p_max = p0;
            }
            count++;
        }
    }
    if (count == 0)
        printf("0\n");
    else
        printf("%d %s %s\n", count, p_max.name, p_min.name);

}

//g++ b1028/*.cpp -o 3_2.out && ./3_2.out