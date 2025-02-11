#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Book
{
    private:
       char *name;
       char *author;
       int pgcnt;
       bool format;
       float *chpages;
       int chnumbers;

    public:
       Book(){
        name='\0';
        author='\0';
        pgcnt=0;
        format=0;
        chpages='\0';
        chnumbers=0;
       }

       Book(char *nm,char *at,int pcnt,bool ft,float *chpg,int chno)
       {
        name=new char[(strlen(nm)+1)];
        strcpy(name,nm);
        author=new char[strlen(at)+1];
        strcpy(author,at);
        pgcnt=pcnt;
        format=ft;
        chpages=new float[chno];
        for(int i=0;i<chno;i++){
            chpages[i]=chpg[i];
        }
        chnumbers=chno;
       }

       void display(){
        cout<<"Book name :"<<name<<endl;
        cout<<"Book author name : "<<author<<endl;
        cout<<"Book page count :"<<pgcnt<<endl;
        cout<<"format : "<<format<<endl;
        cout<<"chapter pages :";
        for(int i=0;i<chnumbers;i++){
            cout<<chpages[i]<<" ";
        }
        cout<<"\nchapter numbers  :"<<chnumbers<<endl;
       }

       Book(const Book &obj){
        name=new char[(strlen(obj.name)+1)];
        strcpy(name,obj.name);
        author=new char[strlen(obj.author)+1];
        strcpy(author,obj.author);
        pgcnt=obj.pgcnt;
        format=obj.format;
        chpages=new float[obj.chnumbers];
        for(int i=0;i<obj.chnumbers;i++){
            chpages[i]=obj.chpages[i];
        }
        chnumbers=obj.chnumbers;
       }

       ~Book(){
        delete [] name;
        delete [] author;
        delete [] chpages;
        cout<<"Destructor is called\n";
       }
};

int main(){
    float chpages[]={10,20,30,40,50};
    Book b1("ab bc cd ","abcd",100,1,chpages,5);
    b1.display();
    cout<<"\n 2nd book \n ";
    Book b2=b1;
    b2.display();
}
