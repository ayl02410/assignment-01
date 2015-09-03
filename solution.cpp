/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Alex Liao <ycl@csu.fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

//  This program converts an integer value input by the user into roman numeral characters.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void converter(int);

int main()
{
    int user_input_number;
    char decision;
    
    do
    {
        cout << "Please enter an integer between 1 & 4,999: ";
        cin >> user_input_number;
        
        while (user_input_number > 4999 || user_input_number < 1)
        {
            cout << "Number must be from 0 to 4,999 \n"
            << "Please enter a correct number: ";
            cin  >> user_input_number;
        }
        
        converter(user_input_number);
        
        cout << "Would you like to convert another number? ()Y/N): ";
        cin >> decision;
        cout << endl;
    } while (toupper(decision) == 'Y');
    
    return 0;  // success
}

void converter (int int2convert)
{
    //  M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1
    
    char numeralChar[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int place;
    string romanText;
    
    if (int2convert >= 1000)
    {
        place = int2convert / 1000;
        
        for (int i = 0; i < place; i++)
        {
            romanText += numeralChar[0];
        }
        
        int2convert %= 1000;
    }
    
    if (int2convert >= 100)
    {
        place = int2convert / 100;
        
        if (place == 9)
        {
            romanText += numeralChar[2];
            romanText += numeralChar[0];
        }
        else if (place >= 5)
        {
            romanText += numeralChar[1];
            
            for (int i = 0; i < place - 5; i++)
            {
                romanText += numeralChar[2];
            }
        }
        else if (place == 4)
        {
            romanText += numeralChar[2];
            romanText += numeralChar[1];
        }
        else if (place >= 1)
        {
            for (int i = 0; i < place; i++)
            {
                romanText += numeralChar[2];
            }
        }
        
        int2convert %= 100;
    }
    
    if (int2convert >= 10)
    {
        place = int2convert / 10;
        
        if (place == 9)
        {
            romanText += numeralChar[4];
            romanText += numeralChar[2];
        }
        else if (place >= 5)
        {
            romanText += numeralChar[3];
            
            for (int i = 0; i < place - 5; i++)
            {
                romanText += numeralChar[4];
            }
        }
        else if (place == 4)
        {
            romanText += numeralChar[4];
            romanText += numeralChar[3];
        }
        else if (place >= 1)
        {
            for (int i = 0; i < place; i++)
            {
                romanText += numeralChar[4];
            }
        }
        
        int2convert %= 10;
    }
    
    if (int2convert >= 1)
    {
        place = int2convert;
        
        if (place == 9)
        {
            romanText += numeralChar[6];
            romanText += numeralChar[4];
        }
        else if (place >= 5)
        {
            romanText += numeralChar[5];
            
            for (int i = 0; i < place - 5; i++)
            {
                romanText += numeralChar[6];
            }
        }
        else if (place == 4)
        {
            romanText += numeralChar[6];
            romanText += numeralChar[5];
        }
        else if (place >= 1)
        {
            for (int i = 0; i < place; i++)
            {
                romanText += numeralChar[6];
            }
        }
        
    }
    
    cout << "Your number converted to text is: " << romanText << endl;
}

