/*

Class definition drill:

[13] Define a struct Person containing a string name and an int age.

[14] Define a variable of type Person, initialize it with “Goofy” and 63, and write it to the screen (cout).

[15] Define an input (>>) and an output (<<) operator for Person; read in a Person from the keyboard (cin) and write it out to the screen (cout).

[16] Give Person a constructor initializing name and age.

[17] Make the representation of Person private, and provide const member functions name() and age() to read the name and age.

[18] Modify >> and << to work with the redefined Person.

[19] Modify the constructor to check that age is [0:150) and that name doesn’t contain any of the characters ; :"’[] * &^%$#@!. Use error() in case of error. Test.

[20] Read a sequence of Persons from input (cin) into a vector<Person>; write them out again to the screen (cout). Test with correct and erroneous input.

[21] Change the representation of Person to have first_name and second_name instead of name. Make it an error not to supply both a first and a second name. Be sure to fix >> and << also. Test

*/