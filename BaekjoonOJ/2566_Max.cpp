#include <stdio.h>

int main()
{
    int i,j,n,v=-1,vi, vj;
    for(i=1;i<=9;i++)
        for(j=1;j<=9;j++) {
        	scanf("%d", &n);
        	if(n > v)
            {
                v = n;
                vi = i;
                vj = j;
            }
    	}
   
    printf("%d\n%d %d", v, vi, vj);
    return 0;

}