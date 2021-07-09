/* 
 * File:   main.cpp
 * Author: Varis Pornpatanapaisarnkul
 * Created on September 26, 2018, 10:54 AM
 */

#include <iostream>
#include <cmath> //not needed

using namespace std;

//Function Prototypes
int getIntegerBetween(int min,int max);
double elapsedTime(int startHour,int startMin,int startSec,int endHour,int endMin,int endSec);                               
double pace(double timegap, double distanceofSplit);    
void printTime();
void printSplit();

//Declare Variables (Unfortunately, Global)
int numberofSplits;                                
int totalRunDistance;                              
int startHour;                                      
int startMin;
int startSec;
int endHour;
int endMin;
int endSec;
int temp;
int currentSplit;
double timegap;
double distanceofSplit;
double currentPace;

//Declare Arrays to stored values for each split
int storedstartHour[100];
int storedstartMin[100];
int storedstartSec[100];
int storedendHour[100];
int storedendMin[100];
int storedendSec[100];

int main() {    
    cout << "Enter number of splits: ";
    cin >> numberofSplits;
    getIntegerBetween(1,100); // make sure the input is from 1 to 100
    cout << endl;
    
    cout << "Enter START time of split 1 in hours, minutes and seconds." << endl;
    cout << "Enter a value between 0 and 24 [hr]: ";
    cin >> temp;
    getIntegerBetween(0,24); // make sure the input is from 0 to 24
    startHour = temp;        // assign value in temp to startHour
    cout << "Enter a value between 0 and 60 [min]: ";
    cin >> temp;
    getIntegerBetween(0,60); // make sure the input is from 0 to 60
    startMin = temp;         // assign value in temp to startMin
    cout << "Enter a value between 0 and 60 [sec]: ";
    cin >> temp;
    getIntegerBetween(0,60); // make sure the input is from 0 to 60
    startSec = temp;         // assign value in temp to startSec
    cout << endl;
    
    for (currentSplit = 1; currentSplit <= numberofSplits; currentSplit++){ //starting loop from split 1 to the end
        cout << "Enter END time of split "<< currentSplit << " in hours, minutes and seconds." << endl;
        cout << "Enter a value between 0 and 24 [hr]: ";
        cin >> temp; 
        getIntegerBetween(0,24);
        endHour = temp;
        cout << "Enter a value between 0 and 60 [min]: ";
        cin >> temp;
        getIntegerBetween(0,60);
        endMin = temp;
        cout << "Enter a value between 0 and 60 [sec]: ";
        cin >> temp;
        getIntegerBetween(0,60);
        endSec = temp;
        
        elapsedTime(startHour,startMin,startSec,endHour,endMin,endSec); //calculating time elapsed in each split
        pace(timegap,distanceofSplit);  //calculating pace
        cout << endl;
        printTime();    //print time as _:_:_ (before) to _:_:_ (after) 
        printSplit();   //print split info such as time elapsed and pace
        cout << endl;
        
        // store values for each iteration
        storedstartHour[currentSplit] = startHour;  
        storedstartMin[currentSplit] = startMin;
        storedstartSec[currentSplit] = startSec;
        
        storedendHour[currentSplit] = endHour;
        storedendMin[currentSplit] = endMin;
        storedendSec[currentSplit] = endSec;
        
        startHour = endHour;    // replaced start values with the end values
        startMin = endMin;      // in order to calculate the next split
        startSec = endSec;
                                        
    }

    if(numberofSplits%2 == 0){ //even number of splits
        // First half calculations
        double firsthalfHour = storedendHour[numberofSplits/2]-storedstartHour[1];  
        double firsthalfMin = storedendMin[numberofSplits/2]-storedstartMin[1];
        double firsthalfSec = storedendSec[numberofSplits/2]-storedstartSec[1];
        double firsthalfTime = firsthalfMin+(firsthalfHour*60)+(firsthalfSec/(double)60);
        double firsthalfDistance = numberofSplits/2;
        double firsthalfPace = firsthalfTime/(double)firsthalfDistance;
        // Second half calculations
        double secondhalfHour = storedendHour[numberofSplits]-storedendHour[numberofSplits/2];
        double secondhalfMin = storedendMin[numberofSplits]-storedendMin[numberofSplits/2];
        double secondhalfSec = storedendSec[numberofSplits]-storedendSec[numberofSplits/2];
        double secondhalfTime = secondhalfMin + (secondhalfHour*60)+(secondhalfSec/(double)60);
        double secondhalfDistance = numberofSplits - firsthalfDistance;
        double secondhalfPace = secondhalfTime/(double)secondhalfDistance;
        // Print the results
        cout << "First Half Split: time = " << firsthalfTime << ", pace = " << firsthalfPace << " minutes per mile" << endl;
        cout << "Second Half Split: time = " << secondhalfTime << ", pace = " << secondhalfPace << " minutes per mile" << endl;
        // Condition for negative split
        if(secondhalfTime < firsthalfTime){
            printf("You ran a negative split");            
        }
        // calculate and print Avg. speed
        double averageSpeed = numberofSplits/ ((firsthalfTime + secondhalfTime)/(double)60) ;
        cout << endl << endl << "Average speed = " << averageSpeed << " mph" << endl;
    }else{ //odd number of splits
        // First half calculations
        double firsthalfHour = storedendHour[numberofSplits/2]+((storedendHour[(numberofSplits/2)+1] - storedendHour[numberofSplits/2]) /(double)2)  -  storedstartHour[1];
        double firsthalfMin = storedendMin[numberofSplits/2]+((storedendMin[(numberofSplits/2)+1] - storedendMin[numberofSplits/2])/(double)2) - storedstartMin[1];
        double firsthalfSec = storedendSec[numberofSplits/2]+((storedendSec[(numberofSplits/2)+1] - storedendSec[numberofSplits/2])/(double)2) - storedstartSec[1];
        double firsthalfTime = firsthalfMin+(firsthalfHour*60)+(firsthalfSec/(double)60);
        double firsthalfDistance = numberofSplits/2 + 0.5;
        double firsthalfPace = firsthalfTime/(double)firsthalfDistance;
        // Second half calculations
        double secondhalfHour = storedendHour[numberofSplits] - storedendHour[numberofSplits/2]- ((storedendHour[(numberofSplits/2)+1]-storedendHour[numberofSplits/2])/(double)2);
        double secondhalfMin = storedendMin[numberofSplits]-storedendMin[numberofSplits/2]-((storedendMin[(numberofSplits/2)+1]-storedendMin[numberofSplits])/(double)2);
        double secondhalfSec = storedendSec[numberofSplits]-storedendSec[numberofSplits/2]-((storedendSec[(numberofSplits/2)+1]-storedendSec[numberofSplits])/(double)2);
        double secondhalfTime = secondhalfMin+(secondhalfHour*60)+(secondhalfSec/(double)60);
        double secondhalfDistance = numberofSplits - firsthalfDistance;
        double secondhalfPace = secondhalfTime/(double)firsthalfDistance;
        // Print the results
        cout << "First Half Split: time = " << firsthalfTime << ", pace = " << firsthalfPace << " minutes per mile" << endl;
        cout << "Second Half Split: time = " << secondhalfTime << ", pace = " << secondhalfPace << " minutes per mile" << endl;
        // Condition for negative split
        if(secondhalfTime < firsthalfTime){ 
            printf("You ran a negative split");
        }
        // calculate and print Avg. speed
        double averageSpeed = numberofSplits/ ((firsthalfTime + secondhalfTime)/(double)60) ;
        cout << endl << endl << "Average speed = " << averageSpeed << " mph" << endl;
        
    }
    return 0;
} 

int getIntegerBetween(int min, int max){
    if(max == 100){ //for inputing the number of split
        while(numberofSplits < min || numberofSplits > max){
            cout << "Enter number of splits: ";
            cin >> numberofSplits;  
        }
        return numberofSplits;
    }
    if(max == 24){ //for inputing the hours 
        while(temp < min || temp > max){
            cout << "Enter a value between 0 and 24: ";
            cin >> temp;       
        }
        return temp;
    }
    if(max == 60){ //for inputing the minutes and seconds
        while(temp < min || temp > max){
            cout << "Enter a value between 0 and 60: ";
            cin >> temp;
        }
        return temp;
    }
    return 0;
}

double elapsedTime(int startHour, int startMin, int startSec, int endHour, int endMin, int endSec){
    int hourgap = endHour - startHour;
    int mingap = endMin - startMin;
    int secgap = endSec - startSec;
    timegap = mingap + (hourgap*60) + (secgap/(double)60);
    return timegap;
}
double pace(double timegap, double distance){
    distance = 1; //unit is [miles]
    currentPace = timegap/(double)distance;
    return currentPace;
}
void printTime(){
   // cout << "Split " << currentSplit << ": " << startHour << ":" << startMin << ":" << startSec << " to " << endHour << ":" << endMin << ":" << endSec;
    printf("Split %d: %d:%d:%d to %d:%d:%d",currentSplit,startHour,startMin,startSec,endHour,endMin,endSec);
}
void printSplit(){
    cout << " time = " << timegap << ", pace = " << currentPace << " minutes per miles" << endl;
}


