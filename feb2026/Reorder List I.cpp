#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* findMiddle(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* reverseList(ListNode* head) {

    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

void reorderList(ListNode* head) {

    if (!head || !head->next)
        return;

    ListNode* middle = findMiddle(head);

    ListNode* second = middle->next;
    middle->next = NULL;

    second = reverseList(second);

    ListNode* first = head;

    while (second) {

        ListNode* next1 = first->next;
        ListNode* next2 = second->next;

        first->next = second;
        second->next = next1;

        first = next1;
        second = next2;
    }
}

// Helper to create list
ListNode* createList(vector<int>& arr) {

    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int x : arr) {

        ListNode* temp = new ListNode(x);

        if (!head) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 0) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ListNode* head = createList(arr);

    reorderList(head);

    // Print without trailing space
    while (head) {
        cout << head->val;
        if (head->next) cout << " ";
        head = head->next;
    }

    return 0;
}