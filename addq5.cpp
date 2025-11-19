#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev, *up, *down;
    Node(int x) {
        data = x;
        next = prev = up = down = NULL;
    }
};

Node* constructList(int a[][3], int r, int c) {
    Node* head = NULL;
    Node* rowStart = NULL;
    Node* prevRowStart = NULL;

    for (int i = 0; i < r; i++) {
        Node* prev = NULL;
        for (int j = 0; j < c; j++) {

            Node* temp = new Node(a[i][j]);
            if (!head) head = temp;

            if (!rowStart) rowStart = temp;

            if (prev) {
                prev->next = temp;
                temp->prev = prev;
            }

            if (prevRowStart) {
                Node* upNode = prevRowStart;
                for (int k = 0; k < j; k++) upNode = upNode->next;
                upNode->down = temp;
                temp->up = upNode;
            }

            prev = temp;
        }
        prevRowStart = rowStart;
        rowStart = NULL;
    }
    return head;
}

void printRight(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int a[3][3] = { {1,2,3},
                    {4,5,6},
                    {7,8,9} };

    Node* head = constructList(a, 3, 3);

    printRight(head);

    return 0;
}
