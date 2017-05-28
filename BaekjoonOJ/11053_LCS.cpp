#include <stdio.h>
#define max(a,b) ((a>b)? a:b)

int a[1001], d[1001];

int main() {
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);

	int m;
	d[1] = 1;
	for(int i=2;i<=n;i++)
	{
		m = 1;
		for(int j=1;j<i;j++)
			if(d[j]+1 > m && a[i] > a[j])
				m = d[j]+1;
		d[i] = m;
	}
	m = 1;
	for(int i=1;i<=n;i++)
		if(m < d[i])
			m = d[i];
	printf("%d", m);
	return 0;
}