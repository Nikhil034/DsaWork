#include<iostream>
using namespace std;
struct Node
{
 int data;
 struct Node *Next;
};

struct Node *head=NULL;
void InsertFirst();
void InsertLast();
void InsertAscending();
void DeleteNode();
void ShowNodes();
void CopyNodes();
void ReverseNodes();


int main()
{
 int ch;
 do
 {
 cout<<"\n 1.InsertFist \n 2.InsertLast \n 3.DisplayNode \n 4.InsertAscending \n 5.DeleteNode \n 6.CopyNodes \n 7.ReverseNodes \n 8.Exit";
 
 cout<<"\nPass your case=";
 cin>>ch;
 switch (ch)
 {
 case 1:InsertFirst();
 break;
 case 2:InsertLast();
 break;
 case 3:ShowNodes();
 break;
 case 4:InsertAscending();
 break; 
 case 5:DeleteNode();
 break; 
 case 6:CopyNodes();
 break; 
 case 7:ReverseNodes();
 break;
 case 8:exit(0);
 default:cout<<"No case found warning pass!";
 break;
 }
 } while (ch!=7);
 return 0;
}
void InsertFirst()
{
 int no;
 struct Node *newnode;
 cout<<"Enter node value=";
 cin>>no;
 newnode=(struct Node *)malloc(sizeof(struct Node));
 newnode->data=no;
 newnode->Next=head;
 head=newnode;
}
void InsertLast()
{
 int no;
 struct Node *newnode,*p;
 newnode=(struct Node *)malloc(sizeof(struct Node));
 cout<<"Enter node value=";
 cin>>no;
 
 if(head==NULL)
 {
 newnode->data=no;
 newnode->Next=head;
 head=newnode;
 }
 else
 {
 p=head;
 while(p->Next!=NULL)
 {
  p=p->Next;
 }
 newnode->data=no;
 newnode->Next=NULL;
 p->Next=newnode;
 }
}
void InsertAscending()
{
 int val;
 struct Node *newnode;
 struct Node *temp;
 struct Node *previous; 
 //create new node
 newnode= (struct Node *)malloc(sizeof(Node)); 
 if(newnode == NULL) 
 {
 cout<<"Insufficient memory.";
 return;
 } 
 cout<<"Enter a value=";
 cin>>val;
 newnode->data = val;
 newnode -> Next = NULL; 
 if (head == NULL) 
 { 
 head=newnode;
 } 
 //If value is less than the value of first node
 else if(val < head->data) 
 {
 newnode->Next=head;
 head=newnode;
 } 
 else 
 { 
 previous = head;
 temp = head->Next;
 //Go to the position where node is to be inserted
 while(temp != NULL && val > temp->data) 
 {
 previous = temp;
 temp = temp -> Next;
 }
 //Insert the node at particular position
 if(temp == NULL) 
 {
 previous -> Next = newnode;
 } 
 else 
 {
 newnode->Next=temp;
 previous->Next=newnode;
 }
 }
}
void DeleteNode()
{
 int del;
 struct Node *ptr,*tmp,*prev;
 ptr=head;
 cout<<"Enter node value you delete=";
 cin>>del;
 if(head->data==del)
 {
 tmp=head;
 head=head->Next;
 free(tmp);
 }
 else
 {
 while(ptr->data!=del)
 {
 prev=ptr;
 ptr=ptr->Next;
 }
 tmp=ptr;
 prev->Next=ptr->Next; 
 free(tmp);
 }
}
int CountNodes()
{
 int count=0;
 struct Node *ptr=head;
 while(ptr!=NULL)
 {
 count++;
 ptr=ptr->Next;
 }
 return count;
}
void CopyNodes()
{
 int nodes;
 struct Node *OriginalNode,*p;
 OriginalNode=head;
 nodes=CountNodes();
 struct Node *newnode[nodes];
 
 for(int i=0;i<nodes;i++)
 {
 newnode[i]=(struct Node *)malloc(sizeof(struct Node));
 newnode[i]->data=OriginalNode->data;
 newnode[i]->Next=OriginalNode;
 OriginalNode=OriginalNode->Next;
 cout<<" "<<newnode[i]->data;
 
 }
 
}
void ReverseNodes()
{
    
     struct Node* current = head;
     struct Node *prev = NULL, *Next = NULL;
 
        while (current != NULL) {
            // Store next
            Next = current->Next;
            // Reverse current node's pointer
            current->Next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = Next;
        }
        head = prev;

    struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->Next;
        }    
    

}
void ShowNodes()
{
 struct Node *p;
 if(head==NULL)
 {
 cout<<"LinkList is empty!";
 }
 else
 {
 p=head;
 while (p!=NULL)
 {
 cout<<" "<<p->data;
 p=p->Next;
 }}}
