/* 
 * File:
 * Author: Renzo Di Cristofaro
 * Date: 2/27/2025
 * Purpose: Output values with different precision
 * Version: 1
 */

//System Libraries - Post Here
#include <iostream>
//Library for our functions utilized in this question.
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    float arr[4];
    
    //Initialize or input data here
    
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
    //Format and display outputs here
    for(int j = 0; j < 4; j++)
    {
    for(int i = 0; i < 3; i++)
    {
        cout<<fixed<<setprecision(i);
        cout<< ((i == 0) ? setw(9) : setw(10));
        cout<<arr[j];
    }
    if (j==3)
        break;
    cout<<endl;
    }
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}