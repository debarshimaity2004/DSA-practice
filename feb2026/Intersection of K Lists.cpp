
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* getKIntersectionNode(vector<ListNode*>& lists) {
    //Complete the function
    int k = lists.size();
    if(k == 0) return NULL;

    vector<int>length(k, 0);

    for(int i = 0;i < k;i++){
        ListNode* temp = lists[i];
        while(temp){
            length[i]++;
            temp = temp->next;
        }
    }

    int minLen = *min_element(length.begin(), length.end());

    for(int i = 0;i < k;i++){
        int diff = length[i] - minLen;
        while(diff--){
            lists[i] = lists[i]->next;
        }
    }
    while(lists[0]){
        bool same = true;

        for (int i = 1; i < k; i++) {
            if (lists[i] != lists[0]) {
                same = false;
                break;
            }
        }
        if (same) return lists[0];
        for (int i = 0; i < k; i++) lists[i] = lists[i]->next;
    }

    return NULL;
}


vector<ListNode*> GetList(vector<vector<int>> &num, int K) {
    vector<ListNode*> head(K), cur(K);

    for(int i = 0; i < K; i++) {
        head[i] = NULL;
        cur[i] = NULL;
    }

    map <int,ListNode*> M;

    for(int i = 0; i < K; i++) {
        for(int u : num[i]) {
            if(M.find(u) != M.end()) {
                if(!head[i]) {
                    head[i] = M[u];
                    cur[i] = head[i];
                }
                else {
                    cur[i]->next = M[u]; 
                    cur[i] = cur[i]->next;
                }
                break;
            }
            else {
                ListNode* temp = new ListNode(u);
                if(!head[i]) {
                    head[i] = temp;
                    cur[i] = head[i];
                }
                else {
                    cur[i]->next = temp;
                    cur[i] = cur[i]->next;
                }
                M[u] = temp;
            }
        }
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

    vector<ListNode*> head = GetList(num, K);

    ListNode* ans = getKIntersectionNode(head);

    if(ans) cout << ans->val << "\n";
    else cout << "-1\n";

    return 0;
}
