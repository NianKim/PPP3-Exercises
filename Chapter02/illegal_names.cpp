//this program is meant to test the compilers reaction to illegal names using the -Wall flag in terminal
int main(){
    int double = 0; //expected qualified-id, cannot compine with previous declaration specifier
    std::string B@dpractic3 = "Not good!"; //undeclared identifier std
    bool _this_is_not_okay = true; //no error
    char 4noone = '\n'; //unqualified-id
    int huh?; //expected ';' at end of declaration
    bool $PATH; //no error
    std::string white space; //expected ';' at end of declaration
}