#define _USE_MATH_DEFINES
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
using namespace std;
using namespace chrono;
using namespace this_thread;
void funca(float *x);
void funcb(float *x);
void funcc(float *x);
void funcd(float *x);
void funce(float *x);
void funcf(float *x);
void funcg(float *x);
void funch(float *x);
void funci(float *x);
void funcj(float *x);
void (*p[])(float *x)={funca,funcb,funcc,funcd,funce,funcf,funcg,funch,funci,funcj};
int main(){
    int n;
    float x=3.2;
    do{
        cout<<"Input 0 to use funcion a\nInput 1 to use funcion b\nInput 2 to use funcion c\nInput 3 to use funcion d\nInput 4 to use funcion e\nInput 5 to use funcion f\nInput 6 to use funcion g\nInput 7 to use funcion h\nInput 8 to use funcion i\nInput 9 to use funcion j\nInput 10 to stop the program\nInput a number: ";
        cin>>n;
        if(n<10){
            (*p[n])(&x);
        }else if(n>10){
            cout<<"ERROR: Invalid number, please enter a valid number."<<endl;
            sleep_for(seconds(3));
            system("cls");
        }
    }while(n!=10);
    return 0;
}
void funca(float *x){
    cout<<"function a: "<<(pow(*x,2)/3)+(pow(*x,3)/2)-(*x/10)<<endl;
    system("pause");
}
void funcb(float *x){
    cout<<"function b: "<<(1/(5*pow(*x,2)))-(10/(*x))<<endl;
    system("pause");
}
void funcc(float *x){
    cout<<"function c: "<<pow(*x-2,2)*(2*(*x)-3)<<endl;
    system("pause");
}
void funcd(float *x){
    cout<<"function d: "<<*x/(2*sqrt(*x))<<endl;
    system("pause");
}
void funce(float *x){
    cout<<"function e: "<<pow(M_E,-5*(*x))<<endl;
    system("pause");
}
void funcf(float *x){
    cout<<"function f: "<<-12+3/7*(exp(-(*x))-1)<<endl;
    system("pause");
}
void funcg(float *x){
    cout<<"function g: "<<(1/3)*(sin(3*(*x)))<<endl;
    system("pause");
}
void funch(float *x){
    cout<<"function h: "<<3*sin(((5*M_PI)/3)*(*x)+M_PI/10)<<endl;
    system("pause");
}
void funci(float *x){
    cout<<"function i: "<<log(*x+1)<<endl;
    system("pause");
}
void funcj(float *x){
    cout<<"function j: "<<log(log(*x))<<endl;
    system("pause");
}