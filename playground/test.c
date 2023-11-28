#include <ctype.h>
#include <stdio.h>

int main() {
    int choice, a, b, result;
    char cont;
    double divResult;

    do {
        printf("===================\n");
        printf("1. 더하기\n");
        printf("2. 빼기\n");
        printf("3. 곱하기\n");
        printf("4. 나누기\n");
        printf("5. 나머지\n");
        printf("===================\n");
        printf("원하는 연산을 선택하세요: ");
        scanf("%d", &choice);

        printf("숫자 두 개를 입력하세요: ");
        scanf("%d %d", &a, &b);

        switch (choice) {
            case 1:
                result = a + b;
                printf("%d + %d = %d\n", a, b, result);
                break;
            case 2:
                result = a - b;
                printf("%d - %d = %d\n", a, b, result);
                break;
            case 3:
                result = a * b;
                printf("%d * %d = %d\n", a, b, result);
                break;
            case 4:
                if (b != 0) {
                    divResult = (double)a / b;
                    printf("%d / %d = %.3f\n", a, b, divResult);
                } else {
                    printf("0으로 나눌 수 없습니다.\n");
                }
                break;
            case 5:
                result = a % b;
                printf("%d %% %d = %d\n", a, b, result);
                break;
            default:
                printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }

        printf("연산을 계속하시겠습니까?(Y/N) ");
        scanf(" %c", &cont);
        cont = tolower(cont);

    } while (cont == 'y');

    return 0;
}
