#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> ary[1001];

queue<int> q;

int indegree[1001], price[1001];
int minv[1001];


int main(int argc, const char * argv[]) {
    int T;
    scanf("%d", &T);
    for(int ca=1;ca<=T;ca++) {
        for(int i=0;i<=1000;i++) {
            minv[i] = -1;
            indegree[i] = 0;
            price[i] = 0;
            ary[i].clear();
        }
        int n,m;
        scanf("%d %d", &n, &m);
        int a,b;
        for(int i=1;i<=n;i++)
            scanf("%d", &price[i]);
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d", &a, &b);
            ary[a].push_back(b);
            indegree[b]++;
        }
        
        for(int i=1;i<=n;i++)
            if(indegree[i] == 0) {
                minv[i] = price[i];
                q.push(i);
            }
        int t;
        while(!q.empty()) {
            t = q.front(); q.pop();
            for(int i=0;i<ary[t].size();i++)
            {
                indegree[ary[t][i]]--;
                if(minv[ary[t][i]] < minv[t] + price[ary[t][i]])
                    minv[ary[t][i]] = minv[t] + price[ary[t][i]];
                if(indegree[ary[t][i]] == 0) {
                    q.push(ary[t][i]);
                    indegree[ary[t][i]]--;
                }
            }
        }
        int ans;
        scanf("%d", &ans);
        printf("%d\n", minv[ans]);
        

    }
        return 0;
}
