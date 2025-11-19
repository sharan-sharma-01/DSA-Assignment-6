#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

void splitList(Node* head, Node** head1, Node** head2) {
    if (!head || head->next == head) {
        *head1 = head;
        *head2 = NULL;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *head1 = head;
    *head2 = slow->next;

    slow->next = *head1;

    Node* p = *head2;
    while (p->next != head) p = p->next;
    p->next = *head2;
}

void print(Node* head) {
    if (!head) return;
    Node* p = head;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(4);
    head->next->next = new Node(9);
    head->next->next->next = head;

    Node *h1, *h2;
    splitList(head, &h1, &h2);

    print(h1);
    print(h2);

    return 0;
}
