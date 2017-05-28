#include <stdio.h>
#include <queue>

using namespace std;

int group[1001];
int map[1001][1001];

queue<int> q;


int main(void) {
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {

		int n, l, a, b, ans = 1, c;
		scanf("%d %d", &n, &l);
		for (int i = 1; i <= n; i++) group[i] = -1;
		for (int i = 1; i <= l; i++) {
			scanf("%d %d", &a, &b);
			map[a][b] = map[b][a] = 1;
		}

		for (int i = 1; i <= n; i++) {
			if (group[i] == -1) {
				group[i] = 0;
				q.push(i);
				while (!q.empty()) {
					c = q.front();
					q.pop();
					for (int j = 1; j <= n; j++) {
						if (map[c][j] == 1) {
							if (group[j] != -1 && group[c] == group[j]) {
								ans = 0;
								while (!q.empty()) q.pop();
								break;
							}
							if (group[j] == -1) {
								map[c][j] = map[j][c] = 0;
								group[j] = !group[c];
								q.push(j);
							}
						}
					}
				}
			}
			if (ans == 0) break;
		}

		printf("Case #%d\n%d\n", test_case, ans);

	}

	return 0;
}