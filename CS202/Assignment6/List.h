/*
Name: (YOUR NAME)
Description: <Description here>
Input: File name of the map to read and use
Output: Steps of the map to reach the treasure
*/
#ifndef LIST_H
#define LIST_H true

#include <iostream>
using namespace std;

/* List class used to store some generic type. Stores all items in the order
That they are added an allows for them to be accessed like an array. Functionally
similar to a C++ vector. */
template <class T>
class List
{
	T* contents; //Pointer to the array
	int size; //Size of the array 
	int count; //How many items are in the array
	const int RESIZE_AMOUNT = 4; //How much to resize the array by when expanding

public:
	int getCount() const { return count; }
	void addElement(T new_element);

	//Constructors
	List() { size = count = 0; contents = nullptr; }
	List(int start_size) { size = start_size; count = 0; contents = new T[start_size]; }
	List(const List& other);
	~List();

	//Operator overloads
	T& operator [] (int index) const { return contents[index]; } //Indexing overload lets this be used with array syntax
	void operator = (List<T> other);
};

//TODO: Finish List functionsd	2`s/az//////////////////////////////////////////////////

/**/
template <class T>
void List<T>::addElement(T new_element)
{	
	if(contents != NULL && contents[size-1] != NULL){
		contents[size-1] = new_element;
	}
	else if(contents == NULL){
		contents = new T(size);
		contents[0] = new_element;
	}
	else{
		T arr2[size+RESIZE_AMOUNT] = new T;
		for(int i = 0; i < size; i++){
			arr2[i] = contents[i];
		}
		arr2[size] = new_element;
		contents = arr2;
	}
	//Add an element to the dynamic array
	//If the array is out of space or does not exist (is null)
	//Make a new array, copy over any old elements, and update the pointer
	//Be sure to avoid memory leaks

	//Then add the new_element to the end
}

/**/
template <class T>
List<T>::~List()
{
	if(contents != NULL){
		for(int i = 0; i < size; i++){
			delete contents[i];
		}
		delete[] contents;
		contents = NULL;
	}
	//Deallocate the contents of the array if they exist
	//and then mark the contents as null
}

/**/
template <class T>
List<T>::List(const List& other)
{
	
	//Copy the contents of the other list to this one
	//Also set the count and size members
	//Don't forget to allocate a new array

	//Remember that we want a deep copy, so copying pointers
	//directly will not work and is why we must explicitly write 
	//an = overload and a copy contructor
}

template <class T>
void List<T>::operator = (List<T> other)
{

	//Make a deep copy of the other list and set it to this one
	//Essentially the same code as the copy constructor
	//Consider deleting any old array to avoid memory leaks
}

#endif

while (current != nullptr){ //while doesnt reach end of link list
	current = current->next //go to next node
}
current-> next = newNode; //current will be the end at this point
