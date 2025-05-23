/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Common searching and sorting algorithms
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace std::chrono;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void prntAry(const int [],int,int);
void fillAry(int [],int,int,int);
void swap(int &,int &);
void smlLst(int [],int,int);
void mrkSort(int [],int);
int  linSrch(int [],int, int, int&);
int  binSrch(int [],int, int, int&);
void bublSrt(int [],int,int&);
void selSort(int [],int,int&);
void copyAry(int [],int [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int perLine=10;
    int lowRng=100,highRng=200;

    cout<<setw(5)<<left<<"n"<<right<<setw(30)<<"SelTime     SelCount"<<setw(30)<<"BubTime     BubCount"<<endl;

    for(int n = 10; n <= 300; n += 10){
    int array[n],brray[n];
    int selcounter=0;
    int bubcounter=0;
            
    //Finish initializing the rest of the array
    fillAry(array,n,highRng,lowRng);
    copyAry(brray,array,n);
    
    int value=rand()%(highRng-lowRng+1)+lowRng;



    cout<<n;

    auto start = high_resolution_clock::now();
    selSort(brray,n,selcounter);
    auto end = high_resolution_clock::now();
    cout<<setw(15)<<duration_cast<nanoseconds>(end - start).count();
    cout<<setw(15)<<selcounter;


    start = high_resolution_clock::now();
    bublSrt(array,n,bubcounter);
    end = high_resolution_clock::now();
    cout<<setw(15)<<duration_cast<nanoseconds>(end - start).count();
    cout<<setw(15)<<bubcounter<<endl;
    }

    //Exit
    return 0;
}

void copyAry(int copyIt[],int source[],int n){
    for(int i=0;i<n;i++){
        copyIt[i]=source[i];
    }
}

void selSort(int a[],int n,int& count){
    //Loop and declare variables
    int indx,min;
    for(int pos=0;pos<n-1;pos++){
        //Find the smallest in the list, swap after finding
        min=a[pos];indx=pos;
        for(int i=pos+1;i<n;i++){
            if(a[i]<min){
                min=a[i];
                indx=i;
            }
            count++;
        }
        //Perform the swap
        a[indx]=a[pos];
        a[pos]=min;
        count++;
    }
}

void bublSrt(int a[],int n,int& count){
    //Keep looping and comparing until no swaps are left
    bool swap;
    do{
        swap=false;
        //Check the list and Swap when necessary
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
            }
            count++;
        }
        count++;
    }while(swap);
}



void fillAry(int a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void prntAry(const int a[],int n,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<n;indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void smlLst(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}