#include <iostream>
#include <chrono>
#include <thread>
#include <random>
using namespace std;
using namespace chrono;
using namespace this_thread;
void startArray(int array[],int *n);
void findElement(int array[],int *n);
void (*p[])(int array[],int *n)={startArray, findElement};
int main(){
    int n,length;
    cout<<"Input a length of array: ";
    cin>>length;
    int array[length];
    system("cls");
    do{
        cout<<"Input 1 to start the array\nInput 2 to find the elements\nInput 0 to exit the program\nInput a number: ";
        cin>>n;
        if(n!=0&&n<3){
            (*p[n-1])(array,&length);
        }else if(n>=3){
            cout<<"ERROR: Invalid number in argument, please try again\n"<<endl;
            sleep_for(seconds(3));
            system("cls");
        }
    }while(n!=0);
    return 0;
}
void startArray(int array[],int *n){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dist(0,100);
    int *p,*pp,c=0;
    pp=&array[*n];
    for(p=array;p<pp;p++){
        *p=dist(gen);
    }
    cout<<"Array started: "<<endl;
    for(p=array;p<pp;p++){
        cout<<"["<<c<<"]: "<<*p<<endl;
        c++;
    }
    cout<<endl;
}
void findElement(int array[],int *n){
    int element,c=0,*p,*pp;
    cout<<"Input a desired number: ";
    cin>>element;
    pp=&array[*n];
    cout<<"Element desired in array position: "<<endl;
    for(p=array;p<pp;p++){
        if(element==*p){
            cout<<"["<<c<<"]: "<<*p<<endl;
        }
        c++;
    }
    cout<<endl;
}