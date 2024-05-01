//Stack using Two Queues - linked list implementation

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct Node
{
    float data;
    struct Node* next;
};

struct Queue
{
    struct Node* front;
    struct Node* rear;
};

struct Stack
{
    struct Queue* q1;
    struct Queue* q2;
};

struct Node *top; //temp stack
int count_temp =0;//temp count for temp stack

void push_temp(float x)
{
        struct Node* newnode;
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = x;
        newnode->next = NULL;

        if(count_temp==0)
                top = newnode;
        else
        {
                newnode->next = top;
                top = newnode;
        }
        count_temp++;
}

float pop_temp()
{
        float t;
        struct Node* temp;
        temp = top;
        top = top->next;
        t = temp->data;
        free(temp);
        return t;
}

void disp()
{
        struct Node *temp;
        if(top==NULL)
                printf("Underflow! Stack is empty \n");
        else
        {
                printf("Stack is: \n");
                temp = top;
                while(temp!=NULL)
                {
                        printf("%.1f  ",temp->data);
                        temp = temp->next;
                }
                printf("\n");
        }
}

// Create a new node with given data
struct Node* newNode(float data)
{
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->data = data;
        node->next = NULL;
        return node;
}

// Create a new queue
struct Queue* createQueue()
{
        struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
        q->front = NULL;
        q->rear = NULL;
        return q;
}


