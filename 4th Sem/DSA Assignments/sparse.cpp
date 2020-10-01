#include<stdio.h>
void sparse_convert(int a[5][5],int r,int c ,int sp[100][3], int ctr)
{
int i,j;
for(i=0;i<r;i++)
{
    for(j=0;j<c;j++)
    {
        if(a[i][j]!=0)

            {sp[ctr][0]=i;
            sp[ctr][1]=j;
            sp[ctr][2]=a[i][j];
        ctr++;}
    }
}
sp[0][0]=r;
sp[0][1]=c;
sp[0][2]=(ctr-1);
printf("The Sparse matrix is :\n");

for(i=0;i<ctr;i++)
{
    for(j=0;j<3;j++)
    {
        printf("%d",sp[i][j]);
        printf(" ");

    }
    printf("\n");
}
printf("\n");
}

void simple_transpose(int r,int c,int sp[100][3])
{
    int i,j,b[100][3],ctr,nxt,noc;
    ctr=sp[0][2];
    noc=sp[0][1];

    b[0][0]=sp[0][1];
    b[0][1]=sp[0][0];
    b[0][2]=sp[0][2];

    nxt=1;
    for(i=0;i<noc;i++)
    {
        for(j=1;j<=ctr;j++)
        {

            if(sp[j][1]==i)
            {

                b[nxt][0]=sp[j][1];
                b[nxt][1]=sp[j][0];
                b[nxt][2]=sp[j][2];
                nxt++;
            }
        }
    }
    printf("Sparse matrix using simple transpose\n");

for(i=0;i<=ctr;i++)
{
    for(j=0;j<3;j++)
    {
        printf("%d",b[i][j]);
        printf(" ");

    }
    printf("\n");
}

}

void fast_transpose(int r,int c,int sp[100][3])
{

    int i,j,k=0,n=0,start[5],b[100][3],fre[3]={0,0,0};
    b[0][0]=sp[0][1];
    b[0][1]=sp[0][0];
    b[0][2]=sp[0][2];
    for(i=1;i<=sp[0][2];i++)
    {
        k=sp[i][1];
        fre[k]++;
    }
    start[0]=1;
    for(i=1;i<=sp[0][2];i++)
    {
        start[i]=start[i-1]+fre[i-1];
    }
    for(i=1;i<=sp[0][2];i++)
    {
        k = sp[i][1];
        n=start[k];
    b[n][0]=sp[i][1];
    b[n][1]=sp[i][0];
    b[n][2]=sp[i][2];
    start[k++];
    }
    printf("Sparse matrix using fast transpose\n");
    for(i=0;i<=sp[0][2];i++)
    {
    for(j=0;j<3;j++)
    {
        printf("%d",b[i][j]);
        printf(" ");

    }
    printf("\n");
    }
}


int main()
{
    int r,c,a[5][5],i,j,sp[100][3],ctr=1 ,ch;
    printf("Enter the rows and column\n");
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
    {
    for(j=0;j<c;j++)
    {
        scanf("%d",&a[i][j]);
    }
    }
sparse_convert(a,r,c,sp,ctr);
simple_transpose(r,c,sp);
fast_transpose(r,c,sp);
return 0;
}
