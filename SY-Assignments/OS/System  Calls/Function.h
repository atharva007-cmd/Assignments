#include <string.h>
char emptyString[1000];

extern void strrev (char* str)
{
    int len, len2, i=0;
    char temp;
    len=strlen(str)-1;          // We subtract 1 as indexing starts form 0
    len2=strlen(str);

    while (i<len)
    {
        temp=str[len];          // Swapping method
        str[len]=str[i];        // Swapping method
        str[i]=temp;            // Swapping method
        i++;
        len--;
    }
    str[len2++]=',';            // Appending a ',' CHAR as a delimiter
    str[len2++]='\0';           // Appending a NULL CHAR as a terminator
}

extern void intToString (int num, int *arr, char *str, char *mainStr)
{
    int i, j, r, tempNum;
    char ch;
    strcpy(mainStr, emptyString);
    for (i=0; i<num; i++)
    {
        tempNum=arr[i];         // Elementwise assigning number into a temp var
        j=0;
        while(tempNum>0)        
        {
            r=tempNum%10;       // This gives us the number at unit's place
            ch=48+r;            // Adding 48(ASCII of '0') to give us CHAR number
            tempNum/=10;        // To get to the next number
            str[j++]=ch;        // Appending the CHAR number into the string
        }
        str[j]='\0';            // NULL - to terminate the string
        strrev(str);               
        strcat(mainStr, str);   // Putting formated string into the mainString
        strcpy(str, emptyString);
    }
}

// Ascending Bubble Sort - Parent
extern void AsecBubbleSort (int *arr, int len)
{
    int i, j, temp;
    for (i=0; i<len; i++)
    {
        for (j=0; j<len-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}



// Descending Bubble Sort - Child
extern void DescBubbleSort (int *arr, int len)
{
    int i, j, temp;
    for (i=0; i<len; i++)
    {
        for (j=0; j<len-i-1; j++)
        {
            if (arr[j]<arr[j+1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}