#include <stdio.h>

int ary[10];
int d[9];
int check[10];
int n;

int first_com[10];
int last_com[10];
bool first = false;

bool validate() {
    bool result = true;
    for(int i=0;i<n;i++)
    {
        if(d[i] == 0)
            result = result & (ary[i] > ary[i+1]);
        else
            result = result & (ary[i] < ary[i+1]);
    }
    return result;
}

void back(int pos) {
    if(pos == n+1)
    {
        if(validate()) {
            if(!first) {
                for(int i=0;i<=n;i++)
                    first_com[i] = ary[i];
                first = true;
            }
            for(int i=0;i<=n;i++)
                last_com[i] = ary[i];
        }
        return;
    } else {
        for(int i=0;i<=9;i++)
            if(check[i] == 0) {
                check[i] = 1;
                ary[pos] = i;
                back(pos+1);
                check[i] = 0;
            }
    }
}

int main() {
    scanf("%d", &n);
    char s;
    for(int i=0;i<n;i++)
    {
        while(1) {
            scanf("%c", &s);
            if(s != '>' && s != '<')
                continue;
            else
                break;
        }
        if(s=='>')
            d[i] = 0;
        else
            d[i] = 1;
    }
    back(0);
    for(int i=0;i<=n;i++)
        printf("%d", last_com[i]);
    printf("\n");
    for(int i=0;i<=n;i++)
        printf("%d", first_com[i]);
    printf("\n");
    return 0;
}
