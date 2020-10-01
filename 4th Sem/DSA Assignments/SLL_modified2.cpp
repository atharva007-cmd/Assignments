#include<iostream>
using namespace std;

struct node{

int data ;
struct node *next;
};

struct node * create_sll(struct node *h)
{

 struct node *temp , *nn;

 nn = new node ;
 cin>>nn->data;
 nn->next = NULL ;

   if (h == NULL)
   {
    h=nn;
   }
   else
   {
    temp=h ;
    while(temp->next!=NULL)
    {
    temp=temp->next;
    }
    temp->next = nn ;
   }
 return h ;
}

struct node * display_sll(struct node * h)
{
 struct node *temp;
 temp = h ;
 cout<< "The Data stored is" <<endl ;
 while(temp!=NULL)
 {
  cout << temp->data <<" ";
  temp = temp->next ;
 }
 cout<<endl;
 return h ;
}

struct node * append(struct node * h)
{
 struct node *nn , *temp ;
 nn= new node ;
 cout<<"Enter the data "<< endl ;
 cin>> nn->data ;
 nn ->next =NULL ;
 temp = h ;
 while(temp->next!=NULL)
 {
  temp = temp->next ;
 }
 temp->next =nn ;
 return h ;
}

struct node * insrt_begin(struct node * h)
{
 struct node *nn , *temp ;
 nn= new node ;
 cout<<"Enter the data "<< endl ;
 cin>> nn->data ;
 nn ->next = NULL ;
 nn->next  = h ;
 h = nn ;
 return h ;
}

struct node * insrt_pos( struct node * h)
{
 struct node *nn , *temp ;
 int i=0 ,pos ;
 nn= new node ;
 cout<<"Enter the data "<< endl ;
 cin>> nn->data ;
 nn ->next = NULL ;
 cout<<"Enter the Position "<<endl;
 cin>>pos;
 temp = h ;
 while(i<pos-1)
 {
  temp =temp->next;
  i++;
 }
 nn->next   = temp->next ;
 temp->next = nn;

 return h ;
 }

 struct node * del_pos( struct node * h)
 {
     struct node *temp , *t ;
     int pos,i=0;
     cout<<"Enter the position to delete"<<endl;
     cin>>pos;
     temp=h;
     while(i<pos)
     {
         t = temp ;
         temp=temp->next;
         i++;
     }
     t->next=temp->next ;
     temp->next = NULL ;
     delete(temp);
     return h ;
 }

 struct node * del_begin( struct node * h)
 {
     struct node *temp ;
     temp =h;
     h = temp->next ;
     temp->next = NULL ;
     delete(temp);
     return h ;
 }

 struct node * del_end( struct node * h)
 {
    struct node *temp;
    temp = h ;
    do
    {
     temp = temp->next ;
    }while(temp->next!=NULL);
    delete(temp);
    return h ;
 }

 struct node * modify( struct node * h)
 {
     struct node *temp ;
     int i,j;
     temp = h ;
     cout<<"Enter the Data you want to modify\n";
     cin>>i;
     cout<<"\nEnter the data you want to enter\n";
     cin>>j;
     while(temp->next != NULL)
     {
         temp = temp->next;
         if(temp->data == i)
         {
            temp->data = j ;
            break;
         }
     }
     if(temp->next == NULL)
     {
         cout<<"No such data found enter valid data\n";
     }

     return h ;
 }

 struct node * search_ele( struct node * h)
 {
     struct node *temp ;
     int i,j=0 ;
     temp =h;
     cout<<"Enter the data you want to search"<<endl;
     cin>>i;
     while(temp != NULL)
     {

         if(temp->data == i)
         {
            cout<<"The data enter is at index ";
            cout<<j<<endl;
            j=0;
            break;
         }
         j++;
         temp = temp->next;
     }
     if(temp->next == NULL && j!=0)
     {
         cout<<"No such data found\n";
     }
     return h ;
 }
int main()
{
 struct node *head = NULL;
 int ch , p ;
  cout<<endl<<"1.Create list\n2.Display list\n3.Append\n4.Insert at begin\n5.Insert at desired position"<<endl;
 cout<<"6.Delete at any position\n7.delete at begin\n8.delete at end\n9.Modify\n10.Search an element\n11.Exit\n";

 p :  cout<<"\nEnter the choice"<<endl;
 cin >> ch ;
 switch(ch)
 {

  case 1 : cout<<"Enter the number of entries you want"<<endl;
           int k,i;
           cin>>k;
           cout<<"Enter the Data"<<endl;
           for(i=0;i<k;i++)
           {
           head = create_sll( head ) ;
           }
           goto p;
           break;

  case 2 : display_sll ( head ) ;
           goto p;
           break;

  case 3 : append( head ) ;
           goto p;
           break;

  case 4 : head = insrt_begin( head ) ;
           goto p;
           break;

  case 5 : head = insrt_pos ( head ) ;
           goto p;
           break;

  case 6 : head = del_pos ( head );
           goto p;
           break ;

  case 7 : head = del_begin ( head );
           goto p;
           break;

  case 8 : head = del_end ( head );
           goto p;
           break;

  case 9 : head = modify( head );
           goto p ;
           break ;

 case 10 : head = search_ele( head ) ;
           goto p;
           break;

 case 11 : break;
}


return 0;
}

