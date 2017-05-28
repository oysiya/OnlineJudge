#include <stdio.h>
#define MAX 64
int array[MAX][MAX];
char result[100000];
int rp;

int is_all_same(int sx, int sy, int ex, int ey) {
	for(int i=sx;i<=ex;i++)
		for(int j=sy;j<=ey;j++)
		{
			if(array[i][j] != array[sx][sy])
				return 2;
		}
	return array[sx][sy];
}

void divide(int sx, int sy, int ex, int ey) {
	int ias = is_all_same(sx, sy, ex, ey);
	if(ias != 2) {
		result[rp++] = '0' + ias;
		return;
	}
	int mx, my;
	mx = (sx + ex) / 2;
	my = (sy + ey) / 2;
	result[rp++] = '(';
	divide(sx, sy, mx, my);
	divide(sx, my+1, mx, ey);
	divide(mx+1, sy, ex, my);
	divide(mx+1, my+1, ex, ey);
	result[rp++] = ')';
}

int main() {
	int N;
	char ar[MAX+1];
	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		scanf("%s", ar);
		for(int j=0;j<N;j++)
			array[i][j] = ar[j] - '0';
	}
	divide(0, 0, N-1, N-1);
	result[rp]='\0';
	printf("%s\n", result);
	return 0;
}
