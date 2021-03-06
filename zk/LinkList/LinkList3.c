#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef Node* LinkList;

LinkList p;

void initLinkList();
int addHeadLinkList();
int addTailLinkList();
int insertLinkListByI(int i);
int insertLinkListByKey(int key);
int delLinkListByI(int i);
int delLinkListByKey(int key);
int modifyLinkList(int oldData);
LinkList searchLinkListByI(int i);
LinkList searchLinkListByKey(int key);
void displayLinkList();

int main()
{

    return 0;
}

void initLinkList() {
    p = (LinkList)malloc(sizeof(Node));
    p->next = NULL;
}

int addHeadLinkList() {
    LinkList newNode = (LinkList)malloc(sizeof(Node));
    if (newNode == NULL) {
        return 0;
    }
    printf("please input new data:");
    scanf("%d", &newNode->data);
    newNode->next = p->next;
    p->next = newNode;
    return 1;
}

int addTailLinkList() {
    LinkList newNode = (LinkList)malloc(sizeof(Node));
    if (newNode == NULL) {
        return 0;
    }
    LinkList cur = p;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    printf("please input new data:");
    scanf("%d", &newNode->data);
    newNode->next = cur->next;
    cur->next = newNode;
    return 1;   
}

int insertLinkListByI(int i) {
    int j = 1;
    LinkList cur = p;
    while (cur->next != NULL && j < i) {
        cur = cur->next;
        j++;
    }
    if (cur->next == NULL || j > i) {
        return 0;
    }
    LinkList tmp = (LinkList)malloc(sizeof(Node));
    printf("please input new data:");
    scanf("%d", &tmp->data);
    tmp->next = cur->next;
    cur->next = tmp;
    return 1;
}

int insertLinkListByKey(int key) {
    LinkList cur = p;
    while (cur->next != NULL) {
        if (cur->next->data == key) {
            break;
        }
        cur = cur->next;
    }
    if (cur->next == NULL) {
        return 0;
    }
    LinkList tmp = (LinkList)malloc(sizeof(Node));
    printf("please input new data:");
    scanf("%d", &tmp->data);
    tmp->next = cur->next;
    cur->next = tmp;
    return 1;
}

int delLinkListByI(int i) {
    int j = 1;
    LinkList cur = p;
    while (cur->next != NULL && j < i) {
        cur = cur->next;
        j++;
    }
    if (cur->next == NULL || j > i) {
        return 0;
    } 
    LinkList tmp = cur->next;
    cur->next = tmp->next;
    free(tmp);
    return 1;
}

int delLinkListByKey(int key) {
    LinkList cur = p;
    while (cur->next != NULL) {
        if (cur->next->data == key) {
             break;
        }
        cur = cur->next;
    }
    if (cur->next == NULL) {
        return 0;
    }
    LinkList tmp = cur->next;
    cur->next = tmp->next;
    free(tmp);
    return 1;
}

int modifyLinkList(int oldData) {
    LinkList cur = p;
    while (cur->next != NULL) {
        cur = cur->next;
        if (cur->data == oldData) {
            break;
        }
    }
    if (cur->next == NULL) {
        return 0;
    }
    printf("please input new data:");
    scanf("%d", &cur->data);
    return 1;
}

LinkList searchLinkListByI(int i) {
    int j = 0;
    LinkList cur = p;
    while (cur->next != NULL && j < i) {
        cur = cur->next;
        j++;
    }
    if (cur->next == NULL || j > i) {
        return 0;
    }
    return cur;
}

LinkList searchLinkListByKey(int key) {
    LinkList cur = p;
    while (cur->next != NULL) {
        cur = cur->next;
        if (cur->data == key) {
            break;
        }
    }
    if (cur->next == NULL) {
        return 0;
    }
    return cur;
}

void displayLinkList() {
    LinkList cur = p;
    while (cur->next != NULL) {
        cur = cur->next;
        printf("%d\n", cur->data);
    }
}


