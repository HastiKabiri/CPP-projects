
// Lab: Singly Linked List Operations
// question 1


#include <iostream>
using namespace std;

struct Node {
    int studentID;
    Node* next;
};

void insertEnd(Node*& head, int id) {
    Node* newNode = new Node();
    newNode->studentID = id;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to read and display the list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp-> studentID;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to update a value
bool updateID(Node* head, int oldID, int newID) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->studentID == oldID) {
            temp->studentID = newID;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 101);
    insertEnd(head, 102);
    insertEnd(head, 103);
    insertEnd(head, 104);

    cout << "Initial list: ";
    displayList(head);

    updateID(head, 103, 110);


    cout << "After update: ";
    displayList(head);

    return 0;
}













// question 2

struct Node {
    int age;
    Node* next;
};

void insertEnd(Node*& head, int ageVal) {
    Node* newNode = new Node();
    newNode->age = ageVal;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->age;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int searchAge(Node* head, int targetAge) {
    Node* temp = head;
    int position = 1;
    
    while (temp != nullptr) {
        if (temp->age == targetAge) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1; 
}

void sortList(Node* head) {
    if (head == nullptr || head->next == nullptr) return;

    bool swapped;
    Node* current;
    
    do {
        swapped = false;
        current = head;

        while (current->next != nullptr) {
            if (current->age > current->next->age) {
                // Swap data values
                int tempVal = current->age;
                current->age = current->next->age;
                current->next->age = tempVal;
                
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 45);
    insertEnd(head, 32);
    insertEnd(head, 50);
    insertEnd(head, 28);
    insertEnd(head, 39);

    int pos = searchAge(head, 39);
    if (pos != -1) {
        cout << "Search result: Age 39 found at position " << pos << "." << endl;
    } else {
        cout << "Search result: Age 39 not found." << endl;
    }

    sortList(head);

    cout << "Sorted list: ";
    displayList(head);

    return 0;
}

