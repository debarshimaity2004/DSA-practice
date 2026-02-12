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

ListNode* detectCycle(ListNode* head){

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){

            slow = head;

            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return NULL;
}

int main(){

    ListNode* head = new ListNode(3);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(0);
    ListNode* n3 = new ListNode(-4);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n1; // cycle

    ListNode* ans = detectCycle(head);

    if(ans != NULL)
        cout << ans->val << '\n';
    else
        cout << "No cycle\n";

    return 0;
}
