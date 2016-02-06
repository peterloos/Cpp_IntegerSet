class IntegerSet
{
public:
    // c'tors and d'tor
    IntegerSet ();
    IntegerSet (int elems[], int count);
    IntegerSet (const IntegerSet&);
    ~IntegerSet (); 

public:
    // getter
    int Size () const;
    bool IsEmpty () const;

    // public methods
    bool Insert (int);
    bool Remove (int);
    bool Contains (int) const;

    // miscellaneous operators
    IntegerSet& operator= (const IntegerSet&);
    friend bool operator== (const IntegerSet&, const IntegerSet&);
    friend bool operator!= (const IntegerSet&, const IntegerSet&);
    int operator[] (int) const; // read-only subscript operator

    // arithmetic-assignment operators
    friend const IntegerSet& operator+= (IntegerSet&, const IntegerSet&);
    friend const IntegerSet& operator-= (IntegerSet&, const IntegerSet&);

    // set theory specific operators
    friend IntegerSet operator+ (const IntegerSet&, const IntegerSet&);
    friend IntegerSet operator- (const IntegerSet&, const IntegerSet&);
    friend IntegerSet operator^ (const IntegerSet&, const IntegerSet&);
    friend bool operator<= (const IntegerSet&, const IntegerSet&);

    // output operator
    friend ostream& operator<< (ostream&, const IntegerSet&);

private:
    // private member data
    int  m_num;  // current number of elements
    int* m_set;  // array of elements
};
