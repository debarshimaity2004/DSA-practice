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

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){

    ListNode* d1 = headA;

    ListNode* d2 = headB;

    while(d1 != d2){
        d1 = d1 == NULL ? headB : d1->next; 
        d2 = d2 == NULL ? headA : d2->next;
    }

    return d1;
}

void printNode(ListNode* node){

    if(node == NULL){
        cout << "No intersection\n";
    }
    else{
        cout << "Intersection at node value: " << node->val << '\n';
    }
}

int main(){

    // Common part
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    // List A: 3->6->8->10
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(6);
    headA->next->next = common;

    // List B: 4->8->10
    ListNode* headB = new ListNode(4);
    headB->next = common;

    ListNode* intersection = getIntersectionNode(headA, headB);

    printNode(intersection);

    return 0;
}