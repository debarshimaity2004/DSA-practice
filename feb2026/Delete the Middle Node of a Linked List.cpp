#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

ListNode *deleteMiddle(ListNode *head)
{

    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    ListNode *slow = head;
    ListNode *fast = head->next->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *temp = slow->next;
    slow->next = temp->next;

    delete temp;

    return head;
}

void printList(ListNode *head)
{

    while (head != NULL)
    {

        cout << head->val << " ";

        head = head->next;
    }

    cout << '\n';
}

int main()
{

    // Example: 1->2->3->4->5

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = deleteMiddle(head);

    printList(head);

    return 0;
}
