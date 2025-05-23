/* 
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}

//Print the character arrays
void print(const char array[]){
    cout<<array<<endl;
}

//Print the array of indexes where the pattern found
void print(const int array[]){
    if (array[0]==-1){
        cout<<"None"<<endl;
        return;
    }
    for(int i=0;array[i]!=-1;i++){
        cout<<array[i]<<endl;
    }
}

//Search for all occurrences
void srchAll(const char sntnce[],const char pattern[],int match[]){
    int i=0;
    int pos=0;
    do{
        pos = srch1(sntnce,pattern,pos);
        if(pos!=-1){
            match[i]=pos;
            i++;
            pos++;
        }
    }while(pos!=-1);
    match[i]=-1;
}

//Search for 1 occurrence
int  srch1(const char sntnce[],const char pattern[],int pos){
    int pLen=strlen(pattern);
    int sLen=strlen(sntnce);
    int p=0;
    for(int i=pos;i<sLen-pLen+1;i++){
        if(sntnce[i]==pattern[p]){
            bool found=true;
            for(int j=1;j<pLen&&found;j++){
                if(sntnce[i+j]!=pattern[j])found=false;
            }
            if(found)return i;
        }
    }
    return -1;
}