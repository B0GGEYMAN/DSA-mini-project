#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    int id;
    char name[100];
    struct Customer* next;
};

struct Customer* front = NULL;
struct Customer* rear = NULL;

void enqueue(int id, char* name) {
    struct Customer* newCustomer = (struct Customer*)malloc(sizeof(struct Customer));
    if (newCustomer == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newCustomer->id = id;
    strcpy(newCustomer->name, name);
    newCustomer->next = NULL;

    if (rear == NULL) {
        front = newCustomer;  
        rear = newCustomer;
    } else {
        rear->next = newCustomer;  
        rear = newCustomer;
    }
    printf("Customer added: %s (ID: %d)\n", name, id);
}

void dequeue() {
    if (front == NULL) {
        printf("No customers in the queue.\n");
        return;
    }
    
    struct Customer* temp = front;
    printf("Serving customer: %s (ID: %d)\n", temp->name, temp->id);
    front = front->next;

    if (front == NULL) {
        rear = NULL; 
    }
    free(temp);
}

void displayQueue() {
    if (front == NULL) {
        printf("No customers in the queue.\n");
        return;
    }
    struct Customer* temp = front;
    printf("Current queue of customers:\n");
    while (temp != NULL) {
        printf("Customer ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

int main() {
    int choice, id;
    char name[100];

    do {
        printf("\nSimple Banking System:");
        printf("\n1. Add Customer");
        printf("\n2. Serve Customer");
        printf("\n3. Display Queue");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Customer ID: ");
                scanf("%d", &id);
                printf("Enter Customer Name: ");
                scanf(" %[^\n]s", name);
                enqueue(id, name);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    while (front != NULL) {
        dequeue();
    }

    return 0;
}

