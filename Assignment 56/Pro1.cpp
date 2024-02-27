/*
Given a linked list and a key ‘X‘ in, the task is to check if X is present in the linked list
or not.
Examples:
Input: 14->21->11->30->10, X = 14
Output: Yes
Explanation: 14 is present in the linked list.
Input: 6->21->17->30->10->8, X = 13
Output: No

*/
#include <bits/stdc++.h>
using namespace std;
class Node
{ // Linked List Node
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
class LinkedList
{ // user defined data type
public:
    Node *head = NULL;
    Node *tail = NULL;
    int size;
    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }
    void insertAtTail(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void insertAtHead(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insertAtIdx(int idx, int val)
    {
        if (idx < 0 || idx > size)
            cout << "Invalid Index" << endl;
        else if (idx == 0)
            insertAtHead(val);
        else if (idx == size)
            insertAtTail(val);
        else
        {
            Node *t = new Node(val);
            Node *temp = head;
            for (int i = 1; i <= idx - 1; i++)
            {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
string findNode(Node* head, int data)
{
    Node* temp = head;
    while (temp != NULL) {
        if (temp->val == data) {
            return "Yes";
        }
        temp = temp->next;
    }
    return "No";
}
int main()
{
    LinkedList ll;
    int n;
    cout << "Enter no. of nodes: ";
    cin >> n;
    while (n >= 1)
    {
        int num;
        cin >> num;
        ll.insertAtTail(num);
        n--;
    }
    ll.display();
    int X;
    cout << "Enter a value to find in th list" << endl;
    cin >> X;
    cout << findNode(ll.head, X);
    return 0;
}