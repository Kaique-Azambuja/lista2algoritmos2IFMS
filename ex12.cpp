#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace this_thread;

void elements(int *n,int array[]);
void (*p[])(int *n,int array[])={elements};
int main(){
    int num,n;
    printf("\n\n Pointer : Store and retrieve elements from an array :\n");
    printf("------------------------------------------------------------\n");
    printf(" Input the number of elements to store in the array :");
    scanf("%d",&n);
    int arr1[n];
    do{
        cout<<"Input 1 to input values in array\nInput 0 to exit\nInput a number: ";
        cin>>num;
        if(num!=0&&num<2){
            (*p[num-1])(&n,arr1);
        }else if(num>=2){
            cout<<"ERROR: Invalid number, please enter a number valid."<<endl;
            sleep_for(seconds(2));
            system("cls");
        }
    }while(num!=0);

    return 0;
}
void elements(int *n, int array[]){
    printf(" Input %d number of elements in the array :\n",*n);
    int *p,*pp;
    pp=&array[*n];
    for(p=array;p<pp;p++){
        cout<<"element: ";
        cin>>*p;
    }
    cout<<endl;
    printf(" The elements you entered are : \n");
    for(p=array;p<pp;p++){
        cout<<" element: "<<*p<<" \n";
    }
}