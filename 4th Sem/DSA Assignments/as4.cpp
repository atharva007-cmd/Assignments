#include<iostream>
using namespace std;
//////////////////////////////////////////////////////////SELECTION SORT/////////////////////////////////////////////////
int selection_sort(int *a , int n)
{
 int minindex ,i,j,k,temp,chk ;
  cout<<"The pass wise output is\n\n";
 for(i=0;i<n;i++)
 {
 minindex=i;

 for(j=i+1 ;j<n;j++)
  {
   if(a[j]<a[minindex])
     {
     minindex=j;
     }
  }
  temp=a[minindex];
  a[minindex]=a[i];
  a[i]=temp;
  if(chk==0)
  {
  cout<<"pass "<<i+1<<endl;
   for(k=0;k<n;k++)
     {
       cout<<a[k]<<" ";
     }
     cout<<endl;
  }
 }


 cout<<"\nThe sorted list is \n";
 for(i=0;i<n;i++)
{
 cout<<a[i]<<" ";
}

}
//////////////////////////////////////////////////////////////INSERTION SORT///////////////////////////////////////////////
int insertion_sort(int *a , int n)
{
int key,i,j,k,temp;
cout<<"The pass wise output is\n\n";
for(i=0;i<n;i++)
    { j=i;
         while(j>0 && a[j]>a[j-1])
            {
             temp=a[j];
             a[j]=a[j-1];
             a[j-1]=temp;
             j--;

            }
 cout<<"pass "<<i+1<<endl;
 for(k=0;k<n;k++)
     {
       cout<<a[k]<<" ";
     }
       cout<<endl;
    }
cout<<"\nThe sorted list is \n";
for(i=0;i<n;i++)
   {
    cout<<a[i]<<" ";
   }
}
///////////////////////////////////////////////////////LINEAR SEARCH//////////////////////////////////////////////////////
int linear_search(int *a , int n)
{
    int key,i;
         cout<<"Enter the element you want to search from array\n";
         cin>>key;
         for(i=0;i<n;i++)
         {
          if(a[i]==key)
           {
           cout<<"The index of the key is "<<i<<endl;
           i=-1;
           break;
           }
         }
           if(a[n-1]!=key && i!=-1)
           {
           cout<<"key not found\n";

          }
}
////////////////////////////////////////////////////////////////////BINARY SEARCH//////////////////////////////////////////
int bin_search( int *a , int n )
{
         int chk=1;
         selection_sort(a , n);
         int key ,ub,lb,mid;
         cout<<"Enter the element you want to search from array\n";
         cin>>key;
         lb =0 ;
         ub= n-1;
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
}

////////////////////////////////////////////////////////////////////MAIN////////////////////////////////////////////////////
int main()
{
 int i,j,k,l,count=0,n, temp,chk=0;
 p :cout<<"\n1.Selection sort \n2.Insertion sort\n3.Linear Search\n4.Binary Search\n5.Exit\n";
 cout<<"\nEnter the case u  want\n";
 cin>>l;
cout<<"\nEnter the number of elements you want\n";
 cin>>n;
 int a[n];
  cout<<"Enter the array elements\n";
 for(i=0;i<n;i++)
 {
 cin>>a[i];
 }

 switch(l)
{
 case 1 :selection_sort(a , n);
         goto p ;

 case 2 :insertion_sort(a , n);
         goto p ;

 case 3 :linear_search(a , n);
         goto p ;

 case 4 :bin_search(a , n);
         goto p ;

 case 5 :break ;
 }
return 0;
}
