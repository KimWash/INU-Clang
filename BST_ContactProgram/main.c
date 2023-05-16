//이진 탐색 트리를 사용한 연락처 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_STRING_SIZE 100

// 데이터 형식
typedef struct {
    char name[MAX_STRING_SIZE];
    char phone[MAX_STRING_SIZE];
} element;
//노드의 구조
typedef struct TreeNode {
    element key;
    struct TreeNode *left, *right;
} TreeNode;

int count = 0;

//키필드
//만약 el < e2 이면 -1 반환
//만약 el == e2 이면 0 반환
//만약 e1 > e2 이면 1 반환
int compare (element e1, element e2)
{
    return strcmp (e1.name, e2.name);
}

//이진 탐색 트리 출력 함수
void display (TreeNode * p)
{
    if (p != NULL) {
        count++;
        printf ("( ");
        display (p->left);
        printf ("( %s:%s )", p->key.name, p->key.phone);
        display (p->right);
        printf (" )");
    }
}

TreeNode *search (TreeNode *root, element key) {
    TreeNode *p = root;
    while (p != NULL) {
        if (compare (key, p->key) == 0)
            return p;
        else if (compare (key, p->key) < 0)
            p = p->left;
        else if (compare (key, p->key) > 0)
            p = p->right;
    }
    return p; // 탐색에 실패했을 경우 NULL 반환
    
}
TreeNode * new_node (element item) {
    
    TreeNode * temp = (TreeNode *) malloc(sizeof (TreeNode)) ;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}



TreeNode * insert_node (TreeNode * node, element key)
{
    //트리가 공백이면 새로운 노드를 반환한다.
    if (node == NULL) return new_node (key) ;
    
    //그렇지 않으면 순환적으로 트리를 내려간다.
    if (compare (key, node->key) <0)
        node-> left = insert_node (node->left, key);
    else if (compare (key, node->key)>0)
        node->right = insert_node (node->right, key);
    else { // 같은 전화번호인 경우
        node->key = key;
    }
    //루트 포인터를 반환한다.
    return node;
}


// 정렬 돼있는 것을 가정.
TreeNode * max_value_node (TreeNode * node)
{
    TreeNode * current = node;
    //맨 오른쪽 단말 노드를 찾으러 내려감
    while (current->right != NULL)
    current = current->right;
    return current;
}

TreeNode *delete_node(TreeNode *root, element key) {
    if (root == NULL) return root;
    // 현재 노드가 부모 노드보다 작으면 왼쪽
    if (compare(key, root->key) < 0)
        root->left = delete_node(root->left, key);
    // 현재 노드가 부모 노드보다 크면 오른쪽
    else if (compare(key, root->key) > 0)
        root->right = delete_node(root->right, key);
    else { // 같으면
        // if-else if 구문이 말단/하나의 서브트리만 갖고 있는 경우 handling
       // 왼쪽 자식 노드가 없으면 오른쪽을 새로운 상위 노드로 지정, 기존의 상위 노드는 할당 해제
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        // 오른쪽 자식 노드가 없으면 왼쪽을 새로운 상위 노드로 지정, 기존의 상위 노드는 할당 해제
        else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        // 왼쪽/오른쪽 자식 노드 모두 있을 때 오른쪽 서브트리의 최솟값 (오른쪽 내의 맨 왼쪽) 혹은 왼쪽 서브트리의 최댓값 (왼쪽 내의 맨 오른쪽)을 찾아 해당 노드를 제거
        TreeNode *temp = max_value_node(root->left);
        root->key = temp->key;
        root->left = delete_node(root->left, temp->key);
    }
    return root;
}


void help(void)
{
    printf("\n**** i: 입력, d: 삭제, s: 탐색, p: 출력, q: 종료 ****: ");
}

int main(void) {
    char command;
    element e;
    TreeNode *root = NULL;
    TreeNode *tmp;
    
    do {
        help();
        command = getchar ();
        getchar ();                //엔터키 제거
        switch (command) {
            case 'i':
                printf("이름 :");
                gets (e.name);
                printf("전화번호('-' 포함) :");
                gets (e.phone);
                root = insert_node (root, e);
                break;
            case 'd':
                printf("이름 : ");
                gets (e.name);
                root=delete_node (root, e);
                break;
            case 'p':
                display (root); printf ("\n");
                printf("%d 개 존재", count);
                count = 0;
                break;
            case 's':
                printf("이름 : ");
                gets (e.name);
                tmp = search (root, e);
                if (tmp != NULL)
                    printf("전화번호 :%s\n", tmp->key.phone);
                break;
        }
    } while (command != 'q');
    return 0;
}
