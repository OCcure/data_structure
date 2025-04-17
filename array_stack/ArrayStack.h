#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType; // 스택에 저장할 데이터 타입을 int로 정의

typedef struct tagNode {
    ElementType data; // 데이터
} Node;

typedef struct tagArrayStack {
    int capacity; // 스택의 용량
    int top; // 스택의 최상단 인덱스
    Node* nodes; // 스택의 노드 배열
} ArrayStack;

void createStack(ArrayStack** stack, int capacity); // 스택 생성
void destroyStack(ArrayStack* stack); // 스택 소멸
void push(ArrayStack* stack, ElementType data); // 스택에 데이터 추가
ElementType pop(ArrayStack* stack); // 스택에서 데이터 제거
ElementType getTop(ArrayStack* stack); // 스택의 최상단 데이터 반환
int getSize(ArrayStack* stack); // 스택의 크기 반환
int isEmpty(ArrayStack* stack); // 스택이 비어있는지 확인

#endif