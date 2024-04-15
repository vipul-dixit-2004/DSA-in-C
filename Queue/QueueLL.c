#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int value;
    struct Node* next;
}node;

node* front;
node* rear;
node* createNode(){
    return (node*)malloc(sizeof(node));
}
void insert(int val){
    node* new_node = createNode();
    new_node->value = val;
    new_node->next = NULL;
    if(front==NULL){
        front = new_node;
        rear = new_node;
    }else{
        rear->next=new_node;
        rear = new_node;
    }
}
int delete(){
    if(front==NULL){
        printf("UnderFlow");
        return -1;
    }else{
        int item = front->value;
        front = front->next;
        return item;
    }
}
void display(){
    node*temp= front;
    while(temp!=NULL){
        printf("%d, ",temp->value);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    insert(5);
    insert(4);
    insert(6);
    insert(7);
    insert(8);
    insert(10);
    display();
    delete();
    delete();
    display();
}