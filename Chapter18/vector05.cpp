template<typename T>           // for all types T (just like in math)
class Vector {
        int sz;              // the size
        T* elem;          // a pointer to the elements
        int space;        // size + free space
public:
        Vector() :sz{0}, elem{nullptr}, space{0} { }

        explicit Vector(int s) :sz{s}, elem{new T[s]}, space{s}
        {
                for (int i=0; i<sz; ++i)
                elem[i]=0;                        // elements are initialized
        }
        Vector(initializer_list<T>);                                      // list constructor
        Vector& operator=(initializer_list<T>);                    // list assignment

        Vector(const Vector&);                                            // copy constructor
        Vector& operator=(const Vector&);                         // copy assignment

        Vector(vector&&);                                                   // move constructor
        Vector& operator=(Vector&&);                                // move assignment

        ~Vector() { delete[] elem; }                                      // destructor

        T& operator[](int n) { return elem[n]; }                    // access: return reference
        const T& operator[](int n) const { return elem[n]; }

        int size() const { return sz; }                                    // the current size
        int capacity() const { return space; }                       // the current capacity

        void resize(int newsize);                                        // growth
        void push_back(const T& d);
        void reserve(int newalloc);

        T* begin() const { return elem; }                             // iteration support
        T* end() const { return elem+sz; }
};

template<typename T>
bool operator==(const Vector<T>&, const Vector<T>&);

template<typename T>
bool operator!=(const Vector<T>&, const Vector<T>&);

//this is new
template<typename T>
class allocator {
public:
        // ...
        T* allocate(int n);                           // allocate space for n objects of type T
        void deallocate(T* p, int n);           // deallocate n objects of type T starting at p
};
// Assuming Element and Allocator concepts are defined elsewhere or replaced with typename

template<typename T, typename A = allocator<T>>
class Vector {
    A alloc;
    int sz;
    T* elem;
    int space;
public:
    // ... rest of your class members (ensuring Vector(Vector&&) is capitalized) ...
    void reserve(int newalloc);
    void push_back(const T& val);
    void resize(int newsize, T val = T()); // Default argument goes HERE
};

Vector<double> vd;
Vector<int> vi;
Vector<double*> vpd;
Vector<Vector<int>> vvi;

/*
from the book
// Assuming Element and Allocator concepts are defined elsewhere or replaced with typename

template<typename T, typename A = allocator<T>>
class Vector {
    A alloc;
    int sz;
    T* elem;
    int space;
public:
    // ... rest of your class members (ensuring Vector(Vector&&) is capitalized) ...
    void reserve(int newalloc);
    void push_back(const T& val);
    void resize(int newsize, T val = T()); // Default argument goes HERE
};

template<typename T, typename A>
void Vector<T,A>::reserve(int newalloc)
{
    if (newalloc <= space) return;
    
    T* p = alloc.allocate(newalloc); // Allocate raw memory
    
    // Move old initialized elements to new space safely
    std::uninitialized_move(elem, elem + sz, p); 
    
    // Destroy ONLY the initialized old elements
    std::destroy(elem, elem + sz); 
    
    // Deallocate the old raw memory block
    alloc.deallocate(elem, space); 
    
    elem = p;
    space = newalloc;
}

template<typename T, typename A>
void Vector<T,A>::push_back(const T& val)
{
    // ONLY grow if we've hit our capacity limit!
    if (sz == space) {
        reserve((space == 0) ? 8 : 2 * space);
    }
    std::construct_at(&elem[sz], val); // Construct object in raw memory
    ++sz;
}

template<typename T, typename A>
void Vector<T,A>::resize(int newsize, T val) // No default argument here
{
    reserve(newsize);
    if (sz < newsize) {
        // Construct new elements up to newsize
        std::uninitialized_fill(elem + sz, elem + newsize, val);
    }
    if (newsize < sz) {
        // Destroy surplus elements if shrinking
        std::destroy(elem + newsize, elem + sz);
    }
    sz = newsize;
}
*/