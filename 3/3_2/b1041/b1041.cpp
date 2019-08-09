#include <cstdio>

struct student
{
    char name[101];
    char no[101];
    int cc;
} s[111];

int main()
{
    int n = 0;
    scanf("%d", &n);

    int max = 0, min = 0;
    char a[101], b[101];
    int c;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d", s[i].name, s[i].no, &s[i].cc);
        if (s[max].cc < s[i].cc)
            max = i;
        if (s[min].cc > s[i].cc)
            min = i;
    }

    printf("%s %s\n", s[max].name, s[max].no);
    printf("%s %s", s[min].name, s[min].no);
}

//g++ b1041/*.cpp -o 3_2.out && ./3_2.out