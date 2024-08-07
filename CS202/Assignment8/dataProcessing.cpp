 #include "dataProcessing.h"
using namespace std;

// ******************************
// * Global Helper Functions
// ********************************

// ---------------------
// isInteger
//    returns true if the string
//    parameter is an integer
//---------------------- **
bool isInteger(string s){
    // If length is 0
    if(s.length() == 0){ return false; }
    // If first char is not '-' or a digit
    if(s[0] != '-' && (s[0] < 48 || s[0] > 57)){ return false; }
    // For all chars
    for(unsigned int i = 1; i < s.length(); i++){
        // If not a digit
        if(s[i] < 48 || s[i] > 57){
            return false;
        }
    }
    // Succesfully made it through
    return true;
}

// ---------------------
// isChar
//    returns true if the string
//    parameter is a char
//---------------------- **
bool isChar(string s){
    // If length is 1
    if(s.length() == 1){
        // Return (is this a not digit?)
        return (s[0] < 48 || s[0] > 57);
    }
    return false;
}

// ---------------------
// isDouble
//    returns true if the string
//    parameter is a double
//---------------------- **
bool isDouble(string s){
    // If length is 0
    if(s.length() == 0){ return false; }
    // If first char is not '-' or a digit
    if(s[0] != '-' && (s[0] < 48 || s[0] > 57)){ return false; }
    
    bool foundDecimal = false;
    // For all chars
    for(unsigned int i = 1; i < s.length(); i++){
        // If not a digit or a decimal
        if((s[i] < 48 || s[i] > 57) && s[i] != '.'){
            return false;
        }
        // If a decimal
        if(s[i] == '.'){
            // If already found a decimal
            if(foundDecimal){
                return false;
            }
            foundDecimal = true;
        }
    }
    // Succesfully made it through
    return true;
}

// ---------------------
// isBool
//    returns true if the string
//    parameter is a bool
//---------------------- **
bool isBool(string s){
    return (s == string("true") || s == string("false")); 
}

// ---------------------
// stob
//   convert string to bool
//---------------------- **
bool stob(string s){
    if(s == string("true")){
        return true;
    }
    else if(s == string("false")){
        return false;
    }
    cout << "ERROR: Tried to convert something that is not a bool." << endl;
    exit(1);
    return false;
}

// ---------------------
// getDataType
//    checks what kind of data type is in parameter
//    returns data type.
//---------------------- **
unsigned int getDataType(string garbage){
    if(isInteger(garbage) == true)
        return INT;
    else if(isChar(garbage) == true)
        return CHAR;
    else if(isBool(garbage) == true)
        return BOOL;
    else if(isDouble(garbage) == true)
        return DOUBLE;
    else
        return STRING; // Students may want to replace
}

// ******************************
// * dataElementBase
// ********************************

// ---------------------
// param constructor dataElementBase
//    <your comments here>
//---------------------- **
dataElementBase::dataElementBase(unsigned short dt){
    // YOUR CODE HERE
    dataType = dt;
    short *head;
    head = new short;
}

// ---------------------
// copy constructor dataElementBase
//    <your comments here>
//---------------------- **
dataElementBase::dataElementBase(const dataElementBase& copy){
    dataType = copy.dataType;
    next = nullptr;
    prev = nullptr;
}

// ---------------------
// assignment operator overload dataElementBase
//    <your comments here>
//---------------------- **
void dataElementBase::operator=(const dataElementBase& copy){
    dataType = copy.dataType;
    next = nullptr;
    prev = nullptr;
    // YOUR CODE HERE
}

// ---------------------
// destructor dataElementBase
//    Virtual destructor that does nothing.

//    It must be here to call the dataElement
//    destructor, which in turn will deallocate
//    any data from a class (like string). 
//---------------------- **
dataElementBase::~dataElementBase(){}

// ---------------------
// getDataType
//    return dataType of dataElement
//---------------------- **
unsigned short dataElementBase::getDataType() const{
    return this->dataType;
}

// ---------------------
// getNext
//    return link to next dataElement
//---------------------- **
dataElementBase *dataElementBase::getNext() const{
    return next;
}

// ---------------------
// getPrev
//    return link to previous dataElement
//---------------------- **
dataElementBase *dataElementBase::getPrev() const{
    return prev;
}

// ---------------------
// link
//    <your comments here>
//---------------------- **
void dataElementBase::link(dataElementBase *node){
    // YOUR CODE HERE
    node->next = node;
    if(node != nullptr)
        node->prev = node;

}

// ---------------------
// compare
//    Function is used to compare 
//      2 dataElements. Must be called
//      like this: deb1->compare(deb2)
//
//      The pointer is required to call getData
//      the return pointer must be casted to
//      the correct type, then compared. 
//---------------------- **
short dataElementBase::compare(dataElementBase *deb){
    if(deb == nullptr){
        cout << "ERROR: Tried to compare nullptr." << endl;
    }
    // If the dataTypes are not equal
    if(dataType < deb->dataType){
        return LESSTHAN;
    }
    if(dataType > deb->dataType){
        return GREATERTHAN;
    }
    // Datatypes are equal 
    switch(dataType){
        case(INT):{
            if(*(static_cast<int*>(this->getData())) < *(static_cast<int*>(deb->getData()))){
                return LESSTHAN;
            }
            if(*(static_cast<int*>(this->getData())) > *(static_cast<int*>(deb->getData()))){
                return GREATERTHAN;
            }
            break;
        }
        case(CHAR):{
            if(*(static_cast<char*>(this->getData())) < *(static_cast<char*>(deb->getData()))){
                return LESSTHAN;
            }
            if(*(static_cast<char*>(this->getData())) > *(static_cast<char*>(deb->getData()))){
                return GREATERTHAN;
            }
            break;
        }
        case(DOUBLE):{
            if(*(static_cast<double*>(this->getData())) < *(static_cast<double*>(deb->getData()))){
                return LESSTHAN;
            }
            if(*(static_cast<double*>(this->getData())) > *(static_cast<double*>(deb->getData()))){
                return GREATERTHAN;
            }
            break;
        }
        case(BOOL):{
            if(*(static_cast<bool*>(this->getData())) < *(static_cast<bool*>(deb->getData()))){
                return LESSTHAN;
            }
            if(*(static_cast<bool*>(this->getData())) > *(static_cast<bool*>(deb->getData()))){
                return GREATERTHAN;
            }
            break;
        }
        case(STRING):{
            if(*(static_cast<string*>(this->getData())) < *(static_cast<string*>(deb->getData()))){
                return LESSTHAN;
            }
            if(*(static_cast<string*>(this->getData())) > *(static_cast<string*>(deb->getData()))){
                return GREATERTHAN;
            }
            break;
        }
    }
    return EQUAL;
}

// ---------------------
// getNewDataElement
//    <your comments here>
//---------------------- **
dataElementBase* dataElementBase::getNewDataElement(unsigned short dataType, string data){
    // YOUR CODE HERE
    return nullptr; // Students may want to replace
}

// ---------------------
// deepCopyDataElement
//    <your comments here>
//---------------------- **
dataElementBase* dataElementBase::deepCopyDataElement(dataElementBase *deb){
    // YOUR CODE HERE
    return nullptr; // Students may want to replace
}

// ---------------------
// swap
//    <your comments here>
//---------------------- **
void dataElementBase::swap(dataElementBase* A, dataElementBase* B){
    // YOUR CODE HERE
    dataElementBase* temp;
    if(A->next != B && B->prev != A){
        if(A->next != NULL)
            temp = A->next;
        else
            return;
        if(B->next != NULL)
            A->next = B->next;
        else
            return;
        B->next = temp;
        if(A->prev != NULL)
            temp = A->prev;
        else
            return;
        if(B->prev != NULL)
            A->prev = B->prev;
        else
            return;
        B->prev = temp;
    }
    else{
        if(B->next != NULL)
            temp = B->next;
        else
            return;
        if(B->prev != NULL)
            B->next = B->prev;
        else
            return;
        if(A->prev != NULL)
            B->prev = A->prev;
        else
            return;
        if(A->next != NULL)
            A->prev = A->next;
        else
            return;
        A->next = temp;
    }
}

// ******************************
// * dataElement
// ********************************

// ---------------------
// param constructor dataElement
//    constructor to initliaze the data
//    must inline a call to the dataElementBase ctor.
//---------------------- **
template<typename t>
dataElement<t>::dataElement(unsigned short dt, t d) : dataElementBase(dt){
    data = d;
}

// ---------------------
// getData
//    return a void pointer 
//    to the data
//---------------------- **
template<typename t>
void* dataElement<t>::getData(){
    return static_cast<void*>(&data);
}

// ---------------------
// printElement
//    print out the data
//---------------------- **
template<typename t>
void dataElement<t>::printElement(ostream& out) const{
    out << data;
}

// ******************************
// * garbagePile
// ********************************

// ---------------------
// default constructor garbagePile
//    <your comments here>
//---------------------- **
garbagePile::garbagePile(){
    // YOUR CODE HERE
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// ---------------------
// copy constructor garbagePile
//    <your comments here>
//---------------------- **
garbagePile::garbagePile(const garbagePile &copy){
    // YOUR CODE HERE
    head = copy.head;
    tail = copy.tail;

}

// ---------------------
// operator assignment overload
//    <your comments here>
//---------------------- **
void garbagePile::operator=(const garbagePile &copy){
    // YOUR CODE HERE
}

// ---------------------
// destructor for garbagePile
//    <your comments here>
//---------------------- **
garbagePile::~garbagePile(){
    clearGarbagePile();
    // YOUR CODE HERE
}

// ---------------------
// addItem
//    <your comments here>
//---------------------- **
void garbagePile::addItem(string garbage){
    // YOUR CODE HERE
}

// ---------------------
// operator[]
//    <your comments here>
//---------------------- **
dataElementBase *garbagePile::operator[](unsigned int index){
    // YOUR CODE HERE
}

// ---------------------
// clearGarbagePile
//    <your comments here>
//---------------------- **
void garbagePile::clearGarbagePile(){
    // YOUR CODE HERE
}

// ---------------------
// sort
//    <your comments here>
//---------------------- **
void garbagePile::sort(){
    // YOUR CODE HERE
}

// ---------------------
// operator<<
//    <your comments here>
//---------------------- **
ostream& operator<<(ostream& out, garbagePile gp){
    // YOUR CODE HERE
    return out;
}

// ---------------------
// operator>>
//    <your comments here>
//---------------------- **
istream& operator>>(istream& in, garbagePile &gp){
    // YOUR CODE HERE
    return in;
}

//recursion?
//if(head==nullptr)
    //return;
//DEB* temp = head;
//head = head->getNext();
//delete temp;