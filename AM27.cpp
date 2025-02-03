#include<iostream>
#include<string.h>
using namespace std;

class Worker{
	private:
		string name;
		string Wid;
		long int salary;
    public:
    	void setInfo(string nm,string id,long int sl){
    		name=nm;
    		Wid=id;
    		salary=sl;
		}
		void getInfo(){
			cout<<"Worker's Name is : "<<name<<endl;
			cout<<"Worker's id is : "<<Wid<<endl;
			cout<<"Worker's salary is : "<<salary<<endl;
		}
		Worker(){
			cout<<"\n Default constructer is called"<<endl;
		    name='\0';
		    Wid='\0';
		    salary=00;
		}
		Worker(string nm,string id,long int sl){
			cout<<"\nParametric  constructer is called"<<endl;
			name=nm;
		    Wid=id;
		    salary=sl;
		}
		Worker(const Worker &obj){
			cout<<"\ncopy constructer  is called"<<endl;
			name=obj.name;
			Wid=obj.Wid;
			salary=obj.salary;
		}
		~Worker(){
		cout<<"\nDestructer is called.";
		}
		
};
int main()
{
	Worker w1;	w1.getInfo();
	w1.setInfo("Ramesh","12DN30",20000);
	w1.getInfo();
	Worker w2("Mahesh","234IUH",30000);w2.getInfo();
	Worker w3=w1;
	w3.getInfo();
}
