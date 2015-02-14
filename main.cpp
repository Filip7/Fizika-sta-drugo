#include <iostream>
#include <string>
#include "study.h"
#include "printStudy.h"
#include "extraTools.h"

using namespace std;

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
	      printStudy(elaborat);
        break;
      }
      else{
        cout << "Not enough options to start the program!" << endl;
        cout << "Use h to see help" << endl;
        break;
      }
    }
    else if(*argv[i] == 'h'){
      PrintUsage();
      break;
    }
    else if(*argv[i] == 'o'){
      Options();
      break;
    }
    else{
      cout << "Unknown option:  " << argv[i] << endl;
      cout << "Usage: ";
      PrintUsage();
      break;
    }
  }
  
  return 0;
}

