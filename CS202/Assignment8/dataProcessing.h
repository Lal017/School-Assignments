#include <string>
#include <iostream>
using namespace std;

#define INT     0
#define CHAR    1
#define DOUBLE  2
#define BOOL    3
#define STRING  4

#define LESSTHAN    -1
#define GREATERTHAN 1
#define EQUAL       0

// *******************************
// * Global Helper Functions
// *******************************
bool isInteger(string s);
bool isChar(string s);
bool isDouble(string s);
bool isBool(string s);

bool stob(string s);

unsigned int getDataType(string garbage);

// *******************************
// * dataElementBase
// *******************************

class dataElementBase{
private:
    unsigned short dataType; 
    dataElementBase *next = nullptr, *prev = nullptr; 
public:
    dataElementBase(unsigned short dt);
    dataElementBase(const dataElementBase& copy);
    void operator=(const dataElementBase& copy);

    virtual ~dataElementBase();
    virtual void *getData() = 0;  
    virtual void printElement(ostream& out) const = 0;

    unsigned short getDataType() const;
    dataElementBase *getNext() const;
    dataElementBase *getPrev() const;

    void link(dataElementBase *deb);
    short compare(dataElementBase *deb);

    static dataElementBase* getNewDataElement(unsigned short dt, string data);
    static dataElementBase* deepCopyDataElement(dataElementBase *deb);

    static void swap(dataElementBase *A, dataElementBase *B);
};

// *******************************
// * dataElement
// ********************************
template<typename t>
class dataElement : public dataElementBase{
private:
    t data;
public:
    dataElement(unsigned short dt, t data);
    void *getData();
    void printElement(ostream& out) const;
};

// *******************************
// * garbagePile
// ********************************
class garbagePile{
private:
    dataElementBase *head = nullptr, *tail = nullptr;
    unsigned int size = 0; 
public:
    garbagePile();
    garbagePile(const garbagePile &copy);
    void operator=(const garbagePile &copy);
    ~garbagePile();

    void addItem(string garbage);
    void clearGarbagePile();

    dataElementBase *operator[](unsigned int index);
    void sort(); 

    friend ostream& operator<<(ostream& out, garbagePile gp);
    friend istream& operator>>(istream& in, garbagePile &gp);
};

ostream& operator<<(ostream& out, garbagePile gp);
istream& operator>>(istream& in, garbagePile &gp);
