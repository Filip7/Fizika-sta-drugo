#include <iostream>
#include <string>
#include <sys/stat.h>
#include <cstdlib>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>
#include "dfPath.h"

using namespace std;
using namespace boost::filesystem;

string DefaultDirectory(string dir){
  #ifdef _WIN32
    const char* homePath = getenv("HOMEPATH");
    if(homePath == NULL){
      cerr << "No  %HOMEPATH% set!\n";
    }
    string fsd_folder{"\\" + dir + "\\"};
    string default_save_location = string(homePath) + fsd_folder;
  #else
    const char* homePath = getenv("HOME");
    if(homePath == NULL){
      cerr << "No $HOME set\n";
    }
    string fsd_folder{"/" + dir + "/"};
    string default_save_location = string(homePath) + fsd_folder;
  #endif
  
  try {
    path p = complete(default_save_location);
    create_directory(p);
  }
  catch (exception& e) {
    cerr << e.what() << endl;
  }

  return default_save_location;
}

bool fileExists(const string& filename){
    struct stat buf;
    return stat(filename.c_str(), &buf) != -1;
}

string GetFileNameAndLocation(){
  string nameOfFile;
  string path =  DefaultDirectory("Fizika-sta-drugo");  
  
  string choice;
  char choiceChar;
  
  input:
  
  cout << "Upisi ime datoteke: ";
  getline(cin,nameOfFile);
  string file_location = path + nameOfFile + ".txt";
 
  if(fileExists(file_location)){
    cout << "Datoteka: \"" << nameOfFile << ".txt" << " \"vec postoji" << endl;
    cout << "Zelite li spremiti datoteku pod drugim imenom? (Da/Ne) : ";
    getline(cin, choice);
    choiceChar = choice[0];
    if(choiceChar == 'D' || choiceChar == 'd'){
      goto input;
    }
  }
  
  return file_location;
}
