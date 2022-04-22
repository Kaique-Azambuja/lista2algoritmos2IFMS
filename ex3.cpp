#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
using namespace std;
using namespace chrono;
using namespace this_thread;
void func1(int *v);
void func2(int *v);
void func3(int *v);
void (*pt[])(int *v)={func1, func2, func3};
int main(){
    int x,n;
    do{
        cout<<"input 1 to use function 1\ninput 2 to use function 2\ninput 3 to use function 3\ninput 0 to end program\ninput a number: ";
        cin>>n;
        if(n>0&&n<4){
            cout<<"input the value of x: ";
            cin>>x;
            (*pt[n-1])(&x);
        }else if(n>4){
            cout<<"ERROR: invalid value of input."<<endl;
            sleep_for(seconds(3));
            system("cls");
        }
    }while(n!=0);
    return 0;
}
void func1(int *v){
    cout<<"result of expression x-1: "<<*v-1<<endl;
}
void func2(int *v){
    cout<<"result of expression x+1: "<<*v+1<<endl;
}
void func3(int *v){
    cout<<"result of expression x^2+x-2: "<<pow(*v,2)+*v-2<<endl;
}