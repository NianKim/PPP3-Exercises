//Try_this: find 3 ways this could lead to obscure errors

//global scope for v_val which is uninitialized can be problematic
//if multiple function are using larger_than_v we could introduce race conditions if one of them
//writes to v_val
//due to find_if being reliant on larger_than_v predicate staying functional, this compounds our errors

double v_val;          // the value to which larger_than_v() compares its argument
bool larger_than_v(double x) { return x>v_val; }


void f(list<double>& v, int x)
{
        v_val = 31;               // set v_val to 31 for the next call of larger_than_v
        auto p = find_if(v.begin(), v.end(), larger_than_v);
        if (p!=v.end()) {
                // ... we found a value > 31 ...
        }

        v_val = x;         // set v_val to x for the next call of larger_than_v
        auto q = find_if(v.begin(), v.end(), larger_than_v);
        if (q!=v.end()) {
                // ... we found a value > x ...
        }
        // ...
}
