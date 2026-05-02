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