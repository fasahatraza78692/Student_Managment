#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int ID;
class Student
{
	int id;
	string name,stream,address;
	 public:
	 	void AddStudent()
	 	{
	 		ofstream fout;
	 		fout.open("D:/DevC++/Student.txt",ios::app);
	 		if(!fout)
	 		 cout<<"	File not open"<<endl;
	 		else
	 		 {
	 		 	cout<<"	Name    : ";
	 		 	cin.get();
	 		 	getline(cin,name);
	 		 	cout<<"	Stream  : ";
	 		 	getline(cin,stream);
	 		 	cout<<"	Address : ";
	 		 	getline(cin,address);
	 		 	ID++;
	 		 	fout<<"\n"<<ID;
	 		 	fout<<"\nName   : "<<name;
	 		 	fout<<"\nStream : "<<stream;
	 		 	fout<<"\nAddress: "<<address;
	 		 	fout.close();
	 		 	fout.open("D:/DevC++/Id.txt",ios::app);
	 		 	fout<<ID<<endl;
	 		 	fout.close();
	 	     }
		}
	    void PrintAll()
	    { 
	    	ifstream fin;
	    	fin.open("D:/DevC++/Student.txt");
	    	Student s;
	    	while(!fin.eof())
	    	{
	    		fin>>s.id;
	    		if(s.id!=0)
	    		{
	    			fin.ignore();
	    	        getline(fin,s.name);
	    	        getline(fin,s.stream);
	    	        getline(fin,s.address);
	    	        cout<<"	ID     : "<<s.id<<endl;
	    	        cout<<"	"<<s.name<<endl;
	    	        cout<<"	"<<s.stream<<endl;
	    	        cout<<"	"<<s.address<<endl;
	    	        cout<<"	------------------------------------"<<endl;
				}
				else
					cout<<"	File is Empty...";
		    }
		  fin.close();
		}
		void SearchStudent(int id)
		{
			ifstream fin;
	    	fin.open("D:/DevC++/Student.txt");
	    	Student s;
	    	while(!fin.eof())
	    	{
	    		fin>>s.id;
	    		fin.ignore();
	    	    getline(fin,s.name);
	    	    getline(fin,s.stream);
	    	    getline(fin,s.address);
	    	    if(id==s.id)
	    	     {
	    	     	cout<<"	------------------------------------"<<endl;
	    	     	cout<<"	ID     : "<<s.id<<endl;
	    	        cout<<"	"<<s.name<<endl;
	    	        cout<<"	"<<s.stream<<endl;
	    	        cout<<"	"<<s.address<<endl;
				 }
		    }
		  fin.close();
	    }
        void DeleteStudent(int id)
        {
        	ofstream fout;
        	ifstream fin;
        	fin.open("D:/DevC++/Student.txt");
        	fout.open("D:/DevC++/temp.txt");
        	Student s;
	    	while(!fin.eof())
	    	{
	    		fin>>s.id;
	    		fin.ignore();
	    	    getline(fin,s.name);
	    	    getline(fin,s.stream);
	    	    getline(fin,s.address);
	    	    if(id!=s.id)
	    	     {
	    	     	fout<<"\n"<<s.id;
	 		 	    fout<<"\n"<<s.name;
	 		 	    fout<<"\n"<<s.stream;
	 		 	    fout<<"\n"<<s.address;
				 }
	    	    
		    }
		  fin.close();
		  fout.close();
          remove("D:/DevC++/Student.txt");
          rename("D:/DevC++/temp.txt","D:/DevC++/Student.txt");
		}
        void UpdateStudent(int id)
        {
        	DeleteStudent(id);
        	ofstream fout;
        	fout.open("D:/DevC++/Student.txt",ios::app);
        	cout<<"	Name    : ";
	 		cin.get();
	 		getline(cin,name);
	 		cout<<"	Stream  : ";
	 		getline(cin,stream);
	 		cout<<"	Address : ";
	 		getline(cin,address);
            fout<<"\n"<<id;
	 		fout<<"\nName   : "<<name;
	 		fout<<"\nStream : "<<stream;
	 		fout<<"\nAddress: "<<address;
	 		fout.close();
		}
};
int main()
{
	Student s1;
	ifstream fin;
	fin.open("D:/DevC++/Id.txt");
	if(!fin)
	 cout<<"	File not open"<<endl;
    else 
      {
      	while(!fin.eof())
	     {
	 	    fin>>ID;
	     }
	     fin.close();
	  }
    while(true)
     {
     	system("cls");
     	int ch,id;
     	cout<<"	________________________"<<endl<<endl;
     	cout<<"	   STUDENT MANAGEMENT"<<endl;
     	cout<<"	________________________"<<endl;
     	cout<<"	----------------------------"<<endl;
	    cout<<"	1.Add Student"<<endl;
	    cout<<"	2.Delete Student"<<endl;
     	cout<<"	3.Update Student"<<endl;
	    cout<<"	4.Search Student"<<endl;
	    cout<<"	5.Print All Students"<<endl;
	    cout<<"	6.Exit"<<endl;
	    cout<<"	----------------------------"<<endl;
	    cout<<"	____________________________"<<endl;
	    cout<<"	Enter your choice: ";
	    cin>>ch;
	    switch(ch)
	    {
	 	    case 1:
	 		   s1.AddStudent();
	 		   cout<<"	Record added successfully..."<<endl;
	 		   break;
	 	    case 2:
	 	    	cout<<"	Give the id to delete student : ";
	 	    	cin>>id;
	 		   s1.DeleteStudent(id);
	 		   cout<<"	Record Deleted successfully...";
	 	       break;
	 	    case 3:
	 	    	cout<<"	Give the id to Update : ";
	 	    	cin>>id;
	 		   s1.UpdateStudent(id);
	 		   cout<<"	Student Updated...";
	 		   break;
		    case 4:
		       cout<<"	Give the ID to Search... ";
		       cin>>id;
	 		   s1.SearchStudent(id);
	 		   break;
	 	    case 5:
	 	       cout<<"	"<<endl;
	 		   s1.PrintAll();
	 		   break;
	 		case 6:
	 			exit(0);
	 	    default:
	 		   cout<<"	Invalid choice"<<endl;
	    }
	    cin.get();
	    cin.get();
	 }
	return 0;
}
