#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
 int i,k,n,j,l;
 cout<<"Enter the number of elements in the array";
 cin>>n;
 int a[n];
 for(i=0;i<n;i++)
{
  cin>>a[i];
}

cout<<"Enter the switch case you want\n";
cout<<"1.Linear Search\n2.Binary search\n";
cin>>l;
switch(l)
{
case 1 : int key;
         cout<<"Enter the element you want to search from array\n";
         cin>>key;
         for(i=0;i<n;i++)
         {
          if(a[i]==key)
           {
           cout<<"The index of the key is "<<i<<endl;
           break;
           }

          }
          if(a[i]!=key)
           {
           cout<<"key not found\n";
           }

case 2 : sort (a,a+n) ;
         int  ub,lb,mid;
         cout<<"Enter the element you want to search from array\n";
         cin>>key;
         lb =0 ; ub= n-1;
         while(lb < ub)
         {
          mid = (lb + ub)/2;
          if(a[mid]==key)
          {
           cout<<"key index is"<<mid;
           break;
          }
          else if(key>a[mid])
          {
           lb=mid+1;
          }
          else if (key<a[mid])
         {
         ub = mid -1 ;
         }
        }
        break ;
}
return 0;
}






