#ifndef STUDY_H
#define STUDY_H
#include <string>
using namespace std;

/*
 * Colection of data to create a Study
 * Study takes care of calculating its values based on values inserted by user
 * Study should not do enything else like printing and exporting in seperate file
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
  
  string getNameOfStudy(){return nameOfStudy;}
  string getNameOfValue(){return nameOfValue;}
  string getNameOfMeasurementUnit(){return nameOfMeasurementUnit;}
  
  int getNumberOfMeasurements(){return numberOfMeasurements;}
                                                
  const double* getMeasuredValues(){
    const  double* mesVal = &measuredValues[0];

    return mesVal;
  }

  const double* getDeviation(){
    const double* dev = &deviation[0];

    return dev;
  }

  double getMidValue(){return midValue;}
  double getMaxApsDev(){return maxApsoluteDeviation;}
  double getMaxRelDev(){return maxRelativeDeviation;}
  double getSumOfVal(){return sumOfVal;}
  
protected:
  void SetNameOfStudy();
  void SetNameOfValue();
  void SetNameOfMeasurementUnit();
  
  void SetNumberOfMeasurement();
  
  void CalculateMeasuredValues();
  
  void CalculateDeviationAndMaxDev();

  double MaxDeviation(double dev[]);

  void SetValues();
};

#endif // STUDY_H
