#include<iostream>
using namespace std;
template <typename T>
T fndmax(T a,T b){
	return (a>b) ? a : b;
}

template <typename T>
class Calculator
{
   T a,b;
   public:
   	
   	Calculator(T val1,T val2): a(val1),b(val2){}
   	
   	T add(){
   		return a+b;
	   }
   	T sub(){
   		return a-b;
	   }
   	T mul(){
   		return a*b;
	   }
   	T div(){
   		if(b!=0)
   		   return a/b;
   		else{
   			cout<<"Number will not be devide"; 
   		    return 0;
		   }
   		     
	   }
};

int main(){
	
	cout<<"Maximum from 10 and 60 is"<< fndmax(10,60)<<endl;

    Calculator<int> Calint(15,45);
    cout<<"\nInteger Operations:\n";
    cout<<"15+45= "<<Calint.add()<<endl;
    cout<<"15-45= "<<Calint.sub()<<endl;
    cout<<"15*45= "<<Calint.mul()<<endl;
    cout<<"15/45= "<<Calint.div()<<endl;
	
    Calculator<float> Calfloat(15.0f,45.0f);
    cout<<"\nfloat Operations:\n";
    cout<<"15+45= "<<Calfloat.add()<<endl;
    cout<<"15-45= "<<Calfloat.sub()<<endl;
    cout<<"15*45= "<<Calfloat.mul()<<endl;
    cout<<"15/45= "<<Calfloat.div()<<endl;	

}
