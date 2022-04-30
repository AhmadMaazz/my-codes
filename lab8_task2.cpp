#include<iostream>
using namespace std;

class shape{
    protected:
        float length=0;
        float breadth=0;
        float height=0;
        public:
        shape(){
            cout<<"enter length: ";
            cin>>length;
            cout<<"enter breadth: ";
            cin>>breadth;
            cout<<"enter heigth: ";
            cin>>height;
        }
        virtual float area(){
            return length* breadth;
        }
        virtual void display(){
            cout<<"no area yet"<<endl;
        }

};

class rectangle : public shape{
    
    public:
        float area(){
            return length * breadth;
        }
        void display(){
            cout<<"shape: Rectangle"<<endl;
            cout<<"Area: "<<area()<<endl;
        }
};

class triangle : public shape{
    
    public:
        float area(){
            return 0.5 * length * breadth;
        }
        void display(){
            cout<<"shape: Triangle"<<endl;
            cout<<"Area: "<<area()<<endl;   
        }
};

class trapezoid : public shape{
    public:
        float area(){
            return 0.5 * (length + breadth)* height;
        }
        void display(){
            cout<<"shape: trapezoid"<<endl;
            cout<<"Area: "<<area()<<endl;   
        }
};

int main(){
    rectangle r1;
    shape *s1;
    s1=&r1;
    s1->area();
    s1->display();


    triangle t1;
    shape *s2;
    s2=&t1;
    s2->area();
    s2->display();
    
    trapezoid tr1;
    shape *s3;
    s3= &tr1;    
    s3->area();
    s3->display();



    return 0;
}