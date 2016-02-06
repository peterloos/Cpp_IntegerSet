#include <iostream>
using namespace std;

#include "IntegerSet.h"

void TestingCtorsDtor();
void TestingMethods();
void TestingRemove();
void TestingInsert();
void TestingOperators();
void TestingArithmeticAssignmentOperators();
void TestingSubscriptOperator();

void main()
{
	TestingCtorsDtor();
	TestingMethods();
	TestingRemove();
	TestingInsert();
	TestingOperators();
	TestingArithmeticAssignmentOperators();
	TestingSubscriptOperator();

	getchar();
}


void TestingCtorsDtor ()
{
    cout << "Testing c'tors / d'tor: " << endl;

    IntegerSet is1;
    cout << "is1: " << is1 << endl;

    int elems1[7] = { -2, -1, 0, 1, 2, -1, -2 };
    IntegerSet is2(elems1, 7);
    cout << "is2: " << is2 << endl;

    int elems2[11] = { -1, 1, 2, 3, 1, 2, 3, 1, 2, 3, -1 };
    IntegerSet is3(elems2, 11);
    cout << "is3: " << is3 << endl;

    IntegerSet is4(is3);
    cout << "is4: " << is4 << endl;

    cout << "is1.IsEmpty: " << is1.IsEmpty () << endl;
    cout << "is2.IsEmpty: " << is2.IsEmpty () << endl;
    cout << "is3.IsEmpty: " << is3.IsEmpty () << endl;
    cout << "is4.IsEmpty: " << is4.IsEmpty () << endl;
}

void TestingMethods ()
{
    cout << "Testing methods: " << endl;

    IntegerSet is;
    cout << "is: " << is << endl;

    // testing 'Insert'
    is.Insert (1);
    is.Insert (2);
    is.Insert (3);
    is.Insert (4);
    is.Insert (5);
    is.Insert (6);
    cout << "is: " << is << endl;

    // testing 'Remove'
    is.Remove (3);
    is.Remove (4);
    is.Remove (5);
    is.Remove (6);
    cout << "is: " << is << endl;

    is.Insert (10);
    is.Insert (11);
    is.Insert (12);

    is.Insert (13);
    is.Insert (14);
    is.Insert (15);
    is.Insert (16);
    is.Insert (17);
    is.Insert (18);
    is.Insert (19);
    is.Insert (20);
    is.Insert (21);
    is.Insert (22);
    is.Insert (23);
    cout << "is: " << is << endl;

    is.Insert (24);
    cout << "is: " << is << endl;

    is.Remove (11);
    cout << "is: " << is << endl;

    // testing 'Contains'
    cout << "Contains(1): " << is.Contains(1) << endl;
    cout << "Contains(5): " << is.Contains(5) << endl;
    cout << "Contains(10): " << is.Contains(10) << endl;
}

void TestingRemove ()
{
    IntegerSet is;
    for (int i = 0; i < 20; i ++)
        is.Insert (i);
    cout << "is: " << is << endl;

    is.Remove (5);
    is.Remove (1);
    is.Remove (8);
    cout << "is: " << is << endl;

    is.Remove (11);
    cout << "is: " << is << endl;

    is.Remove (16);
    cout << "is: " << is << endl;

    is.Remove (19);
    cout << "is: " << is << endl;
}

void TestingInsert ()
{
    IntegerSet is;
    for (int i = 0; i < 16; i ++)
        is.Insert (i);

    cout << "is: " << is << endl;

    is.Insert (16);
    cout << "is: " << is << endl;
}

void TestingOperators ()
{
    // testing union set
    IntegerSet is1;
    IntegerSet is2;
    for (int i = 0; i < 7; i ++)
        is1.Insert (i);
    for (int i = 2; i < 9; i ++)
        is2.Insert (i);
    cout << "is1: " << is1 << endl;
    cout << "is2: " << is2 << endl;
    cout << "is1+is2: " << (is1 + is2) << endl;

    // testing difference set
    cout << "is1-is2: " << (is1 - is2) << endl;

    // testing intersection set
    cout << "is1^is2: " << (is1 ^ is2) << endl;

    // testing ==-operator
    cout << "is1 == is2: " << (is1 == is2) << endl;
    is2.Insert (0);
    is2.Insert (1);
    is2.Remove (7);
    is2.Remove (8);
    cout << "is2: " << is2 << endl;
    cout << "is1 == is2: " << (is1 == is2) << endl;
    cout << "is1 != is2: " << (is1 != is2) << endl;

    // testing subset operator
    cout << "is1: " << is1 << endl;
    cout << "is2: " << is2 << endl;
    cout << "is1 <= is2: " << (is1 <= is2) << endl;
    is1.Insert (7);
    cout << "is1: " << is1 << endl;
    cout << "is1 <= is2: " << (is1 <= is2) << endl;

    // testing assignment operator
    is1 = is2;
    cout << "is1: " << is1 << endl;
    is1 = is1;
    cout << "is1: " << is1 << endl;
}

void TestingArithmeticAssignmentOperators ()
{
    int elems1[3] = { 1, 2, 3 };
    IntegerSet is1(elems1, 3);
    cout << "is1: " << is1 << endl;

	int elems2[3] = { 4, 5, 6 };
    IntegerSet is2(elems2, 3);
    cout << "is2: " << is2 << endl;

	int elems3[3] = { 7, 8, 9 };
    IntegerSet is3(elems3, 3);
    cout << "is3: " << is3 << endl;
    
    is1 += is2 += is3;

    cout << "is1: " << is1 << endl;
    cout << "is2: " << is2 << endl;
    cout << "is3: " << is3 << endl;
}

void TestingSubscriptOperator ()
{
    int elems[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    IntegerSet is(elems, 9);

    for (int i = 0; i < is.Size(); i ++)
        cout << "Element at " << i << ": " << is[i] << endl;
}

