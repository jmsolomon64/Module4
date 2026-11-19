# Dynamic Memory Allocation
## Pointers
* Pointer point to addresses in memory to avoid allocating new memory
* new keyword can be used to allocate new memory for object
    * returns a pointer to the newly allocated memory
    * if new keyword is used with class instead of array, it will call objects constructor
* When working with pointers in functions, it is good practice to check if they are null
    * if (pointer != nullptr)
    * before C++ 11, it was common to use 0 instead of nullptr, since nullptr wasn't available till then
* Changing the size of dynamic arrays needs to be done in a specific order
    * for adding capacity:
        * Create new array of whatever size needed
        * Copy over elements from old array
        * delete old array
        * set old array equal to new array
    * for merging two arrays:
        * Create new array that is length of two arrays
        * Copy first array over
        * Delete first array
        * copy second array over
        * delete second array
        * set new array equal to first
    * removing an element:
        * determine index to delete
        * start loop from index to shift all existing elements down one index
* To access members of an object stored behind a pointer, the member access operator must be used '->'
* To retrieve data stored from a pointer, the dereference operator must be used '*' in front of the variable name
* example->method() is equivalent to (*example).method()
    * when using dereference operator like this, it needs to be in parenthesis since '.' operator has precedence over dereference
* If an array of objects is allocated in memory, it will run the default constructor for every element added
    * If there is no default constructor, an error will occur
* Dynamically changing the size of an object array requires some extra steps
    * Usually wrapped in a class with three basic properties:
        * Pointer to hold dynamic array address
        * int that states capacity of array
        * int to hold # of elements currently stored
* Copy constructors are automatically called when passing objects by value
    * compiler by default makes shallow copies, which can mess stuff up when leaving the function since memory will be wiped 
    * Deep copies can be created if copy constructor is defined by developer
    * same can be done when you set an object var equal to an instance of another object var
* Rule of 3 dictates if developer defines destructor, copy constructor, or copy operator, then the other two should be defined as well

```
double* recordedTimes; //creates pointer in memory
recordedTimes = new double[3]; //sets pointer to point at newly allocated double array (initially points to first item in array)
delete[] recordedTimes; //deallocates memory which will free up memory

int* nullExample = nullptr; //nullptr is the keyword for declaring a pointer as null

Example example = new Example; //Calling new on class sets up constructor
delete example; 

// Copy constructor
MyClass::MyClass(const MyClass& origObject) {
   cout << "Copy constructor called." << endl;
   dataObject = new int; // Allocate sub-object
   *dataObject = *(origObject.dataObject);
}


MyClass& MyClass::operator=(const MyClass& objToCopy) {
   cout << "Assignment op called." << endl;
   
   if (this != &objToCopy) {           // 1. Don't self-assign
      delete dataObject;                  // 2. Delete old dataObject
      dataObject = new int;               // 3. Allocate new dataObject
      *dataObject = *(objToCopy.dataObject); // 4. Copy dataObject
   }
   
   return *this;
}
```

## Memory Regions
* Code: Where the instructions are stored
* Static Memory: Where global vars and local static vars are stored
* Stack: Where functions local variables are stored
    * Data is automatically added and removed as functions are invoked and resolved
    * also known as the automatic memory
* Heap: Region where manually allocated memory is stored
    * also known as free store