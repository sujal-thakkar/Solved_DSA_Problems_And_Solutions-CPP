#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 2, b = 5, c, d, e;
    //lambda expressions:

    //No capture lambda function: with arguements
    [](int a,int b) -> void {
        cout << a << " " << b;
        a = 4; //This will not change the original value of a, because it's not taken as reference.
    }(a,b);

    //Capture by value lambda function: without arguments
    [=]()->void{ // '=' expression take all the values variables present in the parent function to the lamda function.
        cout << a << " " << b;
    }(); // we can also provide specific variables if we want and not select all the variable values.

    //capture by reference:
    [&]()->void { // '&' expression take all the variables, present in the parent function as reference and provide the lambda function.
        cout << a << " " << b;
        b = 52; //this will actually change the value of the original value of b as it is passed as reference to the function.
    }();
    cout << endl << b;

    //can mix capture by val and ref as well as arg:
    [&, a]()-> void { //will provide reference of all the variables in the parent func except will provide a as value(can't modify)
        cout << a << b;
    }();
    
    return 0;
}