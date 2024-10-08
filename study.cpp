#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "study.h"
using namespace std;

Study::Study(){
  cout << endl << "\t***Izrada elaborata***" << endl;
  SetValues();
}

Study::Study(string nameOfStd, string nameOfVal, string nameOfMesUnit, int numOfMes)
: nameOfStudy(nameOfStd), nameOfValue(nameOfVal), nameOfMeasurementUnit(nameOfMesUnit), numberOfMeasurements(numOfMes)
{
  CalculateMeasuredValues(); 
}

Study::~Study(){
}

void Study::SetNameOfStudy(){ 
  cout << endl << "Upisi ime elaborata: ";
  getline(cin, nameOfStudy);
}

void Study::SetNameOfValue(){
  cout << "Upisi ime vrijednosti: ";
  getline(cin, nameOfValue);
}

void Study::SetNameOfMeasurementUnit(){
  cout << "Upisi ime mjerne jedinice: ";
  getline(cin, nameOfMeasurementUnit);
}

void Study::SetNumberOfMeasurement(){
  string input{""};
  numberOfMeasurements = 0;
  while(true){
    cout << "Upisi broj mjerenja: ";
    getline(cin, input);
    stringstream thisStream(input);
    if(thisStream >> numberOfMeasurements){
      break;
    }
    cout << "Nije upisan broj!" << endl;
  }
}

void Study::CalculateMeasuredValues(){
  string input{""};
    
  // Cheaking if numberOfMeasurment is 0 here because program can be started from command line and
  // program goes throught this part every time so it is logical
  if(numberOfMeasurements == 0){
    cout << "\tBravo!" << endl;
    cout << "Nisi nista izmjerio!" << endl;
    cout << "Ocjena: 1" << endl;
    exit(0);
  }
  else{
    cout << endl << "Unesi vrijednosti:" << endl; 
  
    for(int i = 0; i < numberOfMeasurements; ++i){
      measuredValues[i] = 0;
      while(true){
        cout << nameOfValue << i+1 << ": ";
        getline(cin, input);
        stringstream thisStream(input);
        if(thisStream >> measuredValues[i]){
          break;
        }
        cout << "Nije upisan broj!" << endl;
      }
      sumOfVal += measuredValues[i];
    }
    midValue = sumOfVal / numberOfMeasurements;
    CalculateDeviationAndMaxDev();
  }
}

void Study::SetValues(){  
  // This is called when using normal constructor
  SetNameOfStudy();
  SetNameOfValue();
  SetNameOfMeasurementUnit();
  SetNumberOfMeasurement();
  CalculateMeasuredValues();
}

void Study::CalculateDeviationAndMaxDev(){
  // This function calculates Deviations, Maximal apsolute and relative deviation
  // I wanted to make last two in seperate functions but I am focusing on other stuff in this program cause I have writeen Study creators 1000 times
  for(int i = 0; i < numberOfMeasurements; ++i){
    deviation[i] = midValue - measuredValues[i];  
  }
  maxApsoluteDeviation = MaxDeviation(deviation);
  maxRelativeDeviation = (maxApsoluteDeviation / midValue) * 100;
}

double Study::MaxDeviation(double dev[]){
  // This function calculates Maximal Deviation from values inserted. It needs to be rewriten because it could be more efficant
  // TODO: Write algorithm so that the first for is implmented in second (than I wouldnt have to send hole array to the function)
  int i;

  for(i = 0; i < numberOfMeasurements; ++i){
    if(dev[i] < 0){
      dev[i] *= -1;
    }
  } 
  
  double max = dev[0];
  for(i = 1; i < numberOfMeasurements; ++i){
    if(dev[i] > max){
      max = dev[i];
    } 
  }
  return max;
}

