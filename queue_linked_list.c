
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter the element: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Element inserted\n");
}

void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        temp = front;

        printf("Deleted element = %d\n", front->data);

        front = front->next;

        if(front == NULL)
        {
            rear = NULL;
        }

        free(temp);
    }
}

void peek()
{
    if(front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front element = %d\n", front->data);
    }
}

void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        temp = front;

        printf("Queue elements:\n");

        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: enqueue();
                    break;

            case 2: dequeue();
                    break;

            case 3: peek();
                    break;

            case 4: display();
                    break;

            case 5: exit(0);

            default: printf("Invalid Choice\n");
        }
    }

    return 0;
}
