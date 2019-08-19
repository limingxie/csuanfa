#include <cstdio>
#include <cstring>

struct node
{
    char name[20], password[20];
    bool ischanged;
} t[1010];

void change_password(node &t, int &cnt)
{
    int slen = strlen(t.password);
    for (int i = 0; i < slen; i++)
    {
        if (t.password[i] == '1')
        {
            t.password[i] = '@';
            t.ischanged = true;
        }
        else if (t.password[i] == '0')
        {
            t.password[i] = '%';
            t.ischanged = true;
        }
        else if (t.password[i] == 'l')
        {
            t.password[i] = 'L';
            t.ischanged = true;
        }
        else if (t.password[i] == 'O')
        {
            t.password[i] = 'o';
            t.ischanged = true;
        }
    }

    if (t.ischanged)
    {
        cnt++;
    }
}

int main()
{

    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", t[i].name, t[i].password);
        t[i].ischanged = false;
        change_password(t[i], cnt);
    }

    if (cnt == 0)
    {
        if (n == 1)
        {
            printf("There is %d account and no account is modified\n", n);
        }
        else
        {
            printf("There are %d accounts and no account is modified\n", n);
        }
    }
    else
    {
        printf("%d\n", cnt);

        for (int i = 0; i < n; i++)
        {
            if (t[i].ischanged)
            {
                printf("%s %s\n", t[i].name, t[i].password);
            }
        }
    }

    return 0;
}

//g++ a1035/*.cpp -o a.out && ./a.out