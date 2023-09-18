#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class RandomWork
{
    vector<int>vec;
    int i=0;
    

 public:
       RandomWork()
      {
         cout<<"created!";
      }
      bool insert(int n)
      {
         vec.push_back(n);
         i++;
         return true;
      }
      bool remove(int n)
      {
        int is_there=0;

        for(int i=0;i<vec.size();i++)
        {
            if(n==vec[i])
            {
                 is_there=1;
                 break;
            }

            if(is_there==1)
            {
                vec.erase(std::remove(vec.begin(), vec.end(), n), vec.end());
                return true;
            }
            else
            {
                return false;
            }
        }
      }
      int getrandom()
      {
        int random = 0 + (rand() % vec.size());
        return vec[random];
      }
};

int main(){
    
    RandomWork obj;
    cout<<"\n"<<obj.insert(1);
    cout<<"\n"<<obj.remove(2);
    cout<<"\n"<<obj.insert(2);
    cout<<"\n"<<obj.getrandom();
    cout<<"\n"<<obj.remove(1);




    return 0;
}