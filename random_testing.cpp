//
//  main.cpp
//
//  Created by Varis Pornpatanapaisarnkul on 29/10/18.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

const int ROW = 3;

// Prototypes
// 1. Sum of Squares
double sumSquares(double array[], int arraySize); // done

// 2. Binary to Decimal
int binaryToDecimal(string binary); // done

// 3. Column Total
int* columnTotals(int m[][ROW], int n); // done

// 4. Longest Strings
string* longestStrings(string array[], int arraySize, int& returnArraySize); // done

// 5. Fibonacci Sequence
int* fibonacci(int n); //done

// 6. Decimal to Binary
string decimalToBinary(int decimal); // done

// 7. Print in Columns
void printColumns(double arr[], int arraySize, int numColumns, int fieldWidth, int numDigits, bool rowFirst); // done

// 8. Sorted
bool sorted(int arr[], int lastIndex); // done

int main(){
//     Testing sumSquares function
//    double array[3] = {2.0,3.0,4.0};
//    cout << sumSquares(array, 3) << endl;
//
//     Testing binaryToDecimal function
//    string binary = "11010";
//    cout << binaryToDecimal(binary) << endl;
//
//     Testing columnTotals function
//    int table[6][ROW] = { {1,2,3},{4,5,6},{7,8,9},{3,4,5},{5,2,3},{10,10,10} };
//    int* foo = columnTotals(table, 6);
//    for(int i=0;i<6;i++){
//        cout << foo[i] << endl;
//    }
//
//     Testing decimalToBinary function
//    cout << decimalToBinary(1271) << endl;
//
//     Testing longestString function
//    string sarr[9] = {"bob","alice","kate","dr no","alice","sue","lee","min","hahaha"};
//    int n;
//    string* arr = longestStrings(sarr, 9, n);
//    for(int i =0 ; i < n ;i++){
//        cout << arr[i] << endl;
//    }
//
//     Testing fibonacci function
//    int* arr =fibonacci(10);
//    for(int i=0;i<10;i++){
//        cout << arr[i] << endl;
//    }
//
//     Testing printColumns function
//    double arr1[] = {1.1, 2.22, 3.333, 4.444, 5.555, 6.66, 7.7, 8.888, 9.199};
//    double arr2[] = {3.1415, 11, 12.875, 21.33, 100.1234, 9.3, 10.111, 5.54, 89.1, 3.8, 11.7, 19.42, 5420.786, 1.1};
//    printColumns(arr1,9,2,5,1,true);
//    printColumns(arr2, 14, 5, 10, 2, false);
//
//     Testing sorted function
//    int arr[5] = {1,2,4,8,5};     // should return 0
//    int arr2[4]= {3,5,23,91};     // should return 1
//    int arr3[5] = {1,2,4,3,5};    // should return 0
//    int arr4[5] = {1,1,1,1,1};    // should return 1
//    cout << sorted(arr4,4);
//    return 0;
}

// 1. Sum of Squares
double sumSquares(double array[], int arraySize){
    double result = 0;
    for(int i = 0; i<arraySize; i++){
        result = result + pow(array[i],2);
    }
    return result;
}

// 2. Binary to Decimal
int binaryToDecimal(string binary){
    int arraySize = binary.size();          // obtain the size of the string
    int array[arraySize];
    for(int i = 0; i < arraySize; i++){
        if(binary[i] == '0'){               // compare if string is 1, input 1 in array
            array[i] = 0;                   // similarly with 0
        }else if(binary[i] == '1'){
            array[i] = 1;
        }else{
            return -1;                      // if string is neither 0 nor 1, return with error
        }
    }
    int result = 0;
    for(int i = 0; i < arraySize; i++){
        result = result + array[i]*pow(2, arraySize-1-i);   // compute the binary to decimal
    }
    return result;
}

// 3. Column Total
int* columnTotals(int m[][ROW], int n){
    int* result = new int[n];               // allocate dynamic memory
    for(int i = 0; i<n; i++){
        result[i] =0;
        for(int j = 0; j<ROW; j++){
            result[i] = result[i] + m[i][j];    // add the component in each row
        }
    }
    return result;
}

// 4. Longest Strings
string* longestStrings(string array[], int arraySize, int& returnArraySize){
    int stringLength[arraySize];
    int temp = 0;
    int j = 0;
    for(int i = 0; i < arraySize; i++){
        stringLength[i] = array[i].size();      // get the size of the component
        if(stringLength[i]>=temp){
            temp = stringLength[i];             // update temp until temp is the highest
        }
    }
    for(int i= 0; i< arraySize; i++){
        if(stringLength[i]>=temp){              // the number of element that has the size of temp
            j++;                                // is the return array size
        }
    }
    returnArraySize = j;
    string* result = new string[arraySize];     // allocate dynamic memory
    int k=0;                                    // index for shifting array
    for(int i = 0; i < arraySize; i++){
        if(array[i].size() == temp){
            result[k] = array[i];               // get the longest string and shift the index
            k++;
        }
    }
    return result;
}
// 5. Fibonacci Sequence
int* fibonacci(int n){
    int* result = new int[n];                   // allocating dynamic memory
    int firstTerm = 0;
    int secondTerm = 1;
    result[0]=firstTerm;
    result[1]=secondTerm;
    for(int i = 2; i < n ;i++){
        result[i] = firstTerm + secondTerm;     // next number is the result of first + second
        firstTerm = secondTerm;                 // update first term and second term
        secondTerm = result[i];
    }
    return result;
}
// 6. Decimal to Binary
string decimalToBinary(int decimal){
    string result = "";
    if(decimal == 1){                           // check for cases of input is simply 1 or 0
        result = "1";
        return result;
    }
    if(decimal == 0){
        result = "0";
        return result;
    }
    int LargestExponent = log2(decimal);
    int LargestPower2 = pow(2,LargestExponent);
    while(LargestPower2 > 0){                   // starting from the largest exponent of 2
        if(decimal >= LargestPower2){           // then reduce to convert to binary
            result = result + "1";              // if the exponent is greater that the number then add "0"
            decimal = decimal - LargestPower2;  // else add "1"
        }else{
            result = result + "0";
        }
        LargestPower2 = LargestPower2/2;        // update the largestPower
    }
    return result;
}
// 7. Print in Columns
void printColumns(double arr[], int arraySize, int numColumns, int fieldWidth, int numDigits, bool rowFirst){
    int i = 0;
    int numRow = 0;
    if(arraySize % numColumns > 0){
        numRow = arraySize/numColumns + 1;          // determine number of row in each case
    }else{
        numRow = arraySize/numColumns;
    }
    if(rowFirst == true){                           // print row first
        for(int row = 1; row <= numRow; row++){
            for(int col = 1; col <= numColumns; col++){
                if(i >= arraySize){                 // break when all the number is listed
                    break;
                }
                cout << setw(fieldWidth) << fixed << setprecision(numDigits) << arr[i];     // print with set width and precision
                i++;                                // update i
            }
            cout << endl;                           // go to next line when the row is complete
        }
    }else{
        for(int row = 1; row <= numRow; row++){
            i = row-1;                              // compensate i with row
            for(int col = 1; col <= numColumns; col++){
                if(i>arraySize-1){                  // break when all the number is listed
                    break;
                }
                cout << setw(fieldWidth) << fixed << setprecision(numDigits) << arr[i];     // print with set width and precision
                i = i+numRow;                       // starting the next row is the next value from the first column
            }
            cout << endl;
        }
    }
}

// 8. Sorted
bool sorted(int arr[], int lastIndex){
    if(arr[lastIndex-1] > arr[lastIndex]){          // if the previous is greater than the next value
        return false;                               // array is not sorted
    }else if(lastIndex <= 0){                       // else, keep checking until the first elememt
        return true;
    }else{
        return sorted(arr, lastIndex-1);            // recursive to test every value downward
    }
    return true;
}
