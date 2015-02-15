#include <iostream>
#include <string>
#include <cstdlib>
#include "extraTools.h"
#include "printStudy.h"
#include "study.h"

using namespace std;

const char fsd_usage_string[]{
  "\n./fsd  ~ normalno pokretanje programa, pokreće wizard za izradu elaborata \n"
  "./fsd [s] [\"ime elaborata\"] [\"ime vrijednosti\"] [\"ime mjerne jedinice\"] [broj mjerenja] \n"
  "  ^ Koristi ovu naredbu za brzu izradu elaborata \n"
  "./fsd [h] ~ ispisuje ovu pomoć \n"
  "./fsd [o] ~ prikazuje opcije za program \n"
  "./fsd [v] ~ prikazuje informacije o verziji programa"};

void MainMenu(){
  // Default program goes here
  int choice;
  
  cout << "\t***Fizika sta drugo***" << endl;
  cout << "Verzija 3.0" << endl;
  
  start:
  cout << endl << "Odaberi jednu od opcija upisujuči broj" << endl;
  cout << "(1) Izradi elaborat, (2) Opcije, (3) Pomoć, (4) Verzija, (5) Izlaz" << endl;
  cout << "Upisi odabir:  ";
  
  cin >> choice;
  switch(choice){
    case 1:
    {
      Study elaborat; 
      printStudy(elaborat);
      goto start;
    }
    case 2:
    {
      Options();
      goto start;
    }
    case 3:
    {
      PrintHelp();
      goto start;
    }
    case 4:
    {
      PrintVersion();
      goto start;
    }
    case 5:
    {
     cout << "Hvala na korištenju programa Fsd!" << endl;
     exit(0); 
    }
  }
}

void Options(){
  cout << endl << "Here would go some options" << endl;
}

void PrintHelp(){
  cout << endl << fsd_usage_string << endl;
}

void PrintVersion(){
  cout << endl << "\t***Fizika sta drugo***" << endl;
  cout << "Verzija 3.0" << endl << endl;
  cout << "U sjećanje na Nikolu M." << endl << endl;;
  cout << "Napravio: Filip Milković" << endl;
}

void PrintUsage(){
  cout << fsd_usage_string << endl;
}

