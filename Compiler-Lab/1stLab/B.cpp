#include <bits/stdc++.h>
using namespace std;

bool isSpecialChar(char c)
{
    if (c >= 'a' and c <= 'z')
        return 0;
    else if (c >= 'A' and c <= 'Z')
        return 0;
    else if (c >= '0' and c <= '9')
        return 0;
    else if (c == '"')
        return 0;
    else
        return 1;
}

int main()
{
    FILE *ptr, *out;
    ptr = fopen("in.txt", "r");

    out = fopen("out.txt", "w"); 


    char ar[100001];

    while (fgets(ar, 100001, ptr))
    {
        for(int i=0;ar[i]!='\0'; i++)
        {
            if(isSpecialChar(ar[i])==0)
            {
                printf("%c", ar[i]); 
                fprintf(out, "%c", ar[i]); 
            }
            else 
            {
                if(ar[i]=='(')
                {
                    printf("\n"); 
                    fprintf(out, "\n");
                    while(ar[i]!=')')
                    {
                        printf("%c", ar[i]); 
                        fprintf(out, "%c", ar[i]); 
                        i++; 
                    }
                    printf("%c\n", ar[i]); 
                    fprintf(out, "%c\n", ar[i]); 
                }
                else 
                {
                    printf("\n%c\n", ar[i]); 
                    fprintf(out, "\n%c\n", ar[i]); 
                }
            }
        }
    }
}