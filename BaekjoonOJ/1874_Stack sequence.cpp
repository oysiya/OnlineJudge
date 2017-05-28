#include <stdio.h>

int stack[100000];
char result[5000000];
int main() {
    int cnt=1,top=0, rtop=0 ,n,m,i, flag=0;
    scanf("%d", &n);
    scanf("%d", &m);
    for(i=1;i<=m;i++) {
        stack[top++] = i;
        result[rtop++] = '+';
    }
    top--;
    cnt = m+1;
    result[rtop++] = '-';
    for(i=2;i<=n;i++) {
        scanf("%d", &m);
        if(m == stack[top-1])
        {
            result[rtop++] = '-';
            top--;
            continue;
        }
        if(m < stack[top-1])
        {
            printf("NO");
            flag = 1;
            break;
        }
        for(;cnt<=m;cnt++) {
            stack[top++] = cnt;
            result[rtop++] = '+';
        }
        result[rtop++] = '-';
        top--;
    }
    if(flag == 0)
        for(i=0;i<rtop;i++)
            printf("%c\n", result[i]);
    
}