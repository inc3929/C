// 백준 9625
/*
고민한거:

- 동적할당 배열을 만들어야 하나?
- arr[i] = 'B';   arr[i + 1] = 'A'; 이런식으로 하면 반복문을 k번 돌리는데 k를 넘는다
- B일때 arr[i] = BA로 하면 안 원소에 알파벳 두개 들어가 밑에서 갯수 셀 때 못센다...
- strcmp를 써야하나? 문자열 비교?....

결론: 

다 필요없음 
ex) [4입력할때]
   A개수   B개수 
    1         0   A
    0         1   B
    1         1   BA
    1         2   BAB
    2         3   BABBA
를 보면  B가 그다음에 차례에 A의 개수가 되고 B는 A의 개수와 자기 자신을 더한게 다음 차례의 B가 된거를 볼 수 있음

*/




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
    int k;
    int n1 = 1, n2 = 0;
    int tmp;
    
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {

        tmp = n1;
        n1 = n2;
        n2 = tmp + n2;



    }

    printf("%d %d", n1, n2);

    return 0;
}
