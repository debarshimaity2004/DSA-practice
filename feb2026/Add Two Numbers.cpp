
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* n1, ListNode* n2) {
    //Complete the function
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;

    int carry = 0;
    while (n1 || n2 || carry) {
        int sum = carry;
        if (n1) {
            sum += n1->val;
            n1 = n1->next;
        }
        if (n2) {
            sum += n2->val;
            n2 = n2->next;
        }
        carry = sum / 10;

        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }
    return dummy->next;
}


ListNode* GetList(string &num) {
    ListNode* n1 = nullptr;
    ListNode* head = nullptr;
    for(int i = (int)num.length() - 1; i >= 0; i--) {
        ListNode* temp = new ListNode(num[i] - '0');
        if(n1) {
            n1->next = temp;
            n1 = temp;
        }
        else {
            n1 = temp;
            head = n1;
        }
    }
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string num1, num2;
    cin >> num1;
    cin >> num2;

    ListNode* n1 = GetList(num1);
    ListNode* n2 = GetList(num2);

    ListNode* sum = addTwoNumbers(n1, n2);

    string ans = "";
    while(sum) {
        ans += ('0' + sum->val);
        sum = sum->next;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";

    return 0;
}
