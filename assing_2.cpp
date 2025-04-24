#include<iostream>
#include<string.h>
using namespace std;

class Demo{
	private:
		int *p;
	public:
		void getDemo(){
			cout<<" value :"<<(*p);
		}
		void setDemo(int val)
		{
			(*p)=val;
		}
		Demo(){
			cout<<"\nCONST."<<endl;
			(*p)=0;
		}
		Demo(const Demo &obj){
			cout<<"\nCOPY CONST"<<endl;
			p=obj.p;
		}
		
};
int main()
{
	Demo d1;d1.setDemo(10);d1.getDemo();
	Demo d3=d1;d3.getDemo();
}
