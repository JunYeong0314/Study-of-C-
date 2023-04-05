#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(1);
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            printf("%d", i);
            n /= i;
            if (n % i == 0) {
                printf("*");
            }
            else if (n % i != 0) {

            }
        }
    }
    return answer;
}

int main(void) {
    int n;
    scanf_s("%d", &n);

    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            if (n <= i) {
                printf("%d", i);
                break;
            }
            n /= i;
            printf("%d * ", i);
       }
    }
}