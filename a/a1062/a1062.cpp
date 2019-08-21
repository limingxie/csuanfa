#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
    char id[15];
    int de, cai, sum;
    int lei;
} stu[100010];

bool cmp(Student s1, Student s2)
{
    if (s1.lei != s2.lei)
    {
        return s1.lei < s2.lei;
    }
    else if (s1.sum != s2.sum)
    {
        return s1.sum > s2.sum;
    }
    else if (s1.de != s2.de)
    {
        return s1.de > s2.de;
    }
    else
    {
        return strcmp(s1.id, s2.id) < 0;
    }
}
int main()
{
    int n, L, H, m;
    scanf("%d %d %d", &n, &L, &H);

    m = n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", stu[i].id, &stu[i].de, &stu[i].cai);
        stu[i].sum = stu[i].de + stu[i].cai;
        if (stu[i].de < L || stu[i].cai < L)
        {
            stu[i].lei = 5;
            m--;
        }
        else if (stu[i].de >= H && stu[i].cai >= H)
        {
            stu[i].lei = 1;
        }
        else if (stu[i].de >= H && stu[i].cai < H && stu[i].cai >= L)
        {
            stu[i].lei = 2;
        }
        else if (stu[i].de < H && stu[i].cai < H && stu[i].de >= stu[i].cai)
        {
            stu[i].lei = 3;
        }
        else
        {
            stu[i].lei = 4;
        }
    }
    sort(stu, stu + n, cmp);
    printf("%d\n", m);
    for (int i = 0; i < n; i++)
    {
        if (stu[i].lei != 5)
        {
            printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
        }
    }

    return 0;
}

//g++ a1012/*.cpp -o a.out && ./a.out