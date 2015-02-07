#include <iostream>
#include <string>
#include "study.h"
#include "extraTools.h"

using namespace std;

const char fsd_usage_string[]{
  "\n./fsd  ~ deafult running of program, starts wizard for creating study \n"
  "./fsd [s] [\"name of study\"] [\"name of value\"] [\"name of unit\"] [number of measured values] \n"
  "  ^ Use this command to create study quicly \n"
  "./fsd [h] ~ prints this help \n"
  "./fsd [o] ~ shows options for Fsd \n"
  "./fsd [v] ~ shows version information"};

int main(int argc, char* argv[]){
  system(".././testFile.sh");

  if(argc < 2){
    MainMenu();
  }
  
  for(int i = 1; i < argc; ++i){
    if(*argv[i] == 's'){
      if(argc == 6){
        string studyName = argv[2];
        string valueName = argv[3];
        string mesUnitName = argv[4];
        int valueNumber = atoi(argv[5]);

	      Study elaborat{ studyName, valueName, mesUnitName, valueNumber};
	      elaborat.PrintValues();
        break;
      }
      else{
        cout << "Not enough options to start the program!" << endl;
        cout << "Use h to see help" << endl;
        break;
      }
    }
    else if(*argv[i] == 'h'){
      cout << fsd_usage_string << endl;
      break;
    }
    else if(*argv[i] == 'o'){
      Options();
      break;
    }
    else{
      cout << "Unknown option:  " << argv[i] << endl;
      cout << "Usage: " << fsd_usage_string << endl;
      break;
    }
  }
  
  return 0;
}

