#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = NULL;
    }
};

ListNode* oddEvenList(ListNode* head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while(even != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

void printList(ListNode* head){

    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << '\n';
}

int main(){

    // Example: 1->2->3->4->5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = oddEvenList(head);

    printList(head);

    return 0;
}
