#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> ary[32001];

queue<int> q;

int indegree[32001];


int main(int argc, const char * argv[]) {
    
    int n,m;
    scanf("%d %d", &n, &m);
    int a,b;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d", &a, &b);
        ary[a].push_back(b);
        indegree[b]++;
    }
    
    for(int i=1;i<=n;i++)
        if(indegree[i] == 0)
            q.push(i);
    int t;
    while(!q.empty()) {
        t = q.front(); q.pop();
        printf("%d ", t);
        for(int i=0;i<ary[t].size();i++)
        {
            indegree[ary[t][i]]--;
            if(indegree[ary[t][i]] == 0) {
                q.push(ary[t][i]);
                indegree[ary[t][i]]--;
            }
        }
    }
    
    return 0;
}
