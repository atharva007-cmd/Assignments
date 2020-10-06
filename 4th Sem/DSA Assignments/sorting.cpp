#include<iostream>
#include<algorithm>
using namespace std;

int selection_sort(int *a , int n)
{
 int minindex ,i,j,k,temp ;
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



int main()
{
 int i,j,k,l,count=0,n, temp;
 cout<<"Enter the number of elements you want\n";
 cin>>n;
 int a[n];
 cout<<"Enter the array elements\n";
 for(i=0;i<n;i++)
 {
 cin>>a[i];
 }
 cout<<"1.Selection sort \n2.Insertion sort\n3.Linear Search\n4.Binary Search";
 cout<<"\nEnter the case u  want\n";
 cin>>l;
 switch(l)
{
 case 1 :selection_sort(a , n);
         break;

 case 2 :insertion_sort(a , n);
         break;

 case 3 :linear_search(a , n);
         break;

}
return 0;
}
