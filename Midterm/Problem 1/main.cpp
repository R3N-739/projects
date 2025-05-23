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
void bublSrt(int [],int);
void selSort(int [],int);
void copyAry(int [],int [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int perLine=10;
    int lowRng=100,highRng=200;

    cout<<setw(5)<<"n"<<setw(5)<<"Lin"<<setw(5)<<"Bin"<<endl;
    for(int n = 100; n <= 3000; n += 100){
    int array[n],brray[n];
    int bincounter=0;
    int lincounter=0;
    
        
    //Finish initializing the rest of the array
    fillAry(array,n,highRng,lowRng);
    copyAry(brray,array,n);
    
    //Print the values in the array
    //prntAry(array,SIZE,perLine);
    //prntAry(brray,SIZE,perLine);
    
    //Sort the array the for all positions
    //mrkSort(array,SIZE);
    bublSrt(array,n);
    selSort(brray,n);
    
    //Test the linear search by randomly choosing a value and
    //determine if found;
    int value=rand()%(highRng-lowRng+1)+lowRng;

    cout<<setw(5)<<n;
    //cout<<"Using the Linear Search"<<endl;
    //cout<<"The value "<<value<<" was found at position "
    //        <<linSrch(array,n,value,lincounter)<<endl;
    auto start = high_resolution_clock::now();
    linSrch(array,n,value,lincounter);
    auto end = high_resolution_clock::now();
    cout<<setw(5)<<duration_cast<nanoseconds>(end - start).count();

    //cout<<"Using the Binary Search"<< endl;
    //cout<<"The value "<<value<<" was found at position "
    //        <<binSrch(brray,n,value,bincounter)<<endl;
    start = high_resolution_clock::now();
    binSrch(brray,n,value,bincounter);
    end = high_resolution_clock::now();
    cout<<setw(5)<<duration_cast<nanoseconds>(end - start).count()<<endl;  
    }

    //Exit
    return 0;
}

void copyAry(int copyIt[],int source[],int n){
    for(int i=0;i<n;i++){
        copyIt[i]=source[i];
    }
}

void selSort(int a[],int n){
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
        }
        //Perform the swap
        a[indx]=a[pos];
        a[pos]=min;
    }
}

void bublSrt(int a[],int n){
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
        }
    }while(swap);
}

int  binSrch(int a[],int n, int val, int& counter){
    //Initialize end points which are indexes
    int lowEnd=0;
    int highEnd=n-1;
    //Loop until value found not indexes
    do{
        int middle=(highEnd+lowEnd)/2;
        if(val==a[middle])return middle;
        else if(val>a[middle])lowEnd=middle+1;
        else highEnd=middle-1;
        counter++;
    }while(lowEnd<=highEnd);
    //Not found
    return -1;
}

int  linSrch(int a[],int n, int val, int& counter){
    for(int indx=0;indx<n;indx++){
        if(val==a[indx])return indx;
        counter++; 
    }
    return -1;
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

void mrkSort(int a[],int n){
    for(int pos=0;pos<n-1;pos++){
        smlLst(a,n,pos);
    }
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