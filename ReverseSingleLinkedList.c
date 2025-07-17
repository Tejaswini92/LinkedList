// 2->3->4->1

Node* reverse_list(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next_node = NULL; // Renamed 'temp' to 'next_node' for clarity

    while (current != NULL) {
        // Store the next node before we change current->next
        next_node = current->next;

        // Reverse the current node's pointer
        current->next = prev;

        // Move pointers one position ahead
        prev = current;
        current = next_node;
    }

    // 'prev' will be the new head of the reversed list
    return prev;
}
