#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* segregate(Node* head) {

    if (!head || !head->next)
        return head;

    Node* zeroDummy = new Node(-1);
    Node* oneDummy  = new Node(-1);
    Node* twoDummy  = new Node(-1);

    Node* zeroTail = zeroDummy;
    Node* oneTail  = oneDummy;
    Node* twoTail  = twoDummy;

    Node* curr = head;

    while (curr != NULL) {

        if (curr->data == 0) {
            zeroTail->next = curr;
            zeroTail = zeroTail->next;
        }
        else if (curr->data == 1) {
            oneTail->next = curr;
            oneTail = oneTail->next;
        }
        else {
            twoTail->next = curr;
            twoTail = twoTail->next;
        }

        curr = curr->next;
    }

    // Connect lists
    zeroTail->next = (oneDummy->next != NULL) ? oneDummy->next : twoDummy->next;
    oneTail->next = twoDummy->next;
    twoTail->next = NULL;

    Node* newHead = zeroDummy->next;

    delete zeroDummy;
    delete oneDummy;
    delete twoDummy;

    return newHead;
}

Node* createList(vector<int>& arr) {

    Node* head = NULL;
    Node* tail = NULL;

    for (int x : arr) {
        Node* temp = new Node(x);
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

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    vector<int> arr = {1, 2, 0, 1, 2, 0, 1};

    Node* head = createList(arr);

    head = segregate(head);

    printList(head);

    return 0;
}