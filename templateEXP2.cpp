#include<iostream>
using namespace std;

template<class T>

class operation{
    protected:
        T num1,num2;
    public:
        operation(){
            cout<<"numbers are: ";
            cin>>num1>>num2;
            cout<<endl;
            cout<<"numbers are "<<num1<<" and "<<num2<<endl
                <<"addition is "<<num1+num2<<endl
                <<"subtraction is "<<num1-num2<<endl
                <<"multiplication is "<<num1*num2<<endl
                <<"division is "<<num1/num2<<endl;
        }
};


int main(){
    cout<<"enter integer values"<<endl;
    operation<int> T1;

    cout<<"enter float values"<<endl;
    operation<float> T2;
    return 0;

}