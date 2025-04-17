#include "ArrayStack.h"

void createStack(ArrayStack** stack, int capacity) {
    //스택을 자유 저장소에 생성
    *stack = (ArrayStack*)malloc(sizeof(ArrayStack)); // 스택 메모리 할당
    //입력된 capacity만큼의 노드를 자유 저장소에 생성성
    (*stack)->nodes = (Node*)malloc(sizeof(Node)*capacity);

    //capacity및 top 초기화
    (*stack)->capacity = capacity; 
    (*stack)->top = -1; 
}

void destroyStack(ArrayStack* stack) {
    free(stack->nodes); // 노드를 자유 저장소에서 해제
    free(stack); // 스택을 자유 저장소에서 해제
}

void push(ArrayStack* stack, ElementType data) {
    stack -> top++;// 스택의 top을 증가시킴
    stack -> nodes[stack -> top].data = data; // 스택의 최상단에 데이터 추가
}

ElementType pop(ArrayStack* stack) {
    int position = stack -> top--; // 스택의 top을 감소시킴
    return stack -> nodes[position].data; // 스택의 최상단 데이터 반환
}

ElementType getTop(ArrayStack* stack) {
    return stack -> nodes[stack -> top].data; // 스택의 최상단 데이터 반환
}

int getSize(ArrayStack* stack) {
    return stack -> top + 1; // 스택의 크기 반환
}

int isEmpty(ArrayStack* stack) {
    return stack -> top == -1; // 스택이 비어있는지 확인
}