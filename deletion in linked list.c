
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create() {
    struct Node *newNode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }
}

void deleteBeginning() {
    struct Node *temp;

    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("Node deleted successfully!\n");
}

void deleteEnd() {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        temp = head;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        free(temp);
    }

    printf("Node deleted successfully!\n");
}

void deletePosition() {
    struct Node *temp, *prev;
    int pos, i;

    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Node deleted successfully!\n");
}

void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n----- LINKED LIST MENU -----\n");
        printf("1. Create Linked List\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete from Specific Position\n");
        printf("5. Display Linked List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;

            case 2:
                deleteBeginning();
                break;

            case 3:
                deleteEnd();
                break;

            case 4:
                deletePosition();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
