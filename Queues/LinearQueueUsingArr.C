/*Implementation of Queue using arrays */

#include <stdio.h>
#include <stdlib.h>
#define MAX 3 // the size is less for demonstration purpose

// Linear Queue has two ends front end and rear end
// insertion is done in rear end
// deletion is done in front end

// Queue user defined datatype will have size, front ptr, and rear ptr as it's attributes and also a pointer to array
struct Queue
{
    int data[MAX];
    int front, rear;
};

// function initialize struct queue: set both the ptrs as -1
void initialize(struct Queue *q)
{
    q->front = q->rear = -1;
}

// function isFull: returns 1 if queue is full, else returns 0
int isFull(struct Queue *q)
{
    return (q->rear == MAX - 1) ? 1 : 0;
}

// function isEmpty: returns 1 if queue is empty, else returns 0
int isEmpty(struct Queue *q)
{
    return (q->rear == -1) ? 1 : 0;
}

// function enqueue: insert a value in queue if space is available else return 0 since Queue is Full
// for inserting, increment rear ptr and then assign(insert) the value at that location
int enqueue(struct Queue *q, int value)
{
    if (isFull(q))
        return 0;

    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;

    return value;
}

// function dequeue: returns garbage value if queue is empty else returns the deleted element
// if all the elements are deleted reset the front and rear pointers so we can use that memory again
int dequeue(struct Queue *q)
{
    int deletedElement;

    deletedElement = q->data[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % MAX;

    return deletedElement;
}

// displays the queue
void display(struct Queue *q)
{
    int i = q->front + 1;
    if (isEmpty(q))
        printf("\nQueue is Empty!!");
    else
    {
        printf("\nQueue Contents \n");
        printf("Queue Size : %d\nFront = %d\nRear = %d\n", MAX, q->front, q->rear);

        for (i = q->front; i <= q->rear; i++)
        {
            printf("%d\n", q->data[i]);
        }
    }
}

int main()
{
    int ch, d;
    struct Queue q;
    initialize(&q);
    while (1)
    {
        printf("\n ------------------------\n|\tQueue menu\t|\n ------------------------\n|\t1. Insert.\t|\n ------------------------\n|\t2. Delete.\t|\n ------------------------\n|\t3. Display.\t|\n ------------------------\n|\t4. Exit.\t|\n ------------------------\n");
        printf("\nEnter your choice :: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to be Inserted : ");
            scanf("%d", &d);
            d = enqueue(&q, d);
            if (d == 0)
                printf("Queue is full..");
            else
                printf("%d was inserted successfully...", d);
            break;
        case 2:
            if (isEmpty(&q))
                printf("\nQueue is empty...");
            else
                printf("\nDeleted element is %d", dequeue(&q));
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("\nPlease enter correct choice :: ");
        }
    }
}

/*


 ------------------------
|	Queue menu	|
 ------------------------
|	1. Insert.	|
 ------------------------
|	2. Delete.	|
 ------------------------
|	3. Display.	|
 ------------------------
|	4. Exit.	|
 ------------------------

Enter your choice :: 1

Enter element to be Inserted : 2002
2002 was inserted successfully...
 ------------------------
|	Queue menu	|
 ------------------------
|	1. Insert.	|
 ------------------------
|	2. Delete.	|
 ------------------------
|	3. Display.	|
 ------------------------
|	4. Exit.	|
 ------------------------

Enter your choice :: 1

Enter element to be Inserted : 1000
1000 was inserted successfully...
 ------------------------
|	Queue menu	|
 ------------------------
|	1. Insert.	|
 ------------------------
|	2. Delete.	|
 ------------------------
|	3. Display.	|
 ------------------------
|	4. Exit.	|
 ------------------------

Enter your choice :: 1

Enter element to be Inserted : 2939
2939 was inserted successfully...
 ------------------------
|	Queue menu	|
 ------------------------
|	1. Insert.	|
 ------------------------
|	2. Delete.	|
 ------------------------
|	3. Display.	|
 ------------------------
|	4. Exit.	|
 ------------------------

Enter your choice :: 1

Enter element to be Inserted : 2323
Queue is full..
 ------------------------
|	Queue menu	|
 ------------------------
|	1. Insert.	|
 ------------------------
|	2. Delete.	|
 ------------------------
|	3. Display.	|
 ------------------------
|	4. Exit.	|
 ------------------------

Enter your choice :: 3

Queue Contents 
Queue Size : 3
Front = -1
Rear = 2
0
2002
1000
2939

 ------------------------
|	Queue menu	|
 ------------------------
|	1. Insert.	|
 ------------------------
|	2. Delete.	|
 ------------------------
|	3. Display.	|
 ------------------------
|	4. Exit.	|
 ------------------------

Enter your choice :: 2

Deleted element is 0
 ------------------------
|	Queue menu	|
 ------------------------
|	1. Insert.	|
 ------------------------
|	2. Delete.	|
 ------------------------
|	3. Display.	|
 ------------------------
|	4. Exit.	|
 ------------------------

Enter your choice :: 2

Deleted element is 2002
 ------------------------
|	Queue menu	|
 ------------------------
|	1. Insert.	|
 ------------------------
|	2. Delete.	|
 ------------------------
|	3. Display.	|
 ------------------------
|	4. Exit.	|
 ------------------------

Enter your choice :: 3

Queue Contents 
Queue Size : 3
Front = 1
Rear = 2
1000
2939

 ------------------------
|	Queue menu	|
 ------------------------
|	1. Insert.	|
 ------------------------
|	2. Delete.	|
 ------------------------
|	3. Display.	|
 ------------------------
|	4. Exit.	|
 ------------------------

Enter your choice :: 4

*/