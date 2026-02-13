#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

int countLoopLength(Node* meetingPoint){

    Node* temp = meetingPoint;
    int length = 1;

    while(temp->next != meetingPoint){
        temp = temp->next;
        length++;
    }

    return length;
}

int lengthOfLoop(Node* head){

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return countLoopLength(slow);
        }
    }

    return 0;
}

int main(){

    // Example 
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // create loop: 4 -> 2
    head->next->next->next->next = head->next;

    cout << lengthOfLoop(head) << '\n';

    return 0;
}
