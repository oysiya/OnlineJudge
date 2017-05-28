#include <stdio.h>

int ary[100001], d[100001];

int main(void) {
	setbuf(stdout, NULL);

	int T;
	int test_case;

	int s, e, ans;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		
		int n, o;
		scanf("%d %d", &n, &o);
		s = e = 1;
		ans = 2147483647;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &ary[i]);
			d[i] = d[i-1] + ary[i];
		}

		while (1) {
			if (d[e] - d[s - 1] >= o) {
				ans = (ans > e - s + 1) ? e - s + 1 : ans;
				if (s == n) break;
				s = s + 1;
			}
			else {
				if (e == n) break;
				e = e + 1;
			}
		}

		printf("#testcase%d\n", test_case);
		printf("%d\n", (ans == 2147483647) ? 0 : ans);

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}