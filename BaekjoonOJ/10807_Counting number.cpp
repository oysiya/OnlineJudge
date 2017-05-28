#include <stdio.h>

int main() {
    int n, v, a[100], i, c=0;
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    scanf("%d", &v);
    for(i=0;i<n;i++)
        if(a[i]==v) c++;
    printf("%d",c);
}