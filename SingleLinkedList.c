#include <stdio.h>
#include <stdlib.h> //Malloc and Free

typedef struct _node_ Node;

// Define the structure for a node in the linked list
struct _node_ {
  int Data;
  Node* Next;
}

// Global head pointer for simplicity in this example.
// In real-world applications, you'd often pass the head pointer
// or a pointer to the head pointer to functions.
Node* Head = NULL;

//create a new node API
Node* CreateNode (int Data) {
  Node* NewNode = (List*) malloc (sizeof (List));
  NewNode->Data = Data;
  NewNode->Next = NULL;
  return NewNode;
}

//add to the head of Linked List.

void AddToHead (int Data) {

  Node* NewNode = CreateNode(Data);
  NewNode->next = Head;
  Head = NewNode;  
}

//add to end of the linked list.

void AddToTail (int Data) {
Node* NewNode = CreateNode(Data);

  if (Head == NULL) {
    Head = NewNode;
  } else {
    Node* temp = Head;
    while (temp->Next != NULL) {
      temp = temp->next;
    }
    temp->next = NewNode;
  }
}

// Function to insert a new element at a specific position in the singly linked list
void insertAtPosition(int data, int position) {
  Node* NewNode = CreateNode(Data);
  Node* Temp = Head, Prev;
  if (position == 0) {
      AddToHead (Head,data);
      return;
  }
  
  while ((Temp != NULL) && (position > 0)) {
    position--;
    Prev = Temp;
    Temp= Temp->Next;
  }
  if (temp == NULL) {
   free(newNode);
   return;
  } else {
    Prev->Next = NewNode;
    NewNode->Next = Temp ;
  }
}



//  Insertion after a specific value
void insertAfter(int key, int data) {
    Node* current = head;
    while (current != NULL && current->data != key) { // Find the key
        current = current->next;
    }

    if (current == NULL) {
        printf("Key %d not found. Cannot insert %d after it.\n", key, data);
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = current->next; // New node points to what current was pointing to
    current->next = newNode;       // Current points to the new node
    printf("Inserted %d after %d.\n", data, key);
}


//  Deletion by value
void deleteNode(int data) {
    if (head == NULL) {
        printf("List is empty. Cannot delete %d.\n", data);
        return;
    }

    // If head node itself holds the data to be deleted
    if (head->data == data) {
        Node* temp = head;
        head = head->next; // Move head to the next node
        free(temp);         // Free the old head node
        printf("Deleted %d from the beginning.\n", data);
        return;
    }

    Node* current = head;
    Node* prev = NULL; // Keep track of the previous node for linking
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) { // Data not found in the list
        printf("Data %d not found in the list. Cannot delete.\n", data);
        return;
    }

    // Data found, link previous node to current's next node
    prev->next = current->next;
    free(current); // Free the node to be deleted
    printf("Deleted %d from the list.\n", data);
}

// Free the entire list (important for memory management)
void freeList() {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next; // Save pointer to the next node
        free(current);            // Free the current node
        current = nextNode;       // Move to the next node
    }
    head = NULL; // Set head to NULL as the list is now empty
    printf("All nodes freed. List is now empty.\n");
}


// --- Main function to demonstrate operations ---
int main() {
    printList(); // List is empty initially

    AddToHead(10);
    AddToHead(5);
    AddToTail(20);
    AddToHead(2);
    printList(); // Expected: 2 -> 5 -> 10 -> 20 -> NULL

    insertAfter(5, 7);
    printList(); // Expected: 2 -> 5 -> 7 -> 10 -> 20 -> NULL

    deleteNode(10);
    printList(); // Expected: 2 -> 5 -> 7 -> 20 -> NULL

    deleteNode(2); // Delete head
    printList(); // Expected: 5 -> 7 -> 20 -> NULL

    deleteNode(20); // Delete last node
    printList(); // Expected: 5 -> 7 -> NULL

    deleteNode(100); // Not found
    printList(); // Expected: 5 -> 7 -> NULL

    searchNode(7);
    searchNode(100);

    insertAtBeginning(1);
    insertAtEnd(99);
    printList(); // Expected: 1 -> 5 -> 7 -> 99 -> NULL

    freeList();
    printList(); // Should be empty

    return 0;
}
