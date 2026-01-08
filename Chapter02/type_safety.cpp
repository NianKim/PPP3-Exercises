//this program is meant to illustrate the importance of type safety
int main(){
    double x;          //x has not been initialized: value of x is undefined
    double y = x;      //value of y is undefined
    double z = 2.0 +x; //the meaning of + and the value of z are undefined"
}