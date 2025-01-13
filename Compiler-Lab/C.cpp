#include <stdio.h>
#include <string.h>

int isSpecial(char c)
{
    if(c>='a' and c<='z') return 0; 
    if(c>='A' and c<='Z') return 0; 
    if(c>='0' and c<='9') return 0; 
    else return 1; 
}

int main()
{
    FILE *ptr, *out;

    ptr = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    char ar[100001];
    int newline = 0; 
    while (fgets(ar, 100001, ptr))
    {
        for (int i = 0; ar[i] != '\0'; i++)
        {
            if(isSpecial(ar[i])==0) 
            {
                fprintf(out, "%c", ar[i]); 
                newline  = 0; 
            }
            else 
            {
                if(ar[i]==' ' or ar[i]=='\n')
                {
                    if(newline==0)
                    {
                        fprintf(out, "\n"); 
                        newline = 1; 
                    }
                }
                else 
                {
                    if (newline==0)
                    {
                        fprintf(out, "\n%c\n", ar[i]); 
                        newline = 1; 
                    }
                    else 
                    {
                        fprintf(out, "%c\n", ar[i]); 
                        newline = 1;
                    }
                }
            }
        }
    }
}