#include<iostream>
using namespace std;

int str_len(char *p)
{
 int i=0,j;
 while(*p != '\0')
 {
     i++;
 p++;
 }
 cout<<"lenght of string is  "<<i<<endl;
return i;
}

int str_con(char *p1 , char *p2)
{
 while(*p1 != '\0')
 {
     cout<<*p1;
     p1++;
 }
 p1 = p2 ;
 while(*p1 != '\0')
 {
    cout<<*p1;
    p1++;
 }
return -1 ;
}

int reverse(char *p1 ,int len )
{
 int l=len,j;
 char *i ,temp ;
 i=p1 ;
 for(j=0;j<len/2;j++)
 {
     temp=*i ;
     *i =  * ((p1)+((l-1)*sizeof(char)));
     *((p1)+((l-1)*sizeof(char))) = temp;
     i++;
     l--;
 }

 while(*p1 != '\0')
 {
     cout<<*p1;
     p1++;
 }
return 0 ;
}


int main()
{
 int i=0,j,len=0;
 char *p1,*p2 ,str1[50] , str2[50] ;
  cout<<"Enter the string\n";
  cin>>str1;
  while(str1[i] != '\0')
        {
           len ++;
           i++;
        }

  p1=str1;
  cout<<"\n1.String lenght\n2.String concatenate\n3.String reverse"<<endl;
  cout<<"Enter the operation you want to perform"<<endl;
  cin>>j;
  switch(j)
 {
 case 1 : str_len(p1);
          break;

 case 2 : cout<<"Enter the second string you want to concatenate ";
          cin>>str2;
          p2=str2 ;
          str_con(p1 ,p2);
          break;

 case 3 : reverse(p1 , len);
          break;
 }
return 0;
}


