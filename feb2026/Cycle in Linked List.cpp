/*Given a non-empty linked list, your task is to find the cycle in the linked list. 
Return the starting node of the cycle and the length of the cycle. If there is no cycle, 
then return null as node and −1 as length.
*/


#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


pair<ListNode*,int> cycleInLinkedList(ListNode* head) {
    //Complete the function
    if (!head)
        return {NULL, -1};

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (!fast || !fast->next)
        return {NULL, -1};

    ListNode* start = head;
    while (start != slow) {
        start = start->next;
        slow = slow->next;
    }

    int length = 1;
    ListNode* temp = start->next;

    while (temp != start) {
        temp = temp->next;
        length++;
    }
    return {start, length};
}


ListNode* GetList(int n, vector<int> &num, int lastLink) {
    ListNode* head = nullptr;

    if(num.empty()) {
        return head;
    }

    ListNode* cur = head;
    
    for(int i  = 0; i < n; i++) {
        ListNode* temp = new ListNode(num[i]);
        if(!cur) {
            cur = temp;
            head = cur;
        }
        else {
            cur->next = temp;
            cur = temp;
        }
    }

    if(lastLink) {
        ListNode* temp = head;
        for(int i = 0; i < lastLink - 1; i++) {
            temp = temp->next;
        }
        cur->next = temp;
    }
    
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> num;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }

    int lastLink;
    cin >> lastLink;

    ListNode* head = GetList(n, num, lastLink);

    pair<ListNode*,int> ans = cycleInLinkedList(head);

    cout << (ans.first ? ans.first->val : -1) << " " << ans.second << "\n";
    
    return 0;
}
