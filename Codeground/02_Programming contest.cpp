#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int ary[300000];

int main(void) {
	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		int n, i;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &ary[i]);
		}
		sort(ary, ary + n, greater<int>());
		ary[0]++;
		for (i = 1; i < n; i++) {
			ary[i] += i + 1;
			if (ary[i] < ary[i - 1])
				break;
		}
		printf("Case #%d\n", test_case);
		printf("%d\n", i);

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}