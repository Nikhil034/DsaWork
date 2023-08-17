#include<iostream>
#define size 5
int queue[size];
int f=-1,r=-1;
using namespace std;

int isFull()
{
    if(r==size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if(f==-1 && r==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue()
{
    int val;

    if(isFull())
    {
        cout<<"QUEUE IS FULL!";
    }
    else
    {
        cout<<"Enter a value=";
        cin>>val;
        r++;
        queue[r]=val;

        if(f==-1)
        {
            f=0;
        }
        
    }

}
void dequeue()
{
    int delval;
    if(isEmpty())
    {
        cout<<"QUEUE IS UNDERFLOW!";
    }
    else
    {
        delval=queue[f];
        f++;
        cout<<"DEQUEUE VALUE IS="<<delval;
    }
}
void display()
{
    if(isEmpty())
    {
        cout<<"QUEUE IS EMPTY";
    }
    else
    {
        for(int i=f;i<=r;i++)
        {
            cout<<queue[i]<<" | ";
        }
    }
}

int main(){

    int n;
    do
    {
        cout<<"\n1.ENQUEUE \n2.DEQUEUE \n3.DISPLAY \n0.EXIT\n";

        cout<<"Enter your use case=";
        cin>>n;

        switch (n)
        {
        case 1:enqueue();
               break;
        case 2:dequeue();
               break;
        case 3:display(); 
               break;
        case 4:exit(0);                      
        default:cout<<"CASE NOT FOUND!";
                break;
        }
    
    } while (n!=0);
       
    return 0;
}