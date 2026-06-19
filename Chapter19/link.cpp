/*
The purpose of our List is to convey an understanding of 
what linked lists are, how a list might be implemented, 
and how to use the key features. For more information 
see an expert-level C++ book.
*/

template<typename T>
struct Link {
    Link* prev;
    Link* succ;
    T val;
};

template<typename T> class List {
    Link<T>* first;
    Link<T>* last;      //one beyond the last link

    public:
        class iterator; //member type
        
        iterator begin();
        iterator end(); //one beyond the last link

        iterator insert(iterator p, const T& v);    //insert after p
        iterator erase(iterator p);                 //erase p

        void push_back(const T& v);                 //insert v at end
        void push_front(const T& v);                //insert v at front
        void pop_front();                           //remove the first element
        void pop_back();                            //remove the last element


        T& front();     //the first element
        T& back();      //the last element
};