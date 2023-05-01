//Crile Staudt
//CIS 1202 101
//May 7, 2023

#include <iostream>
#include<string>

using namespace std;

class Invalid_Character_Excpeption_C
{
public:
    string Invalid_Character_Excpeption()   // member function
    {
        return ("\nInvalid character... Please re-enter");

    }

};

class Invalid_Range_Exception_C
{
public:
    string Invalid_Range_Exception()   // member function
    {
        return ("\nInvalid range... Please re-enter");

    }

};

char character(char start, int offset);


int main() {

    try {
        char testOne = character('1', -1);
        cout << "Result of 'Z' and -1: " << testOne << endl;

    }
    catch (Invalid_Character_Excpeption_C invalidCharExcept){

        cout << invalidCharExcept.Invalid_Character_Excpeption();
    }
    catch (Invalid_Range_Exception_C invalidRangeExcept){

        cout << invalidRangeExcept.Invalid_Range_Exception();

    }
    

}

char character(char start, int offset) {

    char characterFinal;
    
    if (!isalpha(start)) {

        throw (Invalid_Character_Excpeption_C());

    }
    else if (!isdigit(offset)) {

        throw (Invalid_Range_Exception_C());

    }
    else {

        characterFinal = start + offset;

    }

    return characterFinal;

}