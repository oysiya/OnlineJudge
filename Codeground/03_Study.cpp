// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <stdio.h>
#include <algorithm>

using namespace std;

int ary[200000];

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

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		int n, k, ans=0;
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%d", &ary[i]);
		}
		sort(ary, ary + n);
		for (int i = n - 1; i >= n - k; i--) {
			ans += ary[i];
		}

		printf("Case #%d\n%d\n", test_case, ans);

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}