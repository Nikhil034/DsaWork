#include<iostream>
using namespace std;

int main(){
    
    int r,c,arr[4][7],start,end,first=3,f1=0,f2;
    start=first-1;  // 2 1 0
    end=first+1;  // 4 5 6

    for(r=0;r<4;r++)
    {
        for(c=0;c<7;c++)
        {
           
           arr[r][c]=0;

        }

    }

      for(r=0;r<4;r++)
    {
        if(r==0)
        {
            arr[r][first]=1;
        }
        else
        {
        
          for(c=start;c<=end;c++)
          {
            arr[r][c]=1;
          }
          start--;
          end++;
        }


    }

     for(r=0;r<4;r++)
    {
        for(c=0;c<7;c++)
        {
            cout<<arr[r][c]<<" ";
        }
        cout<<"\n";
    }

    
    return 0;
}