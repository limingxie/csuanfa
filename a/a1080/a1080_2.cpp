#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
    int GE,GI,sum;
    int stu_id, rank;
    int cho[6];
}stu[40010];

struct School
{
    int quota;
    int stuNum;
    int id[40010];
    int lastAdmit;
}sch[110];

bool cmp(Student a, Student b)
{
    if (a.sum != b.sum)
        return a.sum > b.sum;
    else 
        return a.GE > b.GE;
}

bool cmpId(int a, int b)
{
    return stu[a].stu_id < stu[b].stu_id;
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    // School sch[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &sch[i].quota);
        sch[i].stuNum = 0;
        sch[i].lastAdmit = -1;
    }

    // Student stu[n];

    for (int i = 0; i < n; i++)
    {
        stu[i].stu_id=i;
        scanf("%d %d", &stu[i].GE, &stu[i].GI);
        stu[i].sum = stu[i].GE + stu[i].GI;
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &stu[i].cho[j]);
        }
    }

    sort(stu, stu + n, cmp);

    for (int i = 0; i < n; i++)
    {
        if(i > 0 && stu[i].sum == stu[i - 1].sum && stu[i].GE == stu[i-1].GE)
        {
            stu[i].rank = stu[i-1].rank;
        }
        else
        {
            stu[i].rank = i;
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        printf("====%d %d %d %d %d %d %d %d===\n", stu[i].rank , stu[i].stu_id, stu[i].sum, stu[i].GE, stu[i].GI, stu[i].cho[0], stu[i].cho[1], stu[i].cho[2]);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int choice = stu[i].cho[j];
            int num = sch[choice].stuNum;
            int last = sch[choice].lastAdmit;
            if( (num < sch[choice].quota) || (last !=-1 && stu[i].rank == stu[last].rank) )
            {
                sch[choice].id[num] = i;
                sch[choice].lastAdmit = i;
                sch[choice].stuNum++;
                break;
            }
        } 
    }

    for (int i = 0; i < m; i++)
    {
        printf("[%d]", i);        
        printf("===%d %d %d=== ", sch[i].quota, sch[i].stuNum, sch[i].lastAdmit);     
        for (int j = 0; j < sch[i].stuNum; j++)
        {
            printf("%d ", sch[i].id[j]);
        }
        printf("\n");                       
    }

    for (int i = 0; i < m; i++)
    {
        if (sch[i].stuNum > 0)
        {
            sort(sch[i].id, sch[i].id + sch[i].stuNum, cmpId);
            for (int j = 0; j < sch[i].stuNum; j++)
            {
                printf("%d", stu[sch[i].id[j]].stu_id);
                if (j != sch[i].stuNum -1)
                    printf(" ");
            }
        }
        printf("\n");        
    }
    
    return 0;
}

//g++ a1080/a1080_2.cpp -o a.out && ./a.out
/*
11 6 3
2 1 2 2 2 3
100 100 0 1 2
100 90 0 3 4
80 80 0 1 2
90 100 1 2 0
80 90 1 0 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
60 60 2 3 5
90 90 5 1 3

0 8
3
2 4 5
1 6

9 10

5 5 3
0 0 0 5 5
100 100 0 1 2
100 99 1 2 0
99 100 2 1 0
99 99 1 0 2
98 98 2 0 1

*/