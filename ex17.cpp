#include <iostream>
#include <chrono>
#include <thread>
#include <random>
using namespace std;
using namespace chrono;
using namespace this_thread;
void Inicializer(int *array1,int *array2,int *len);
void Trade(int *array1,int *array2,int *len);
void (*p[])(int *array1,int *array2,int *len)={Inicializer,Trade};
int main(){
    int n,len;
    cout<<"Input a length of array: ";
    cin>>len;
    int arrayA[len],arrayB[len];
    system("cls");
    do{
        cout<<"Input 1 to start the array\nInput 2 to trade the array A to B\nInput 0 to exit the program\nInput a number: ";
        cin>>n;
        if(n!=0&&n<3){
            (*p[n-1])(arrayA,arrayB,&len);
        }else if(n>=3){
            cout<<"ERROR: Invalid number, please try again\n"<<endl;
            sleep_for(seconds(2));
            system("cls");
        }
    }while(n!=0);
    return 0;
}
void Inicializer(int *array1,int *array2,int *len){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dist(0,100);
    int *p,*pp,*p1;
    pp=&array1[*len];
    for(p=array1,p1=array2;p<pp;p++,p1++){
        *p = dist(gen);
        *p1 = dist(gen);
    }
    cout<<"Array has iniciated "<<endl;
    for(p=array1,p1=array2;p<pp;p++,p1++){
        cout<<"A:"<<*p<<"\t";
        cout<<"B:"<<*p1<<endl;
    }
}
void Trade(int *array1,int *array2,int *len){
    int aux;
    int *p,*pp,*p1;
    pp=&array1[*len];
    for(p=array1,p1=array2;p<pp;p++,p1++){
        aux = *p;
        *p = *p1;
        *p1=aux;
    }
    cout<<"The array has traded successfully "<<endl;
    for(p=array1,p1=array2;p<pp;p++,p1++){
        cout<<"A: "<<*p<<"\t";
        cout<<"B: "<<*p1<<endl;
    }
}