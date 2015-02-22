#include <iostream>
#include <string>
#include <fstream>
#include "printStudy.h"
#include "study.h"
#include "dfPath.h"

using namespace std;

#ifdef _WIN32
  #define Triangle "(delta)"
#else
  #define Triangle "\u25B2"
#endif

void printStudy(Study& elaborat){
  int i;
  const double* dev = elaborat.getDeviation();
  
  cout << endl;
  cout << "\tIzracunate vrijednosti: " << endl << endl;

  cout << endl << "Broj mjerenja: " << elaborat.getNumberOfMeasurements() << endl;

  cout << endl << "Srednja vrijednost: " << endl;
  cout << "\t" << elaborat.getNameOfValue() << "' = " << elaborat.getMidValue()  << " " << elaborat.getNameOfMeasurementUnit() << endl;

  cout << endl << "Odstupanje od srednje vrijednosti: " << endl;
  for(i = 0; i < elaborat.getNumberOfMeasurements(); ++i){
    cout << Triangle << elaborat.getNameOfValue() << i+1 << " = " << *(dev+i) << " " << elaborat.getNameOfMeasurementUnit() << endl;
  }

  cout << endl << "Maksimalno apsolutno odstupanje: " << endl;
  cout << "\t" << "|" << elaborat.getNameOfValue() << "|max = " << elaborat.getMaxApsDev() << elaborat.getNameOfMeasurementUnit() << endl; 

  cout << endl << "Maksimalna relativna pogreska: " << endl;
  cout << "\t" << "rmax = " << elaborat.getMaxRelDev() << "%" << endl;
  
  cout << endl << "Rezultat s maksimalnim relativnim odstupanjem: " << endl;
  cout << "\t" << elaborat.getNameOfValue() << " = " << elaborat.getMidValue() << elaborat.getNameOfMeasurementUnit();
  cout << " +/- " << elaborat.getMaxRelDev() << "%" << endl;

  cout << endl << "Rezultat: " << endl;
  cout << "\t" << elaborat.getNameOfValue() << " = " << elaborat.getMidValue() << " +/- " << elaborat.getMaxApsDev();
  cout << " " << elaborat.getNameOfMeasurementUnit() << endl;

  string choice;
  char choiceChar;

  cout << endl << endl << "Zelite li spremiti elaborat u posebnu datoteku? (Da/Ne) :";
  getline(cin, choice);
  choiceChar = choice[0];
  if(choiceChar == 'd' || choiceChar == 'D'){
    exportStudyInFile(elaborat);
  }
}

void exportStudyInFile(Study& elaborat){
  int i;
  const double* mesVal = elaborat.getMeasuredValues();
  const double* dev = elaborat.getDeviation();
  string save_location = GetFileNameAndLocation(); 
  
  ofstream saveFile;
  saveFile.open(save_location);
  
  saveFile << "Elaborat iz fizikalnih mjerenja" << endl;
  saveFile << "__________________________________________________________________________________" << endl << endl;
  saveFile << elaborat.getNameOfStudy() << endl << endl;
  
  saveFile << endl << "Broj mjerenja: " << elaborat.getNumberOfMeasurements() << endl;
  
  saveFile << endl << "Izmjerene vrijednosti: " << endl;
  for(i = 0; i < elaborat.getNumberOfMeasurements(); ++i){
    saveFile << elaborat.getNameOfValue() << i+1 << " = " << *(mesVal+i) << " " << elaborat.getNameOfMeasurementUnit() << endl;
  }

  saveFile << endl << "Izracunate vrijednosti: " << endl;

  saveFile << endl << "Srednja vrijednost: " << endl;
  saveFile << elaborat.getNameOfValue() << "' = " << elaborat.getMidValue()  << " " << elaborat.getNameOfMeasurementUnit() << endl;

  saveFile << endl << "Odstupanje od srednje vrijednosti: " << endl;
  for(i = 0; i < elaborat.getNumberOfMeasurements(); ++i){
    saveFile << Triangle << elaborat.getNameOfValue() << i+1 << " = " << *(dev+i) << " " << elaborat.getNameOfMeasurementUnit() << endl;
  }

  saveFile << endl << "Maksimalno apsolutno odstupanje: " << endl;
  saveFile << "|" << elaborat.getNameOfValue() << "|max = " << elaborat.getMaxApsDev() << elaborat.getNameOfMeasurementUnit() << endl; 

  saveFile << endl << "Maksimalna relativna pogreska: " << endl;
  saveFile  << "rmax = " << elaborat.getMaxRelDev() << "%" << endl;
  
  saveFile << endl << "Rezultat s maksimalnim relativnim odstupanjem: " << endl;
  saveFile << elaborat.getNameOfValue() << " = " << elaborat.getMidValue() << elaborat.getNameOfMeasurementUnit();
  saveFile << " +/- " << elaborat.getMaxRelDev() << "%" << endl;

  saveFile << endl << "Rezultat: " << endl;
  saveFile  << elaborat.getNameOfValue() << " = " << elaborat.getMidValue() << " +/- " << elaborat.getMaxApsDev();
  saveFile << " " << elaborat.getNameOfMeasurementUnit() << endl;
  
  saveFile.close();
  
  cout << endl << "*** Elaborat spremljen na lokaciji: " << save_location << " ***" << endl << endl;
}
