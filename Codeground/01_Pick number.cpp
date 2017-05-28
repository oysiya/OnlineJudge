#include <stdio.h>

int main(void) {

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		int n, ans = 0, x;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x);
			ans ^= x;
		}
		printf("Case #%d\n%d\n", test_case, ans);

	}

	return 0;	
}