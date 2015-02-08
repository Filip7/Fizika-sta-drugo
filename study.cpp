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
  SetMeasuredValues(); 
}

Study::~Study(){
}

void Study::SetNameOfStudy(){
  cin.ignore(); 
  
  cout << endl << "Insert name of study: ";
  getline(cin, nameOfStudy);
}

void Study::SetNameOfValue(){
  cout << "Insert name of value: ";
  cin >> nameOfValue;
}

void Study::SetNameOfMeasurementUnit(){
  cout << "Insert measuring unit: ";
  cin >> nameOfMeasurementUnit;
}

void Study::SetNumberOfMeasurement(){
  cout << "Insert how many values you measured: ";
  cin >> numberOfMeasurements;
}

void Study::SetMeasuredValues(){
  // Cheaking if numberOfMeasurment is 0 here because program can be started from command line and
  // program goes throught this part every time so it is logical
  if(numberOfMeasurements == 0){
    cout << "\tWell done mate!" << endl;
    cout << "You measured nothing!" << endl;
    cout << "End resault: F" << endl;
  }
  else{
    cout << endl << "Insert values:" << endl; 
  
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
  SetMeasuredValues();
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

void Study::PrintValues(){
  cout << "Name of study: " << nameOfStudy << endl;
  
  for(int i = 0; i < numberOfMeasurements; ++i){
    cout << nameOfValue << i+1 << ": " << measuredValues[i] << " " << nameOfMeasurementUnit << endl;
  }
}

