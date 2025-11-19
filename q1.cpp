// --------------------- CIRCULAR LINKED LIST ---------------------

#include <iostream>
using namespace std;

class CNode {
public:
    int data;
    CNode* next;
    CNode(int x) { data = x; next = NULL; }
};

class CircularList {
public:
    CNode* head = NULL;

    void insert(int x) {
        CNode* n = new CNode(x);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        CNode* t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }

    void insertAfter(int key, int x) {
        if (!head) return;
        CNode* t = head;
        do {
            if (t->data == key) {
                CNode* n = new CNode(x);
                n->next = t->next;
                t->next = n;
                return;
            }
            t = t->next;
        } while (t != head);
    }

    void deleteNode(int key) {
        if (!head) return;
        CNode* t = head;
        CNode* p = NULL;

        do {
            if (t->data == key) {
                if (t == head) {
                    CNode* last = head;
                    while (last->next != head) last = last->next;
                    if (last == head) { head = NULL; return; }
                    last->next = head->next;
                    head = head->next;
                } else {
                    p->next = t->next;
                }
                return;
            }
            p = t;
            t = t->next;
        } while (t != head);
    }

    bool search(int key) {
        if (!head) return false;
        CNode* t = head;
        do {
            if (t->data == key) return true;
            t = t->next;
        } while (t != head);
        return false;
    }
};

// --------------------- DOUBLY LINKED LIST ---------------------

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int x) { data = x; next = prev = NULL; }
};

class DoublyList {
public:
    DNode* head = NULL;

    void insertLast(int x) {
        DNode* n = new DNode(x);
        if (!head) { head = n; return; }
        DNode* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }

    void insertAfter(int key, int x) {
        DNode* t = head;
        while (t) {
            if (t->data == key) {
                DNode* n = new DNode(x);
                n->next = t->next;
                if (t->next) t->next->prev = n;
                t->next = n;
                n->prev = t;
                return;
            }
            t = t->next;
        }
    }

    void deleteNode(int key) {
        DNode* t = head;
        while (t) {
            if (t->data == key) {
                if (t->prev) t->prev->next = t->next;
                else head = t->next;
                if (t->next) t->next->prev = t->prev;
                return;
            }
            t = t->next;
        }
    }

    bool search(int key) {
        DNode* t = head;
        while (t) {
            if (t->data == key) return true;
            t = t->next;
        }
        return false;
    }
};

int main() {
    return 0;
}
