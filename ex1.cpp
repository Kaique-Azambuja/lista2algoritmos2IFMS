#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;
using namespace this_thread;
void iniciate(float v[]);
void some(float v[]);
void (*p[])(float V[])={iniciate,some};

int main(){
    srand(time(NULL));
    int n;
    float array[10];
    do{
        cout<<"Input the number 1 to iniciate the vector\nInput the number 2 to some\nInput the number 3 to exit\nInput a number: ";
        cin>>n;
        if(n<3&&n!=0){
            (*p[n-1])(array);
        }
        else if(n>3||n==0){
            cout<<"ERROR: Invalid number of input";
            sleep_for(seconds(2));
            system("cls");
        }
    }while(n!=3);
    return 0;
}
void iniciate(float v[]){
    float *p,*pp;
    pp=&v[10];
    for(p=v;p<pp;p++){
        cout<<"input a number: ";
        cin>>*p;
    }
    system("cls");
    cout<<"Array iniciated: "<<endl<<endl;
    for(p=v;p<pp;p++){
        cout<<*p<<"\t";
    }
    cout<<endl<<endl;
}
void some(float v[]){
    float soma=0;
    float *p,*pp;
    pp=&v[10];
    for(p=v;p<pp;p++){
        soma+=*p;
    }
    cout<<"Some of array elements are "<< soma<<endl;
}