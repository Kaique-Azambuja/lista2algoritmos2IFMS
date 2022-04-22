#include <iostream>
#include <chrono>
#include <thread>
#include <cstdio>
using namespace std;
using namespace chrono;
using namespace this_thread;
void compare(char str[]);
void (*p[])(char str[])={compare};
int main(){
    int n;
    char array[100];
    do{
        cout<<"Input 1 to iniciate the string and count your characters\nInput 0 to stop the program\nInput a number: ";
        cin>>n;
        fflush(stdin);
        if(n!=0&&n<2){
            (*p[n-1])(array);
        }else if(n>=2){
            cout<<"ERROR: Invalid number, please try again\n"<<endl;
            sleep_for(seconds(3));
            system("cls");
        }
    }while(n!=0);
    return 0;
}
void compare(char str[]){
    int count=0;
    cout<<"Input a string: ";
    gets(str);
    cout<<"Length of '"<<str;
    while(*(str++) != '\0') count++;
    cout<<"' is "<<count<<endl<<endl;
}