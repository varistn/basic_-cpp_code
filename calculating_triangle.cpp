/* 
 * File:   main.cpp
 * Author: Varis Pornpatanapaisarnkul
 * Created on September 14, 2018, 11:34 AM
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // name variables
    float first_length;
    float second_length;
    float third_length;
    float perimeter;
    float semi_perimeter;
    float area;
    float sqrt_condition;
    
    // take user input
    cout << "Enter length of first side: ";
    cin >> first_length;
    cout << "Enter length of second side: ";
    cin >> second_length;
    cout << "Enter length of third side: ";
    cin >> third_length;
    
    // name to simplifying calculation
    float l1 = first_length;
    float l2 = second_length;
    float l3 = third_length;
    float sp = semi_perimeter; 
    
    // calculations 
    perimeter = l1 + l2 + l3;
    sp = perimeter/2;
    area = sqrt(sp*(sp-l1)*(sp-l2)*(sp-l3));
    
    // sqrt_condition is to evaluate the value inside the sqrt
    // if it is greater than 0 >> triangle is valid
    // otherwise >> triangle is invalid
    sqrt_condition = (sp*(sp-l1)*(sp-l2)*(sp-l3)); 
    
    if (sqrt_condition < 1){
        std::cout << std::endl << "You entered sides length of " << l1 << ", "<< l2 << ", " << l3 << std::endl;
        std::cout << "These three side lengths cannot form a legal triangle " << std::endl;
    }else{
        std::cout << std::endl << "You entered sides length of " << l1 << ", "<< l2 << ", " << l3 << std::endl;
        std::cout << "The perimeter is " << perimeter << std::endl;
        std::cout << "The area is " << area << std::endl;
        // check of specific type of triangle
        // if all lengths are equal >> equilateral
        // if two out of three are equal >> isosceles
        }if( ((l1==l2) || (l2==l3) || (l1==l3)) && (sqrt_condition>0) ){
            std::cout << "This triangle is an isosceles triangle" << std::endl;
        }if( (l1==l2) && (l1==l3) ){
            std::cout << "This triangle is an equilateral triangle" << std::endl;                    
    }
    return 0;
}

