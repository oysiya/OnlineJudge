#include <stdio.h>
#include <string.h>

char str1[10010];
char str2[10010];

int main() {
    scanf("%s %s", str1, str2);
    long long int sum = 0;
    for(int i=0;i<strlen(str1);i++) {
        for(int j=0;j<strlen(str2);j++)
            sum += (str1[i]-'0')*(str2[j]-'0');
    }
    printf("%lld", sum);
    return 0;
}