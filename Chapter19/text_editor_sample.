#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>

using Line = std::vector<char>;

class Text_iterator {

    std::list<Line>::iterator ln;
    Line::iterator pos;

    public:
        Text_iterator(std::list<Line>::iterator l1, Line::iterator pp)
            :ln{l1}, pos{pp} { }

        char& operator*() { return *pos; }
        Text_iterator& operator++();
        bool operator==(const Text_iterator& other) const
            { return ln==other.ln && pos==other.pos; }
        bool operator!=(const Text_iterator& other) const
            { return !(*this==other); }
};

Text_iterator& Text_iterator::operator++()
{
    ++pos;
    if (pos==ln->end()){
        ++ln;
        pos = ln->begin();

    }
    return *this;
}

struct Document {
    std::list<Line> line;
    Document() { line.push_back(Line{}); }  //avoid empty container

    Text_iterator begin()
        { return Text_iterator{line.begin(), line.begin()->begin()}; }

    Text_iterator end()
        { 
            auto last = line.end();
            --last;
            return Text_iterator{last, (*last).end()};
        }
};

std::istream& operator>>(std::istream& is, Document& d){
    for (char ch; is.get(ch); ){
        d.line.back().push_back(ch);
        if(ch=='\n')
            d.line.push_back(Line{});
    }
    if(d.line.back().size())
        d.line.push_back(Line{});
    return is;
}


template<typename Iter> //instead of concepts I use standard templates
void advance(Iter& p, int n)
{
    while (0 < n) {
        ++p;
        --n;
    }
}

void print(Document& d)
{
    for ( auto p : d )
        std::cout << p;
}

void erase_line(Document& d, int n)
{
    if (!(0 <= n && n < d.line.size()))
        return;
    auto p = d.line.begin();
    std::advance(p, n); 
    d.line.erase(p);
}

int main() 
{
    std::cout << "It works!\n";
    return 0;
}