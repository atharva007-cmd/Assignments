#include<iostream>
#include<string.h>
using namespace std;
struct 	student 
{
   int roll;
   string name;
   float percent;
}s[100];
int main()
{
   int i,l,n,m,a,z,k,temp,j;
   cout<<"Enter the number of enteries do you want"<<endl;
   cin>>n;
   cout<<"Roll No."<<"\t"<<"Name"<<"\t"<<"Percent"<<endl;
   for(i=0;i<n;i++)
   {
      cin>>s[i].roll>>s[i].name>>s[i].percent;
   }
   cout<<"Roll No."<<"\t"<<"Name"<<"\t"<<"Percent"<<endl;
   for(i=0;i<n;i++)
   {
     cout<<s[i].roll<<"\t"<<s[i].name<<"\t"<<s[i].percent<<endl;
   }
   cout<<"choose the following operation"<<endl;
   cout<<"1.Addtion	2.Delete	3.Search	4.Sort"<<endl;
   cin>>l;
   switch(l)
   {
      case 1:cout<<"How many enteries do you want add?"<<endl;
             cin>>m;
             m=m+n; 
             for(i=n;i<m;i++)
             {
                cin>>s[i].roll>>s[i].name>>s[i].percent;
             }
             cout<<"Modified list is:"<<endl;
             cout<<"Roll No."<<"\t"<<"Name"<<"\t"<<"Percent"<<endl;
             for(i=0;i<m;i++)
             {
               cout<<s[i].roll<<"\t"<<s[i].name<<"\t"<<s[i].percent<<endl;
             }
             n=n+m;
             break;
      case 2:cout<<"Enter the roll number do you want to delete"<<endl;
             cin>>a;
             for(i=0;i<n;i++)
             {
                if(s[i].roll==a)
                {
                   for(j=i;j<n;j++)
                   {
                      s[j].roll=s[j+1].roll;
                      s[j].name=s[j+1].name;
                      s[j].percent=s[j+1].percent;
                   }
                   break;
                 }
              }
              cout<<"Roll No."<<"\t"<<"Name"<<"\t"<<"Percent"<<endl;
              for(i=0;i<n-1;i++)
              {
                 cout<<s[i].roll<<"\t"<<s[i].name<<"\t"<<s[i].percent<<endl;
              } 
              break;     
                 
                
      case 3:cout<<"Enter the roll number do you want to search"<<endl;
             cin>>k;
             for(i=0;i<n;i++)
             {
                 if(s[i].roll==k)
                 {
                     cout<<"Roll No."<<"\t"<<"Name"<<"\t"<<"Percent"<<endl;
                     cout<<s[i].roll<<"\t"<<s[i].name<<"\t"<<s[i].percent<<endl;
                     break;
                 }
             }
             break;
      case 4:
                         
   }
   return 0;
}
































     
    
