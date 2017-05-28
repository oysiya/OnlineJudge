#include <stdio.h>

int main(int argc, char *argv[])
{
	int C,a,b,t,i;

	scanf("%d", &C);

	for(int c=0;c<C;c++) {

		scanf("%d %d",&a,&b);
		
		t = a%10;

		for(i=1;i<b;i++) {
			t *= a;
			t %= 10;
		}

		printf("%d\n",((t==0)?10:t));

	}
	return 0;
}
