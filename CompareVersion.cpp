#include<iostream>
using namespace std;

int CheckVersion(string v1,string v2)
{
     int flag=0;

    for(int i=0;i<v1.size();i++)
    {
       if(v1[i]=='.')
       {
         continue;
       } 
       else
       {
        if(v1[i]<v2[i])
        {
            flag=-1;
        }
        else if(v1[i]==v2[i])
        {
            flag=0;
        }
        else
        {
          flag=1;
        }
       } 
    }
    return flag;

}

int main(){
    
    string ver1="1.2.4";
    string ver2="1.2.3";

    cout<<CheckVersion(ver1,ver2);
    
    
    


    return 0;
}