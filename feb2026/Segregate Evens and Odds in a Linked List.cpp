#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* divide(Node* head){

    Node* oddHead = new Node(-1);
    Node* oddTail = oddHead;

    Node* evenHead = new Node(-1);
    Node* evenTail = evenHead;

    Node* curr = head;

    while(curr != NULL){
        Node* temp = curr;
        curr = curr->next;
        temp->next = NULL;

        if(temp->data % 2 == 0){
            evenTail->next = temp;
            evenTail = temp;
        }
        else{
            oddTail->next = temp;
            oddTail = temp;
        }
    }
    evenTail->next = oddHead->next;
    return evenHead->next;
}

void printList(Node* head){

    while(head != NULL){

        cout << head->data << " ";

        head = head->next;
    }

    cout << '\n';
}

int main(){

    // Example: 1->2->3->4->5->6

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    head = divide(head);

    printList(head);

    return 0;
}
