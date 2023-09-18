#include<iostream>
using namespace std;

int main(){
    
    char ch[3][4];

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>ch[i][j];
        }
    }

      for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<ch[i][j]<<" ";
        }
        cout<<"\n";
    }

    char wrd[5];
    int w=0,is_find=0;


    cout<<"Enter your word=";
    cin>>wrd;

    for(int i=0;i<3;i++)
    {

        for(int j=0;j<4;j++)
        {
             if(wrd[w]==ch[i][j])
             {
                is_find=1;
                w++;
             }   
        }
    }

    if(is_find==0)
    {
        cout<<"NOT FIND WORD!";
    }
    else
    {
        cout<<"FIND RETURN TRUE!";
    }

    return 0;
}