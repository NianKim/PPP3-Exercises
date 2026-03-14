#include <iostream>
#include <string>
using namespace std;

struct Link {
    //p is the predecessor, s is the successor
    Link(const string& v, Link* p = nullptr, Link* s = nullptr) : value{v}, prev{p}, succ{s} { }
    string value;
    Link* prev;
    Link* succ;
};

Link* insert(Link* p, Link* n)  // insert n before p; return n
{
    if (n==nullptr)
        return p;
    if (p==nullptr)
        return n;
    n->succ = p;                                  // p comes after n
    if (p->prev)
        p->prev->succ = n;
    n->prev = p->prev;                       // p’s predecessor becomes n’s predecessor
    p->prev = n;                            // n becomes p’s predecessor
    return n;
}

Link* add(Link* p, Link* n)  // insert n after p; return n
{
    if (n==nullptr)
        return p;
    if (p==nullptr)
        return n;
    n->prev = p;                                  // p comes before n
    if (p->prev)
        p->prev->succ = n;
    n->succ = p->succ;                       // p’s predecessor becomes n’s predecessor
    p->succ = n;                            // n becomes p’s successor
    return n;
}

Link* erase(Link* p) //remove *p from list; return p's successor
{
    if (p == nullptr)
        return nullptr;
    if(p->succ)
        p->succ->prev = p->prev;
    if(p->prev)
        p->prev->succ = p->succ;
    return p->succ;
}

Link* find(Link* p, const string& s)   //find s in list; return nullptr for "not found"
{
    while(p) {
        if (p->value == s)
            return p;
        p = p->succ;
    }
    return nullptr;
}

Link* advance(Link* p, int n){ //move n positions in list; return nullptr for "not found"
    if(p == nullptr)
        return nullptr;
    while(0<n){
        --n;
        if (p->succ)
            p = p->succ;
        return nullptr;
    }
    while(n<0){
        ++n;
        if(p->prev)
            p = p->prev;
        return nullptr;
    }
    return p;
}
//nullptr usage here is more error prone than std library list

void print_all(Link* p)
{
        cout << "{ ";
        while (p) {
                 cout << p->value;
                 if ((p=p->succ))   //using assignment as a condition
                         cout << ", ";
         }
         cout << " }";
}

int main() {
    /*
    Link* norse_gods = new Link{"Thor",nullptr,nullptr};
    norse_gods = new Link{"Odin",nullptr,norse_gods};
    norse_gods->succ->prev = norse_gods;
    norse_gods = new Link {"freja",nullptr,norse_gods};
    norse_gods->succ->prev = norse_gods;
    */

    Link* norse_gods = new Link{"Thor"};
    norse_gods = insert(norse_gods,new Link{"Odin"});
    norse_gods = insert(norse_gods,new Link{"Freja"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = insert(greek_gods,new Link{"Athena"});
    greek_gods = insert(greek_gods,new Link{"Mars"});
    greek_gods = insert(greek_gods,new Link{"Poseidon"});

    Link* p = find(greek_gods, "Mars");
    if (p){
        p->value = "Ares";
    }
    
    Link* g = find(norse_gods,"Zeus");
    if (g) {
        //making sure that the erased() Link isn't pointed to by norse_gods
        if(g==norse_gods)
            norse_gods = g->succ;
        erase(g);
        //when inserting Zeus BEFORE the first greek god, make greek_gods point to Zeus Link
        greek_gods = insert(greek_gods,g);
    }
    print_all(norse_gods);
    cout << '\n';

    print_all(greek_gods);
    cout << '\n';
    
}