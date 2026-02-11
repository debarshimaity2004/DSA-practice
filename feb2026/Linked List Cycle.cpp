#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = NULL;
    }
};

bool hasCycle(ListNode* head){

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }

    return false;
}

int main(){

    // Creating linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Creating cycle: 4 -> 2
    head->next->next->next->next = head->next;

    if(hasCycle(head)){
        cout << "Cycle Detected\n";
    }
    else{
        cout << "No Cycle\n";
    }

    return 0;
}
