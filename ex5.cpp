#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;
using namespace this_thread;
void recipe(int *n);
void (*ptr[])(int *number)={recipe};
int main(){
    int n,client;
    do{
        cout<<"Input 1 to start the recipe.\nInput 0 to exit the program.\nInput a number: ";
        cin>>n;
        if(n==1){
            cout<<"Input the number of clients: ";
            cin>>client;
            (*ptr[n-1])(&client);
        }else if(n!=1&&n!=0){
            cout<<"ERROR: Invalid number input"<<endl;
            sleep_for(seconds(3));
            system("cls");
        }
    }while(n!=0);
    return 0;
}
void recipe(int *n){
    cout<<*n*675<<"g of apple."<<endl;
    cout<<*n*75<<"g of butter."<<endl;
    cout<<*n*150<<"g of sugar."<<endl;
    cout<<*n*100<<"g of bread crumbs."<<endl;
    cout<<*n*150<<"ml of milk cream."<<endl;
}