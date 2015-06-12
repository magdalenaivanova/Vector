//
//  Vector.h
//  Vector2
//
//  Created by Magdalena Ivanova on 5/17/15.
//  Copyright (c) 2015 Magdalena Ivanova. All rights reserved.
//

#ifndef __Vector2__Vector__
#define __Vector2__Vector__

#include <iostream>



template <typename T>
class Vector
{
public:
    Vector();                               // Default constructor
    Vector(const Vector&);                  // Copy constructor
    
    Vector(T arr[], int n);                 // Fill constructor
    
    Vector& operator=(const Vector& vec);   // Assignment operator

    Vector(int n, const T& t);              // Construct with "n" copies of t.
    
    ~Vector();                              // Destructor
    
    void Push_Back(const T);                // Add to end of vector
    void Push_Front(const T);               // Add to front of vector
    
    void Pop_Back();                        // Remove last element
    void Pop_Front();                       // Remove first element
    
    void Swap(const Vector& vec);           // Swap vectors
    
    T&   Front() const;                     // Return reference to first element
    T&   Back() const;                      // Return reference to last element
    
    T&   operator[](size_t) const;          // Return reference to specified element
    
    int Size() const;                       // Return number of elements
    int Capacity() const;                   // Return capacity
    
    bool Empty() const;                     // True if empty

    void insert(int index, T value);        // insert value element on index
    void erase(int index);                  // delete element on index

    void Clear();                           // Remove all elements
    
    void Resize();                          // Resize vector
    void Shrink_To_Fit();                   // Make capacity equal to size

private:
    T* content;                             // Points to the actual elements
    int amount;                             // Number of elements in the vector
    int capacity;                           // Reserved memory count
};



#endif /* defined(__Vector2__Vector__) */
