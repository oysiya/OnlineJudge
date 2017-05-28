// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>

int n, array[1001][1001];
int check[1001][1001];

int main(void) {
	/* �Ʒ� freopen �Լ��� input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�
	�� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
	// freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;
	int ans = 0;
	char str[1001];
	
	int posx, posy, pos; // 0 from left 1 from top 2 from right 3 from bottom

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
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
			if (array[posx][posy] == 2) { // ��������
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
			else if (array[posx][posy] == 1) { // ������
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

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}