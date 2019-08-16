#include <cstdio>
#include <cstring>

int main()
{
    char s[10010];
    scanf("%s", s);
    int pos = 0;

    int slen = strlen(s);

    if (s[0] == '-')
    {
        printf("-");
    }

    for (pos = pos + 0; pos < slen; pos++)
    {
        if( s[pos] == 'E')
        {
            break;
        }
    }
  
    int exp = 0;
    for (int i = pos + 2; i < slen; i++)
    {
        exp = exp * 10 + (s[i] - '0');
    }

    if (exp == 0)
    {
        for (int i = 1; i < pos; i++)
        {
            printf("%c", s[i]);
        } 
    }

    if (s[pos + 1] == '-'){
        printf("0.");
        for (int i = 0; i < exp - 1; i++)
        {
            printf("0");
        }
        printf("%c", s[1]);
        for (int i = 3; i < pos; i++)
        {
            printf("%c", s[i]);
        }
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            if (s[i] == '.') continue;
            printf("%c", s[i]);
            if(i == exp + 2 && pos -3 != exp)
            {
                printf(".");
            }
        }

        for (int i = 0; i < exp - (pos - 3); i++)
        {
            printf("0");
        }
        
    }
    

    printf("\n");
    return 0;
}

//g++ a1073/*.cpp -o a.out && ./a.out