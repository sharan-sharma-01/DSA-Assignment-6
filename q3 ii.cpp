#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) { data = d; next = NULL; }
};

int sizeCLL(Node* head) {
    if (head == NULL) return 0;
    int count = 1;
    Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = new Node(5);
    Node* n1 = new Node(10);
    Node* n2 = new Node(15);

    head->next = n1;
    n1->next = n2;
    n2->next = head;

    cout << sizeCLL(head);
    return 0;
}
