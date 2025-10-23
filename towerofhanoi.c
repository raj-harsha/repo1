#include <stdio.h>
#include <stdlib.h>

void toh(int n, char s, char t, char d)
{
    if (n>1)
    {
        toh(n-1,s,t,d);
        printf("\n move %d disc form %c to %c",n,s,d);
        toh(n-1,t,d,s);
    }
    else
        printf("\n move %d disk from %c to %c",n,s,d);
}
int main()
{
    int n;
    printf("\n read number of discs:");
    scanf("%d",&n);
    toh(n, 's', 'd', 't');
    return 0;
}
