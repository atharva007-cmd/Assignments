#include<iostream>
using namespace std;
void st_reverse(char *p);
int st_length(char *pt);
void st_concantenate(char *sp,char *s2p);


int main()
{
int c;
char s[10],s2[10];
cout<<"enter the string"<<endl;                                             ///////////a b h i
cin>>s;

cout<<"select from the following options:-"<<endl;
cout<<"1::REVERSE THE STRING"<<endl<<"2::ADD ANOTHER STRING TO IT"<<endl;

cin>>c;

switch(c)
{
 case 1:st_reverse(s);
        break;
 case 2:cout<<"enter other string"<<endl;
        cin>>s2;
        st_concantenate(s,s2);
        break;
}
return 0;
}



/////////////////////////////////////////////////////REVERSE STRING///////////////////////////////////////////////////////////

void st_reverse(char *p)
{
int i,l;
char temp;
l=st_length(p);
for(i=0;i<l/2;i++)
{
temp=*(p+i);
*(p+i)=*(p+(l-i-1)*sizeof(char));
*(p+(l-i-1)*sizeof(char))=temp;
}
i=0;
while(*(p+i)!='\0')
{
cout<<*(p+i);
i++;
}
}


////////////////////////////////////////////////////LENGTH OF STRING//////////////////////////////////////////////////////////

int st_length(char *pt)
{
int i,l=0;
for(i=0;*(pt+i)!='\0';i++)
{
l++;
}
return l;

}
//////////////////////////////////////////////////CONCANTANATE STRING////////////////////////////////////////////////////////

void st_concantenate(char *sp,char *s2p)
{
int i,l1,l2,j;
char s3[20];
l1=st_length(sp);
l2=st_length(s2p);
for(i=0;i<l1;i++)
{
*(s3+i*sizeof(char))=*(sp+i*sizeof(char));
}
for(i=l1,j=0;i<l1+l2 && j<l2;i++,j++)
{
*(s3+i*sizeof(char))=*(s2p+j*sizeof(char));
}
cout<<s3;
}
////////////////////////////////////////////////////COMPARE?////////////////////////////////////////////////////////////

void st_compare(char*c1,char *c2)
{



