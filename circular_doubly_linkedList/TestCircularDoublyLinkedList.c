#include "CircularDoublyLinkedList.h"
#include "CircularDoublyLinkedList.c"

int main() {
    int i = 0;
    int count = 0;
    Node* list = NULL; // 환형 링크드 리스트 초기화
    Node* newNode = NULL; // 노드 초기화
    Node* current = NULL; // 현재 노드 초기화

    for (i = 0; i < 5; i++) {
        newNode = createNode(i); // 노드 생성
        appendNode(&list, newNode); // 노드 추가
    }

    count = size(list); // 리스트 크기 확인
    for (i = 0; i < count; i++) {
        current = getNode(list, i); // 노드 탐색
        printf("List[%d] : %d\n", i, current->data); // 노드 출력
    }

    //리스트의 세 번째 칸 뒤에 노드 삽입

    printf("\ninserting 3000 after [2]...\n");
    current = getNode(list, 2); // 노드 탐색
    newNode = createNode(3000); // 노드 생성
    insertNodeAfter(current, newNode); // 노드 삽입

    printf("\nRemoving Node at 2...\n");
    current = getNode(list, 2); // 노드 탐색
    removeNode(&list, current); // 노드 삭제
    destroyNode(current); // 노드 메모리 해제

    //리스트 출력
    //노드 개수의 2배 만큼 루프를 돌며 환형임을 확인

    count = size(list); // 리스트 크기 확인
    for (i = 0; i < count * 2; i++) {
        if (i == 0) {
            current = list; // 리스트의 첫 번째 노드
        } else {
            current = current->next; // 다음 노드
        }
        printf("List[%d] : %d\n", i, current->data); // 노드 출력
    }

    //모든 노드 메모리에서 제거
    printf("\ndestroying...\n");
    count = size(list); // 리스트 크기 확인

    for (i = 0; i < count; i++) {
        current = getNode(list, 0); // 노드 탐색
        if (current != NULL) {
            removeNode(&list, current); // 노드 삭제
            destroyNode(current); // 노드 메모리 해제
        }
    }

    return 0; // 프로그램 종료
}