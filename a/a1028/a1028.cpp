#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
    int id;
    char name[10];
    int score;
} stu[100010];

bool cmp1(Student s1, Student s2)
{
    return s1.id < s2.id;
}

bool cmp2(Student s1, Student s2)
{
    if (strcmp(s1.name, s2.name) != 0 )
    {
        return strcmp(s1.name, s2.name) < 0;
    }
    else
    {
        return s1.id < s2.id;
    }
}

bool cmp3(Student s1, Student s2)
{
    if (s1.score != s2.score )
    {
        return s1.score < s2.score;
    }
    else
    {
        return s1.id < s2.id;
    }
}

int main()
{
    int n, c;
    scanf("%d %d", &n, &c);
    

    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].score);
    }
    
    if (c == 1)
    {
        sort(stu, stu + n, cmp1);
    }
    else if(c==2)
    {
        sort(stu, stu + n, cmp2);
    }
    else
    {
        sort(stu, stu + n, cmp3);
    }

    for (size_t i = 0; i < n; i++)
    {
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
    }


    return 0;
}

//g++ a1028/*.cpp -o a.out && ./a.out