
void concatenate() {
    struct node *head2 = NULL;
    struct node *temp, *newnode;
    int n, i;

    printf("Enter number of nodes in second list: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;
        newnode->prev = NULL;

        if (head2 == NULL) {
            head2 = newnode;
        } else {
            temp = head2;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    if (head == NULL) {
        head = head2;
    }
    else if (head2 != NULL) {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = head2;
        head2->prev = temp;
    }

    printf("Lists concatenated successfully!\n");
}
