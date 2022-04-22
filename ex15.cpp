#include <iostream>
#include <chrono>
#include <thread>
#include <cstring>
using namespace std;
using namespace chrono;
using namespace this_thread;
void poststring(char array[]);
void (*p[])(char array[])={poststring};

int main(){
    char array[50];
    int n;
    do{
        cout<<"Input 1 to start the program\nInput 0 to exit the program\nInput a number: ";
        cin>>n;
        fflush(stdin);
        if(n!=0&&n<2){
            (*p[n-1])(array);
        }else if(n>=2){
            cout<<"ERROR: Invalid number, please try again.\n"<<endl;
            sleep_for(seconds(3));
            system("cls");
        }
    }while(n!=0);
    return 0;
}
void poststring(char array[]){
    int tam,i=0;
    cout<<"Input a string: ";
    gets(array);
    fflush(stdin);
    tam=strlen(array);
    char *p=(char*)malloc(tam+1), *in=p,*fim=p+tam-1;
    char aux,rev[tam];
    for(int i=0;i<=tam;i++) p[i]=array[i];
    for(;in<fim;in++,fim--){
        aux=*fim;
        *fim=*in;
        *in=aux;
    }
    cout<<endl<<"String: "<<array<<endl;
    cout<<"Reversed string: ";
    for(;*p!='\0';p++){
        rev[i]=*p;
        i++;
    }
    cout<<rev;
    free;
    cout<<endl<<endl;
}