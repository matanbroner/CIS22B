//
//  main.cpp
//  CIS 22B Lab 2
//
//  Created by Matan Broner on 5/2/18.
//  Copyright © 2018 Matan Broner. All rights reserved.
//



#include <iostream>

using namespace std;
const int sizeWords = 200; // max size of words allowed to user
char* stringNAdd(char* dest, char* source, int cat);
int stringNCompare(char* string1, char* string2, int nums );
int stringLength(char *string1);
char *stringNCopy(char* string1, char* string2, int nums);



int main()
{
    int fNum; // menu function number choosing variable
    char cont = 'y'; // loop exit condition
    char word1[sizeWords];
    char word2[sizeWords];
    cout << "Welcome to the C-String Functions Menu \nWhat C-Library copy function would you like to check: \n";
    
    while(cont == 'y') // loop exit condition
    {
        cout << "1. stringLength\n2. stringNCopy\n3. stringNAdd\n4. stringNCompare" << endl << endl << "Function: ";
        cin >> fNum; // menu for user to choose which function to run
    switch (fNum) // menu
    {
        case 1:
        {
            cout << "\nstringLength!\nPlease provide a word up to 200 characters:   ";
            cin >> word1; // basic input for word, then prints the result
            cout << "The string: '" << word1 << "' is " << stringLength(word1) << " characters long!" << endl;
        }
            break;
        case 2:
        {
            int n;
            cout << "\nstringNCopy! Please provide a source string (at most 200 chars), a destination string (at most 200 chars), and the number of characters to copy:  \n";
            cout << "Source String:  ";
            cin >> word1;
            cout << "Destination String:  ";
            cin >> word2;
            cout << "Number of characters to copy:  ";
            cin >> n;
            if (n <= 200)
            cout << "Your destination string now holds the value: " << stringNCopy(word2, word1, n);
            else
                cout << "Each string can only hold a max of 200 characters! Try again." << endl;

        }
            break;
        case 3:
        {
            int n;
            cout << "\nstringNAdd! Please provide a source string (at most 200 chars), a destination string (at most 200 chars), and the number of characters to concatenate:\n";
            cout << "Source String:  ";
            cin >> word1;
            cout << "Destination String:  ";
            cin >> word2;
            cout << "Number of characters to concatenate:  ";
            cin >> n;
            if (n <= 200)
            {
                stringNAdd(word1, word2, n); // concat's n chars (at most) from word 1 to word 2 plus a null char at end
                cout << "Your new word after adding " << n << " [at most] characters is: " << word2 << endl; // result printed
            }
            else
                cout << "Can only add 200 chars at most! Try again!" << endl;
            
        }
            break;
        case 4:
        {
            int n;
            cout << "\nstringNCompare! Please provide a source string (at most 200 chars), a destination string (at most 200 chars), and the number of characters to compare:\n";
            cout << "Source String:  ";
            cin >> word1;
            cout << "Destination String:  ";
            cin >> word2;
            cout << "Number of characters to compare:  ";
            cin >> n;
            int res = stringNCompare(word1, word2, n); // compares n chars from word 1 and word 2 to determine equality
            if (res < 0)
                cout << "String 1 ("<<word1<<") is less than String 2 (" <<word2<<")" <<endl;
            else if (res > 0)
                cout << "String 2 ("<<word2<<") is less than String 1 (" <<word1<<")" <<endl;
            else
                cout << "Both strings (up to " << n << " characters) contain the same exact value!" << endl;
        }
            break;
        default:
            cout << "Input not understood, please choose a new value." << endl; // input other than 1-4 entered
    }
        cout << "\nWould you like to choose another function to test? (y/n):  "; // loop continuation prompt
        cin >> cont;
    }
    if (cont == 'n') // letting user know that program knows they don't want to continue
        cout << "\nThanks, bye!" << endl;
    else if (cont != 'y' && cont != 'n')
        cout << "Unclear response, program ending..." << endl; // char other than 'y' or 'n' quits program
    return 0;
}

char* stringNAdd(char* source, char* dest, int cat)
{
    int buffCount = 0;
    char* endWord = dest; // pointer to be returned by function
    while (*dest != '\0')
    {
        *dest++;
        buffCount++;
    }
    for (int i =0; i < cat && i <(sizeWords-buffCount); i++)
    {
        *dest++ = *source++;
    }
    *dest = '\0';
 
    return endWord;
}

int stringNCompare(char* string1, char* string2, int nums )
{
    int result = 0;
    while(result == 0 && nums > 0)
    {
        if (*string1 > *string2)
            result = 1;
        else if (*string1 < *string2)
            result = -1;
        *string1++;
        *string2++;
        nums--;
    }
    return result;
}

int stringLength(char *string1)
{
    int numChars = 0;
    while (*string1 != '\0')
    {
        numChars += 1;
        *string1++;
    }
    return numChars;
}

char *stringNCopy(char* string1, char* string2, int nums)
{
    char* endWord = string1;
    while (*string2 != '\0' && nums > 0)
    {
        *string1++ = *string2++;
        nums--;
    }
    *string1 = '\0';
    
    return endWord;
}
