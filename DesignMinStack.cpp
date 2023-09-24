#include<iostream>
using namespace std;

#define size 10



class Stack
{
    int stk[size];
    int top=-1;
    
 public:
     Stack()
    {
        cout<<"STACK CREATED!";
    }
    int push(int val)
    {
        if(top==size-1)
        {
            return 0;
        }
        else
        {
           top++;
           stk[top]=val;
           return 1;
        }
    }
    int pop()
    {
        if(top<0)
        {
            return 0;
        }
        else
        {
            int val=stk[top];
            top--;
            return val;
        }
    }
    int getMin()
    {
        int min=stk[top];
        for(int i=0;i<top;i++)
        {
           if(min>stk[i])
           {
            min=stk[i];
           }
        }
        return min;

    }
    int topget()
    {
        return stk[top];
    }
    void print()
    {
        for(int i=top;i>=0;i--)
        {
            cout<<stk[i]<<" ";
        }
    }

};


int main(){
    
    Stack obj;
    cout<<"\n"<<obj.push(2);
    cout<<"\n"<<obj.push(0);
    cout<<"\n"<<obj.push(-3);
    cout<<"\n"<<obj.push(-10);
    // cout<<"\n"<<obj.getMin();
    obj.print();

    return 0;
}