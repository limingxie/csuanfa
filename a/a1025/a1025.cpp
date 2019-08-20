#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
    char id[15];
    int score;
    int no;
    int rank;
} stu[30010];

bool cmp(Student s1, Student s2)
{
    if (s1.score != s2.score)
    {
        return s1.score > s2.score;
    }
    else
    {
        return strcmp(s1.id, s2.id) < 0;
    }
}
int main()
{
    int n, k, s_num = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%s %d", stu[s_num].id, &stu[s_num].score);
            stu[s_num].no = i;
            s_num++;
        }
        sort(stu + s_num - k, stu + s_num, cmp);
        stu[s_num - k].rank = 1;
        for (int j = s_num - k + 1; j < s_num; j++)
        {
            if (stu[j].score == stu[j - 1].score)
            {
                stu[j].rank = stu[j - 1].rank;
            }
            else
            {
                stu[j].rank = j + 1 - s_num + k;
            }
        }
    }
    printf("%d\n", s_num);
    sort(stu, stu + s_num, cmp);
    int r = 1;
    for (int i = 0; i < s_num; i++)
    {
        if (i > 0 && stu[i].score != stu[i - 1].score)
        {
            r = i + 1;
        }
        printf("%s ", stu[i].id);
        printf("%d %d %d\n", r, stu[i].no, stu[i].rank);
    }

    return 0;
}

//g++ a1025/*.cpp -o a.out && ./a.out