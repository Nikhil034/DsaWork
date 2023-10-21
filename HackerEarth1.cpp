#include <iostream>
using namespace std;
int main() {
	int num;
	cin >> num;    //Reading input from STDIN
	//cout << "Input number is " << num << endl;	// Writing output to STDOUT

	long int a[num],sum=0; 
	    
	for(int i=0;i<num;i++)   
	   {     
		  cin>>a[i];   
		  sum+=a[i]; 
	   }	
	   
	   cout<<sum;
	   return 0;


       /* 
         
        Test case 1

       5
       1000000001 1000000002 1000000003 1000000004 1000000005

       */
}