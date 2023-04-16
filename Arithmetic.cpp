/*********************************************************************************
* Edison Chen, edhachen
* 2022 Winter CSE101 PA6
* Arithmetic.cpp
* Main program file for PA6
*********************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include"BigInteger.h"
using namespace std;
int main(int argc, char *argv[]){
    ifstream in;
    ofstream out;
    string a;
    string b;
    string empty;
    BigInteger A;
    BigInteger B;

   if( argc != 3 ){
      cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
      return(EXIT_FAILURE);
   }

   in.open(argv[1]);
   if( !in.is_open() ){
      cerr << "Unable to open file " << argv[1] << " for reading" << endl;
      return(EXIT_FAILURE);
   }

   out.open(argv[2]);
   if( !out.is_open() ){
      cerr << "Unable to open file " << argv[2] << " for writing" << endl;
      return(EXIT_FAILURE);
   }

    getline(in, a);
    A = BigInteger(a);
    out << A << "\n" << endl;
    getline(in, empty);
    getline(in, b);
    B = BigInteger(b);
    out << B << "\n" << endl;
    out << A+B << "\n" << endl;
    out << A-B << "\n" << endl;
    out << A-A << "\n" << endl;
    out << (A * BigInteger("3") - (B * BigInteger("2")) ) << "\n" << endl;
    out << A*B << "\n" << endl;
    out << A*A << "\n" << endl;
    out << B*B << "\n" << endl;
    out << ((A*A*A*A)*BigInteger("9")) + ((B*B*B*B*B)*BigInteger("16")) << "\n" << endl;
    in.close();
    out.close();
}