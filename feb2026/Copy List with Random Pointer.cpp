
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *random;
    ListNode() : val(0), next(nullptr), random(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), random(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next), random(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *random) : val(x), next(next), random(random) {}
};


ListNode* copyRandomList(ListNode* head) {
    //Complete the function
    if(!head) return NULL;

    ListNode* curr = head;

    while(curr){
        ListNode* copy = new ListNode(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }
    curr = head;

    while(curr){
        if(curr->random) curr->next->random = curr->random->next;
        else curr->next->random = NULL;

        curr = curr->next->next;
    }

    curr = head;
    ListNode* copyHead = head->next;
    ListNode* copyCurr = copyHead;

    while(curr){
        curr->next = curr->next->next;
        if(copyCurr->next) copyCurr->next = copyCurr->next->next;

        curr = curr->next;
        copyCurr = copyCurr->next;
    }

    return copyHead;
}


ListNode* GetList(vector<pair<int,int>> &num) {
    int n = (int)num.size();
    vector<ListNode*> copy(n);

    ListNode* head = NULL;
    ListNode* cur = NULL;

    for(int i = 0; i < n; i++) {
        ListNode* temp = new ListNode(num[i].first);
        copy[i] = temp;
        if(!head) {
            head = temp;
            cur = temp;
        }
        else {
            cur->next = temp;
            cur = cur->next;
        }
    }

    for(int i = 0; i < n; i++) {
        if(num[i].second == -1) continue;
        copy[i]->random = copy[num[i].second];
    }

    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int,int>> num(n);

    for(int i = 0; i < n; i++) {
        cin >> num[i].first >> num[i].second;
    }

    ListNode* head = GetList(num);

    ListNode* ans = copyRandomList(head);

    while(ans) {
        cout << ans->val << " ";
        if(ans->random) cout << ans->random->val << "\n";
        else cout << "-1\n";
        ans = ans->next;
    }
    
    return 0;
}
