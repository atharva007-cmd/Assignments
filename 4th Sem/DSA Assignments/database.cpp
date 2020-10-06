#include<iostream>
#include<string>
using namespace std;


struct stud
{
   int roll;
   string name;
};

int main()
{
  stud s[100];
   int n,a,m,i,k,d,h,j,temp1,dj,RON;
   string temp2;
   cout<<"Enter the number of enteries"<<endl;
   cin>>n;

   for(i=0;i<n;i++)
   {
      cout<<"Enter r.no of "<<i+1<<" student"<<endl;
      cin>>s[i].roll;
      cout<<"Enter his name"<<endl;
      cin>>s[i].name;
   }


  for(i=0;i<n-1;i++)
   {
    for(j=0;j<n-i-1;j++)
     {
      if(s[j].roll>s[j+1].roll)
       {
         temp1=s[j].roll;
         temp2=s[j].name;
         s[j].roll=s[j+1].roll;
         s[j].name=s[j+1].name;
         s[j+1].roll=temp1;
         s[j+1].name=temp2;
       }

     }
   }


 p:
   cout<<"wht do u want to do"<<endl;
   cout<<"1:print record"<<endl<<"2:add record"<<endl<<"3:delete record\n"<<"4:search record by Roll no."<<endl;

   cin>>a;


   switch(a)
   {
    case 1:
        cout<<"have u added any record afterwords"<<endl<<"type 1 if YES and type 0 if NO"<<endl;
       cin>>h;

             if(h==0)
             {

               for(i=0;i<n;i++)
                {
                  cout<<"data of"<<i+1<<"student is:"<<endl;
                  cout<<s[i].roll<<endl;
                  cout<<s[i].name<<endl;
                }
             }

            if(h==1)
            {
              for(i=0;i<n+m;i++)
               {
                cout<<"data of"<<i+1<<"student is:"<<endl;
                cout<<s[i].roll<<endl;
                cout<<s[i].name<<endl;
               }
            }
     goto p;
     break;

    case 2:
       cout<<"how many more records u want to add";
       cin>>m;

           for(i=n;i<m+n;i++)
           {
            cout<<"r.no of "<<i<<"student is:"<<endl;
            cin>>s[i].roll;
            cout<<"his name is:"<<endl;
            cin>>s[i].name;
           }
            cout<<"records added";

           goto p;

        break;

     case 3:

        cout<<"have u added any record earlier"<<endl<<"Type 1 if YES,0 for NO"<<endl;
        cin>>d;

        cout<<"enter rollno to delete"<<endl;
        cin>>k;
        for(i=0;i<n;i++)
        {
         if(k==s[i].roll)
         {
          break;
         }
        }
        if(d==0)
        {
        for(j=i;j<n;j++)
        {
         s[j].roll=s[j+1].roll;
         s[j].name=s[j+1].name;
        }

        }

         if(d==1)
        {
        for(j=i;j<n+m;j++)
        {
         s[j].roll=s[j+1].roll;
         s[j].name=s[j+1].name;
        }

        }

        cout<<"record deleted succesfully";
        goto p;
        break;


    case 4:

        cout<<"have u added any record earlier"<<endl<<"Type 1 if YES,0 for NO"<<endl;
        cin>>dj;
        cout<<"enter the roll no. to search"<<endl;
        cin>>RON;
        if(dj==0)
        {
        for(j=0;j<n;j++)
        {
          if(s[j].roll==RON)
           {
            break;
           }
         }
         cout<<"name of student u searched is:"<<s[j].name<<endl;
        }

         if(dj==1)
        {
         for(j=0;j<n+m;j++)
         {
          if(s[j].roll==RON)
           {
            break;
           }
         }
         cout<<"name of student u searched is:"<<s[j].name<<endl;
        }
        goto p;
        break;

    }
    return 0;
    }




