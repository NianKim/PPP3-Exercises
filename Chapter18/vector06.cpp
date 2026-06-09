//example representation with allocator
//deals with raw memory instead of (typed) objects

#include <memory>
template <typename T, typename A = std::allocator<T>>
struct Vector_rep {
    A alloc;        // allocator
    int sz;         // number of elements
    T* elem;        // start of allocation
    int space;      // amount of allocated space

    Vector_rep(const A& a, int n) 
        : alloc { a }, sz{ n }, elem{ alloc.allocate(n) }, space{n} { } 
    ~Vector_rep() { alloc.deallocate(elem, space); }    // destructor
};

template<typename T, typename A = std::allocator<T>>
class Vector {
    Vector_rep<T,A> r;
public:
    Vector() : r{A{}, 0} {}
    explicit Vector(int s) :r{A{},s}
    {
        for(int i = 0; i<r.sz; ++i)     // initialization
            r.elem[i] = 0;
    }

    void reserve(int newalloc);
    // ...
}; 

// rewriting "reserve()"
template<typename T, typename A>
void Vector<T, A>::reserve(int newalloc)
{
    if(newalloc <= r.space)
        return;
    Vector_rep<T, A> b{ r.alloc, newalloc };
    std::uninitialized_move(r.elem,r.elem+r.sz,b.elem);
    std::destroy(r.elem,r.elem + r.sz);

    using std::swap;
    swap(r, b);
}