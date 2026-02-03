#include <iostream>

struct Node {
    int data{};
    Node* link{};
};

void Insert(Node*& head, int x) {   // Node*& permite alterar o head do caller
    Node* temp = new Node();
    temp->data = x;
    temp->link = head;
    head = temp;
}

int main() {
    Node* head = nullptr;

    Insert(head, 2);
    Insert(head, 4);

    for (Node* cur = head; cur != nullptr; cur = cur->link) {
        std::cout << cur->data << " ";
    }
    std::cout << "\n";

    while (head) {
        Node* next = head->link;
        delete head;
        head = next;
    }
}
