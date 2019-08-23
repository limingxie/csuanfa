#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
    int id;
    int C, M, E;
    double A;
    int C_rank, M_rank, E_rank, A_rank;
};

void stu_print(Student s)
{
    int highest_rank = s.A_rank;
    char highest_rank_subject = 'A';
    if (s.C_rank < highest_rank)
    {
        highest_rank = s.C_rank;
        highest_rank_subject = 'C';
    }
    if (s.M_rank < highest_rank)
    {
        highest_rank = s.M_rank;
        highest_rank_subject = 'M';
    }
    if (s.E_rank < highest_rank)
    {
        highest_rank = s.E_rank;
        highest_rank_subject = 'E';
    }
    printf("%d %c\n", highest_rank, highest_rank_subject);
}

bool cmpC(Student s1, Student s2)
{
    if (s1.C != s2.C)
    {
        return s1.C > s2.C;
    }
    else
    {
        return s1.id < s2.id;
    }
}
bool cmpM(Student s1, Student s2)
{
    if (s1.M != s2.M)
    {
        return s1.M > s2.M;
    }
    else
    {
        return s1.id < s2.id;
    }
}
bool cmpE(Student s1, Student s2)
{
    if (s1.E != s2.E)
    {
        return s1.E > s2.E;
    }
    else
    {
        return s1.id < s2.id;
    }
}
bool cmpA(Student s1, Student s2)
{
    if (s1.A != s2.A)
    {
        return s1.A > s2.A;
    }
    else
    {
        return s1.id < s2.id;
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Student stu[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].C, &stu[i].M, &stu[i].E);
        stu[i].A = double(stu[i].C + stu[i].M + stu[i].E) / 3;
    }

    sort(stu, stu + n, cmpA);
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && stu[i].A == stu[i - 1].A)
            stu[i].A_rank = stu[i - 1].A_rank;
        else
            stu[i].A_rank = i + 1;
    }

    sort(stu, stu + n, cmpC);
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && stu[i].C == stu[i - 1].C)
            stu[i].C_rank = stu[i - 1].C_rank;
        else
            stu[i].C_rank = i + 1;
    }

    sort(stu, stu + n, cmpM);
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && stu[i].M == stu[i - 1].M)
            stu[i].M_rank = stu[i - 1].M_rank;
        else
            stu[i].M_rank = i + 1;
    }

    sort(stu, stu + n, cmpE);
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && stu[i].E == stu[i - 1].E)
            stu[i].E_rank = stu[i - 1].E_rank;
        else
            stu[i].E_rank = i + 1;
    }

    int id;
    bool is_found = false;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &id);
        for (int j = 0; j < n; j++)
        {
            if (stu[j].id == id)
            {
                stu_print(stu[j]);
                is_found = true;
                break;
            }
        }
        if (!is_found)
        {
            printf("N/A\n");
        }
        is_found=false;
    }

    return 0;
}

//g++ a1012/*.cpp -o a.out && ./a.out

/*
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999

*/
