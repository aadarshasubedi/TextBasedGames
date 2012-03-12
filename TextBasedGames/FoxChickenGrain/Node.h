#pragma once

#include <string>

using namespace std;

class Node
{
    friend class List;

public:
    Node (const string& data);
    Node(void);
    ~Node(void);

private:
    string m_data;
    Node* m_pNext;
};