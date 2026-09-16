#include <stdio.h>
#define MAX 100
int heap[MAX];
int size = 0;
// Insert into Max Heap
void insert(int element)
{
    if (size >= MAX)
    {
        printf("Heap Overflow\n");
        return;
    }

    heap[size] = element;
    int current = size;

    while (current > 0 && heap[current] > heap[(current - 1) / 2])
    {
        int temp = heap[current];
        heap[current] = heap[(current - 1) / 2];
        heap[(current - 1) / 2] = temp;
        current = (current - 1) / 2;
    }
    size++;
}
// Heapify Down
void heapifyDown(int current)
{
    int largest = current;
    int left = 2 * current + 1;
    int right = 2 * current + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != current)
    {
        int temp = heap[current];
        heap[current] = heap[largest];
        heap[largest] = temp;
        heapifyDown(largest);
    }
}
// Delete Root
void deleteHeap()
{
    if (size <= 0)
    {
        printf("Heap Underflow\n");
        return;
    }

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}
// Display Heap
void display()
{
    if (size == 0)
    {
        printf("Heap is empty\n");
        return;
    }

    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");
}
int main()
{
    int choice, element;
    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &element);
            insert(element);
            break;

        case 2:
            deleteHeap();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}

Output :
1. Insert
2. Delete
3. Display
4. Exit

Enter your choice: 1
Enter element: 50

Enter your choice: 1
Enter element: 30

Enter your choice: 1
Enter element: 20

Enter your choice: 1
Enter element: 15

Enter your choice: 3
50 30 20 15

Enter your choice: 2

Enter your choice: 3
30 15 20
