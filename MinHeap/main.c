#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct element{
    int key;
    struct element* left;
    struct element* right;
} element;


typedef struct HeapType {
    element* heap;
    int heap_size;
} HeapType;

void printError(char* msg) {
    fprintf(stderr, "%s", msg);
    exit(1);
}


element* new_element(int value) {
    element* newNode = (element*)malloc(sizeof(element));
    newNode->key = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

HeapType* create_heap(void) {
    HeapType* heap = (HeapType*)malloc(sizeof(HeapType));
    return heap;
}

void init_heap(HeapType* heap) {
    heap->heap = NULL;
    heap->heap_size = 0;
}

char* makeBinaryString(int number) {
    char *binString = (char*)malloc(sizeof(int) * 8);
    int count, left, right, temp;
    for (count = 0; number > 0; count++) {
        binString[count] = '0' + number % 2;
        number /= 2;
    }
    binString[count] = 0;
    
    right = count - 1;
    for (left = 0; left < count / 2; left++) {
        temp = binString[left];
        binString[left] = binString[right];
        binString[right] = temp;
        right--;
    }
    return binString;
}

element* searchNodeByIndex(HeapType *heap, int index) {
    char* path = makeBinaryString(index);
    element* curr = heap->heap;
    
    int i;
    for (i = 1; i < strlen(path) && path[i] != '\0'; i++) {
        if (path[i] == '0') {
            curr = curr->left;
        } else if (path[i] == '1'){
            curr = curr->right;
        }
    }
    return curr;
}

void insert_min_heap(HeapType* heap, int value) {
    if (heap->heap == NULL) {
        heap->heap = new_element(value);
        heap->heap_size++;
        return;
    }

    // 이진수로 표현된 경로를 따라 삽입할 위치 찾기
    element* curr = heap->heap;
    element* prev = NULL;
    
    char* path = makeBinaryString(heap->heap_size + 1);
    int i;
    for (i = 1; i < strlen(path) && path[i] != '\0'; i++) {
        prev = curr;
        if (path[i] == '0') {
            curr = curr->left;
        } else if (path[i] == '1'){
            curr = curr->right;
        }
    }
    
    if (prev == NULL) return;

    // 새 노드 생성 및 링크 설정
    element* newNode = new_element(value);
    
    // 0 -> 왼쪽, 1 -> 오른쪽
    if (path[i-1] == '0') {
        prev->left = newNode;
    } else {
        prev->right = newNode;
    }
    heap->heap_size++;
    
    int currentIdx = heap->heap_size;
    curr = searchNodeByIndex(heap, currentIdx);
    prev = searchNodeByIndex(heap, currentIdx / 2);
    while ((curr->key < prev->key)) {
        int temp = curr->key;
        curr->key = prev->key;
        prev->key = temp;
        currentIdx /= 2;
        curr = prev;
        prev = searchNodeByIndex(heap, currentIdx / 2);
    }
}

int is_empty(HeapType* heap) {
    return heap->heap_size == 0 || heap->heap == NULL;
}

element* find(HeapType *heap) {
    return heap->heap;
}

void delete_min_heap(HeapType *heap){
    if (is_empty(heap)) printError("힙이 비어 있습니다.");
    if (heap->heap_size == 1) {
        free(heap->heap);
        heap->heap = NULL;
        heap->heap_size = 0;
        return;
    }
    
    // 말단 노드를 루트 노드와 swap 한다.
    char* path = makeBinaryString(heap->heap_size);
    element *parentOfLeaf = searchNodeByIndex(heap, heap->heap_size / 2);
    
    
    char lastDirection = path[strlen(path)-1];
    if (lastDirection == '0') {
        heap->heap->key = parentOfLeaf->left->key;
    } else if (lastDirection == '1') {
        heap->heap->key = parentOfLeaf->right->key;
    } 

    // 말단 노드를 free 시킨다.
    if (lastDirection == '0') {
        free(parentOfLeaf->left);
        parentOfLeaf->left = NULL;
    } else if (lastDirection == '1') {
        free(parentOfLeaf->right);
        parentOfLeaf->right = NULL;
    }
    
    // 루트로 간 말단 노드를 제자리로 보내준다.
    element *curr = heap->heap;
    element *child = curr->left;
    while (curr->left != NULL) {
        if (curr->right != NULL && curr->right->key < curr->left->key)
            child = curr->right;

        if (curr->key <= child->key)
            break;

        int temp = curr->key;
        curr->key = child->key;
        child->key = temp;
        curr = child;
        child = curr->left;
    }
    heap->heap_size--;
    
}

void print_min_heap(element* root, int space) {
    if (root == NULL)
        return;
    
    int i;
    space += 5;

    print_min_heap(root->right, space);
    
    printf("\n");
    for (i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    print_min_heap(root->left, space);
}


int main() {
    HeapType *heap = create_heap();
    init_heap(heap);

    insert_min_heap(heap, 30);
    insert_min_heap(heap, 50);
    insert_min_heap(heap, 10);
    insert_min_heap(heap, 20);
    insert_min_heap(heap, 5);
    
    
    print_min_heap(heap->heap, 0);
    printf("--------------------");
    
    delete_min_heap(heap);
    
    print_min_heap(heap->heap, 0);
    printf("--------------------");

    delete_min_heap(heap);

    print_min_heap(heap->heap, 0);
    printf("--------------------");

    delete_min_heap(heap);

    print_min_heap(heap->heap, 0);
    printf("--------------------");

    delete_min_heap(heap);

    print_min_heap(heap->heap, 0);
    printf("--------------------");

    delete_min_heap(heap);

    print_min_heap(heap->heap, 0);
    printf("--------------------");


    return 0;
}
