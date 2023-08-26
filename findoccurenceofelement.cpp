#include<iostream>
using namespace std;

void CountOccurence(int arr[],int size,int key)
{

  int count=0,flag=0; 

  for(int i=0;i<size;i++)
  {
    if(arr[i]==key)
    {
        flag=1;
        break;
    }
    else
    {
        flag=0;
    }
  }

  if(flag==1)
  {
  for(int i=0;i<size;i++)
  {
    if(arr[i]==key)
    {
        count++;
    }
  }
  cout<<"Key value "<<key<<" occurence count is= "<<count;
  }
  else
  {
    cout<<"KEY VALUE= "<<key<<" DOES NOT EXIST -1";
  }
}

int main(){
    int n;
    
    cout<<"Enter a size of array=";
    cin>>n;

    int arr[n],check;

    for(int i=0;i<n;i++)
    {
        cout<<"index: "<<i <<" = ";
        cin>>arr[i];
    }


    cout<<"Enter key to count occurence=";
    cin>>check;

    CountOccurence(arr,n,check);

    return 0;
}