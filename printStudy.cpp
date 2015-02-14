#include <iostream>
#include "study.h"
using namespace std;

void printStudy(Study& elaborat){
  int i;
  cout << "\tCalculated values: " << endl;

  cout << elaborat.getNameOfStudy() << endl << endl;
  for(i = 0; i < elaborat.getNumberOfMeasurements(); ++i){
  
  }
}
