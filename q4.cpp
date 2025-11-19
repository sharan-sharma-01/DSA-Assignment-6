#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char d) {
        data = d;
        next = prev = NULL;
    }
};

int main() {
    string s;
    cin >> s;

    Node* head = NULL;
    Node* tail = NULL;

    for (char c : s) {
        Node* n = new Node(c);
        if (head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    Node* left = head;
    Node* right = tail;

    while (left != NULL && right != NULL && left != right && right->next != left) {
        if (left->data != right->data) {
            cout << "false";
            return 0;
        }
        left = left->next;
        right = right->prev;
    }

    cout << "true";
    return 0;
}
