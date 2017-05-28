#include <stdio.h>

int main() {
	int d[1001];
	d[0] = 0;
	d[1] = 1;
	d[2] = 2;
	int n;
	for(int i=3;i<=1000;i++)
		d[i] = (d[i-1] + d[i-2]) % 10007;
	scanf("%d", &n);
	printf("%d\n", d[n]);
}