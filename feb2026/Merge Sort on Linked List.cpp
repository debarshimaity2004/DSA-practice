
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeLists(ListNode* l1, ListNode* l2){
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;

    while(l1 && l2){
        if(l1->val <= l2->val){
            temp->next = l1;
            l1 = l1->next;
        }
        else{
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    if(l1) temp->next = l1;
    else temp ->next = l2;

    return dummy->next;
}


ListNode* findMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


ListNode* mergesort(ListNode* head) {
    //Complete the function
    if(!head || !head->next) return head;

    ListNode* mid = findMiddle(head);
    ListNode* right = mid ->next;
    mid ->next = NULL;

    ListNode* left = mergesort(head);
    right = mergesort(right);

    return mergeLists(left, right);
}


ListNode* GetList(vector<int> &num) {
    ListNode* head = nullptr;

    if(num.empty()) {
        return head;
    }

    ListNode* cur = head;
    
    for(int i  = 0; i < (int)num.size(); i++) {
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

    ListNode* head = GetList(num);

    head = mergesort(head);

    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
    
    return 0;
}
