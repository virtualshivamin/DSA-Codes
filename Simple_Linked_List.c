#include <stdio.h>
#include <stdlib.h> 

struct node {
    int data;
    struct node *next;
};

int main(){
    struct node *head;
    struct node *node1, *node2, *node3, *node4, *temp;
    head = (struct node*)malloc(sizeof(struct node));
    node1 = (struct node*)malloc(sizeof(struct node));
    node2 = (struct node*)malloc(sizeof(struct node));
    node3 = (struct node*)malloc(sizeof(struct node));
    node4 = (struct node*)malloc(sizeof(struct node));

    head->next = node1;
    node1->data = 10; node1->next = node2;
    node2->data = 20; node2->next = node3;
    node3->data = 30; node3->next = node4;
    node4->data = 40; node4->next = NULL;

    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

