#include <cstdio>

int change(char c)
{
    if (c == 'B')
        return 0;
    if (c == 'C')
        return 1;
    if (c == 'J')
        return 2;
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    char c1, c2;
    int k1, k2;

    int kk1[3] = {0};
    int kk2[3] = {0};

    int kkk1[3] = {0};
    int kkk2[3] = {0};

    char m[3] = {'B', 'C', 'J'};
    for (int i = 0; i < n; i++)
    {
        getchar();
        scanf("%c %c", &c1, &c2);
        k1 = change(c1);
        k2 = change(c2);
        if ((k1 + 1) % 3 == k2)
        {
            kk1[0]++;
            kk2[2]++;
            kkk1[k1]++;
        }
        else if (k1 == k2)
        {
            kk1[1]++;
            kk2[1]++;
        }
        else
        {
            kk1[2]++;
            kk2[0]++;
            kkk2[k2]++;
        }
    }
    int km1 = 0;
    int km2 = 0;
    int t1 = 0;
    int t2 = 0;

    for (int i = 0; i < 3; i++)
    {
        if (kkk1[i] > t1)
        {
            t1 = kkk1[i];
            km1 = i;
        }

        if (kkk2[i] > kkk2[0])
        {
            t2 = kkk2[i];
            km2 = i;
        }
    }

    printf("%d %d %d\n", kk1[0], kk1[1], kk1[2]);
    printf("%d %d %d\n", kk2[0], kk2[1], kk2[2]);
    printf("%c %c", m[km1], m[km2]);
}

//g++ b1018/*.cpp -o 3.out && ./3.out