#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
    char name[20];
    char no[20];
    int score;
};

bool cmp(Student a, Student b)
{
    return a.score > b.score;
}

int main()
{
    int n;
    scanf("%d", &n);

    Student stu[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d", stu[i].name, stu[i].no, &stu[i].score);
    }

    int l, r;
    scanf("%d %d", &l, &r);


    sort(stu, stu + n, cmp);

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if(stu[i].score >= l && stu[i].score <= r)
        {
            printf("%s %s\n", stu[i].name, stu[i].no);
            j++;
        }
    }
    
    if (j == 0)
    {
        printf("NONE\n");
    }

    return 0;
}

//g++ a1083/*.cpp -o a.out && ./a.out
/*
4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100

*/