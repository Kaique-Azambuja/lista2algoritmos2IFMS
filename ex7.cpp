#include <iostream>
#include <chrono>
#include <thread>
#include <random>
using namespace std;
using namespace chrono;
using namespace this_thread;
void iniciate(int v[],int *n,int *maximus,int *minimum);
void find(int v[],int *n,int *maximus,int *minimum);
void (*pt[])(int v[],int *n,int *maximus,int *minimum)={iniciate, find};
int main(){
    int num,tam,max,min;
    cout<<"Input a size of array to iniciate the program: ";
    cin>>tam;
    int array[tam];
    system("cls");
    do{
        cout<<"Input 1 to iniciate the array\nInput 2 to find the maximum and minimum values of array\nInput 0 to exit\nInput a number: ";
        cin>>num;
        if(num<3&&num!=0){
            (*pt[num-1])(array,&tam,&max,&min);
        }else if(num>=3){
            cout<<"ERROR: invalid number, please try again."<<endl;
            sleep_for(seconds(3));
            system("cls");
        }

    }while(num!=0);
    return 0;
}
void iniciate(int v[],int *n,int *maximus,int *minimum){
    int *p,*pp;
    pp=&v[*n];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dist(1,1000);
    for(p=v;p<pp;p++){
        *p=dist(gen);
    }
}
void find(int v[],int *n,int *maximus,int *minimum){
    *maximus=v[0];
    *minimum=v[0];
    int *p,*pp;
    pp=&v[*n];
    for(p=v;p<pp;p++){
        if(*maximus<=*p){
            maximus=p;
        }
        if(*minimum>=*p){
            minimum=p;
        }
    }
    cout<<"Array values: "<<endl;
    for(p=v;p<pp;p++){
        cout<<*p<<endl;
    }
    cout<<"Maximum value: "<<*maximus<<endl;
    cout<<"Minimum value: "<<*minimum<<endl;
}