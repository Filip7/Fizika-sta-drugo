#include <iostream>
#include <string>
#include <cstdlib>
#include "extraTools.h"
#include "printStudy.h"
#include "study.h"

using namespace std;

const char fsd_usage_string[]{
  "\n./fsd  ~ deafult running of program, starts wizard for creating study \n"
  "./fsd [s] [\"name of study\"] [\"name of value\"] [\"name of unit\"] [number of measured values] \n"
  "  ^ Use this command to create study quicly \n"
  "./fsd [h] ~ prints this help \n"
  "./fsd [o] ~ shows options for Fsd \n"
  "./fsd [v] ~ shows version information"};

void MainMenu(){
  // Default program goes here
  int choice;
  
  cout << "\t***Fizika sta drugo***" << endl;
  cout << "Version 2.0" << endl;
  
  start:
  cout << endl << "Chose option by typing number of the option" << endl;
  cout << "(1) Create study, (2) Options, (3) Help, (4) Version, (5) Exit" << endl;
  cout << "Insert option: ";
  
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
     cout << "Thank you for using Fizika sta drugo program" << endl;
     exit(0); 
    }
  }
}

void Options(){
  cout << endl << "Here would go some options" << endl;
}

void PrintHelp(){
  cout << endl << "You can start program normaly and use wizard to create an study" << endl;
  cout << endl << "Here would go some help" << endl;
}

void PrintVersion(){
  cout << endl << "\t***Fizika sta drugo***" << endl;
  cout << "Version 2.0" << endl << endl;
  cout << "In memory of Nikola M." << endl << endl;;
  cout << "Made by: Filip Milković" << endl;
}

void PrintUsage(){
  cout << fsd_usage_string << endl;
}

