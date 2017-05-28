#include <stdio.h>

int main() {
	int a[10], b[10], score=0, flag=0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 9; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < 9; i++) {
		score += a[i];
		if (score > 0)
			flag = 1;
		score -= b[i];
	}
	if (flag == 1)
		printf("YES");
	else
		printf("NO");
}