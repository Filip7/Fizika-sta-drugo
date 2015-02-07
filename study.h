#ifndef STUDY_H
#define STUDY_H
#include <string>
using namespace std;

/*
 * Colection of data to create a Study
 */

class Study
{
private:
  string nameOfStudy;
  string nameOfValue;
  string nameOfMeasurementUnit;
    
  int numberOfMeasurements;
    
  double measuredValues[100];
  double deviation[100];
  double midValue;
  double maxApsoluteDeviation;
  double maxRelativeDeviation;
  double sumOfVal = 0;
    
public:
  Study();
  Study(string nameOfStd, string nameOfVal, string nameOfMesUnit, int numOfMes);
  ~Study();
  
  void PrintValues();
  
protected:
  void SetNameOfStudy();
  void SetNameOfValue();
  void SetNameOfMeasurementUnit();
  
  void SetNumberOfMeasurement();
  
  void SetMeasuredValues();
  
  void SetValues();
};

#endif // STUDY_H
