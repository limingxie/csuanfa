#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
    int id;
    int score[6];
    int score_all;
    int solve_count;
    bool flag;
};

bool cmp(Student a, Student b)
{
    if (a.score_all != b.score_all)
        return a.score_all > b.score_all;
    else if (a.solve_count != b.solve_count)
        return a.solve_count > b.solve_count;
    else
        return a.id < b.id;
}

int main()
{
    int n, k, l;
    scanf("%d %d %d", &n, &k, &l);

    Student stu[n];

    for (int i = 0; i < n; i++)
    {
        stu[i].id = i + 1;
        stu[i].score_all = 0;
        stu[i].solve_count = 0;
        stu[i].flag = false;
        for (int j = 0; j < k; j++)
        {
            stu[i].score[j] = -2;
        }
    }

    int full[k + 1];

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &full[i]);
    }

    int id, subject, score;
    for (int i = 0; i < l; i++)
    {
        scanf("%d %d %d", &id, &subject, &score);
        if (score != -1)
        {
            stu[id - 1].flag = true;
            if (score > stu[id - 1].score[subject - 1])
            {
                if (stu[id - 1].score[subject - 1] != -2)
                {
                    stu[id - 1].score_all = stu[id - 1].score_all - stu[id - 1].score[subject - 1];
                }

                stu[id - 1].score[subject - 1] = score;
                stu[id - 1].score_all += score;

                if (score == full[subject - 1])
                    stu[id - 1].solve_count++;
            }
        }

        else if (score == -1 && stu[id - 1].score[subject - 1] == -2)
        {
            stu[id - 1].score[subject - 1] = 0;
        }
    }

    sort(stu, stu + n, cmp);

    int rank = 1;
    for (int i = 0; i < n; i++)
    {
        if (stu[i].flag == false)
            continue;
        if (i != 0 && stu[i].score_all != stu[i - 1].score_all)
            rank = i + 1;

        printf("%d %05d %d ", rank, stu[i].id, stu[i].score_all);

        for (int j = 0; j < k; j++)
        {
            if (stu[i].score[j] == -2)
                printf("-");
            else if (stu[i].score[j] == -1)
                printf("0");
            else
                printf("%d", stu[i].score[j]);
            if (j == k - 1)
                printf("\n");
            else
                printf(" ");
        }
    }

    return 0;
}

//g++ a1075/*.cpp -o a.out && ./a.out
/*
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0


4 3 8
20 30 40
00001 1 15
00001 3 20
00002 2 0
00002 3 0
00003 1 20
00003 2 15
00004 1 -1
00004 3 -1

*/