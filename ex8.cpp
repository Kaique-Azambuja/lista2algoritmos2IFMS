#include <iostream>
#include <chrono>
#include <thread>
#include <cmath> //round
using namespace std;
using namespace chrono;
using namespace this_thread;
void HalleyApparation(float v[]);
void (*pt[])(float v[])={HalleyApparation};
int main(){
    float array[10];
    int n;
    do{
        cout<<"Input 1 to calculate the Halley apparition\nInput 0 to exit the program\nInput a number: ";
        cin>>n;
        if(n<2&&n!=0){
            (*pt[n-1])(array);
        }else if(n>=2){
            cout<<"ERROR: Invalid number, please try again."<<endl;
            sleep_for(seconds(2));
            system("cls");
        }
    }while(n!=0);
    return 0;
}
void HalleyApparation(float v[]){
    v[0]=1986;
    float *p,*pp;
    pp=&v[10];
    
    for(p=v;p<pp;p++){
        if(*p==1986){
            *p=*p+75.3;
            cout<<floor(*p)<<"\t";
        }else{
            *p=*(p-1)+75.3;
            cout<<floor(*p)<<"\t";
        }
   }
   cout<<endl;
}