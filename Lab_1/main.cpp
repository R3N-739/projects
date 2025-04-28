/*Renzo Di Cristofaro
  March 30th, 2025
  Purpose:  Curve fit of Data Structure
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;

//User Libraries 
//Global Constants - Physics, Math, Conversions, Dimensions for
//function prototypes only!

//Function Prototypes

    //Read Farenheit Data
vector<float> readFarenheitData(const string& FILE){ 
    ifstream in(FILE);
    vector<float> X; //Vector for  Data
    float temp;
    while(in >> temp){
        X.push_back(temp);
    }
    in.close();
    return X;
}
    //Read Farenheit Data
vector<float> readErrorData(const string& FILE){
    ifstream in(FILE);
    vector<float> e; //Vector for  Data
    float temp;
    while(in >> temp){
        e.push_back(temp);
    }
    in.close();
    return e;
}
    //Convert Farenheit to Celsius and add Noise
vector<float> FtoCplusError(const vector<float>& X, const vector<float>& e){ 
    vector<float> Y; //Vector for Celsius Data
    for(int i = 0; i < X.size(); i++){
        Y.push_back(5.0/9.0*(X[i]-32)+e[i]); //Convert Farenheit to Celsius plus Error
    }
    return Y;
}
    //Sum with single input
double sum(const vector<float>& vec){
    int n = vec.size();
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += vec[i];
    }
    return sum;
}
    //Sum with two inputs
double sum(const vector<float>& X, const vector<float>& Y){
    int n = X.size();
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += X[i]*Y[i];
    }
    return sum;
}


//Execution begins here
int main(){
    //Constants
    const int n = 15; //Width of the output

    //Declare Variables
    float m, b; //Slope and Intercept
    int N;  //Data size

    //Vectors + Initialization
    vector<float> X = readFarenheitData("DegreeF_X.txt"); //Vector for Farenheit Data
    vector<float> e = readErrorData("error.txt"); //Vector for Celsius Data
    vector<float> Y = FtoCplusError(X,e); //Vector for Noisy Celsius Data

    //Calculate Slope and Intercept
    N = X.size();
    m = (sum(X)*sum(Y)-N*sum(X,Y))/(sum(X)*sum(X)-N*sum(X,X));  //Calculated Slope
    b = (sum(Y)-m*sum(X))/N;

    //Output
    cout<<"Count"<<setw(n)<<"Deg. F"<<setw(n)<<"Error"<<setw(n)
        <<"Noisy Deg. C"<<endl;
    cout<<fixed<<setprecision(2);
    for(int i = 0; i < X.size(); i++){
        cout<<setw(5)<<i+1<<setw(n)<<X[i]<<setw(n)<<e[i]<<setw(n)<<Y[i]<<endl;
    }
    cout<<endl;
    cout<<"SumX  = "<<left<<setw(n)<<sum(X)  <<" SumY  = "<<sum(Y)<<endl;
    cout<<"SumXX = "<<left<<setw(n)<<sum(X,X)<<" SumXY = "<<sum(X,Y)<<endl;
    cout<<setprecision(5);
    cout<<"Derived m = "<<setw(n/2)<<m<<"\tTrue m = "<<5.0/9.0<<endl;
    cout<<"Derived b = "<<setw(n/2)<<b<<"\tTrue b = "<<-32*5.0/9.0<<endl;
}