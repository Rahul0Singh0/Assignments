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
int findNode(Node* head, int k)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if(temp->val == k)
            return 1;
    }
    return 0;
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