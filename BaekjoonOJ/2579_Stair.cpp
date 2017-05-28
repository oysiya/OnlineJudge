#include <stdio.h>
#define max(a,b) ((a>b)? a:b)


int main() {
	int a[301];
	int d[301][3];
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);

	d[1][1] = a[1];
	d[1][2] = 0;
	d[0][1] = 0;
	d[0][2] = 0;
	for(int i=2;i<=n;i++)
	{
		d[i][1] = max(d[i-2][1], d[i-2][2]) + a[i];
		d[i][2] = d[i-1][1] + a[i];
	}
	printf("%d", max(d[n][1], d[n][2]));
}