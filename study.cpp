#include <iostream>
#include <string>
#include "study.h"
using namespace std;

Study::Study(){
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
  cin.ignore(); 
  
  cout << endl << "Upiši ime elaborata: ";
  getline(cin, nameOfStudy);
}

void Study::SetNameOfValue(){
  cout << "Upiši ime vrijednosti: ";
  getline(cin, nameOfValue);
}

void Study::SetNameOfMeasurementUnit(){
  cout << "Upiši ime mjerne jedinice: ";
  getline(cin, nameOfMeasurementUnit);
}

void Study::SetNumberOfMeasurement(){
  cout << "Upiši broj mjerenja: ";
  cin >> numberOfMeasurements;
}

void Study::CalculateMeasuredValues(){
  // Cheaking if numberOfMeasurment is 0 here because program can be started from command line and
  // program goes throught this part every time so it is logical
  if(numberOfMeasurements == 0){
    cout << "\tBravo!" << endl;
    cout << "Nisi ništa izmjerio!" << endl;
    cout << "Ocjena: 1" << endl;
  }
  else{
    cout << endl << "Unesi vrijednosti:" << endl; 
  
    for(int i = 0; i < numberOfMeasurements; ++i){
        cout << nameOfValue << i+1 << ": ";
        cin >> measuredValues[i];
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

