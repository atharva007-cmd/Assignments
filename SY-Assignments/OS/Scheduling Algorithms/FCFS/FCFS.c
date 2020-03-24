#include <stdio.h>
#include <stdlib.h>

struct node
{
    int ID, AT, BT, CT, TAT;
    struct node *next, *prev;
};

int num=0;

void createNode (struct node**);
void deleteNode (struct node*);

int main(int args, char* argv[])
{
    struct node *head=NULL, *temp=NULL;
    int i=0, num=0, ID, AT, BT, totalTAT=0, totalCT=0;
    temp=head;
    
    printf("Enter number of processes you want to schedule: ");
    scanf("%d", &num);

    for (i=0; i<num; i++) createNode(&head);
    for (temp=head; temp!=NULL; temp=temp->next)
    {
        if (temp->prev == NULL)
        {
            (temp->CT)=(temp->BT)+(temp->AT);
        }
        else 
        {
            if (((temp->prev)->CT) > temp->AT)
            {
                temp->CT=(temp->prev)->CT+temp->BT;
            }
            else
            {
                (temp->CT)=(temp->BT)+(temp->AT);
            }                        
        } 
        totalCT+=temp->CT;       
    }

    for (temp=head; temp!=NULL; temp=temp->next)
    {
        temp->TAT=temp->CT-temp->AT;
        totalTAT+=temp->TAT;
    }

    printf("\nProcess-ID\tAT\tBT\tCT\tTAT\n");
    for (temp=head; temp!=NULL; temp=temp->next) printf("    P%d\t\t%d\t%d\t%d\t%d\n", temp->ID, temp->AT, temp->BT, temp->CT, temp->TAT);

    printf("\nAverage CT: %d\nAverage TAT: %d\n", (totalCT/num), (totalTAT/num));
  
    deleteNode(head); 
    printf("\nSuccessfully Executed\n"); 
    return 0;
}

void createNode (struct node** head)
{
    struct node *newNode, *temp;
    newNode = (struct node*) malloc (sizeof(struct node));
    printf("Enter ID, AT, BT: ");
    scanf("%d%d%d", &newNode->ID, &newNode->AT, &newNode->BT);
    newNode->CT=newNode->TAT=0;
    newNode->next = newNode->prev =  NULL;

    if (*head==NULL)
    {
        (*head)=newNode;
    } 
    else
    {
        if ((*head)->AT > newNode->AT)
        {
            newNode->next=(*head);
            (*head)->prev=newNode;
            *head=newNode;
        }
        else 
        {
            for (temp=(*head); temp->next!=NULL && ((temp->next)->AT < newNode->AT); temp=temp->next);
            if (temp->next==NULL)
            {
                temp->next=newNode;
            }
            else 
            {
                newNode->next=temp->next;
                (temp->next)->prev=newNode;
                temp->next=newNode;
            }   
            newNode->prev=temp;
        }
    }
    return;
}

void deleteNode (struct node* head)
{
    struct node *temp, *temp1;
    temp=head;
    while (temp->next!=NULL)
    {
        temp1=temp;
        temp=temp->next;
        temp->prev=NULL;
        free(temp1);
    }
    free (temp);
    return;
}