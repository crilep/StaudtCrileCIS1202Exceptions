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
        return ("\nERROR : Invalid character...");

    }

};

class Invalid_Range_Exception_C
{
public:
    string Invalid_Range_Exception()   // member function
    {
        return ("\nERROR : Invalid range...");

    }

};

char character(char start, int offset);

int main() {

    //loop to test different exceptions
    for (int i = 0; i < 5; i++) {
        try {

            if (i == 0) {
                char testChar1 = character('a', 1);
                cout << "\ncharacter('a', 1) : \n" << testChar1;
            }
            else if (i == 1) {
                cout << "\ncharacter('A', -1) : ";
                char testChar2 = character('A', -1);
            }
            else if (i == 2) {
                cout << "\ncharacter('?', -1) : ";
                char testChar4 = character('?', -1);
            }
            else if (i == 3) {
                char testChar4 = character('Z', -1);
                cout << "\ncharacter('Z', -1) : \n" << testChar4;
            }
            else if (i == 4) {
                cout << "\ncharacter('A', 35) : ";
                char testChar5 = character('A', 35);
            }


        }
        //catch exceptions
        catch (Invalid_Character_Excpeption_C invalidCharExcept) {

            cout << invalidCharExcept.Invalid_Character_Excpeption();

        }
        catch (Invalid_Range_Exception_C invalidRangeExcept) {

            cout << invalidRangeExcept.Invalid_Range_Exception();

        }

    }

}

char character(char start, int offset) {

    char characterFinal;
    bool valid = false;

    //test if start is a character
    if (!isalpha(start)) {

        throw (Invalid_Character_Excpeption_C());

    }
    else {

        //prevent uppercase to lowercase ranges and vice versa
        bool isUpperCase = isupper(start);
        characterFinal = start + offset;
        bool isUpperCaseAfter = isupper(characterFinal);

        if (isUpperCase == isUpperCaseAfter) {

            valid = true;

        }

        if (!isalpha(characterFinal) || !valid) {

            throw (Invalid_Range_Exception_C());

        }


    }

    return characterFinal;

}