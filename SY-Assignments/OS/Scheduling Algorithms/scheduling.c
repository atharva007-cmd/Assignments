   #include<stdio.h>
#include<stdlib.h>

struct node{
	int AT,BT,ID,CT;
	struct node *next;
}*head;

struct fcfs{
	int Id,At,Bt,Ct;
	struct fcfs *next;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct node *create(struct node *head,int ID,int AT,int BT,int n){
struct node *temp;
struct node *t;
t=(struct node* )malloc(sizeof(struct node));
int *a;
a=(int *)malloc(n*sizeof(int));

temp=head;

if(head==NULL){
	head=t;
	temp=head;
	temp->AT=AT;
	temp->BT=BT;
	temp->ID=ID;

	temp->next=NULL;
	return head;
}
else{

	while(temp->next!=NULL){
		temp=temp->next;
	}
	t->ID=ID;
	t->AT=AT;
	t->BT=BT;
	t->next=NULL;
	temp->next=t;

	return head;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct node *display(struct node *head){

struct node *temp;
temp=head;



while(temp!=NULL){
	printf("%d,%d,%d\n",temp->ID,temp->AT,temp->BT);
	temp=temp->next;
}
return head;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct fcfs *display1(struct fcfs *head1){

struct fcfs *temp;
temp=head1;

while(temp!=NULL){
	printf("%d,%d,%d\n",temp->Id,temp->At,temp->Bt);
	temp=temp->next;
}

printf("\n");
return head1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int enque(int *q,int p,int end){
	*(q+end)=p;
	end++;
	return end;
}












////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
	
struct node *temp1;           
struct fcfs *t1,*head1=NULL,*temp11,*temp12,*follower;
int u,v,w;
int ct=0,front,end,T,TQ,flag1=0,flag2=0,A,flag3=0,flag4=0,flag5=0,flag6=0;
int *q;

struct node *head=NULL;

int i,n,ID,CT,BT,a[10],c,b[10],cmp,ind;

scanf("%d",&n);

for(i=0;i<n;i++){
        scanf("%d%d%d",&ID,&CT,&BT);
        head=create(head,ID,CT,BT,n);
}

printf("Enter your choice\n");
scanf("%d",&c);

switch(c){


case 1:
//////////////////////////////////////////////////////////////////////////////////////////////////START OF FCFS////////////////////////////

//creating copy of input ll;
temp1=head;
while(temp1!=NULL){
	t1=(struct fcfs*)malloc(sizeof(struct fcfs));
	t1->Id=temp1->ID;
	t1->At=temp1->AT;
	t1->Bt=temp1->BT;
	t1->next=NULL;
	
	temp11=head1;
	if(head1==NULL){
		head1=t1;
		temp11=head1;
	}
	else{
		while(temp11->next!=NULL){
			temp11=temp11->next;
		}
		temp11->next=t1;
	}
	
	temp1=temp1->next;
	
}

//sorting according to AT
for(temp11=head1;temp11->next!=NULL;temp11=temp11->next){
	for(temp12=head1;temp12->next!=NULL;temp12=temp12->next){
		if(temp12->next->At < temp12->At){
			u=temp12->next->At;
			v=temp12->next->Id;
			w=temp12->next->Bt;
			temp12->next->At=temp12->At;
			temp12->next->Id=temp12->Id;
			temp12->next->Bt=temp12->Bt;
			temp12->At=u;
			temp12->Id=v;
			temp12->Bt=w;

		}
	}
}

head=display(head);
head1=display1(head1);   

printf("The Process flow is like This\n");


//PRINTING PROCESS FLOW
for(temp11=head1;temp11!=NULL;temp11=temp11->next){
	printf("P%d--->",temp11->Id);
} 
printf("\n");

///creating a of CT
for(temp11=head1;temp11->next!=NULL;temp11=temp11->next){
	if(temp11==head1){
			a[temp11->Id]=temp11->At+temp11->Bt;
			if(a[temp11->Id]<=temp11->next->At){
				a[temp11->next->Id]=temp11->next->At+temp11->next->Bt;
			} 
	}
	else{
		if(a[temp11->Id]<=temp11->next->At){
			a[temp11->next->Id]=temp11->next->At+temp11->next->Bt;
		}	 
		else{
			a[temp11->next->Id]=a[temp11->Id]+temp11->next->Bt;
		}
	}
}

//printing in tabular way
for(temp1=head,i=1;temp1!=NULL;temp1=temp1->next,i++){
	printf("P%d     ",i);
	printf("%d     %d     %d\n",a[i],a[i]-temp1->AT,a[i]-temp1->AT-temp1->BT);
}
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////END OF FCFS/////////
break;

//////////////////////////////////////////////////////////////////////////////////////////////////SATRT OF SJF///////////////////
case 2:
	

//creating a copy of input linked list
temp1=head;
while(temp1!=NULL){
	t1=(struct fcfs*)malloc(sizeof(struct fcfs));
	t1->Id=temp1->ID;
	t1->At=temp1->AT;
	t1->Bt=temp1->BT;
	t1->next=NULL;
	
	temp11=head1;
	if(head1==NULL){
		head1=t1;
		temp11=head1;
	}
	else{
		while(temp11->next!=NULL){
			temp11=temp11->next;
		}
		temp11->next=t1;
	}
	
	temp1=temp1->next;
	
}

head1=display1(head1);   
//sorting ll2 according to BT
for(temp11=head1;temp11->next!=NULL;temp11=temp11->next){
	for(temp12=head1;temp12->next!=NULL;temp12=temp12->next){
		if(temp12->next->Bt < temp12->Bt){
			u=temp12->next->At;
			v=temp12->next->Id;
			w=temp12->next->Bt;
			temp12->next->At=temp12->At;
			temp12->next->Id=temp12->Id;
			temp12->next->Bt=temp12->Bt;
			temp12->At=u;
			temp12->Id=v;
			temp12->Bt=w;

		}
		if(temp12->next->Bt==temp12->Bt){
			if(temp12->next->At < temp12->At){
				u=temp12->next->At;
				v=temp12->next->Id;
				w=temp12->next->Bt;
				temp12->next->At=temp12->At;
				temp12->next->Id=temp12->Id;
				temp12->next->Bt=temp12->Bt;
				temp12->At=u;
				temp12->Id=v;
				temp12->Bt=w;

			}
		}
	}
}

head1=display1(head1);

//finding the least arrival time
cmp=head1->At;
ind=head1->Id;

printf("%d\n",ind);
printf("%d\n",cmp);

for(temp11=head1;temp11!=NULL;temp11=temp11->next){
	if(temp11->At < cmp){
		cmp=temp11->At;
		ind=temp11->Id;
	}
}

printf("%d\n",ind);
printf("%d\n",cmp);



temp11=head1;

//arranging ll2 so to apply logic...see in notebook
if(head1->Id!=ind){
	while(temp11->Id!=ind){
		follower=temp11;
		temp11=temp11->next;
	}
	follower->next=temp11->next;
	temp11->next=head1;
	head1=temp11;
}

head1=display1(head1);
//storing Ct in array b
for(temp11=head1;temp11->next!=NULL;temp11=temp11->next){
	if(temp11==head1){
		b[temp11->Id]=temp11->At + temp11->Bt;
		b[temp11->next->Id]=b[temp11->Id] + temp11->next->Bt;
	}
	else{
		b[temp11->next->Id]=b[temp11->Id] + temp11->next->Bt;
	}
}

//printing tabular answer
for(temp1=head,i=1;temp1!=NULL;temp1=temp1->next,i++){
	printf("P%d     ",i);
	printf("%d     %d     %d\n",b[i],b[i]-temp1->AT,b[i]-temp1->AT-temp1->BT);
}


break;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


case 3:
	
	printf("Enter Time Quantum\n");
	scanf("%d",&TQ);
	
	//creating a copy of input linked list
temp1=head;
while(temp1!=NULL){
	t1=(struct fcfs*)malloc(sizeof(struct fcfs));
	t1->Id=temp1->ID;
	t1->At=temp1->AT;
	t1->Bt=temp1->BT;
	t1->Ct=0;
	t1->next=NULL;
	
	temp11=head1;
	if(head1==NULL){
		head1=t1;
		temp11=head1;
	}
	else{
		while(temp11->next!=NULL){
			temp11=temp11->next;
		}
		temp11->next=t1;
	}
	
	temp1=temp1->next;
	
}


for(temp11=head1;temp11->next!=NULL;temp11=temp11->next){
	for(temp12=head1;temp12->next!=NULL;temp12=temp12->next){
		if(temp12->next->At < temp12->At){
			u=temp12->next->At;
			v=temp12->next->Id;
			w=temp12->next->Bt;
			temp12->next->At=temp12->At;
			temp12->next->Id=temp12->Id;
			temp12->next->Bt=temp12->Bt;
			temp12->At=u;
			temp12->Id=v;
			temp12->Bt=w;

		}
	}
}

head=display(head);
head1=display1(head1);   

//   A queue.

q=(int *)malloc(1000*sizeof(int));

front=0;
end=0;

/*for(T=0;T<100;T++){
	for(temp11=head1;temp11->next!=NULL;temp11=temp11->next){
		if(temp11->At==T){
			end=enque(q,temp11->Id,end);
			if(flag==0){
				printf("p%d",temp11->Id);
				temp11->Bt=temp11->Bt-1;
				ct++;
			}
			if(ct==TQ){
				front++;
				end=enque(q,temp11->Id,end);
			}
			if(flag==1){
			
		}
	}
}
}*/
temp11=head1;
end=enque(q,temp11->Id,end);
for(T=0;T<100;T++){
	
	for(temp11=head1;temp11!=NULL;temp11=temp11->next){
		if(temp11->At==T && temp11!=head1){
			end=enque(q,temp11->Id,end);
			flag2=1;
		}
	}
	if(flag1==1 && flag2==1){
		A=q[end-1];
		q[end-1]=q[end-2];
		q[end-2]=A;
	}
	flag1=0;
	flag2=0;
	
	for(temp12=head1;temp12->next!=NULL;temp12=temp12->next){
		if(temp12->Id==q[front]){
			break;
		}
	}
	printf("%d\n",temp12->Id);
	temp12->Ct=T;
	ct++;
	
	if(ct==TQ){
		if(temp12->Bt!=0){
			front++;
			end=enque(q,temp12->Id,end);
			flag1=1;
			flag5=1;
		}
		else{
			front++;
		}
		ct=0;
		flag3=1;
	}
	
	temp12->Bt--;
	if(temp12->Bt==0){
		flag4=1;
		flag6=1;
		front++;
		ct=0;
	}
	
	if(flag3==1 && flag4==1){
		front--;
	}
	flag3=0;
	flag4=0;
	
	if(flag5==1 && flag6==1){
		end--;
	}
	flag5=0;
	flag6=0;
	
	if(front==end){
		break;
	}
	
	for(i=0;i<15;i++){
		printf("%d ",q[i]);
	}
	printf("\n%d %d\n",front,end);
	printf("\n");
}
  
for(temp12=head1;temp12!=NULL;temp12=temp12->next){
	printf("%d %d\n",temp12->Id,temp12->Ct+1);
}


for(temp1=head;temp1!=NULL;temp1=temp1->next){
	for(temp12=head1;temp12!=NULL;temp12=temp12->next){
		if(temp1->ID==temp12->Id){
			temp1->CT=temp12->Ct+1;
			break;
		}
	}
}

for(temp1=head;temp1!=NULL;temp1=temp1->next){
	printf("%d %d\n",temp1->ID,temp1->CT);
}


for(temp1=head,i=1;temp1!=NULL;temp1=temp1->next,i++){
	printf("P%d     ",i);
	printf("%d     %d     %d\n",temp1->CT,temp1->CT-temp1->AT,temp1->CT-temp1->AT-temp1->BT);
}


  
break;

}
	
return 0;
 
}


