#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;
using namespace this_thread;
void findFact(int n, int *f);
void (*p1[])(int,int *p)={findFact};
int main()
{
    int n;
    int fact;
    int num1;
    do{
        cout<<"Input the number 1 to iniciate: ";
        cin>>n;
        if(n==1){
            cout<<"Input a number: ";
            cin>>num1;
            (*p1[n-1])(num1,&fact);
        }
        else if(n>1||n<1){
            cout<<"Error: Invalid number."<<endl;
            sleep_for(seconds(2));
            system("cls");
        }
    }while(n!=1);
    cout<<"Factorial of "<<num1<<" is "<<fact<<endl;
    return 0;
}
void findFact(int n, int *f)
{
    int i;
    *f = 1;
    for (i = 1; i <= n; i++)
    *f = *f * i;
}