#include <stdio.h>

struct Node {
    int Data;
    struct Node *Next;
} typedef N;

void AddNode(N **, int Data);
void InsertNode(N **, int Data, int position);
void DeleteNode(N **, int position);
void ShowNode(N **);

int main() {
    N *start = NULL;
    int data = 0, pos = 0 ;
    printf( "Add (data) :" ) ; scanf( "%d", &data ) ; AddNode(&start, data);
    printf( "Add (data) :" ) ; scanf( "%d", &data ) ; AddNode(&start, data);
    printf( "Add (data) :" ) ; scanf( "%d", &data ) ; AddNode(&start, data);
    ShowNode(&start); 

    printf( "Insert (data, pos) :" ) ; scanf( "%d %d", &data, &pos ) ; InsertNode(&start, data, pos);
    printf( "Insert (data, pos) :" ) ; scanf( "%d %d", &data, &pos ) ; InsertNode(&start, data, pos);
    printf( "Insert (data, pos) :" ) ; scanf( "%d %d", &data, &pos ) ; InsertNode(&start, data, pos);
    ShowNode(&start);

    printf( "Delete (pos) :" ) ; scanf( "%d", &pos ) ; DeleteNode(&start, pos);
    printf( "Delete (pos) :" ) ; scanf( "%d", &pos ) ; DeleteNode(&start, pos);
    printf( "Delete (pos) :" ) ; scanf( "%d", &pos ) ; DeleteNode(&start, pos);
    ShowNode(&start);

    return 0;
}

void AddNode(N **Walk, int Data) {
    N *newNode = new N;
    newNode->Data = Data;
    newNode->Next = NULL;

    if (*Walk == NULL) {
        *Walk = newNode;
    } else {
        N *temp = *Walk;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
}

void ShowNode(N **Walk) {
    N *temp = *Walk;
    while (temp != NULL) {
        printf("%d ", temp->Data);
        temp = temp->Next;
    }
    printf("\n");
}

void InsertNode(N **Walk, int Data, int position) {
    N *newNode = new N;
    newNode->Data = Data;
    newNode->Next = NULL;

    if (position == 1) {
        newNode->Next = *Walk;
        *Walk = newNode;
        return;
    }

    N *temp = *Walk;
    for (int i = 1; i < position - 1 && temp != NULL; ++i) {
        temp = temp->Next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        delete newNode;
    } else {
        newNode->Next = temp->Next;
        temp->Next = newNode;
    }
}

void DeleteNode(N **Walk, int position) {
    if (*Walk == NULL) {
        printf("List is empty\n");
        return;
    }

    N *temp = *Walk;

    if (position == 1) {
        *Walk = temp->Next;
        delete temp;
        return;
    }

    for (int i = 1; temp != NULL && i < position - 1; ++i) {
        temp = temp->Next;
    }

    if (temp == NULL || temp->Next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    N *next = temp->Next->Next;
    delete temp->Next;
    temp->Next = next;
}
