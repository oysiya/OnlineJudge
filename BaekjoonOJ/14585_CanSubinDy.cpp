#include <stdio.h>
#define max(a,b) ((a>b)?a:b)

int n, m, ary[301][301], d[301][301], x, y, ans;

int main() {
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		ary[x][y] = max(m - x - y, 0);
	}

	for (int i = 0; i <= 300; i++) {
		for (int j = 0; j <= 300; j++) {
			if (i == 0) d[i][j] = d[i][j - 1] + ary[i][j];
			if (j == 0) d[i][j] = d[i - 1][j] + ary[i][j];
			if (i != 0 && j != 0) {
				d[i][j] = max(d[i - 1][j], d[i][j - 1]) + ary[i][j];
			}
			if (ans < d[i][j]) ans = d[i][j];
		}
	}
	printf("%d", ans);

	return 0;
}