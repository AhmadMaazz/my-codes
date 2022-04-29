#include<iostream>
#include<string>
#include<fstream>

using namespace std;

string regno;
string fname="data.csv";
int rctr = 0;
string all_data[100][5];

void read(string fname);
void write(string fname);
void sort();
void status();
void search();
void registration();
void deleting();
void totalstudents();
void bill();


int main() {
	char option;
	do{

	cout<<"enter options"
	<<"\n1. for search"
	<<"\n2. for registration"
	<<"\n3. for status"
	<<"\n4. for deletion of record"
	<<"\n5. for counting total students"
	<<"\n6. for calculating bill"<<endl;
	cout << endl;
	cout << endl;
	

	int ch;
	cin>>ch;

	switch (ch)
	{
	case 1:
		
        search();
		break;
	case 2:
		
        registration();
		break;
	case 3:
		
        status();
		break;
	case 4:
		
        deleting();
		break;
	case 5:
		
        totalstudents();
		break;
	case 6:

		bill();
		break;
	default:

		cout<<"please input the correct options"<<endl;
		break;
	
	}
	cout<<endl;
	cout<<endl;

	cout<<"press y. if you want to use the mess system again"<<endl;
	cin>>option;

	}while(option =='y');
}

void read(string fname) {
	string line, word;
	int wctr, len;
	fstream file(fname,ios::in);
	rctr = 0;
	while (getline(file, line)) {
		wctr = 0;
		word = "";
		len = line.length();
		for (int i = 0; i < len; i++)
		{
			if (line[i] == ',') {
				all_data[rctr][wctr] = word;
				word = "";
				wctr++;
			}
			else if (i == len - 1) {
				word += line[i];
				all_data[rctr][wctr] = word;
			}
			else {
				word += line[i];
			}
			
		}
		rctr++;
	}
}

void write(string fname) {
	fstream file(fname, ios::out);
	for (int i = 0; i < rctr; i++) {
		for (int j = 0; j < 5; j++) {
			if (j == 4) {
				file << all_data[i][j] << endl;
			}
			else {
				file << all_data[i][j] << ",";
			}
            
		}
	}
    rctr = 0;
}

void search() {

	cout << "enter the reg no. of the student" << endl;
	cin >> regno;
    read(fname);

    bool found = 1;
	for(int r = 0 ; r<rctr; r++)
	{
		if (regno == all_data[r][0])
		{
			cout<<"regno :"<<all_data[r][0]
			<<"\nname :"<<all_data[r][1]
			<<"\nbill :"<<all_data[r][2]
			<<"\nstatus :"<<all_data[r][3]
			<<"\ndays :"<<all_data[r][4]
			<<endl;
			found = 0;
		}
	}
	if (found==1)
	{
		cout<<"data of the student not found"<<endl;
	}
}

void registration(){
string name, bill = "0", status = "out", days = "0";
bool found = false;

cout<<"Enter your registration number: ";
cin>>regno;

read(fname);
for(int i =0 ; i<rctr; i++)
{
	if(regno==all_data[i][0])
	{
		found = true;
	}
}
if(found == false)
{
	
	cout<<"Enter your name: ";
	cin.ignore();
	getline(cin, name);
	all_data[rctr][0] = regno;
	all_data[rctr][1] = name;
	all_data[rctr][2] = bill;
	all_data[rctr][3] = status;
	all_data[rctr][4] = days;
	rctr++;

	write(fname);
	
}
else
{
	cout<<"the data of the student is already present"<<endl;

}
sort();
}

void sort(){
    read(fname);

    string arr[5];
	int temp1;
	int temp2;

    for(int i = (rctr - 1); i > 0; i--)
    {
        for(int j = 1; j < i; j++)
        {
			// changing from string to integer
			temp1 = stoi(all_data[j][0]);
			temp2 = stoi(all_data[j + 1][0]);
            if(temp1 > temp2)
            {
                for(int k = 0; k < 5; k++)
                {
                    arr[k] = all_data[j][k];
                    all_data[j][k] = all_data[j + 1][k];
                    all_data[j + 1][k] = arr[k];
                }
            }
        }
    
    }
    write(fname);
}

void status() {
   read(fname);

    int temp;
	int tempbill;
	bool found = 1;

	cout << "enter the reg no. of the student" << endl;
	cin >> regno;
	for(int i =0; i<rctr;i++)
	{
		if (regno == all_data[i][0])
		{
			cout << "mess status of student is :"<< endl;
			cout<<all_data[i][3];
			cout<<endl;
			char opt2;
			
			cout<<"enter (y/n) if you want to change the mess status"<<endl;
			cin >> opt2;
		
			if (opt2 == 'y') 
			{
                if(all_data[i][3] == "out")
                {
				    all_data[i][3] = "in";
					tempbill = stoi(all_data[i][2]);
					tempbill = tempbill + 300;
                    temp = stoi(all_data[i][4]);
                    temp++;
					all_data[i][2] = to_string(tempbill);
                    all_data[i][4] = to_string(temp);
                }
                else
				{
				    all_data[i][3] = "out";
                }
			}
			cout<<endl;
			cout << "the mess status of the student after updation is " << all_data[i][3] << endl;
			found=0;
		}
		
	}
	if(found==1) 
	{
		cout<<"no student is registered for this regno"<<endl;
	}
    write(fname);
}

void deleting() {
    read(fname);

    bool found = true;
    int index = 0;
	cout << "enter the reg no. of the student" << endl;
	cin >> regno;
	for(int i = 1; i<rctr;i++)
    {
		if (regno == all_data[i][0])
		{
            index = i;
        }
    }
    if(index != 0)
    {
        for (int i = index; i < rctr; i++)
        {
            for (int j = 0; j < 5; j++) 
			{
		        all_data[i][j] = all_data[i + 1][j];
			}
        }
		rctr--;
		cout << endl;
		cout << "the student record has been deleted succesfully" << endl;
        found = false;
    }
    if(found == true) 
	{
	    cout << "the regnumber you entered is not valid" << endl;
		cout << "no student is registered for this regno" << endl;
	}
    write(fname);
}
	
void totalstudents() {
	read(fname);
	int inctr = 0;
	int outctr = 0;
	for (int i = 0; i < rctr; i++)
	{
		if (all_data[i][3] == "out") 
		{
			outctr++;
		}
		else if (all_data[i][3] == "in")
		{
			inctr++;
		}
	}
		cout<<"the total number of out students are "<<outctr<<endl;
		cout<<"the total number of in students are "<<inctr<<endl;
}	

void bill() {
	read(fname);

	int bill = 0;
	bool found = false;
	cout << "enter the regno of the student to calculate their mess bill" << endl;
	cin >> regno;
	for(int i = 0 ; i < rctr; i++){
		if (regno == all_data[i][0]) {
			bill = stoi(all_data[i][2]); 
			found = true;
		}
	}
	if(found == true)
	{
		cout << "The student's bill is: " << endl;
		cout << bill;
	}
	else {
		cout<<"please enter a correct regno" << endl;
		}
	cout<<endl;
}