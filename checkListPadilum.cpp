#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class LinkList
{
    Node *head;

public:
    LinkList()
    {
        head = NULL;
    }
    void insetAtEnd(int data)
    {
        if (head == NULL)
        {
            cout << "LIST IS EMPTY SO THIS IS OUR FIRST NODE INTO LIST "
                 << "\n";
            Node *newNode = new Node(data);
            head = newNode;
        }
        else
        {
            Node *temp = head;
            Node *newNode = new Node(data);
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            cout << "VALUES ARE INSERTED AT THE END \n";
        }
    }
    void print()
    {
        if (head == NULL)
        {
            cout << "WE CAN NOT PRINT THE VALUES BECAUSE LINK LIST IS EMPTY ";
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                /* code */
                cout << endl;
                cout << temp->data;
                // cout << endl;
                temp = temp->next;
            }
        }
    }
    Node *middleValue(Node *head)
    {
        Node *slow = head;
        Node *forward = head;
        int counter = 0;
        while (forward != NULL && forward->next != NULL)
        {
            /* code */
            forward = forward->next->next;
            // cout<<endl;
            // cout<<"foward : "<<forward -> data <<endl;
            //  cout<<"slow :"<<slow -> data <<endl;
            slow = slow->next;
            counter++;
        }
        return slow;
    }
    Node *findTheReverese(Node *temp)
    {
        Node *forward = NULL;
        Node *prev = NULL;
        Node *curr = temp;
        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    bool findThePandlium()
    {
        Node *temp = head;
        Node *tempHead = middleValue(head);
        Node *tempHeadReverse = findTheReverese(tempHead);
        while (tempHeadReverse!=NULL)
        {
            if (temp->data != tempHeadReverse->data)
            {
               return 0;
            }

            temp = temp->next;
            tempHeadReverse = tempHeadReverse->next;
        }
        return 1;
    }
};
int main()
{
    LinkList l;
    l.insetAtEnd(1);
    l.insetAtEnd(2);
    l.insetAtEnd(3);
    l.insetAtEnd(3);
    l.insetAtEnd(2);
    l.insetAtEnd(1);
    cout << "PRINT THE VALUES \n ";
    cout<<l.findThePandlium();

    cout << "\nMIDDLE VALUES IS THIS : \n ";
}