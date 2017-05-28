#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int T, i,j,t, flag;
    scanf("%d", &T);
    for(i=1;i<=T;i++) {
        scanf("%s", s);
        t=0;
        flag = 1;
        for(j=0;j<strlen(s);j++)
            if(s[j] == '(')
                t++;
            else {
                t--;
                if(t<0) {
                    flag = 0;
                }
            }
        if(t == 0 && flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
        
    }
}