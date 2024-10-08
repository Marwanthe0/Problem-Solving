#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void insertInSortedOrder(Node*& head, int value) {
    Node* newNode = createNode(value);

    if (head == nullptr || head->data > value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}


int findIndexByValue(Node* head, int value) {
    Node* current = head;
    int index = 0;

    while (current != nullptr) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}


void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int n, value, target;

    cout << "Enter the total number of elements in the linked list: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node in index " << i + 1 << ": ";
        cin >> value;
        insertNode(head, value);
    }

    cout << "Linked list: ";
    displayList(head);

    cout << "Enter the value to find its index: ";
    cin >> target;

    int index = findIndexByValue(head, target);

    if (index != -1) {
        cout << "Element " << target << " found at index: " << index + 1 << endl;
    } else {
        cout << "Element " << target << " not found in the list!" << endl;
        cout << "Inserting element " << target << " in the list in sorted order." << endl;

        insertInSortedOrder(head, target);

        cout << "Updated Linked list: ";
        displayList(head);
    }

    return 0;
}
