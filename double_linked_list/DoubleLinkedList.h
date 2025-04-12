#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType; // 데이터 타입 정의

typedef struct tagNode {
    ElementType data; // 데이터
    struct tagNode* next; // 다음 노드 포인터
    struct tagNode* prev; // 이전 노드 포인터
} Node;

//함수 원형 선언

Node* createNode(ElementType data); // 노드 생성
void destroyNode(Node* node); // 노드 소멸
void appendNode(Node** head, Node* newNode); // 노드 추가
void insertNodeAfter(Node* current, Node* newNode); // 노드 삽입
void removeNode(Node** head, Node* target); // 노드 삭제
Node* getNode(Node* head, int index); // 노드 탐색
int size(Node* head);// 노드 개수 반환
void printNode(Node* node); // 노드 출력
void printReverse(Node* node);// 노드 역순 출력

#endif