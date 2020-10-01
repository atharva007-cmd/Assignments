//Student database code
#include <iostream>
using namespace std;
struct stu
{
    int roll;
    string name;
};
void sorrec(stu s[],int num) //Sorting
{
    int i,j;
    stu temp;
    for(i=0;i<=num;i++)
    {
        for(j=0;j<=num;j++)
        {
            if(s[j].roll>s[j+1].roll)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}
void disrec(stu s[],int num) //Display
{
    int i;
    cout<<"Student's Database :\n";
    for(i=0;i<num;i++)
    {
        cout<<"Roll number : "<<s[i].roll<<endl;
        cout<<"Name : "<<s[i].name<<endl;
        cout<<"*************************"<<endl;
    }
}
stu bsea(stu s[],int t,int b,int e) //Binary Search
    {
      while (b <= e)
      {
        int m = b + (e-b)/2;
        if (s[m].roll == t)
            return s[m];
        if (s[m].roll < t)
            b = m + 1;
        else
             e = m - 1;
      }
      return s[-1];
    }
int main()
{
    stu s[10],temp;
    int num=0;
    int i,k=0,sw,add,t;
    cout<<"**********  Student Database  ***********\n";
    while(k!=1)
    {
        cout<<"Select:\n1. Add Record\n2. Display Record\n3. Sort Record\n4. Delete Record\n5. Search\n6. Modify record\n7. Exit\n";
        cin>>sw;
        switch(sw)
        {
            case 1:
                cout<<"How many records do you want to add?\n";
                cin>>add;
                cout<<"Enter Details:\n";
                for(i=num;i<num+add;i++)
                {
                    cout<<"Enter Roll number:";
                    cin>>s[i].roll;
                    cout<<"Enter Name:";
                    cin>>s[i].name;
                }
                num=num+add;
                break;
            case 2:
                disrec(s,num);
                break;
            case 3:
                sorrec(s,num);
                break;
            case 4:
                cout<<"Enter Roll number of the student you want to delete record of:";
                cin>>t;
                for(i=0;i<num;i++)
                {
                    if(s[i].roll==t)
                    {
                        s[i].roll=NULL;
                        s[i].name='\0';
                        break;
                    }
                }
                break;
            case 5:
                cout<<"Enter the roll number:";
                cin>>t;
              temp=bsea(s,t,s[0].roll,s[num-1].roll);
                cout<<"Your Searched Record : \nRoll number : "<<temp.roll<<endl<<"Name : "<<temp.name<<endl;
                break;
            case 6:
                cout<<"Enter roll number of the record you wish to modify : ";
                cin>>t;
                for(i=0;i<num;i++)
                {
                    if(s[i].roll==t)
                    {
                        cout<<"Enter Roll number : ";
                        cin>>s[i].roll;
                        cout<<"Enter Name : ";
                        cin>>s[i].name;
                        break;
                    }
                    else
                    {
                        cout<<"Roll Number not found\n";
                    }
                }
                break;
            case 7:
                k=1;
                break;
                default:
                cout<<"Invalid Selection\n";
        };
    }
    return 0;
}
