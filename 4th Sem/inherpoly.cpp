#include<iostream>
using namespace std;

class Shape
{
    public:
    int l,h;

    public:
    void getdata()
    {
        cout<<"Enter Length: ";
        cin>>l;
        cout<<"Enter Breadth: ";
        cin>>h;
    }

};

class Rectangle: public Shape
{
    int area=0;
    public:
    void display()
    {
        area= l*h;

        cout<<"Area of Rectangle is: "<<area<<endl;
    }
};

class Triangle: public Rectangle
{
    int area=0;
    public:
    void putdata()
    {
    area = 0.5*l*h;

    cout<<"Area of Triangle is: "<<area<<endl;
    }
};

int main()
{
    int ch;
     cout<<"Calculate Area of: ";
    cout<<"\n\t1.Triangle \n\t2.Rectangle \n\t3.Exit \n";
    cout<<"Enter Your Choice: ";
    cin>>ch;
   
    Triangle t;
    t.getdata();
    switch(ch)
    {
        case 1: t.display(); break;
        case 2: t.putdata(); break;
        
    }while(ch!=0);

return 0;


}