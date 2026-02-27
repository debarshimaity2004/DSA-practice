
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwo(ListNode* l1, ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    if(l1 ->val <= l2->val){
        head = l1;
        l1 = l1->next;
    }
    else{
        head = l2;
        l2 = l2->next;
    }

    tail = head;

    while(l1 && l2){
        if(l1 -> val <= l2 ->val){
            tail->next = l1;
            l1 = l1->next;
        }
        else{
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail ->next;
    }

    if(l1) tail->next = l1;
    else tail->next = l2;

    return head;
}


ListNode* mergeKLists(vector<ListNode*> head) {
    //Complete the function
    int k = head.size();
    if(k == 0) return NULL;

    while(k > 1){
        int i = 0;
        int j = k -1;
        while(i < j){
            head[i] = mergeTwo(head[i], head[j]);
            i++;
            j--;
        }
        k = (k+1) / 2;
    }

    return head[0];
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

vector<ListNode*> GetList(int K, vector<vector<int>> &num) {
    vector<ListNode*> head(K);
    for(int i = 0; i < K; i++) {
        head[i] = GetList(num[i]);
    }
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K;
    cin >> K;

    vector<vector<int>> num(K);

    for(int i = 0; i < K; i++) {
        int n;
        cin >> n;
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            num[i].push_back(x);
        }
    }

    vector<ListNode*> head = GetList(K, num);

    ListNode* mergeHead = mergeKLists(head);

    while(mergeHead) {
        cout << mergeHead->val << " ";
        mergeHead = mergeHead->next;
    }
    cout << "\n";
    
    return 0;
}
