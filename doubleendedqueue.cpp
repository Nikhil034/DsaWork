#include<iostream>
#define size 5
int f=-1;
int r=-1;
int queue[size];
using namespace std;

int isEmpty()
{
    if(f==-1 && r==-1 || f==size-1)
    {
       return 1;
    }
    else
    {
        return 0;
    }
}
int isFull()
{
    if(f==0 && r==size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void EnqueuFront()
{
    int val;
    if(isFull())
    {
        cout<<"QUEUE IS ALREADY FULL!";
    }
    else
    {
        cout<<"Enter a value";
        cin>>val;
        r++;
        queue[r]=val;

        if(f==-1)
        {
            f=0;
        }

    }
}
void EnqueuBack()
{
    int val;
    if(isFull())
    {
        cout<<"QUEUE IS ALREADY FULL!";
    }
    else
    {
        if(r==size-1 || f==r-1)
        {
           cout<<"NOT POSSIBLE";
        }
        else
        {
            cout<<"Enter a back value=";
            cin>>val;
            f=size-1;
            queue[f]=val;
            f--;
        }
    }
    f=0;
}
void DequeuFront()
{
    int delval;
    if(isEmpty())
    {
        cout<<"QUEUE IS EMPTY!";
    }
    else
    {
        delval=queue[f];
        cout<<"QUEUE VALUE FROM FRONT="<<delval;
        f++;
    }
}
void DequeueBack()
{
   int delval;
   int tmp=r-1;
   if(isEmpty())
   {
    cout<<"QUEUE IS EMPTY!";
   }
   else
   { 
    delval=queue[tmp];
    cout<<"BACK VALUE="<<delval;
    tmp--;
   }
   r=tmp;
}
void DisplayQueue()
{
    if(isEmpty())
    {
        cout<<"QUEUE IS EMPTY!";
    }
    else
    {
        for(int i=f;i<=r-1;i++)
        {
            cout<<queue[i]<<" | ";
        }
    }
}
int main(){
    
    int ch;
    do
    {
        cout<<"\n 1.Enqueue Front \n 2.Enqueue Back \n 3.Dequeue Front \n 4.Dequeue Back \n 5.Display \n 0.Exit\n";

        cout<<"PASS YOUR USE CASE=";
        cin>>ch;

        switch (ch)
        {
        case 1:EnqueuFront();
               break;
        case 2:EnqueuBack();
               break;     
        case 3:DequeuFront();
               break;       
        case 4:DequeueBack();
               break;
        case 5:DisplayQueue();
               break;
        case 0:exit(0);                       
        default:cout<<"CASE NOT FOUND!";
            break;
        }
    
    } while (ch!=0);
    


    return 0;
}