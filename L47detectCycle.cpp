#include <unordered_map>

Node* removeLoop(Node* head) {
    if (head == NULL) return NULL;  // Edge case: empty list

    unordered_map<Node*, bool> visited;
    Node* curr = head;
    Node* prev = NULL;  // To track the previous node

    while (curr != NULL) {
        if (visited.find(curr) != visited.end()) {  // Loop detected
            prev->next = NULL;  // Break the loop
            return head;
        }
        visited[curr] = true;  // Mark as visited
        prev = curr;
        curr = curr->next;
    }

    return head;  // No loop found
}