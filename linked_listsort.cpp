#include <iostream>

using namespace std;

// A struct to represent a node in the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the beginning of a linked list
void insert(Node** head, int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    // Create a dummy node and a pointer to it
    Node* dummy = new Node;
    Node* tail = dummy;
    
    // Merge the left and right linked lists, keeping track of the tail of the merged list
    while (left != nullptr && right != nullptr) {
        if (left->data <= right->data) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }
    
    // Append any remaining nodes to the merged list
    if (left != nullptr) {
        tail->next = left;
    } else if (right != nullptr) {
        tail->next = right;
    }
    
    // Return the head of the merged list (skipping the dummy node)
    Node* head = dummy->next;
    delete dummy;
    return head;
}

// Function to sort a linked list using Merge Sort
void mergeSort(Node** head) {
    // Base case: if the list is empty or has only one node, it is already sorted
    if (*head == nullptr || (*head)->next == nullptr) {
        return;
    }
    
    // Split the list into two halves using the slow-fast pointer technique
    Node* slow = *head;
    Node* fast = (*head)->next;
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    Node* left = *head;
    Node* right = slow->next;
    slow->next = nullptr;
    
    // Recursively sort the left and right halves of the list
    mergeSort(&left);
    mergeSort(&right);
    
    // Merge the sorted left and right halves
    *head = merge(left, right);
}

// Function to print a linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insert(&head, 3);
    insert(&head, 1);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 5);
    cout << "Before sorting: ";
    printList(head);
    mergeSort(&head);
    cout << "After sorting: ";
    printList(head);
    return 0;
}
