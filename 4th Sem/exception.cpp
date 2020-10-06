#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char city[20];
    int ch2;

    cout<<"Enter the City Name: ";
    cin>>city;

    cout<<"Enter the type of vehicle based on no of wheels: ";
    cin>>ch2;

    try
    {
        if(strcmp(city,"pune")==0||strcmp(city,"bangalore")==0||strcmp(city,"mumbai")==0||strcmp(city,"chennai")==0 && ch2==4)
        {
            cout<<"\n Your city is: "<<city;
            cout<<"\n Your Vehicle type is: "<<ch2<<"\n";

        }

        else
        {
            throw 0;
        }
        
    }
    catch(int i)
    {
        cout<<"\n Exception caught";
    }
    
}