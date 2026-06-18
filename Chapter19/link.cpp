template<typename T>
struct Link {
    Link* prev;
    Link* succ;
    T val;
};

template<typename T> struct List {
    Link<T>* first;
    Link<T>* last;      //one beyond the last link
};