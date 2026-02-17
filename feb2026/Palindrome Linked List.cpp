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

ListNode* reverseList(ListNode* head){
    ListNode* prev = NULL;
    while(head){
        ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }

    return prev;
}

bool isPalindrome(ListNode* head){

    if(head == NULL || head->next == NULL){
        return true;
    }

    //middle
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse second half
    ListNode* second = reverseList(slow);
    ListNode* first = head;

    while(second != NULL){
        if(first->val != second->val){
            return false;
        }
        first = first->next;
        second = second->next;
    }
    return true;
}

int main(){

    // example: 1->2->2->1

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    if(isPalindrome(head)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }

    return 0;
}
