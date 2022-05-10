#include <stdio.h>

typedef struct node{
    int data;
    struct node* next_node;    
}node_t;

node_t* allocation_node(int data){
    node_t* p = (node_t*)calloc(1,sizeof(node_t));
    p->data = data;
    p->next_node = NULL;
    return p;
}

node_t* append_node(node_t* head, int new_data){
    node_t* new_node = allocation_node(new_data);
    
    if(head){
        node_t* p = head;
        while (p->next_node){
            p = p->next_node;
        }
        p->next_node = new_node;
    } else {
        head = new_node; //pointer head -> new_node
    }
    return head;
}

show_list(node_t* head){
    while(head){
        printf("[%d]->",head->data);
        head = head->next_node;
    }
    printf("NULL\n");
}

void free_all_node(node_t* head){
    node_t* p=NULL;
    while(head){
        p = head;
        head = head->next_node;
        printf("free([%d])->",p->data);
        free(p);
    }
    printf("null\n");
}

int main()
{
    node_t* head = NULL;
    head = append_node(head, 0);
    show_list(head);
    head = append_node(head, 11);
    show_list(head);
    head = append_node(head, 222);
    show_list(head);
    head = append_node(head, 3333);
    show_list(head);
    free_all_node(head);
    return 0;
}
