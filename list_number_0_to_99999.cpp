//
//  main.cpp
//
//  Created by Varis Pornpatanapaisarnkul on Friday October 12, 2018.
//  Last Modified on Friday October 26, 2018.


#include <iostream>
#include <string>

using namespace std;

// Function Prototypes
string intToString(int number);
string determine_word_one(int one);
string determine_word_ten(int ten, int one);
string determine_word_hundred(int hundred, int ten, int one);
string determine_word_thousand(int thousand, int hundred, int ten, int one);
string determine_word_tenthousand(int tenthousand, int thousand, int hundred, int ten, int one);

int determine_one_digit(int number);
int determine_ten_digit(int number);
int determine_hundred_digit(int number);
int determine_thousand_digit(int number);
int determine_tenthousand_digit(int number);
void printIntString(int start, int end, int step);

int main() {
    
    // for testing the code
    //int number, start, end, step;
    
    //cout << "Number = ";
    //cin >> number;
    //number = 99900;
    //cout << intToString(number) << endl;
    /*
    cout << "Start = ";
    cin >> start;
    cout << "End = ";
    cin >> end;
    cout << "Interval = ";
    cin >> step;
    */
    //start = 1;
    //end = 99999;
    //step = 1;
    //printIntString(start,end,step);
    //return 0;
    

}
// Function that print the string in the interval
void printIntString(int start, int end, int step){
    for(int i = start; i <= end; i = i+step){
        cout << intToString(i) << endl;
    }
}

// Function that turn an integer number to string of words
string intToString(int number){
    int one,ten,hundred,thousand,tenthousand;
    if(number > 0){ // 0 to 9
        one = determine_one_digit(number);
        if(number >= 10){ // 10 to 99
            ten = determine_ten_digit(number);
            if(number >= 100){ // 100 to 999
                hundred = determine_hundred_digit(number);
                if(number >= 1000){ // 1000 to 9999
                    thousand = determine_thousand_digit(number);
                    if(number >= 10000){ // 10000 to 99999
                        tenthousand = determine_tenthousand_digit(number);
                    }
                }
            }
        }
    }else{
        return "zero";
    }
    if(number < 10){ // 0 to 9
        return determine_word_one(one);
    }else if(number < 100){ // 10 to 99
        return determine_word_ten(ten,one);
    }else if(number < 1000){ // 100 to 999
        return determine_word_hundred(hundred,ten,one);
    }else if(number < 10000){ // 1000 to 9999
        return determine_word_thousand(thousand,hundred,ten,one);
    }else if(number < 100000){ // 10000 to 99999
        return determine_word_tenthousand(tenthousand,thousand,hundred,ten,one);
    }else{
        return "Error - Invalid input, please input number from 0 to 99999";
    }
    return "Error";
}

// Subfunctions for determining the digit of the input
int determine_one_digit(int number){
    int one = (number-(number/10)*10);
    return one;
}
int determine_ten_digit(int number){
    int ten = (number-(number/100)*100)/10;
    return ten;
}
int determine_hundred_digit(int number){
    int hundred = (number-(number/1000)*1000)/100;
    return hundred;
}
int determine_thousand_digit(int number){
    int thousand = (number-(number/10000)*10000)/1000;
    return thousand;
}
int determine_tenthousand_digit(int number){
    int tenthousand = (number-(number/100000)*100000)/10000;
    return tenthousand;
}

// Subfunctions for turning digits to word
string determine_word_tenthousand(int tenthousand, int thousand, int hundred, int ten, int one){
    if(thousand == 0 && hundred == 0 && ten == 0 && one == 0){ // take care of _0000
        return determine_word_ten(tenthousand,one) + " thousand";
    }else if(hundred == 0 && ten == 0 && one == 0){ // take care of __000
        return determine_word_ten(tenthousand,thousand) + " thousand";
    }else if(ten == 0 && one == 0){ // take care of ___00
        return determine_word_ten(tenthousand,thousand) + " thousand and " + determine_word_hundred(hundred,ten,one);
    }else if(hundred == 0 && ten == 0){ // take care of __00_
        return determine_word_ten(tenthousand,thousand) + " thousand and " + determine_word_one(one);
    }else if(hundred == 0){ // take care of __0__
        return determine_word_ten(tenthousand,thousand) + " thousand and " + determine_word_ten(ten,one);
    }else{ // take care of _____
        return determine_word_ten(tenthousand,thousand) + " thousand, " + determine_word_hundred(hundred,ten,one);
    }
    return "Error";
}
string determine_word_thousand(int thousand,int hundred,int ten,int one){
    if(hundred == 0 && ten == 0 && one == 0){ // take care of _000
        return determine_word_one(thousand) + " thousand";
    }else if(hundred == 0 && ten == 0){ // take care of _00_
        return determine_word_one(thousand) + " thousand and " + determine_word_one(one);
    }else if(hundred == 0 && one == 0){ // take care of _0_0
        return determine_word_one(thousand) + " thousand and " + determine_word_ten(ten,one);
    }else if(hundred == 0 && one != 0){ // take care of _0__
        return determine_word_one(thousand) + " thousand and " + determine_word_ten(ten,one);
    }else{ // take care of ____
        return determine_word_one(thousand) + " thousand, " + determine_word_hundred(hundred,ten,one);
    }
    return "Error";
}
string determine_word_hundred(int hundred, int ten, int one){
    if(ten == 0 && one == 0){ // take care of _00
        return determine_word_one(hundred) + " hundred";
    }else if(ten == 0 && one != 0){ // take care of _0_
        return determine_word_one(hundred) + " hundred and " + determine_word_one(one);
    }else{ // take care of ___
        return determine_word_one(hundred) + " hundred and " + determine_word_ten(ten,one);
    }
    return "Error";
}
string determine_word_ten(int ten, int one){
    if(ten == 1){
        if(one == 0){ // take care of the special case ten to nineteen
            return "ten";
        }
        if(one == 1){
            return "eleven";
        }
        if(one == 2){
            return "twelve";
        }
        if(one == 3){
            return "thirteen";
        }
        if(one == 4){
            return "fourteen";
        }
        if(one == 5){
            return "fifteen";
        }
        if(one == 6){
            return "sixteen";
        }
        if(one == 7){
            return "seventeen";
        }
        if(one == 8){
            return "eighteen";
        }
        if(one == 9){
            return "nineteen";
        }
    }else if(ten == 2){
        if(one == 0){
            return "twenty";
        }
        return "twenty-" + determine_word_one(one);
    }else if(ten == 3){
        if(one == 0){
            return "thirty";
        }
        return "thirty-" + determine_word_one(one);
    }else if(ten == 4){
        if(one == 0){
            return "forty";
        }
        return "forty-" + determine_word_one(one);
    }else if(ten == 5){
        if(one == 0){
            return "fifty";
        }
        return "fifty-" + determine_word_one(one);
    }else if(ten == 6){
        if(one == 0){
            return "sixty";
        }
        return "sixty-" + determine_word_one(one);
    }else if(ten == 7){
        if(one == 0){
            return "seventy";
        }
        return "seventy-" + determine_word_one(one);
    }else if(ten == 8){
        if(one == 0){
            return "eighty";
        }
        return "eighty-" + determine_word_one(one);
    }else if(ten == 9){
        if(one == 0){
            return "ninety";
        }
        return "ninety-" + determine_word_one(one);
    }
    return "Error";
}
string determine_word_one(int one){
    if(one == 1){
        return "one";
    }
    if(one == 2){
        return "two";
    }
    if(one == 3){
        return "three";
    }
    if(one == 4){
        return "four";
    }
    if(one == 5){
        return "five";
    }
    if(one == 6){
        return "six";
    }
    if(one == 7){
        return "seven";
    }
    if(one == 8){
        return "eight";
    }
    if(one == 9){
        return "nine";
    }
    return "Error";
}
