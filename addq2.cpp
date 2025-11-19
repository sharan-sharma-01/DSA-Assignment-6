#include <iostream>
using namespace std;

int parity(int x) {
    int c = 0;
    while (x > 0) {
        c += (x & 1);
        x >>= 1;
    }
    return c;
}

// ---------------- CIRCULAR LINKED LIST ----------------

class CNode {
public:
    int data;
    CNode* next;
    CNode(int x) { data = x; next = NULL; }
};

CNode* removeEvenParityCLL(CNode* head) {
    if (!head) return NULL;

    CNode* curr = head;
    CNode* prev = NULL;

    do {
        int p = parity(curr->data);
        if (p % 2 == 0) {
            if (curr == head && curr->next == head) return NULL;

            if (curr == head) {
                CNode* last = head;
                while (last->next != head) last = last->next;
                head = head->next;
                last->next = head;
                curr = head;
                continue;
            }

            prev->next = curr->next;
            curr = curr->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    } while (curr != head);

    return head;
}

void printCLL(CNode* head) {
    if (!head) return;
    CNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}


// ---------------- DOUBLY LINKED LIST ----------------

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int x) { data = x; next = prev = NULL; }
};

DNode* removeEvenParityDLL(DNode* head) {
    DNode* curr = head;

    while (curr) {
        int p = parity(curr->data);
        if (p % 2 == 0) {
            if (curr == head) {
                head = curr->next;
                if (head) head->prev = NULL;
                curr = head;
                continue;
            }

            curr->prev->next = curr->next;
            if (curr->next) curr->next->prev = curr->prev;

        }
        curr = curr ? curr->next : NULL;
    }
    return head;
}

void printDLL(DNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


// ---------------- MAIN ----------------

int main() {
    // CLL example
    CNode* head = new CNode(9);
    head->next = new CNode(11);
    head->next->next = new CNode(34);
    head->next->next->next = new CNode(6);
    head->next->next->next->next = new CNode(13);
    head->next->next->next->next->next = head;

    head = removeEvenParityCLL(head);
    printCLL(head);

    // DLL example
    DNode* h = new DNode(18);
    h->next = new DNode(15); h->next->prev = h;
    h->next->next = new DNode(8); h->next->next->prev = h->next;
    h->next->next->next = new DNode(9); h->next->next->next->prev = h->next->next;
    h->next->next->next->next = new DNode(14); h->next->next->next->next->prev = h->next->next->next;

    h = removeEvenParityDLL(h);
    printDLL(h);

    return 0;
}
