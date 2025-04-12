#include "CircularDoublyLinkedList.h"

//노드생성
Node* createNode(ElementType data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // 힙 영역에 노드 메모리 할당

    newNode -> data = data; // 노드에 데이터 저장
    newNode -> next = NULL; // 다음 노드 주소는 NULL로 초기화
    newNode -> prev = NULL; // 이전 노드 주소는 NULL로 초기화

    return newNode; // 생성된 노드 반환
}

//노드 소멸
void destroyNode(Node* node) {
    free(node); // 노드 메모리 해제
}

//노드 추가
void appendNode(Node** head, Node* newNode) {
    //헤드 노드가 NULL이면 새로운 노드를 헤드로 설정
    if ((*head) == NULL) {
        *head = newNode; // 헤드 노드에 새로운 노드 설정
        (*head) -> next = *head; // 헤드 노드의 next를 헤드로 설정
        (*head) -> prev = *head; // 헤드 노드의 prev를 헤드로 설정
    } else {
        Node* tail = (*head) -> prev ; // 테일과 헤드 사이에 newNode를 추가가

        tail -> next -> prev = newNode; // 테일 노드의 next에 새로운 노드 설정
        tail -> next = newNode; // 테일 노드의 next에 새로운 노드 설정

        newNode -> next = (*head); // 새로운 노드의 next에 헤드 노드 설정
        newNode -> prev = tail; // 새로운 노드의 prev에 테일 노드 설정
    }
}

//노드 삽입
void insertNodeAfter(Node* current, Node* newNode) {
    newNode -> next = current->next; // 새로운 노드의 next에 현재 노드의 next 설정
    newNode -> prev = current; // 새로운 노드의 prev에 현재 노드 설정

    if (current -> next != NULL) { // 다음 노드가 NULL이 아닌 경우
        current -> next -> prev = newNode; // 다음 노드의 prev에 새로운 노드 설정
        current -> next = newNode; // 현재 노드의 next에 새로운 노드 설정
    }
}

//노드 제거
void removeNode(Node** head, Node* target) {
    if ((*head) == target) {
        (*head) -> prev -> next = target -> next; // 헤드 노드가 삭제할 노드인 경우 헤드 노드를 다음 노드로 설정
        (*head) -> next -> prev = target -> prev; // 헤드 노드의 next에 삭제할 노드의 prev 설정

        *head = target -> next; // 헤드 노드를 삭제할 노드의 다음 노드로 설정

        target -> next = NULL; // 삭제할 노드의 next를 NULL로 설정
        target -> prev = NULL; // 삭제할 노드의 prev를 NULL로 설정

    } else {
        target -> prev -> next = target -> next; // 삭제할 노드의 prev의 next에 삭제할 노드의 next 설정
        target -> next -> prev = target -> prev; // 삭제할 노드의 next의 prev에 삭제할 노드의 prev 설정

        target -> next = NULL; // 삭제할 노드의 next를 NULL로 설정
        target -> prev = NULL; // 삭제할 노드의 prev를 NULL로 설정
    }
}

//노드 탐색
Node* getNode(Node* head, int index) {
    Node* current = head; // 현재 노드를 헤드로 설정

    while (current != NULL && --index >= 0) { //헤드 노드에서 부터 인덱스를 감소 시키며 0보다 크거나 같을때 까지 반복
        current = current -> next; // 다음 노드로 이동
    }

    return current; // 찾은 노드 반환
}

//노드 개수 반환
int size(Node* head) {
    unsigned int count = 0; // 노드 개수 카운트
    Node* current = head; // 현재 노드를 헤드로 설정

    while (current != NULL) {
        current = current -> next; // 다음 노드로 이동
        count++; // 노드 개수 증가
        if (current == head) {
            break; // 반복문 종료
        }
    }
    return count; // 노드 개수 반환
}

//노드 출력
void printNode(Node* node) {
    if (node -> prev == NULL) {
        printf("Prev : NULL, "); // 이전 노드가 NULL인 경우
    } else {
        printf("Prev : %d, ", node -> prev -> data); // 이전 노드의 데이터 출력
    }
    printf("current : %d, ", node -> data); // 현재 노드의 데이터 출력

    if (node -> next == NULL) {
        printf("Next : NULL\n"); // 다음 노드가 NULL인 경우
    } else {
        printf("Next : %d\n", node -> next -> data); // 다음 노드의 데이터 출력
    }
}