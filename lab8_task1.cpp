#include<iostream>
#include<iomanip>
using namespace std;

class student{
    protected:
        int rollNo;
    public:
        void getroll(){
            cout<<"Enter Roll Number: ";
            cin>>rollNo;
        }

        void putroll(){
            cout<<setw(22);
            cout<<"roll number: "<<rollNo<<endl;
        }
};

class test : virtual public student{
    protected:
        float part1;
        float part2;
    public:
        void getMarks(){
            cout<<"enter marks:"<<endl;
            cout<<"part 1: ";
            cin>>part1;
            cout<<"part 2: ";
            cin>>part2;
        }
        void putmarks(){
            cout<<setw(25);
            cout<<"marks obtained: "<<endl;
            cout<<endl;
            cout<<setw(17);
            cout<<"Part 1: "<<part1<<endl;
            cout<<setw(17);
            cout<<"Part 2: "<<part2<<endl;
        }
};

class sports : virtual public student{
    protected:
        float score;
    public:
        void getscore(){
            cout<<"enter sports score: ";
            cin>>score;
        }
        void putscore(){
            cout<<setw(26);
            cout<<"sports score is: "<<score<<endl;
        }
};

class result : virtual public test, virtual public sports{
    protected:
        float result;

    public:
        void showresult(){
            getroll();
            getMarks();
            getscore();
            cout<<endl<<endl;
            
            putroll();
            result = part1 + part2 + score;
            putmarks();
            putscore();
            cout<<setw(22);
            cout<<"total score: "<<result<<endl;
            cout<<setw(25)<<"---------------------------------"<<endl;
        }

};

int main(){
    result R1;
    R1.showresult();
    return 0;
}