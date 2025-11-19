#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* random;
    Node(int x) {
        data = x;
        next = prev = random = NULL;
    }
};

void correctRandom(Node* head) {
    Node* temp = head;
    while (temp) {
        temp->random = temp;  
        temp = temp->next;
    }
}

void print(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    head->next = n2;
    n2->prev = head;
    n2->next = n3;
    n3->prev = n2;

    head->random = head;
    n2->random = n3;
    n3->random = NULL;

    correctRandom(head);

    print(head);
    return 0;
}
