#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int x){ data=x; next=prev=NULL; }
};

Node* reverseK(Node* head, int k){
    Node* curr = head;
    Node* newHead = NULL;
    int count = 0;
    
    while (curr && count < k){
        Node* next = curr->next;
        curr->next = curr->prev;
        curr->prev = next;
        newHead = curr;
        curr = next;
        count++;
    }
    
    if (curr){
        head->next = reverseK(curr, k);
        if (head->next) head->next->prev = head;
    }
    
    return newHead;
}

void print(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2); head->next->prev = head;
    head->next->next = new Node(3); head->next->next->prev = head->next;
    head->next->next->next = new Node(4); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5); head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6); head->next->next->next->next->next->prev = head->next->next->next->next;

    int k = 2;

    head = reverseK(head, k);
    print(head);
}
