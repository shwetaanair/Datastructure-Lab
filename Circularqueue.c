#include <stdio.h>
#include <stdlib.h>
struct C_Queue
{
    int *queue;
    int front;
    int rear;
    int size;
    int num;
    int ch;
};

void enqueue(struct C_Queue *Q)
{
    if ((Q->front == 0 && Q->rear == Q->size - 1) || ((Q->rear + 1) % Q->size == Q->front))
    {
        printf("Queue Overflow...");
        return;
    }
    else if (Q->front == -1)
    {
        printf("Enter the number: ");
        scanf("%d", &Q->num); // Remove the space after %d
        Q->front = Q->rear = 0;
        Q->queue[Q->rear] = Q->num;
    }
    else if (Q->rear == Q->size - 1 && Q->front != 0)
    {
        printf("Enter the number: ");
        scanf("%d", &Q->num); 
        Q->rear = 0;
        Q->queue[Q->rear] = Q->num;
    }
    else
    {
        printf("Enter the number: ");
        scanf("%d", &Q->num);
        Q->rear++;
        Q->queue[Q->rear] = Q->num;
    }
}

void dequeue(struct C_Queue *Q)
{
    if (Q->front == -1)
    {
        printf("Empty Queue");
        return;
    }
    if (Q->front == Q->rear) 
    {
        Q->front = -1;
        Q->rear = -1;
    }
    else if (Q->front == Q->size - 1)
        Q->front = 0;
    else
        Q->front++;
}

void display(struct C_Queue *Q)
{
    if (Q->front == -1)
        printf("Queue is empty");
    else if (Q->front <= Q->rear) 
    {
        for (int i = Q->front; i <= Q->rear; i++) 
            printf("%d ", Q->queue[i]);
    }
    else
    {
        for (int i = Q->front; i < Q->size; i++)
            printf("%d ", Q->queue[i]);
        for (int i = 0; i <= Q->rear; i++) 
            printf("%d ", Q->queue[i]);
    }
}

int main()
{
    struct C_Queue Q;
    printf("Enter the size of array: ");
    scanf("%d", &Q.size);
    Q.front = -1;
    Q.rear = -1;
    Q.queue = (int *)malloc(Q.size * sizeof(int));
    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &Q.ch);
        switch (Q.ch)
        {
        case 1:
            enqueue(&Q);
            break;
        case 2:
            dequeue(&Q);
            break;
        case 3:
            display(&Q);
            break;
        default:
            break;
        }
    } while (Q.ch != 0);
    free(Q.queue);
    return 0;
}
