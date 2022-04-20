//including required libraries

#include<bits/stdc++.h>
#include<string>
using namespace std;



int main()
{
  int m,n,k,indexrow,indexcol,c; //initialising m,n,k
  bool present = false;          //checks if element is present or not

  cin>>m>>n;                     //getting input
  cin>>k;                       
  int arr[m][n];                 //matrix array


  for (int i = 0; i < m; i++)
  {
     for (int j = 0; j < n;j++)
     {
         cin>>arr[i][j];         //inputs i+1th row j+1th column element
         if(arr[i][j] == k){     //if that element is the one
             present = true;
             indexrow = i;
             indexcol = j;
         }
     }
  }

  if(present) cout<<"TRUE"<<endl; //if that no. is present print True , else false 
  else cout<<"FALSE"<<endl;
  cout<<indexrow<<" "<<indexcol;
  
return 0;

}