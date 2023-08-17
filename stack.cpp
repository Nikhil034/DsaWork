#include<iostream>
#define size 5
using namespace std;

int stk[size];
int top=-1;

int isFull()
{
    if(top==size-1)
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
    if(top<0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void pop()
{
    int delval;
    if(isEmpty())
    {
        cout<<"STACK IS UNDERFLOW!";
    }
    else
    {
        delval=stk[top];
        top--;
        cout<<"POP VALUE IS="<<delval;
    }

}
void push()
{
    int val;
    if(isFull())
    {
        cout<<"STACK OVERFLOW!";
    }
    else
    {
       cout<<"Enter a value=";
       cin>>val;
       top++;
       stk[top]=val;
    }
}
void display()
{
    if(isEmpty())
    {
        cout<<"STACK IS EMPTY NOTHING TO DISPLAY!";
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            cout<<stk[i]<<" | ";
        }
    }
}


int main(){
    
    int ch,n;
    n=1;

    do
    {
        cout<<"\n1.PUSH \n2.POP \n3.DISPLAY \n0.EXIT\n";

        cout<<"Enter what you do=";
        cin>>n;

        switch (n)
        {
        case 1:push();
               break;
        case 2:pop();
               break;
        case 3:display();
               break; 
        case 0:exit(0);                    
        default:cout<<"CASE NOT FOUND!";
            break;
        }
    }while(n!=0);

    return 0;
}