#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    char str1[100], str2[100];
    cin >> str1 >> str2;

    bool HashTable[128] = {false};
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (int i = 0; i < len1; i++)
    {
        int j = 0;
        for (j = 0; j < len2; j++)
        {
            if (str1[i] >= 'a' && str1[i] <= 'z') str1[i] -= 32;
            if (str2[j] >= 'a' && str2[j] <= 'z') str2[j] -= 32;
            if (str1[i] == str2[j]) break;
        }
        if (j == len2 && HashTable[str1[i]] == false)
        {
            printf("%c", str1[i]);
            HashTable[str1[i]] = true;
        }
    }

    return 0;
}

//g++ a1084/*.cpp -o a.out && ./a.out
/*
7_This_is_a_test
_hs_s_a_es
*/