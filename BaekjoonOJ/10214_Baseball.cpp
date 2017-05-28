#include <stdio.h>

int main() {
    int C,k,y,a,b;
    scanf("%d",&C);
    for(int i=1;i<=C;i++) {
        k=y=0;
        for(int j=1;j<=9;j++) {
            scanf("%d %d",&a,&b);
            if(a>b)
                y++;
            else if(a<b)
                k++;
        }
        if(y==k)
            printf("Draw\n");
        else if(y>k)
            printf("Yonsei\n");
        else
            printf("Korea\n");
    }
}