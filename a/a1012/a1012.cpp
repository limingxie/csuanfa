#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
    int id;
    int C, M, E, A;
    int CC, MM, EE, AA;

} stu[100010];

void ss_print(Student s1)
{
    char g[1];
    int rank;
    strcpy(g, "A");
    rank = s1.AA;
    if (s1.CC < rank)
    {
        rank = s1.CC;
        strcpy(g, "C");
    }
    else if (s1.MM < rank)
    {
        rank = s1.MM;
        strcpy(g, "M");
    }
    else if (s1.EE < rank)
    {
        rank = s1.EE;
        strcpy(g, "E");
    }
    printf("%d %s\n", rank, g);
}

bool cmpC(Student s1, Student s2)
{
    return s1.C > s2.C;
}
bool cmpM(Student s1, Student s2)
{
    return s1.M > s2.M;
}
bool cmpE(Student s1, Student s2)
{
    return s1.E > s2.E;
}
bool cmpA(Student s1, Student s2)
{
    return s1.A > s2.A;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].C, &stu[i].M, &stu[i].E);
        stu[i].A = (stu[i].C + stu[i].M + stu[i].E) / 3;
    }

    sort(stu, stu + n, cmpC);
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && stu[i].C == stu[i - 1].C)
        {
            stu[i].CC = stu[i - 1].CC;
        }
        stu[i].CC = i + 1;
    }

    sort(stu, stu + n, cmpM);
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && stu[i].M == stu[i - 1].M)
        {
            stu[i].MM = stu[i - 1].MM;
        }
        stu[i].MM = i + 1;
    }

    sort(stu, stu + n, cmpE);
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && stu[i].E == stu[i - 1].E)
        {
            stu[i].EE = stu[i - 1].EE;
        }
        stu[i].EE = i + 1;
    }

    sort(stu, stu + n, cmpA);
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && stu[i].A == stu[i - 1].A)
        {
            stu[i].AA = stu[i - 1].AA;
        }
        stu[i].AA = i + 1;
    }

    int id;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &id);
        printf("======%d======\n", i);
        for (int j = 0; j < n; j++)
        {
            if (stu[j].id == id)
            {
                ss_print(stu[j]);
            }
        }
        printf("======%d======\n", i);
    }

    return 0;
}

//g++ a1012/*.cpp -o a.out && ./a.out