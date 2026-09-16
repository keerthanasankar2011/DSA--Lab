#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *ptr;
} *front, *rear, *temp, *front1;
int frontelement();
void enq(int data);
void deq();
void empty();
void display();
void create();
void queuesize();
int count = 0;
void main()
{
    int no, ch, e;

    printf("\n1 - Enqueue");
    printf("\n2 - Dequeue");
    printf("\n3 - Front element");
    printf("\n4 - Empty");
    printf("\n5 - Exit");
    printf("\n6 - Display");
    printf("\n7 - Queue size");
    create();
    while (1)
    {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &no);
            enq(no);
            break;

        case 2:
            deq();
            break;

        case 3:
            e = frontelement();
            if (e != 0)
                printf("Front element: %d", e);
            else
                printf("\nNo front element in Queue as queue is empty");
            break;

        case 4:
            empty();
            break;

        case 5:
            exit(0);

        case 6:
            display();
            break;

        case 7:
            queuesize();
            break;

        default:
            printf("Wrong choice, Please enter correct choice");
        }
    }
}
void create()
{
    front = rear = NULL;
}
void queuesize()
{
    printf("\nQueue size: %d", count);
}
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
        rear = temp;
    }
    count++;
}
void display()
{
    front1 = front;
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}
void deq()
{
    front1 = front;
    if (front1 == NULL)
    {
        printf("\nError: Trying to dequeue from empty queue");
        return;
    }
    if (front1->ptr != NULL)
    {
        front1 = front1->ptr;
        printf("\nDequeued value: %d", front->info);
        free(front);
        front = front1;
    }
    else
    {
        printf("\nDequeued value: %d", front->info);
        free(front);
        front = NULL;
        rear = NULL;
    }
    count--;
}
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return front->info;
    else
        return 0;
}
void empty()
{
    if ((front == NULL) && (rear == NULL))
        printf("\nQueue empty");
    else
        printf("\nQueue not empty");
}

Output :
1 - Enqueue
2 - Dequeue
3 - Front element
4 - Empty
5 - Exit
6 - Display
7 - Queue size

Enter choice: 1
Enter data: 14

Enter choice: 1
Enter data: 85

Enter choice: 1
Enter data: 38

Enter choice: 3
Front element: 14

Enter choice: 6
14 85 38

Enter choice: 7
Queue size: 3

Enter choice: 2
Dequeued value: 14

Enter choice: 6
85 38
