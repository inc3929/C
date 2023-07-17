#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
/*
예시에서 공백이 나오는 부분을 좌표로 생각해보면 (1,1) (4,1) (7,1) ~ (3,3) 등등 양쪽좌표가 모두 3으로 나눠서 확인
그리고 N을 3으로 또 나눠 계속 재귀적으로 확인 
*/
void star(int row, int col, int N) {
	if ((row / N) % 3 == 1 && (col / N) % 3 == 1) {
		printf(" ");
	}
	else {
		if (N / 3 == 0) {
			printf("*");
		}
		else {
			star(row, col, N / 3);
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			star(i, j, N);
		}
		printf("\n");
	}

	return 0;
}

//https://hou27.tistory.com/entry/BaekjoonC%EC%96%B8%EC%96%B4-2447%EB%B2%88-%EB%B3%84%EC%B0%8D%EA%B8%B0-10
//https://csloth.tistory.com/16 
// 2번째 사이트 그림 보면 잘이해됨 
