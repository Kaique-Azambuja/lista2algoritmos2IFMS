#define _USE_MATH_DEFINES
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include <numbers>
using namespace std;
using namespace chrono;
using namespace this_thread;
void func1(float m[5][6]);
void (*p[])(float m[5][6])={func1};
FILE *arq;
int main(){
    int n;
    arq=fopen("ex10.txt","wt");
    float matriz[5][6];
    do{
        cout<<"Input 1 to start a function\nInput 0 to exit a program\nInput a number: ";
        cin>>n;
        if(n!=0&&n<2){
            (*p[n-1])(matriz);
        }else if(n>=2){
            cout<<"ERROR: invalid number of inputs"<<endl;
            sleep_for(seconds(3));
            system("cls");
        }
    }while (n!=0);
    fclose(arq);
    return 0;
}
void func1(float m[5][6]){
    float vx=0.2,x=-3;
    fprintf(arq,"MATRIZ\n");
    for(float (*p)[6]=m;p!=m+5;p++){
        for(float *q=*p;q!=*p+6;q++){
            *q=(1/sqrt(2*M_PI))*exp(-pow(x,2)/2);
            x=x+vx;
            fprintf(arq,"%.4f\t",*q);
        }
        fprintf(arq,"\n");
    }
}
