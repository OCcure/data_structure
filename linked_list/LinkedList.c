#include "LinkedList.h"
// create() : 노드 생성
Node* createNode(ElementType data) {

    Node* newNode = (Node*)malloc(sizeof(Node)); // 힙 영역에 노드 메모리 할당

    newNode -> data = data; // 노드에 데이터 저장
    newNode -> next = NULL; // 다음 노드 주소는 NULL로 초기화

    return newNode; // 생성된 노드 반환
}

// destroy() : 노드 소멸
void destroyNode(Node* node) {
    free(node); // 노드 메모리 해제
}

// append() : 노드 추가
void appendNode(Node** head, Node* newNode) {
    //헤드 노드가 NULL이면 새로운 노드를 헤드로 설정
    if ((*head) == NULL) {
        *head = newNode; // 헤드 노드에 새로운 노드 설정
    } else {
        Node* tail = (*head); // 현재 노드를 헤드로 초기화

        // 마지막 노드까지 이동
        while (tail->next != NULL) {
            tail = tail->next; // 다음 노드로 이동
        }

        tail->next = newNode; // 마지막 노드의 next에 새로운 노드 연결
    }
}

// insertAfter() : 노드 삽입
void insertNodeAfter(Node* current, Node* newNode) {
    newNode->next = current->next; // 새로운 노드의 next에 현재 노드의 next 설정
    current->next = newNode; // 현재 노드의 next에 새로운 노드 설정
}


// insertNewHead() : 노드 헤드에 삽입
void insertNodeNewHead(Node** head, Node* newHead) {
    if((*head) == NULL) {
        (*head) = newHead; // 헤드 노드가 NULL이면 새로운 노드를 헤드로 설정
    } else {
        newHead->next = (*head); // 새로운 노드의 next에 현재 헤드 노드 설정
        (*head) = newHead; // 새로운 노드를 헤드로 설정
    }
}

// remove() : 노드 삭제
void removeNode(Node** head, Node* target) {
    if ((*head) == target) {
        *head = target -> next; // 헤드 노드가 삭제할 노드인 경우 헤드 노드를 다음 노드로 설정
    } else {
        Node* current = *head; // 현재 노드를 헤드로 초기화

        while (current != NULL && current -> next != target) {
            current = current -> next; // 다음 노드로 이동
        }
        if (current != NULL) {
            current -> next = target -> next; // 현재 노드의 next에 삭제할 노드의 next 설정
        }
    }
}

// get() : 노드 탐색
Node* getNode(Node* head, int index) {
    Node* current = head; // 현재 노드를 헤드로 초기화
    int count = 0; // 인덱스 카운트

    while (current != NULL && --index >= 0) {
        current = current -> next; // 다음 노드로 이동
    }

    return current; // 찾은 노드 반환
}

// size() : 노드 개수 반환
int size(Node* head) {
    int count = 0;
    Node* current = head; // 현재 노드를 헤드로 초기화

    while (current != NULL) {
        count++; // 노드 개수 증가
        current = current -> next; // 다음 노드로 이동
    }
    return count; // 노드 개수 반환
}