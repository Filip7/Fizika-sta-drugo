#include <iostream>
#include "printStudy.h"
#include "study.h"
using namespace std;

#define Triangle "\u25B2"

void printStudy(Study& elaborat){
  int i;
  const double* dev = elaborat.getDeviation();
  
  cout << endl;
  cout << "\tIzračunate vrijednosti: " << endl << endl;

  cout << endl << "Broj mjerenja: " << elaborat.getNumberOfMeasurements() << endl;

  cout << endl << "Srednja vrijednost: " << endl;
  cout << "\t" << elaborat.getNameOfValue() << "' = " << elaborat.getMidValue() << endl;

  cout << endl << "Odstupanje od srednje vrijednosti: " << endl;
  for(i = 0; i < elaborat.getNumberOfMeasurements(); ++i){
    cout << Triangle << elaborat.getNameOfValue() << i+1 << " = " << *(dev+i) << " " << elaborat.getNameOfMeasurementUnit() << endl;
  }

  cout << endl << "Maksimalno apsolutno odstupanje: " << endl;
  cout << "\t" << "|" << elaborat.getNameOfValue() << "|max = " << elaborat.getMaxApsDev() << elaborat.getNameOfMeasurementUnit() << endl; 

  cout << endl << "Maksimalna relativna pogreška: " << endl;
  cout << "\t" << "rmax = " << elaborat.getMaxRelDev() << "%" << endl;
  
  cout << endl << "Rezultat s maksimalnim relativnim odstupanjem: " << endl;
  cout << "\t" << elaborat.getNameOfValue() << " = " << elaborat.getMidValue() << elaborat.getNameOfMeasurementUnit();
  cout << " +/- " << elaborat.getMaxRelDev() << "%" << endl;

  cout << endl << "Rezultat: " << endl;
  cout << "\t" << elaborat.getNameOfValue() << " = " << elaborat.getMidValue() << " +/- " << elaborat.getMaxApsDev();
  cout << " " << elaborat.getNameOfMeasurementUnit() << endl;

  char odabir;

  cout << endl << endl << "Želite li spremiti elaborat u posebnu datoteku? (Da/Ne) :";
  cin >> odabir;
  if(odabir == 'd' || odabir == 'D'){
    exportStudyInFile(elaborat);
  }

}

void exportStudyInFile(Study& elaborat){
  cout << "In making" << endl;
}
