#include "ArrayStack.h"
#include "ArrayStack.c"

int main() {

    int i =0;
    ArrayStack* stack = NULL; // 스택 포인터 초기화

    createStack(&stack, 10); // 스택 생성, 용량 10
    
    // 스택에 데이터 추가
    push(stack, 3); 
    push(stack, 37); 
    push(stack, 11); 
    push(stack, 12); 

    //입력 순서 3 >> 37 >> 11 >> 12

    printf("Capacity: %d, Size: %d, Top: %d\n\n", stack -> capacity, getSize(stack), getTop(stack)); // 스택의 용량, 크기, 최상단 데이터 출력

    for ( i=0; i<4; i++) {
        if (isEmpty(stack)) {
            break;
        }

        printf("Pop: %d, ", pop(stack)); // 스택에서 데이터 제거 및 출력

        if (!isEmpty(stack)) {
            printf("Current Top: %d\n", getTop(stack)); // 스택의 최상단 데이터 출력
        } else {
            printf("Stack is empty\n"); // 스택이 비어있을 경우
        }
    }

    destroyStack(stack); // 스택 소멸

    return 0; // 프로그램 종료
}