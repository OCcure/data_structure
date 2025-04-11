#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
    ElementType data;
    struct tagNode* next;
} Node;

//함수 원형 선언

// create() : 노드 생성
Node* createNode(ElementType data);

// destroy() : 노드 소멸
void destroyNode(Node* node);

// append() : 노드 추가
void appendNode(Node** head, Node* newNode);

// insert() : 노드 삽입
void insertNodeAfter(Node* current, Node* newNode);

//insertNewHead() : 노드 헤드에 삽입
void insertNodeNewHead(Node** head, Node* newNode);

//remove() : 노드 삭제
void removeNode(Node** head, Node* target);
//get() : 노드 탐색색
Node* getNode(Node* head, int index);

//size() : 노드 개수 반환
int size(Node* head);

#endif