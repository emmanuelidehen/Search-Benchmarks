//
//  main.cpp
//  SearchBenchmarksEmmanuelIdehen
//
//  Created by Emmanuel Idehen on 4/4/19.
//  Copyright © 2019 Emmanuel Idehen. All rights reserved.
//  Submitted to Mr. Marcus Golden(CS204 Computer programming II)

/*
 Search Benchmarks
 Write a program that has an array of at least 20 integers. It should call a function that
 uses the linear search algorithm to locate one of the values. The function should keep a
 count of the number of comparisons it makes until it finds the value. The program then
 should call a function that uses the binary search algorithm to locate the same value. It
 should also keep count of the number of comparisons it makes. Display these values on the
 screen.
 
 
 
 Psuedo code:
 
 declare var
 init. array of size
 ask the user for a number and pass the number to the binaray and linear search funtions and do your search
 print result 
 
 */




#include <iostream>
using namespace std;


//Linear Search
int linearSearch(int list[], int size, int num, int &x)
{
    int index = 0;            // Used as a subscript to search array
    int position = -1;        // Used to record the position of search value
    bool found = false;     // Flag to indicate if the value was found
    
    while(index < size && !found)
    {
        if (list[index] == num)    // If the value is found
        {
            found = true;            // Set the flag
            position = index;        // Record the value's subscript
        }
        index++;
        
        if (position == -1)
            x++;
    }
    return position;                // Return the position, or -1
}

//Binary Search
int binarySearch(int array[], int size, int num, int &y)
{
    int first = 0,                            // First array element
    last = size - 1,                    // Last array element
    middle,                                // Midpoint of search
    position = -1;                        // Position of search value
    bool found = false;                        // Flag
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;        // Calculate midpoint
        if (array[middle] == num)            // If value is found
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > num)        // If value is in the lower half
            last = middle - 1;
        else
            first = middle + 1;                // If value is in the upper half
        if (position == -1)
            y++;
    }
    return position;
}


int main()
{
    const int SIZE = 20;
    int Array[SIZE] = {1, 3, 4, 6, 12, 5, 7, 8, 9, 2,
        10, 11, 14, 13, 15, 14,  16, 18, 17, 19};
    
    int x(0), y = (0), key(1), //set the key
    xOutput,
    yOutput;
    
    cout << "Enter the number to search for: ";
    cin >> key;
   
    
    xOutput = linearSearch(Array, SIZE, key, x);
    
    yOutput = binarySearch(Array, SIZE, key, y);
    
    cout << "Number of comparisons made before finding the value: "<< key << endl;
    cout << "The linear Search: " << x << endl;
    cout << "The binary Search: " << y << endl;
    
    return 0;
}

/*
 Test Cases:
 
 Enter the number to search for: 1
 Number of comparisons made before finding the value: 1
 The linear Search: 0
 The binary Search: 3
 Program ended with exit code: 0
 
 2//
 
 Enter the number to search for: 16
 Number of comparisons made before finding the value: 16
 The linear Search: 16
 The binary Search: 4
 Program ended with exit code: 0
 
 3///
 
 Enter the number to search for: 3
 Number of comparisons made before finding the value: 3
 The linear Search: 1
 The binary Search: 4
 Program ended with exit code: 0
 
 
 */
