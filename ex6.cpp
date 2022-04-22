#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
using namespace std;
using namespace chrono;
using namespace this_thread;
typedef struct{
    int x,y;
}Coordinate;
void iniciate(Coordinate *x,Coordinate *x0);
void calculate(Coordinate *x,Coordinate *x0);
void (*pt[])(Coordinate *x,Coordinate *y)={iniciate,calculate};
int main(){
    Coordinate c,c0;
    int n;
    do{
        cout<<"Input 1 to start the program\nInput 2 to calculate the coordinates\nInput 0 to exit the program\nInput a number: "<<endl;
        cin>>n;
        if(n<3&&n!=0){
            (*pt[n-1])(&c,&c0);
        }else if(n>=3){
            cout<<"ERROR: Invalid number, please try again.\n"<<endl;
            sleep_for(seconds(3));
            system("cls");
        }
    }while(n!=0);
    return 0;
}
void iniciate(Coordinate *x,Coordinate *x0){
    cout<<"Input the coordinate x in center of circle: ";
    cin>>x0->x;
    cout<<"Input the coordinate y in center of circle: ";
    cin>>x0->y;
    cout<<"Input the coordinate of x in circumference of circle: ";
    cin>>x->x;
    cout<<"Input the coordinate of y in circumference of circle: ";
    cin>>x->y;
}
void calculate(Coordinate *x,Coordinate *x0){
    float R,m,n;
    R=sqrt(pow(x->x,2)+pow(x->y,2)-(2*x0->x*x->x)-(2*x0->y*x->y)+pow(x0->x,2)+pow(x0->y,2));
    cout<<"Circle radius: "<<R<<endl;
    m=(-2*x0->x*x->x);
    n=(-2*x0->y*x->y);
    if(m<0&&n<0){
        cout<<"x^2+y^2"<<m<<n<<"+"<<pow(R,2)<<endl;
    }
    if(m<0&&n>0){
        cout<<"x^2+y^2"<<m<<"+"<<n<<"+"<<pow(R,2)<<endl;
    }
    if(m>0&&n<0){
        cout<<"x^2+y^2+"<<m<<n<<"+"<<pow(R,2)<<endl;
    }
    if(m>0&&n>0){
        cout<<"x^2+y^2+"<<m<<"+"<<n<<"+"<<pow(R,2)<<endl;
    }
}