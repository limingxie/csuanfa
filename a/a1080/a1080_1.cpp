#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
    int GE,GI,sum;
    int id, rank;
    int cho[6];
}stu[40010];

struct School
{
    int qty;
    int stu_qty;
    int stu_id[40010];
    int lastStu;
}sc[110];

bool cmp(Student a, Student b)
{
    if (a.sum != b.sum)
        return a.sum > b.sum;
    else 
        return a.GE > b.GE;
}

bool cmpId(int a, int b)
{
    return stu[a].id < stu[b].id;
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    // School sc[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &sc[i].qty);
        sc[i].stu_qty = 0;
        sc[i].lastStu = -1;
    }
    
    // for (int i = 0; i < m; i++)
    // {
    //     printf("=0==%d %d %d\n", sc[i].qty, sc[i].stu_qty, sc[i].lastStu);        
    // }

    // Student stu[n];

    for (int i = 0; i < n; i++)
    {
        stu[i].id=i;
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
        if(i!=0 && stu[i].sum == stu[i-1].sum && stu[i].GE == stu[i-1].GE)
        {
            stu[i].rank = stu[i-1].rank;
        }
        else
        {
            stu[i].rank = i;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("====%d %d %d %d %d %d %d %d===\n",stu[i].rank , stu[i].id, stu[i].sum, stu[i].GE, stu[i].GI, stu[i].cho[0], stu[i].cho[1], stu[i].cho[2]);
    // }

    // for (int i = 0; i < m; i++)
    // {
    //     printf("=1==%d %d %d\n", sc[i].qty, sc[i].stu_qty, sc[i].lastStu);        
    // }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            
            int choice = stu[i].cho[j];

            // if (i == 7 && j == 2)
            // {
            //     printf("i == 7 && j == 2 [stu[i].rank]%d\n", stu[i].rank);
            //     printf("i == 7 && j == 2 [choice]%d {sc[choice].lastStu}%d\n", choice ,sc[choice].lastStu);
            //     printf("i == 7 && j == 2 [lastStu]%d {stu[sc[choice].lastStu].rank}%d {stu[i].rank}%d \n", sc[choice].lastStu, stu[sc[choice].lastStu].rank, stu[i].rank);
            // }

            if( (sc[choice].stu_qty < sc[choice].qty) || (sc[choice].lastStu!=-1 && stu[sc[choice].lastStu].rank == stu[i].rank ) )
            {
                // if (i == 6 || i == 7)
                // {
                //     printf("-----%d---%d--\n",i, j);
                //     printf("[stu_qty]%d [lastStu]%d\n", sc[choice].stu_qty, sc[choice].lastStu);
                //     printf("----------\n");
                // }
                sc[choice].stu_id[sc[choice].stu_qty] = i;
                sc[choice].lastStu = i;
                sc[choice].stu_qty++;
                break;
            }
        } 
    }

    // for (int i = 0; i < m; i++)
    // {
    //     printf("[%d]", i);        
    //     printf("===%d %d %d=== ", sc[i].qty, sc[i].stu_qty, sc[i].lastStu);     
    //     for (int j = 0; j < sc[i].stu_qty; j++)
    //     {
    //         printf("%d ", sc[i].stu_id[j]);
    //     }
    //     printf("\n");                       
    // }

    for (int i = 0; i < m; i++)
    {
        if (sc[i].stu_qty > 0)
        {
            sort(sc[i].stu_id, sc[i].stu_id + sc[i].stu_qty, cmpId);
            for (int j = 0; j < sc[i].stu_qty; j++)
            {
                printf("%d", stu[sc[i].stu_id[j]].id);
                if (j != sc[i].stu_qty -1)
                    printf(" ");
            }
        }
        printf("\n");        
    }
    
    return 0;
}

//g++ a1080/a1080_1.cpp -o a.out && ./a.out
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

5 5 3
0 0 0 5 5
100 100 0 1 2
100 99 1 2 0
99 100 2 1 0
99 99 1 0 2
98 98 2 0 1

*/