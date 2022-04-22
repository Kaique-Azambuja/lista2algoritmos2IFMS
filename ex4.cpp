#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;
using namespace this_thread;
void calculate(int *ma,int *mb);
void(*p[])(int *x,int *xx)={calculate};
int main(){
    int n,a,b;
    do{
        cout<<"input 1 to calculate the molecule\ninput 2 to exit the program\ninput a number: ";
        cin>>n;
        if(n<2&&n!=0){
            cout<<"input the value of ma: ";
            cin>>a;
            cout<<"input the value of mb: ";
            cin>>b;
            (*p[n-1])(&a,&b);
        }else if(n>2||n==0){
            cout<<"ERROR: invalid number of input, please try again.";
            sleep_for(seconds(2));
            system("cls");
        }
    }while(n!=2);
    return 0;
}
void calculate(int *ma,int *mb){
    cout<<"value of u is: "<<((*ma)*(*mb))/(*ma+*mb)<<endl;
    sleep_for(seconds(2));
    system("cls");
}