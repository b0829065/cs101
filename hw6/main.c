#include <stdio.h>
#include <stdlib.h>
// typedef struct node{
//     int data;
//     struct node* next_node;    
// }node_t;

struct node {
    int data;
    struct node* next_node;
};
typedef struct node node_t;

node_t* allocate_node(int data){
    node_t* p = (node_t*)calloc(1,sizeof(node_t));
    p->data = data;
    p->next_node = NULL;
    return p;
}

void show_list(node_t* head){
    while(head){
        printf("[%d]->",head->data);
        head = head->next_node;
    }
    printf("NULL\n");
}

node_t* append_node(node_t* head, int new_data){
    node_t* new_node = allocate_node(new_data);
    
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

void free_all_node(node_t* head){
    node_t* p=NULL;
    while(head){
        p = head;
        head = head->next_node;
        printf("free([%d])->",p->data);
        free(p);
    }
    printf("NULL\n");
}

node_t* add_node(node_t* head, int new_data){
    node_t* new_node = allocate_node(new_data);
    
    if(head){
        new_node->next_node = head;
        head = new_node;
    } else {
        head = new_node;
    }
    return head;
}

node_t* del_node(node_t* head, int n){
    node_t* p = NULL;
    node_t* pre_n = NULL;
    node_t* head_enable = head;
    int count = 0;
    if (head && n == 0){
        p = head_enable;
        head = head_enable->next_node;
        free(p);
        return head;
    }
    else if (head) {
        while(count != n+1){
            pre_n = p; //N-1
            p = head_enable; //N
            head_enable = head_enable->next_node; //N+1
            count++;
        }
        pre_n->next_node = head_enable;
        free(p);
        return head;
    }
    else {
        printf("NULL\n");
    }
}


int main()
{
    node_t* head = NULL;
    head = append_node(head, 0);
    show_list(head);
    head = append_node(head, 1);
    show_list(head);
    head = add_node(head, -1);
    show_list(head);
    head = del_node(head, 1);
    show_list(head);
    free_all_node(head);
    
    // node_t* head = NULL;
    // head = append_node(head, 1);
    // show_list(head);
    // head = append_node(head, 2);
    // show_list(head);
    // head = append_node(head, 3);
    // show_list(head);
    // head = append_node(head, 4);
    // show_list(head);
    // head = add_node(head, 0);
    // show_list(head);
    // head = del_node(head, 4);
    // show_list(head);
    // head = del_node(head, 2);
    // show_list(head);
    // head = del_node(head, 0);
    // show_list(head);
    // free_all_node(head);
    return 0;
}
