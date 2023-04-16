//-----------------------------------------------------------------------------
// Edison Chen, edhachen
// 2022 Winter CSE101 PA6
// BigIntegerTest.cpp
// Test file for the BigInteger ADT
//-----------------------------------------------------------------------------

#include<iostream>
#include<string>
#include<stdexcept>
#include"BigInteger.h"

using namespace std;

int main(){
    /*
    BigInteger A, B, C, D, E;
    A = BigInteger("-111122223333");
    B = BigInteger("111122223333");
    D = BigInteger("-12348148518469129628889");

    A *= B;
    if (A.sign() != -1)
      return 1;
    cout << "test1 passed" << endl;
    if (!(A == D))
      return 2;
    cout << "test2 passed" << endl;

    A = BigInteger("-111122223333");
    B.negate();
    D.negate();
    A *= B;
    if (A.sign() != 1)
      return 3;
    cout << "test3 passed" << endl;
    if (!(A == D))
      return 4;
    cout << "test4 passed" << endl;

    A = BigInteger("-111122223333");
    B.makeZero();
    A *= B;
    if (A.sign() != 0)
      return 5;

    return 0;

    A = BigInteger("+111122223333");
    B = BigInteger("+222211110000");

    D = BigInteger("+333333333333");
    A += B;

    if (!(A == D))
      return 1;
    cout << "test1 passed" << endl;

    A = BigInteger("+111122223333");
    B = BigInteger("-111122223333");
    A += B;
    if (A.sign() != 0)
      return 2;
    cout << "test2 passed" << endl;

    A = BigInteger("+111122223333");
    B = BigInteger("-110122223333");
    D = BigInteger("1000000000");
    A += B;
    if (A.sign() != 1)
      return 31;
    cout << "test3 passed" << endl;
    if (!(A == D))
      return 32;
    cout << "test4 passed" << endl;

    A = BigInteger("+111122223333");
    B = BigInteger("-112122223333");
    D = BigInteger("-1000000000");
    A += B;
    if (A.sign() != -1)
      return 41;
    cout << "test5 passed" << endl;
    if (!(A == D))
      return 42;
    cout << "test6 passed" << endl;

    //-> neg + neg = neg
    A = BigInteger("-221211110000");
    B = BigInteger("-112122223333");
    D = BigInteger("-333333333333");
    A += B;
    if (!(A == D))
      return 5;

    return 0;
    A = BigInteger("+13378008135");
    A.makeZero();
    if (A.sign() != 0)
      return 1;
    cout << "test1 passed" << endl;

    B = BigInteger();
    if (!(A == B))
      return 2;
    cout << "test2 passed" << endl;
    return 0;
    A = BigInteger("111122223333");
    B = BigInteger("111122223333");
    C = BigInteger();
    D = BigInteger("12348148518469129628889");

    // pos * pos = pos
    C = A * B;
    if (C.sign() != 1)
      return 1;
    cout << "test1 passed" << endl;
    if (!(C == D))
      return 2;
    cout << "test2 passed" << endl;

    // pos * neg = neg
    B.negate();
    D.negate();
    C = A * B;
    if (C.sign() != -1)
      return 3;
    cout << "test3 passed" << endl;
    if (!(C == D))
      return 4;
    cout << "test4 passed" << endl;

    B.makeZero();
    C = A * B;
    if (C.sign() != 0)
      return 5;
    cout << "test5 passed" << endl;

    return 0;
    A = BigInteger("111122223333");
    B = BigInteger("111122223333");
    C = BigInteger("-111122223333");
    D = BigInteger("999111122223333");
    
    if (!(A == B))
      return 1;
    cout << "test1 passed" << endl;
    if ((A == C))
      return 2;
    cout << "test2 passed" << endl;
    if ((A == D))
      return 3;
    cout << "test3 passed" << endl;
    return 0;

    A = BigInteger("111122223333");
    B = BigInteger("111122223333");
    C = BigInteger("112122223333");
    D = BigInteger("110122223333");

    // A = B
    if (!(A <= B))
      return 1;
    cout << "test1 passed" << endl;

    // A < C
    if (A >= C)
      return 2;
    cout << "test2 passed" << endl;
    // A > D
    if (A <= D)
      return 3;
    cout << "test3 passed" << endl;
    return 0;

    A = BigInteger("90");
    B = BigInteger("-82");
    C = A*A*A*A*BigInteger("9");
    D = B*B*B*B*B*BigInteger("16");
    E = C + D;
    cout << C << endl;
    cout << "C sign = " << C.sign() << endl;
    cout << D << endl;
    cout << "D sign = " << D.sign() << endl;
    cout << E << endl;
    cout << "E sign = " << E.sign() << endl;
    cout << C.compare(D) << endl;
    
    return 0;
   string s1 = "9128734667000004389234563456345619187236478";
   //string s2 = "-330293847502398475";
   string s3 = "9876545439000000000000000200000000000006543654365346534";
   //string s4 = "9876545439000000000000000100000000000006543654365346534";
   //string s5 = "98765454390000000000000000000000000000065436543";
   //string s6 = "9876545439000000000000000000000000000006543";

   //BigInteger N;
   BigInteger A = BigInteger(s1);
   BigInteger B = BigInteger(s3);

   cout << endl;

   cout << "A = " << A << endl;
   cout << "B = " << B << endl;
   cout << endl;

   BigInteger C = A+B;
   BigInteger D = B+A;
   BigInteger E = A-A;
   BigInteger F = B-A;
   BigInteger G = A*B;
   BigInteger H = B*A;
   BigInteger I = C*E;

   cout << "(A==B) = " << ((A==B)?"True":"False") << endl;
   cout << "(A<B)  = " << ((A<B)? "True":"False") << endl;
   cout << "(A<=B) = " << ((A<=B)?"True":"False") << endl;
   cout << "(A>B)  = " << ((A>B)? "True":"False") << endl;
   cout << "(A>=B) = " << ((A>=B)?"True":"False") << endl << endl;

   cout << "C = " << C << endl;
   cout << "D = " << D << endl;
   cout << "(C==D) = " << ((C==D)?"True":"False") << endl;
   cout << "E = " << E << endl;
   cout << "F = " << F << endl;
   cout << "G = " << G << endl;
   cout << "H = " << H << endl;
   cout << "(G==H) = " << ((G==H)?"True":"False") << endl;
   cout << "I = " << I << endl << endl;

   cout << endl;

   A += B;
   B -= C;
   C *= D;
   cout << "A = " << A << endl;
   cout << "B = " << B << endl;
   cout << "C = " << C << endl;
   cout << endl;

   cout << A*B*C*D*F*G*H << endl << endl;

   cout << endl;

   // test exceptions
   try{
      BigInteger J = BigInteger("");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      BigInteger J = BigInteger("+");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      BigInteger J = BigInteger("12329837492387492837492$4982379487293847");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      BigInteger J = BigInteger("5298374902837409+82734098729287349827398");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }

   cout << endl;

   return EXIT_SUCCESS; */
}
