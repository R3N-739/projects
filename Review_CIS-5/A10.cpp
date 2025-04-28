/* 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    //if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    
    //Exit
    return 0;
}

int  read(char array[][COLMAX],int &rowDet){
    int colDet=0;
    //clear buffer
    cin.ignore();
    for(int i=0;i<rowDet;i++){
        cin.getline(array[i],COLMAX);
        if(colDet<strlen(array[i]))colDet=strlen(array[i]);
    }
    return colDet;
}

void sort(char array[][COLMAX],int rowIn,int colIn,const char replace[],const char with[]){
    for(int pos=0;pos<rowIn-1;pos++){
        for(int i=pos+1;i<rowIn;i++){
            //If string compare function returns greater than 0 then swap
            if(strcmp(array[pos],array[i],replace,with)>0){
                //SWAP
                char temp[COLMAX];
                strcpy(temp,array[pos]);
                strcpy(array[pos],array[i]);
                strcpy(array[i],temp);
            }
        }
    }
}

void print(const char array[][COLMAX],int rowIn,int colIn){
    for(int i=0;i<rowIn;i++){
        cout<<array[i]<<endl;
    }
}

int strcmp(char a[], char b[], const char replace[], const char with[]) {
    char tempA[COLMAX], tempB[COLMAX];
    strcpy(tempA, a);
    strcpy(tempB, b);
    //Replace array a
    for (int i = 0; tempA[i] != '\0'; i++) {
        for (int j = 0; replace[j] != '\0'; j++) {
            if (tempA[i] == replace[j]) {
                tempA[i] = with[j];
                break;
            }
        }
    }
    //Replace for array b
    for (int i = 0; tempB[i] != '\0'; i++) {
        for (int j = 0; replace[j] != '\0'; j++) {
            if (tempB[i] == replace[j]) {
                tempB[i] = with[j];
                break;
            }
        }
    }
    //Return correct value for sort
    return strcmp(tempA, tempB);
}