#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include "linkedList.h" //Linked list class
using namespace std;

template <class T>
class SimpleVector
{
private:
   LinkedList<T> list;          // To point to the allocated array
   int listSize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      {listSize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return listSize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   //Adding 4 functions Push front/back, Pop front/back
   void pshFrnt(T);
   void pshBack(T);
   T popFrnt();
   T popBack();
};

//*******************************************
//Student to code these functions
//*******************************************

template <class T>
void SimpleVector<T>::pshFrnt(T val)
{
   //Student Code Here
   //Create new link with data
   Link<T>* node = new Link<T>(val);
   //add new value to the front
   list.push_front(node);
   //update vector size
   listSize++;
}


template <class T>
void SimpleVector<T>::pshBack(T val)
{
   //Student Code Here
   //create new link with data
   Link<T>* node = new Link<T>(val);
   //add new value to the end
   list.push_back(node);
   //update vector size
   listSize++;
}

template <class T>
T SimpleVector<T>::popFrnt()
{
   //Student Code Here
   //save popped node pointer
   Link<T>* poppedNode = list.pop_front();
   //save data from popped node
    T ret = poppedNode->data;
   //delete old node
   delete poppedNode;
   //update vector size
   listSize--;

   return ret;
}

template <class T>
T SimpleVector<T>::popBack()
{
   //Student Code Here
    //save popped node pointer
    Link<T>* poppedNode = list.pop_back();
    //save data from popped node
    T ret = poppedNode->data;
    //delete old node
    delete poppedNode;
   //update vector size
   listSize--;

   return ret;
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   listSize = s;
   for (int i = 0; i < s; i++)
   {
    Link<T>* node = new Link<T>(T{});//empty node
    list.push_back(node);   //add empty node to the end of the list
   }
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   listSize = obj.listSize;
    
   // Copy the elements of obj's list.
   for(int i = 0; i < listSize; i++)
   {
    T val = obj.getElementAt(i); //get value from obj
    Link<T>* node = new Link<T>(val); //create new link with data
    list.push_back(node); //add new link to the end of the list
   }
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
    //Linked lists destructor will delete all the nodes in the list 
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= listSize)  subError();
    
   Link<T>* temp = list.getHead(); //get the head of the list
   //loop from head to the subscript index
   for (int i = 0; i < sub; i++)
    {
        temp = temp->next; //move to the next link
    }
   return temp->data;
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= listSize)  subError();

   Link<T>* temp = list.getHead();
   for (int i = 0; i < sub; i++)
   {
       temp = temp->next; //move to the next link
   }

   return temp->data;
}
#endif