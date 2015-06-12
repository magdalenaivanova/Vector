//
//  Vector.cpp
//  Vector2
//
//  Created by Magdalena Ivanova on 5/17/15.
//  Copyright (c) 2015 Magdalena Ivanova. All rights reserved.
//


#include <iostream>
#include "Vector.h"

using namespace std;

template <typename T>
Vector<T>::Vector()
{
    this->amount = 0;
    this->capacity = 1;
    this->content = new T[capacity];
}

template <typename T>
Vector<T>::Vector(const Vector& vec)
{
    this->amount = vec.amount;
    this->capacity = vec.capacity;

    for(int i = 0; i < this->number ; i++)
    {
        this->content[i]= vec[i];
    }
}

template <typename T>
Vector<T>::Vector(T arr[], int n)
{
    for (int i = 0; i < n ; i++) {
        this->content.Push_Back(arr[i]);
    }
}


template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& vec)
{
    if (vec.amount < this->amount) {
        Resize();
    }
    else{
        this->amount = vec.amount;
        this->capacity = vec.capacity;
    }
    
    for(int i = 0; i < this->amount ; i++)
    {
        this->content[i]= vec[i];
    }
    
    return *this;
}


template <typename T>
Vector<T>::Vector(int n, const T& t)
{
    if (this->amount == this->capacity)
    {
        Resize();
    }

    for(int i = 0; i < n; i++)
    {
        this->content[i]= this->content[t];
    }
    
    this->amount = n;
}


template <typename T>
Vector<T>::~Vector()
{
    delete[] this->content;
    
    this->amount = 0;
}


template <typename T>
void Vector<T>::Push_Back(const T vec)
{
    if (this->amount == this->capacity)
    {
        Resize();
    }
    
    this->content[this->amount] = vec;
    this->amount++;
}

template <typename T>
void Vector<T>::Push_Front(const T vec)
{
    if (this->amount == this->capacity)
    {
        Resize();
    }
    
    T* temp = new T[this->capacity];
    for (int i = 0; i < this->amount ; i++) {
        temp[i] = this->content[i];
    }
    
    this->content[0] = vec;
    this->amount++;
    
    for (int i = 1 ; i < this->capacity; i++) {
        this->content[i] = temp[i-1];
    }
    
    delete [] temp;
    
}

template <typename T>
void Vector<T>::Pop_Back()
{
    if (this->amount == 0) {
        throw std::out_of_range("Empty vector");
    }
    
    this->content[this->amount - 1].~T();
    this->amount --;
}

template <typename T>
void Vector<T>::Pop_Front()
{
    if (this->amount == 0) {
        throw std::out_of_range("Empty vector");
    }
    
    this->content[0].~T();
    
    for (int i = 0; i < this->amount; i++) {
        this->content[i]=this->content[i+1];
    }
}

template <typename T>
void Vector<T>::Swap(const Vector& vec)
{
    T* temp = new T[this->capacity];
    for (int i = 0; i < this->amount ; i++) {
        temp[i] = this->content[i];
    }
    
    for (int i = 0 ; i < this->capacity; i++) {
        this->content[i] = vec[i];
    }
    
    for (int i = 0 ; i < this->capacity; i++) {
        vec[i] = temp[i];
    }
    
    delete [] temp;
}

template <typename T>
T& Vector<T>::Front() const
{
    if (this->amount == 0) {
        throw std::out_of_range("Empty vector");
    }
    
    return this->content[0];
}

template <typename T>
T& Vector<T>::Back() const
{
    if (this->amount == 0) {
        throw std::out_of_range("Empty vector");
    }
    
    return this->content[this->amount - 1];
}

template <typename T>
T& Vector<T>::operator[](size_t i) const
{
    return this->content[i];
}

template <typename T>
int Vector<T>::Size() const
{
    return this->amount;
}

template <typename T>
int Vector<T>::Capacity() const
{
    return this->capacity;
}

template <typename T>
bool Vector<T>::Empty() const
{
    if(this->amount == 0)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}

template <typename T>
void Vector<T>::insert(int index, T value)
{

    if (this->amount == this->capacity)
    {
        Resize();
    }

    T* temp = new T[this->capacity];
    for (int i = 0; i < this->amount ; i++) {
        temp[i] = this->content[i+index];
    }
    
    this->content[index] = value;
    this->amount++;
    
    for (int i = index+1 ; i < this->capacity; i++) {
        this->content[i] = temp[i-index-1];
    }
    
    delete [] temp;
}

template <typename T>
void Vector<T>::erase(int index)
{
    if (this->amount == 0) {
        throw std::out_of_range("Empty vector");
    }
    
    this->content[index].~T();
    
    for (int i = index; i < this->amount; i++) {
        this->content[i]=this->content[i+1];
    }
}

template <typename T>
void Vector<T>::Clear()
{ 
    for(int i = 0; i < this->amount; i++)
    {
        this->content[i].~T();
    }
    
    this->amount = 0;
}

template<typename T>
void Vector<T>::Resize()
{
    int newCapacity = this->capacity * 2;
    T * temp = new T[newCapacity];
    
    for (int i = 0; i < this->amount; i++)
    {
        temp[i] = this->content[i];
    }
    
    delete [] this->content;
    
    this->capacity = newCapacity;
    this->content = temp;
}

template<typename T>
void Vector<T>::Shrink_To_Fit()
{
    this->capacity = this->amount;
}



