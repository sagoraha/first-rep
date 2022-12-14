
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *Next;
    Node(int val)
    {

        value=val;
        Next = NULL;
    }

};
struct Test
{
    int position[1000];
};
void inserAtTail(Node *&head,int val);
void insertAtHead(Node *&head,int val);
void display(Node *n);
int countLength(Node *&head);
void insertAtSpecificPosition(Node* &head, int pos, int val);
int searchByValueUnique(Node* &head,int key);
void searchByValueDuplicate(Node* &head,int key);
Test searchByValueDuplicateReturn(Node *&head,int key);
void searchByValueUnique(Node* &head,int searchValue,int value);
void deletionAtHead(Node* &head);
void deletionAtTail(Node* &head);
void deletionAtSpecificPosition(Node* &head,int position);
void deletionByValue(Node* &head,int value);
Node* reverseNonRecursive(Node* &head);
Node* reverseRecursive(Node* &head);


void insertAtTail(Node* &head,int val)
{
    Node *newNode = new Node(val);
    if(head==NULL)
    {
        head=newNode;
        return ;
    }
    Node *temp=head;
    while(temp->Next !=NULL)
    {
        temp=temp->Next;
    }
    temp->Next=newNode;
}
void insertAtHead(Node* &head,int val)
{
    Node *newNode= new Node(val);
    newNode->Next=head;
    head=newNode;
}
void display(Node *n)
{
    while(n !=NULL)
    {
        cout<<n->value;
        if(n->Next !=NULL)
            cout<<" -> ";
        n=n->Next;
    }
    cout<<endl<<endl;
}
int countLength(Node* &head)
{
    Node* temp=head;
    int count=0;
    while(temp != NULL)
    {
        count++;
        temp=temp->Next;
    }
    return count;
}
void insertAtSpecificPosition(Node* &head, int pos, int val)
{
    int i=0;
    Node* temp=head;
    while(i<pos-2)
    {
        temp=temp->Next;
        i++;
    }
    Node *newNode=new Node(val);
    newNode->Next=temp->Next;
    temp->Next=newNode;
}
int searchByValueUnique(Node* &head,int key)
{
    Node* temp=head;
    int count=1;
    if(temp ==NULL)
    {
        return -1;
    }
    while(temp->value !=  key)
    {
        if(temp->Next ==NULL)
        {
            return -1;
        }
        temp=temp->Next;
        count++;
    }
    return count;

}
void searchByValueDuplicate(Node* &head,int key)
{
    Node* temp=head;
    int size;
    size=countLength(head);
    int position[size+1],k=1;
    int count=1;
    int flag=0;
    while(temp!=NULL)
    {
        if(temp->value==key)
        {
//            cout<<count<<" ";
            position[k]=count;
            k++;
            flag=1;

        }
        temp=temp->Next;
        count++;
    }

    if(flag==0)
    {
        cout<<"The search value is not yet in the list " <<endl;
    }
    else
    {
        position[0]=k;
        cout<<"The value is found at Position: ";
        for(int i=1; i<position[0]; i++)
        {
            cout<<position[i];
            if(i<position[0]-1) cout<<",";
        }
        cout<<endl;
    }
}
Test searchByValueDuplicateReturn(Node *&head,int key)
{
    Node* temp=head;
    Test T;
    int k=1;
    int count=1;

    while(temp!=NULL)
    {
        if(temp->value==key)
        {
//            cout<<count<<" ";
            T.position[k]=count;
            k++;


        }
        temp=temp->Next;
        count++;
    }
    T.position[0]=k;
    return T;
}
void searchByValueUnique(Node* &head,int searchValue,int value)
{
    int position;
    //step 1; search the position of the searchValue
    position=searchByValueUnique(head,searchValue);
    //step 2: Insert the value at the position
    insertAtSpecificPosition(head,position+1,value);
}
void deletionAtHead(Node* &head)
{
    Node* temp=head;
    if(temp !=NULL)
    {
        head=temp->Next;
        delete temp;
    }
    else
    {
        cout<<"There is no value in the linked list "<<endl;
    }
}
void deletionAtTail(Node* &head)
{
    Node* temp=head;
    if(temp !=NULL && temp->Next!=NULL)
    {
        while(temp->Next->Next !=NULL)
        {
            temp=temp->Next;
        }
        Node *delNode=temp->Next;
        temp->Next=NULL;
        delete delNode;
    }
    else
    {
        if(temp==NULL) cout<<"There is no value in the linked list "<<endl;
        else
            deletionAtHead(head);
    }
}
void deletionAtSpecificPosition(Node* &head,int position)
{
    Node* temp=head;
    if(temp!=NULL && position<=countLength(head))
    {
        if(position==1)
        {
            deletionAtHead(head);
        }
        else if(position==countLength(head))
        {
            deletionAtTail(head);
        }
        else
        {
            int i=1;
            while(i<position-1)
            {
                temp=temp->Next;
                i++;
            }
            Node* delNode=temp->Next;
            temp->Next=delNode->Next;
            delete delNode;
        }

    }
    else
    {
        if(position>countLength(head))
        {
            cout<<"position Out of Bound";
        }
        //position is out of range
        else
        {
            cout<<"There is no value in the linked list "<<endl;
        }
    }
}
void deletionByValue(Node* &head,int value)
{
    // find the position of the value
    int position;
    position= searchByValueUnique(head,value);

    //delete the node at that position
    if(position==-1)
    {
        cout<<"Value not found in the list "<<endl;
    }
    else
    {
        deletionAtSpecificPosition(head,position);
    }
}
Node* reverseNonRecursive(Node* &head)
{
    Node* prev=NULL;
    Node* current=head;
    if(head==NULL)
    {
        cout<<"The Linked List is Empty "<<endl;
        return head;
    }
    Node* next=head->Next;

    while(true)
    {
        current->Next=prev;
        prev=current;
        current=next;
        if(current==NULL) break;
        next=next->Next;
    }
    return prev;
}
Node* reverseRecursive(Node* &head)
{
    //base call
    if(head==NULL || head->Next==NULL)
    {
       if(head==NULL) cout<<"The Linked List is Empty"<<endl;
        return head;
    }
    //Recursive call
    Node* newHead= reverseRecursive(head->Next);
    head->Next->Next=head;
    head->Next=NULL;
    return newHead->Next;
}
int main()
{
    Node *head=NULL;
    int value,position;
    cout<<"Choice 1: Insertion at Head"<<endl
        <<"Choice 2: Insertion at Tail"<<endl
        <<"Choice 3: Insertion at Specific Position"<<endl
        <<"Choice 4:Search a Specific Value(Unique List) "<<endl
        <<"Choice 5:Search a Specific Value(Duplication enabled List) "<<endl
        <<"Choice 6: Insertion after a specific value(Unique List) "<<endl
        <<"Choice 7: Deletion at Head "<<endl
        <<"Choice 8: Deletion at Tail "<<endl
        <<"Choice 9: Deletion at a specific Position  "<<endl
        <<"Choice 10: Deletion by Value(Unique List)  "<<endl
        <<"Choice 11: Reversal of List Non-Recursive  "<<endl
        <<"Choice 12: Reversal of List Recursive  "<<endl
        <<"Choice 0: Exit"<<endl
        <<endl;
    cout<<"Next Choice: ";
    int Choice;
    cin>>Choice;
    while(Choice !=0)
    {

        switch(Choice)
        {
        case 1:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtHead(head,value);
            break;
        case 2:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtTail(head,value);
            break;
        case 3:
            cout<<"Enter the Desired Position: ";
            cin>>position;
            cout<<"Enter the value: ";
            cin>>value;
            insertAtSpecificPosition(head,position,value);
            break;
        case 4:

            cout<<"Enter the value to search: ";
            cin>>value;
            position=searchByValueUnique(head,value);
            if(position !=-1)
            {
                cout<<"The number is at position "<<position<<endl;
            }
            else
            {
                cout<<"The number is not yet in the list " <<endl;
            }

            break;
        case 5:

            cout<<"Enter the value to search: ";
            cin>>value;

//            searchByValueDuplicate(head,value);
            Test T;
            T=searchByValueDuplicateReturn(head,value);
            if(T.position[0]==1)
            {
                cout<<"The Search Value is not yet in the list"<<endl;
            }
            else
            {
                int size=T.position[0];
                for(int i=1; i<size; i++)
                {
                    cout<<T.position[i];
                    if(i<size-1) cout<<",";
                }
                cout<<endl;
            }
            break;
        case 6:
            cout<<"Enter the value to search: ";
            int searchValue;
            cin>>searchValue;
            cout<<"Enter the value to insert: " ;
            cin>>value;
            searchByValueUnique(head,searchValue,value);
            break;
        case 7:
            deletionAtHead(head);
            break;
        case 8:
            deletionAtTail(head);
            break;
        case 9:
            if(head==NULL)
            {
                cout<<"There is no value in the linked list"<<endl;
                break;
            }

            cout<<"Enter the Desired Position: ";
            cin>>position;
            deletionAtSpecificPosition(head,position);
            cout<<endl;
            display(head);
            break;
        case 10:
            cout<<"Enter the value to Delete: ";
            int delVal;
            cin>>delVal;
            deletionByValue(head,delVal);
            break;
        case 11:
            head=reverseNonRecursive(head);
            break;
        case 12:
            head=reverseRecursive(head);
            break;
        default:
            break;

        }
        cout<<"Next Choice: ";
        cin>>Choice;
    }
    cout<<"Linked List : ";
    display(head);
    cout<<"Lenght of the list : "<<countLength(head)<<endl;
    return 0;
}


