/*********************************************************************************
* Edison Chen, edhachen
* 2022 Winter CSE101 PA6
* ListTest.cpp
* Test file for the List ADT
*********************************************************************************/

#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"

using namespace std;

int main(){
   /*
   List A, B, C, D;
   A.insertAfter(16);
   A.insertAfter(200);
   A.insertAfter(176);
   A.insertAfter(16);
   A.insertAfter(5);
   A.insertAfter(1);
   A.findNext(16);
   if (A.position() != 3)
      return 1;

   A.movePrev();
   A.insertBefore(225);
   if (A.position() != 3)
      return 2;

   A.moveNext();
   A.findNext(16);
   if (A.position() != 7)
      return 3;

   A.moveFront();
   A.findNext(16);
   if (A.position() != 4)
      return 4;
   A.insertBefore(1);
   A.insertBefore(5);
   A.insertBefore(16);
   A.insertBefore(176);
   A.insertBefore(3214);
   A.movePrev();
   A.movePrev();
   if (A.position() != 3)
      return 1;
   A.movePrev();
   A.movePrev();
   A.movePrev();
   if (A.position() != 0)
      return 2;
   A.insertAfter(3214);
   A.insertAfter(176);
   A.insertAfter(16);
   A.insertAfter(5);
   A.insertAfter(1);
   A.moveNext();
   A.moveNext();
   if (A.position() != 2)
      return 1;
   A.moveNext();
   A.moveNext();
   A.moveNext();
   if (A.position() != 5)
      return 2;
   A.insertBefore(3);
   A.insertBefore(3);
   A.insertBefore(1);
   A.insertBefore(3);
   A.insertBefore(2);
   A.insertBefore(2);
   A.insertBefore(1);
   A.insertBefore(4);
   B.insertBefore(3);
   B.insertBefore(1);
   B.insertBefore(2);
   if (A.equals(B))
      return 1;

   A.cleanup();
   if (A.equals(B))
      return 2;

   A.moveBack();
   A.eraseBefore();
   if (!A.equals(B))
      return 3;
   return 0;
   A.insertAfter(3215);
   A.insertAfter(176);
   A.insertAfter(22);
   A.insertAfter(5);
   A.insertAfter(1);
   A.moveNext();
   if (A.moveNext() != 5)
      return 1;

   A.eraseBefore();
   A.eraseBefore();
   A.moveNext();
   A.moveNext();
   if (A.moveNext() != 3215)
      return 2;

   A.moveFront();
   if (A.moveNext() != 22)
      return 3;
   return 0;
   A.insertBefore(1);
   A.insertAfter(3);
   A.insertAfter(2);
   B.insertBefore(3);
   B.insertBefore(2);
   B.insertBefore(1);
   C.insertAfter(1);
   C.insertAfter(2);
   C.insertAfter(3);
   C.insertAfter(3);
   C.insertAfter(2);
   C.insertAfter(1);
   if (!C.equals(A.concat(B)))
      return 1;
   return 0;
   A.insertBefore(1);
   A.insertBefore(5);
   A.insertBefore(16);
   A.insertBefore(176);
   A.insertBefore(3214);
   A.movePrev();
   A.movePrev();
   if (A.position() != 3)
      return 1;
   A.movePrev();
   A.movePrev();
   A.movePrev();
   if (A.position() != 0)
      return 2;
   return 0;
   A.insertAfter(1);
   A.insertAfter(2);
   A.insertAfter(3);
   A.insertAfter(1);
   A.insertAfter(2);
   A.insertAfter(1);
   A.cleanup();
   if (A.length() != 3)
      return 1;
   return 0;
   A.insertBefore(34);
   A.insertBefore(77);
   A.insertBefore(77);
   A.insertBefore(1);
   A.insertBefore(34);
   A.insertBefore(1);
   A.insertBefore(55);
   A.insertBefore(77);
   if (A.findPrev(99) != -1)
      return 1;
   if (A.position() != 0)
      return 2;

   A.moveBack();
   if (A.findPrev(1) != 5)
      return 3;
   if (A.findPrev(1) != 3)
      return 4;
   if (A.findPrev(1) != -1)
      return 5;

   A.moveBack();
   A.cleanup();
   if (A.findPrev(1) != 2)
      return 6;
   if (A.findPrev(1) != -1)
      return 7;
   return 0;

   A.insertBefore(1);
   A.insertBefore(2);
   A.insertBefore(3);
   B.insertBefore(4);
   B.insertBefore(5);
   B.insertBefore(6);
   if (A.concat(B).position() != 0)
      return 1;
   return 0;
   A.insertAfter(3215);
   A.insertAfter(176);
   A.insertAfter(22);
   A.insertAfter(5);
   A.insertAfter(1);
   A.moveNext();
   if (A.moveNext() != 5)
      return 1;
   A.eraseBefore();
   A.eraseBefore();
   A.moveNext();
   A.moveNext();
   if (A.moveNext() != 3215)
      return 2;
   A.moveFront();
   if (A.moveNext() != 22)
      return 3;
   return 0;
   A.insertBefore(1);
   A.insertBefore(2);
   A.insertBefore(2);
   A.insertBefore(1);
   A.insertBefore(2);
   A.insertBefore(3);
   A.insertBefore(1);
   A.findPrev(3);
   A.cleanup();
   if (A.position() != 2)
      return 1;
   B.insertBefore(1);
   B.insertBefore(2);
   B.insertBefore(2);
   B.insertBefore(1);
   B.insertBefore(2);
   B.insertBefore(3);
   B.insertBefore(1);
   B.findPrev(3);
   B.movePrev();
   B.cleanup();
   if (B.position() != 2)
      return 2;
   return 0;

   for(i=1; i<=n; i++){
      A.insertAfter(i);
      B.insertAfter(11-i);
      C.insertBefore(i);
      D.insertBefore(11-i);
   }
   cout << endl;
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
   cout << "C = " << C << endl;
   cout << "C.position() = " << C.position() << endl;
   cout << "D = " << D << endl;
   cout << "D.position() = " << D.position() << endl;
   cout << endl;
   A.moveBack();
   B.moveBack();
   C.moveFront();
   D.moveFront();
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
   cout << "C = " << C << endl;
   cout << "C.position() = " << C.position() << endl;
   cout << "D = " << D << endl;
   cout << "D.position() = " << D.position() << endl;
   cout << endl << "B: ";
   for(i=1; i<=7; i++){
      cout << B.movePrev() << " ";
   }
   cout << endl << "B.position() = " << B.position() << endl;
   cout << endl << "C: ";
   for(i=1; i<=7; i++){
      cout << C.moveNext() << " ";
   }
   cout << endl << "C.position() = " << C.position() << endl;
   cout << endl;
   cout << "A==B is " << (A==B?"true":"false") << endl;
   cout << "B==C is " << (B==C?"true":"false") << endl;
   cout << "C==D is " << (C==D?"true":"false") << endl;
   cout << "D==A is " << (D==A?"true":"false") << endl;
   cout << endl;
   cout << B.findNext(5) << endl;
   cout << B << endl;
   B.eraseBefore();
   B.eraseAfter();
   cout << B << endl;
   cout << B.position() << endl;
   cout << B.findPrev(2) << endl;
   B.eraseBefore();
   B.eraseAfter();
   cout << B << endl;
   cout << B.position() << endl; 
   cout << B.findNext(20) << endl; 
   cout << B.position() << endl;
   cout << B.findPrev(20) << endl;
   cout << B.position() << endl;
   cout << endl;
   int i, n=10;
   for( i=10; i>=1; i--){
      A.insertAfter(i);
      A.movePrev();
   }
   cout << "A = " << A << endl;
   for( i=1; i<=15; i++){
      A.moveNext();
   }
   cout << A.position() << endl;
   A.cleanup();
   cout << "A = " << A << endl;
   cout << A.position() << endl;
   cout << endl;
   List E = A;
   cout << "E==A is " << (E==A?"true":"false") << endl;
   cout << endl;
   List F = A.concat(B);
   cout << "F = " << F << endl;
   cout << "length: " << F.length() << endl;
   cout << "front: " << F.front() << endl;
   cout << "back: " << F.back() << endl;
   cout << "position: " << F.position() << endl;
   for( i=1; i<=7; i++){
      cout << "peekNext: " << F.peekNext() << endl;
      F.insertBefore(-i);
      cout << F.moveNext() << endl; 
   }
   cout << "F = " << F << endl;
   cout << endl;
   cout << "test exceptions: " << endl;
   cout << "A = " << A << endl;
   A.moveFront();
   cout << endl;
   return( EXIT_SUCCESS ); */
}
