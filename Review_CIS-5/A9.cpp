/* 
 * File:   A9.cpp
 * Author: Renzo Di Cristofaro
 * Created on 3/11/25
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}

short subtrct(signed short snShort,int n){
    if(snShort-n<0)return snShort;
    return snShort-n;
}

bool  reverse(unsigned short unShort,signed short &snShort){
    unsigned short rvShort = 0;
    int digits = 0;
    while (unShort > 0){
        rvShort = rvShort*10 + unShort%10;
        unShort/=10;
        digits++;
    }
    while (digits < 5){
        rvShort *= 10;
        digits++;
    }
    if (rvShort > 32767)return false;
    else{
        snShort = rvShort;
        return true;
    }
}

bool  inRange(const char digits[],unsigned short &unShort){
    //Test the size of the array
    if(strlen(digits)>5)return false;
    //Test each digit for a number
    for(int i=0;i<strlen(digits);i++){
        if(digits[i]<'0'||digits[i]>'9')return false;
    }
    //Convert the character array to an unsigned short
    unShort=0;
    for(int i=0;i<strlen(digits);i++){
        unShort=unShort*10+digits[i]-'0';
    }
    return unShort<=65535;
}