//
//  main.cpp
//  Vector2
//
//  Created by Magdalena Ivanova on 5/17/15.
//  Copyright (c) 2015 Magdalena Ivanova. All rights reserved.
//

#include <iostream>
#include <string>
#include "Vector.cpp"

using namespace std;

class Student
{
public:
    Student() : m_name("Ivan"), m_age(19) {}
    Student(string name, int age) : m_name(name), m_age(age) {}
private:
    string m_name;
    int m_age; };

int main(int argc, const char * argv[]) {
    
    Student st1 ("Iva", 20);
    Student st2("Todor", 20);
    
    Vector<Student> students;
    students.Push_Back(st1);
    students.Push_Back(st2);
    
    Vector<int> v1;
    v1.Push_Back(1);
    v1.Push_Back(34);
    v1.Push_Back(67);
    v1.Push_Back(98);
    v1.Push_Back(11);
    v1.Push_Back(341);
    v1.Push_Back(983);
    
    cout << v1.Back() << endl;
    v1.Pop_Back();
    cout << v1.Back() << " " << v1.Front() << endl;
    
    cout << v1[4] << endl;
    
    v1.Push_Back(777);
    
    for (int i = 0; i < v1.Size(); i++){
        cout << v1[i] << " " ;
    }
    
    cout << endl;
    
    Vector<string> v2;
    v2.Push_Back("A man");
    v2.Push_Back("walked");
    v2.Push_Back("into the room.");
    
    for (int i = 0; i < v2.Size(); i++){
        cout << v2[i] << " ";
    }
    
    cout << endl;
    
    Vector<string> v3;
    v3.Push_Back("It was");
    v3.Push_Back("full");
    v3.Push_Back("people.");
    v3.insert(2, "of");

    for (int i = 0; i < v3.Size(); i++) {
        cout << v3[i] << " ";}
    
    cout << endl;

    v3.erase(1);
    
    for (int i = 0; i < v3.Size(); i++)
    {
        cout << v3[i] << " " ;
    }
    
    cout << endl;
    
    v3.Swap(v2);
    
    for (int i = 0; i < v3.Size(); i++)
    {
        cout << v3[i] << " " ;
    }
    
    cout << endl;
    
    cout << v3.Capacity();
    
    v3.Resize();
    
    cout << endl;
    
    cout << v3.Capacity() << " " << v3.Size() << endl;
    
    v3.Shrink_To_Fit();
    
    cout << v3.Capacity() << " " << v3.Size() << endl;
    
    Vector<int> v4;
    
    v4.Push_Back(3);
    v4.Push_Back(5);
    
    Vector<int> v5;
    
    v5=v4;
    
    for (int i = 0; i < v5.Size(); i++)
    {
        cout << v5[i] << " " ;
    }
    
    cout << endl;
    
    cout << "Vector is empty!?" << " " << boolalpha << v5.Empty();

    return 0;
}
