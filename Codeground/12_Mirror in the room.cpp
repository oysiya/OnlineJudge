// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <stdio.h>

int n, array[1001][1001];
int check[1001][1001];

int main(void) {
	/* 아래 freopen 함수는 input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면
	그 아래에서 scanf 함수를 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
	// freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;
	int ans = 0;
	char str[1001];
	
	int posx, posy, pos; // 0 from left 1 from top 2 from right 3 from bottom

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			for (int j = 1; j <= n; j++) {
				array[i][j] = str[j - 1] - '0';
				check[i][j] = 0;
			}
		}

		posx = 1; posy = 0; pos = 0;

		do {
			switch (pos) {
			case 0:
				posy++;
				break;
			case 1:
				posx++;
				break;
			case 2:
				posy--;
				break;
			case 3:
				posx--;
				break;
			}
			if (!(0 < posx && posx <= n && 0 < posy && posy <= n)) break;
			if (array[posx][posy] == 2) { // 역슬래쉬
				switch (pos) {
				case 0:
					pos = 1;
					break;
				case 1:
					pos = 0;
					break;
				case 2:
					pos = 3;
					break;
				case 3:
					pos = 2;
					break;
				}
				check[posx][posy] = 1;
			}
			else if (array[posx][posy] == 1) { // 슬래쉬
				switch (pos) {
				case 0:
					pos = 3;
					break;
				case 1:
					pos = 2;
					break;
				case 2:
					pos = 1;
					break;
				case 3:
					pos = 0;
					break;
				}
				check[posx][posy] = 1;
			} 
		} while (1);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (check[i][j] == 1)
					ans++;
			}
		}

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}