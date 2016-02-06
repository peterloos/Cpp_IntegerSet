#include <iostream>
using namespace std;    
#include "IntegerSet.h"

// c'tors and d'tor
IntegerSet::IntegerSet ()
{
    // empty buffer
    m_num = 0;
    m_set = (int*) 0;
}

IntegerSet::IntegerSet (int elems[], int count)
{
    // empty buffer
    m_num = 0;
    m_set = (int*) 0;

    for (int i = 0; i < count; i ++)
        Insert (elems[i]);
}

IntegerSet::IntegerSet (const IntegerSet& is)
{
    // allocate buffer
    m_num = is.m_num;
    m_set = new int[m_num];

    // copy object
    for (int i = 0; i < m_num; i ++)
        m_set[i] = is.m_set[i];
}

IntegerSet::~IntegerSet ()
{
    delete[] m_set;
}

// getter
int IntegerSet::Size () const
{
    return m_num;
}

bool IntegerSet::IsEmpty () const
{
    return m_num == 0;
}

// public methods
bool IntegerSet::Contains (int n) const
{
    // search element
    for (int i = 0; i < m_num; i ++)
        if (m_set[i] == n)
            return true;

    return false;
}

bool IntegerSet::Insert (int n)
{
    // element already exists
    if (Contains (n))
        return false;

    // allocate new buffer
    int* tmp = new int[m_num + 1];

    // copy old buffer into new one
    for (int i = 0; i < m_num; i ++)
        tmp[i] = m_set[i];

    // insert new element at end of buffer
    tmp[m_num] = n;

    // switch to new buffer
    delete[] m_set;
    m_set = tmp;
    m_num ++;

    return true;
}

bool IntegerSet::Remove (int n)
{
    // element already exists
    if (! Contains (n))
        return false;

    // allocate new buffer
    int* tmp = new int[m_num - 1];

    // copy old buffer into new one
    for (int i = 0, k = 0; i < m_num; i ++)
    {
        if (m_set[i] == n)
            continue;

        tmp[k] = m_set[i];
        k ++;
    }

    // switch to new buffer
    delete[] m_set;
    m_set = tmp;
    m_num --;

    return true;
}

// operators
IntegerSet& IntegerSet::operator= (const IntegerSet& is)
{
    // prevent self-assignment
    if (this == &is)
        return *this;

    // delete old buffer
    delete[] m_set;

    // allocate a new buffer
    m_num = is.m_num;
    m_set = new int[m_num];

    // copy buffer
    for (int i = 0; i < m_num; i ++)
        m_set[i] = is.m_set[i];

    return *this;
}

bool operator== (const IntegerSet& is1, const IntegerSet& is2)
{
    // compare sizes
    if (is1.m_num != is2.m_num)
        return false;

    // compare both sets element per element
    for (int i = 0; i < is1.m_num; i ++)
    {
        if (is2.Contains (is1.m_set[i]))
            continue;

        return false;
    }

    return true;
}

bool operator!= (const IntegerSet& is1, const IntegerSet& is2)
{
    return ! (is1 == is2);
}

int IntegerSet::operator[] (int n) const
{
    // check parameter
    if (n < 0)
        return -1;
    if (n >= m_num)
        return -1;

    // return element
    return m_set[n];
}

// arithmetic-assignment operators
const IntegerSet& operator+= (IntegerSet& is1, const IntegerSet& is2)
{
    for (int i = 0; i < is2.m_num; i ++)
        is1.Insert (is2.m_set[i]);

    return is1;
}

const IntegerSet& operator-= (IntegerSet& is1, const IntegerSet& is2)
{
    for (int i = 0; i < is2.m_num; i ++)
        is1.Remove (is2.m_set[i]);

    return is1;
}
    
// set theory specific operators
IntegerSet operator+ (const IntegerSet& is1, const IntegerSet& is2)
{
    IntegerSet is(is1);
    for (int i = 0; i < is2.m_num; i ++)
        is.Insert (is2.m_set[i]);

    return is;
}

IntegerSet operator- (const IntegerSet& is1, const IntegerSet& is2)
{
    IntegerSet is(is1);
    for (int i = 0; i < is2.m_num; i ++)
        is.Remove (is2.m_set[i]);

    return is;
}

IntegerSet operator^ (const IntegerSet& is1, const IntegerSet& is2)
{
    IntegerSet is;

    for (int i = 0; i < is1.m_num; i ++)
    {
        int n = is1.m_set[i];
        if (is2.Contains (n))
            is.Insert (n);
    }

    return is;
}

bool operator<= (const IntegerSet& is1, const IntegerSet& is2)
{
    // compare both sets element per element
    for (int i = 0; i < is1.m_num; i ++)
    {
        int n = is1.m_set[i];
        if (! is2.Contains (n))
            return false;
    }

    return true;
}

// output operator
ostream& operator<< (ostream& os, const IntegerSet& is)
{
    os << "{";
    for (int i = 0; i < is.m_num; i ++)
    {
        os << is.m_set[i];
        if (i < is.m_num - 1)
            os << ',';
    }
    os << "} [" << is.m_num << "]";

    return os;
}
