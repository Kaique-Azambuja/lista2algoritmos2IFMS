#include <iostream>
#include <random>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;
using namespace this_thread;
void iniciate(int array[],int *len);
void some(int array[],int *len);
void (*p[])(int array[],int *len)={iniciate,some};

int main(){
    int len,n;
    cout<<"Input a lenght of array: ";
    cin>>len;
    int array[len];
    do{
        cout<<"Input 1 to start a array\nInput 2 to sum the elements\nInput 0 to stop the program\nInput a number: ";
        cin>>n;
        cout<<endl<<endl;
        if(n!=0&&n<3){
            (*p[n-1])(array,&len);
        }else if(n>=3){
            cout<<"ERROR: Invalid number, please try again\n"<<endl;
            sleep_for(seconds(2));
            system("cls");
        }
    }while(n!=0);
    return 0;
}
void iniciate(int array[],int *len){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dist(1,1000);
    int *p,*pp;
    pp=&array[*len];
    for(p=array;p<pp;p++){
        *p=dist(gen);
    }
    cout<<"Array iniciated: "<<endl<<endl;
    for(p=array;p<pp;p++){
        cout<<*p<<"\t";
    }
    cout<<endl<<endl;
}
void some(int array[],int *len){
    int *p,*pp,som=0;
    pp=&array[*len];
    for(p=array;p<pp;p++){
        som+=*p;
    }
    cout<<"The sum of array elements are: "<<som<<endl<<endl;
}