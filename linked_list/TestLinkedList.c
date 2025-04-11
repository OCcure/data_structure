#include "LinkedList.h"
#include "LinkedList.c"

int main(void) {
    int i = 0;
    int count = 0;
    Node* list = NULL;
    Node* current = NULL;
    Node* newNode = NULL;

    for (i=0; i<5; i++) {
        newNode = createNode(i); // 새로운 노드 생성
        appendNode(&list, newNode); // 리스트에 노드 추가
    }

    newNode = createNode(-1);
    insertNodeNewHead(&list, newNode); // 리스트의 헤드에 노드 삽입

    newNode = createNode(-2);
    insertNodeNewHead(&list, newNode); // 리스트의 헤드에 노드 삽입

    //리스트 출력
    count = size(list); // 리스트의 크기 구하기
    for (i = 0 ; i < count; i++) {
        current = getNode(list, i); // 리스트에서 노드 가져오기
        printf("List[%d] : %d\n" ,i , current->data); // 노드의 데이터 출력
    }
    //리스트의 세 번째 노드 뒤에 새 노드 삽입 
    printf("\ninseting 3000 After [2]...\n");
    
    current = getNode(list, 2); // 리스트에서 세 번째 노드 가져오기
    newNode = createNode(3000); // 새로운 노드 생성

    insertNodeAfter(current, newNode); // 세 번째 노드 뒤에 새 노드 삽입
    //리스트 출력
    count = size(list); // 리스트의 크기 구하기
    for (i=0 ; i < count; i++) {
        current = getNode(list, i); // 리스트에서 노드 가져오기
        printf("List[%d] : %d\n" ,i , current->data); // 노드의 데이터 출력
    }

    //모든 노드르 메모리에서 제거
    printf("\ndestroying...\n");

    for (i = 0; i < count; i++) {
        current = getNode(list, i); // 리스트에서 노드 가져오기
        if (current != NULL) {
            removeNode(&list, current); // 리스트에서 노드 제거
            destroyNode(current); // 노드 메모리 해제
        }
    }

    return 0; // 프로그램 종료
}