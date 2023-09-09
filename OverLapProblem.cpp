#include<iostream>
using namespace std;

int main(){
    int n,flag=0,sum=0,ans=0;
    cout<<"Enter a size=";
    cin>>n;
      
    int val[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter a value=";
        cin>>val[i];
    }  


   int start[n],end[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter start of meeting no ="<<i+1<<"Time:-";
        cin>>start[i];
    }  

     for(int i=0;i<n;i++)
    {
        cout<<"Enter End of meeting no ="<<i+1<<"Time:-";
        cin>>end[i];
    } 

    cout<<"\n----PERSON IN MEETING---\n";

     for(int i=0;i<n;i++)
    {
       cout<<val[i]<<" ";
    }  

    cout<<"\n----START MEETING TIME---\n";

     for(int i=0;i<n;i++)
    {
       cout<<start[i]<<" ";
    } 

    cout<<"\n----END MEETING TIME---\n";

     for(int i=0;i<n;i++)
    {
       cout<<end[i]<<" ";
    } 


    for(int st=0;st<n;st++)
    {
        for(int en=st+1;en<n;en++)
        {
           if(start[st]==end[en])
           {
             break;
           }
           else
           {
            flag=st+1;
           }
        }
    }

    for(int h=0;h<n;h++)
    {
        sum+=val[h];
    }
    for(int v=0;v<flag;v++)
    {
        ans+=val[v];
    }

    cout<<"\nTotal person is meeting is="<<sum-ans;









    return 0;
}