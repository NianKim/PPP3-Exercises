#include <iostream>
#include <string>
using namespace std;

struct Link {
    //p is the predecessor, s is the successor
    Link(const string& v, Link* p = nullptr, Link* s = nullptr) : value{v}, prev{p}, succ{s} { }
    string value;
    
    Link* insert(Link* n);
    Link* add(Link* n);
    Link* erase();
    Link* find(const string& s);
    Link* advance(int n);

    Link* next() const{ return succ; }
    Link* previous() const {return prev; }

    void print_all() const;
    void free_all();

    private:
        Link* prev;
        Link* succ;
};

Link* Link::insert(Link* n)  // insert n before p; return n
{
    if (n==nullptr)
        return this;
    if (this==nullptr)
        return n;
    n->succ = this;                                  // p comes after n
    if (this->prev)
        prev->succ = n;
    n->prev = prev;                       // p’s predecessor becomes n’s predecessor
    prev = n;                            // n becomes p’s predecessor
    return n;
}

Link* Link::add( Link* n)  // insert n after p; return n
{

    if (n==nullptr)
        return this;
    if (this==nullptr)
        return n;
    n->prev = this;                                  // p comes before n
    if (this->succ)
        succ->prev = n;                  //if p already has a successor, that succesor's new pres is in n
    n->succ = succ;                       // p’s predecessor becomes n’s predecessor
    succ = n;                            // n becomes p’s successor
    return n;
}

Link* Link::erase() //remove *p from list; return p's successor
{
    if(this->succ)
        this->succ->prev = this->prev;
    if(this->prev)
        this->prev->succ = this->succ;
    return this->succ;
}

Link* Link::find(const string& s)   //find s in list; return nullptr for "not found"
{
    Link* current_object = this;
    while(current_object != nullptr) {
        if (current_object->value == s)
            return current_object;
        current_object = current_object->succ; //move one object further
    }
    return nullptr;
}

Link* Link::advance( int n ){ //move n positions in list; return nullptr for "not found"
    Link* current_object = this;
    while(0<n){
        if (current_object->succ == nullptr) return nullptr;
        current_object = current_object -> succ;
        --n;
    }
    while(n<0){
        if(current_object->prev == nullptr) return nullptr;
        current_object = current_object -> prev;
        ++n;
    }
    return current_object;
}
//nullptr usage here is more error prone than std library list

void Link::print_all() const
{
    const Link* current_object = this;
        cout << "{ ";
        while (current_object) {
                cout << current_object->value;
                current_object = current_object->succ;
                if (current_object)   //using assignment as a condition
                         cout << ", ";
         }
         cout << " }";
}

void Link::free_all () {
    Link* current_object = this;
    while( current_object ) {
        Link* next_node = current_object -> succ;
        delete current_object;
        current_object = next_node;
    }
}

int main() {

    Link* norse_gods = new Link{"Thor"};;
    norse_gods = norse_gods -> insert(new Link{"Odin"});
    norse_gods = norse_gods -> insert(new Link{"Freja"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = greek_gods -> insert(new Link{"Athena"});
    greek_gods = greek_gods -> insert(new Link{"Mars"});
    greek_gods = greek_gods -> insert(new Link{"Poseidon"});
    //dot operator won't work because greek_gods is a pointer

    Link* p = greek_gods->find("Mars");
    if (p){
        p->value = "Ares";
    }
    
    Link* g = norse_gods -> find("Zeus");
    if (g) {
        //making sure that the erased() Link isn't pointed to by norse_gods
        if(g==norse_gods)
            norse_gods = g->next();
        g = g -> erase();
        //when inserting Zeus BEFORE the first greek god, make greek_gods point to Zeus Link
        greek_gods = greek_gods -> insert(g);
    }
    norse_gods -> print_all();
    cout << '\n';

    greek_gods -> print_all();
    cout << '\n';
    
    //clear up free memory
    norse_gods -> free_all();
    norse_gods = nullptr; //remove dangling pointer
    greek_gods -> free_all();
    greek_gods = nullptr;

    return 0;
}