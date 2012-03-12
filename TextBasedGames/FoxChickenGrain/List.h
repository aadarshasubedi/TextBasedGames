#pragma once

#include <string>

using namespace std;

class Node;

class List
{
public:
    List ();
    ~List ();

    bool Contains (const string& data) const;   // tests for element existence
    int Count () const;                         // returns number of elements
    void Display () const;                      // displays elements
    void Add (const string& data);              // adds an element
    bool Remove (const string& data);           // removes an element
    void Clear ();                              // removes all elements

private:
    Node* m_pHead;                              // head (front) of list
    Node* m_pTail;                              // tail (end) of list
};

