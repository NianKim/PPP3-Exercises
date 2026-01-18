
#include<iostream>
#include<algorithm>

void solve_quadratic(double a, double b, double c){
    if(a == 0){
        std::cout << "Error: 'a' cannot be zero in a quadratic equation.\n";
        return;
    }
    double discriminant = (b*b) - (4 * a * c);
    if (discriminant < 0){
        //this equation has non-real solutions
        std::cout << "No real roots (discriminant is negative).\n";
        return;
    }else if (discriminant == 0){
        //one real root
        double x = -b/(2*a);
        std::cout << "One real root: x = " << x << '\n'; 
    }else{
        //two real roots
        double x1 = (-b + sqrt(discriminant)) /(2*a);
        double x2 = (-b - sqrt(discriminant)) /(2*a);
        std::cout << "Two real roots: \n";
        std::cout << "x1 = " << x1 << "\n";
        std::cout << "x2 = " << x2 << "\n";
    }
}

int main(){
    double a;
    double b;
    double c;
    //reading the input equation
    std::cout << "Please enter the coefficients of your formula a*x^2 + b*x + c.\n";
    std::cout << "a: "; std::cin >> a;
    std::cout << "b: "; std::cin >> b;
    std::cout << "c: "; std::cin >> c;

    try{
      solve_quadratic(a,b,c);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        return 1;
    }catch(...){
        std::cerr << "Unknown error \n";
        return 2;
    }
}