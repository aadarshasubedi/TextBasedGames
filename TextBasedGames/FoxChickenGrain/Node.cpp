#include "Node.h"
#include <iostream>

using namespace std;

Node::Node (const string& data):
    m_data(data),
    m_pNext(NULL)
{ }


Node::~Node(void)
{
}
