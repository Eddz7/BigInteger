//-----------------------------------------------------------------------------
// Edison Chen, edhachen
// 2022 Winter CSE101 PA6
// List.cpp
// Implementation file for the List ADT
//-----------------------------------------------------------------------------

#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"

List::Node::Node(ListElement x){
    data = x;
    next = nullptr;
    prev = nullptr;
}

List::List(){
    frontDummy = new Node(1);
    backDummy = new Node(2);
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    pos_cursor = 0;
    num_elements = 0;
}

List::List(const List& L){
    frontDummy = new Node(1);
    backDummy = new Node(2);
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    pos_cursor = 0;
    num_elements = 0;

    Node *N;
    N = L.frontDummy->next;
    while (N != L.backDummy){
        this->insertBefore(N->data);
        N = N->next;
    }
    this->moveFront();
    //pos_cursor = L.pos_cursor;
}

List::~List(){
    clear();
    delete frontDummy;
    delete backDummy;
}

int List::length() const{
    return(num_elements);
}

ListElement List::front() const{
    if (num_elements <= 0){
        throw std::length_error("List: front(): empty List");
    }
    return(frontDummy->next->data);
}

ListElement List::back() const{
    if (num_elements <= 0){
        throw std::length_error("List: back(): empty List");
    }
    return(backDummy->prev->data);
}

int List::position() const{
    if (0 > pos_cursor || pos_cursor > num_elements){
        throw std::range_error("List: position(): pos out of range");
    }
    return(pos_cursor);
}

ListElement List::peekNext() const{
    if (pos_cursor >= num_elements){
        throw std::range_error("List: peekNext(): pos out of range");
    }
    return(afterCursor->data);
}
ListElement List::peekPrev() const{
    if (pos_cursor <= 0){
        throw std::range_error("List: peekPrev(): pos out of range");
    }
    return(beforeCursor->data);
}

void List::clear(){
    moveFront();
    while(length() > 0){
        eraseAfter();
    }
}

void List::moveFront(){
    pos_cursor = 0;
    beforeCursor = frontDummy;
    afterCursor = frontDummy->next;
}

void List::moveBack(){
    pos_cursor = num_elements;
    beforeCursor = backDummy->prev;
    afterCursor = backDummy;
}

ListElement List::moveNext(){
    if (pos_cursor >= num_elements){
        throw std::range_error("List: moveNext(): pos out of range");
    }
    beforeCursor = afterCursor;
    afterCursor = afterCursor->next;
    pos_cursor += 1;
    return(afterCursor->prev->data);
}

ListElement List::movePrev(){
    if (pos_cursor <= 0){
        throw std::range_error("List: movePrev(): pos out of range");
    }
    afterCursor = beforeCursor;
    beforeCursor = beforeCursor->prev;
    pos_cursor -= 1;
    return(beforeCursor->next->data);
}

void List::insertAfter(ListElement x){
    Node *n = new Node(x);
    n->next = afterCursor;
    n->prev = beforeCursor;
    beforeCursor->next = n;
    afterCursor->prev = n;
    afterCursor = n;
    num_elements += 1;
}

void List::insertBefore(ListElement x){
    Node *n = new Node(x);
    n->prev = beforeCursor;
    n->next = afterCursor;
    beforeCursor->next = n;
    afterCursor->prev = n;
    beforeCursor = n;
    num_elements += 1;
    pos_cursor += 1;
}

void List::setAfter(ListElement x){
    if (pos_cursor >= num_elements){
        throw std::range_error("List: setAfter(): pos out of range");
    }
    afterCursor->data = x;
}

void List::setBefore(ListElement x){
    if (pos_cursor <= 0){
        throw std::range_error("List: setBefore(): pos out of range");
    }
    beforeCursor->data = x;
}

void List::eraseAfter(){
    if (position() >= length()){
        throw std::range_error("List: eraseAfter(): pos out of range");
    }
    Node *n = afterCursor;
    afterCursor = afterCursor->next;
    beforeCursor->next = afterCursor;
    afterCursor->prev = beforeCursor;
    delete n;
    num_elements -= 1;
}

void List::eraseBefore(){
    if (pos_cursor <= 0){
        throw std::range_error("List: eraseBefore(): pos out of range");
    }
    Node *n = beforeCursor;
    beforeCursor = beforeCursor->prev;
    afterCursor->prev = beforeCursor;
    beforeCursor->next = afterCursor;
    delete n;
    num_elements -= 1;
    pos_cursor -= 1;
}

int List::findNext(ListElement x){
    while (position() < length()){
        if (afterCursor->data == x){
            moveNext();
            return(pos_cursor);
        }
        moveNext();
    }
    return(-1);
}

int List::findPrev(ListElement x){
    while (position() > 0){
        if (beforeCursor->data == x){
            movePrev();
            return(pos_cursor);
        }
        movePrev();
    }
    return(-1);
}

void List::cleanup(){
    Node* N;
    Node* M;
    int count = 0;
    int count_two = 0;
    int temp_pos = pos_cursor;
    N = frontDummy->next;
    while (N != backDummy){
        count = 0;
        count_two += 1;
        M = N->next;
        while (M != backDummy){
            count += 1;
            if (N->data == M->data){
                if (M == beforeCursor){
                    M = M->next;
                    eraseBefore();
                    temp_pos -= 1;
                } else if (M == afterCursor){
                    M = M->next;
                    eraseAfter();
                } else{
                    Node *n = M;
                    M->next->prev = M->prev;
                    M->prev->next = M->next;
                    if ((count + count_two) < temp_pos){
                        temp_pos -= 1;
                    }
                    M = M->next;
                    delete n;
                    num_elements -= 1;
                }
            } else if (N->data != M->data){
                M = M->next;
            }
        }
        N = N->next;
    }
    pos_cursor = temp_pos;
}


List List::concat(const List& L) const{
    List test;
    Node* N;
    Node *M;
    for (N = this->frontDummy->next; N != this->backDummy; N = N->next){
        test.insertBefore(N->data);
    }
    for (M = L.frontDummy->next; M != L.backDummy; M = M->next){
        test.insertBefore(M->data);
    }
    return(test);
}

std::string List::to_string() const{
    Node* N;
    std::string s = "";
    s += ("(");
    for (N = frontDummy->next; N != backDummy; N = N->next){
        if (N != frontDummy->next){
            s += ", ";
        }
        s += std::to_string(N->data);
    }
    s += (")");
    return s;
}

bool List::equals(const List& R) const{
    bool eq = false;
    Node* N = nullptr;
    Node* M = nullptr;
    eq = (this->num_elements == R.num_elements);
    N = this->frontDummy->next;
    M = R.frontDummy->next;
    while (eq && N!= nullptr){
        eq = (N->data == M->data);
        N = N->next;
        M = M->next;
    }
    return eq;
}

std::ostream& operator<< ( std::ostream& stream, const List& L){
    return stream << L.List::to_string();
}

bool operator== (const List& A, const List& B){
    return A.List::equals(B);
}

List& List::operator= ( const List& L){
    if (this != &L){
        List temp = L;
        std::swap(frontDummy, temp.frontDummy);
        std::swap(backDummy, temp.backDummy);
        std::swap(afterCursor, temp.afterCursor);
        std::swap(beforeCursor, temp.beforeCursor);
        std::swap(num_elements, temp.num_elements);
        std::swap(pos_cursor, temp.pos_cursor);
    }
    return *this;
}
