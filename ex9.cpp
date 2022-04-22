#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;
using namespace this_thread;
void declare(int *x,int *y);
void swp1(int *x,int *y);
void (*ptr[])(int *x,int *y)={declare,swp1};
int main(){
    int n,x,y;
    do{
        cout<<"Input 1 to start the program\nInput 2 to swap\nInput 0 to stop the program\nInput a number: ";
        cin>>n;
        if(n!=0&&n<3){
            (*ptr[n-1])(&x,&y);
        }else if(n>=3){
            cout<<"ERROR: Invalid number, please enter a number valid for the program.\n"<<endl;
            sleep_for(seconds(3));
            system("cls");
        }
    }while(n!=0);
    return 0;
}
void declare(int *x,int *y){
    cout<<"Input a value for x: ";
    cin>>*x;
    cout<<"Input a value for y: ";
    cin>>*y;
    cout<<"Values\nx="<<*x<<" y="<<*y<<endl;
}
void swp1(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
    cout<<"Swap values\nx="<<*x<<" y="<<*y<<endl;
}