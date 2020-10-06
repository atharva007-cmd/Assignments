#include<iostream>
using namespace std;

 
class student
{
      private:
            int rno, dob, contact, license_no, marks[6], total;
            char name[20];
            char class1[10];
            char division[5];
            char bgroup[10];
            char address1[50];
            float avg;
      public:
            void initialize();
            friend class fstudent;
};
 
class fstudent       // friend class used here
{
       public:
            void totavg(student &);
            void display(student);
};

void student::initialize() 
{
            int i;
            cout<<"Roll Number: ";    cin>>rno;
            cout<<"Name: ";        cin>>name;
            cout<<"Class: ";        cin>>class1;
            cout<<"Division: ";     cin>>division;
            cout<<"Date of Birth: ";   cin>>dob;
            cout<<"Blood Group: ";    cin>>bgroup;
            cout<<"Address: ";  cin>>address1;
            cout<<"Mobile Number: ";     cin>>contact;
            cout<<"Driving License Number: "; cin>>license_no;
            cout<<"Marks in 3 Subjects: ";
            for(i=0; i<3; i++) cin>>marks[i];
}

void fstudent::totavg(student & st1) 
{
            int i,sum=0;
            for(i=0; i<3; i++)         sum=sum+st1.marks[i];
            st1.total=sum;
            st1.avg=st1.total/3.0;
}

void fstudent::display(student st2) 
{
            int i;
            cout<<st2.rno<<"          |   "<<st2.name<<"             |    " <<st2.class1<<"          |  " <<st2.division<< "       |   " <<st2.dob<<"         |  " <<st2.bgroup<<"          |  " <<st2.address1<<"        |  "<<st2.contact<<"    | " <<st2.license_no<<"    |   ";
            for(i=0; i<3; i++) cout<<st2.marks[i]<<"   |  ";
            cout<<"  | "<<st2.total<<" "<<st2.avg<<endl;
}

int main() 
{
            student st[5]; 
            fstudent fst; 
            int rno,i;
            cout<<"No. of Students: ";
            cin>>rno;
            for(i=0; i<rno; i++)
            {
                        cout<<"Student "<<i+1<<"\n";
                        st[i].initialize();
            }
            for(i=0; i<rno; i++)                       
            fst.totavg(st[i]);
            cout<<"\nRoll Number  | Name                |  Class         |  Division  | Date of Birth | Blood Group | Address      |  Contact No. | License No.  |  Marks          | Total and Average of ";
            cout<<rno<<" students:\n";
            cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            for(i=0; i<rno; i++)                       
            fst.display(st[i]);
            return 0;
}