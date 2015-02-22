#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "extraTools.h"
#include "printStudy.h"
#include "study.h"

using namespace std;

const string fsd_usage_string{
  "\n./fsd  ~ normalno pokretanje programa, pokrece wizard za izradu elaborata \n"
  "./fsd [-s] [\"ime elaborata\"] [\"ime vrijednosti\"] [\"ime mjerne jedinice\"] [broj mjerenja] \n"
  "        ^ Koristi ovu naredbu za brzu izradu elaborata \n"
  "./fsd [-h] ~ ispisuje ovu pomoc \n"
  "./fsd [-o] ~ prikazuje opcije za program \n"
  "./fsd [-v] ~ prikazuje informacije o verziji programa\n"};

void MainMenu(){
  // Default program goes here
  string input{""};
  int choice = 0;
  
  cout << "\t***Fizika sta drugo***" << endl;
  cout << "Verzija 3.0" << endl;
  
  start:
  cout << endl << "Odaberi jednu od opcija upisujuci broj" << endl;
  cout << "(1) Izradi elaborat, (2) Opcije, (3) Pomoc, (4) Verzija, (5) Ocisti ekran, (6) Izlaz" << endl;
  while(true){
    cout << "Upisi odabir:  ";
      getline(cin,input);
      stringstream thisStream(input);
      if(thisStream >> choice){
        break;
      }
      cout << "Nije upisan broj, pokusaj ponovno: " << endl;
  }
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
      ClearScreen();
      goto start;
    }
    case 6:
    {
     cout << "Hvala na koristenju programa Fsd!" << endl;
     exit(0); 
    }
    default:
    {
      cout << endl << "Krivi odabir!" << endl;
      goto start;
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
  cout << R"(
              _____                    _____                    _____          
             /\    \                  /\    \                  /\    \         
            /::\    \                /::\    \                /::\    \        
           /::::\    \              /::::\    \              /::::\    \       
          /::::::\    \            /::::::\    \            /::::::\    \      
         /:::/\:::\    \          /:::/\:::\    \          /:::/\:::\    \     
        /:::/__\:::\    \        /:::/__\:::\    \        /:::/  \:::\    \    
       /::::\   \:::\    \       \:::\   \:::\    \      /:::/    \:::\    \   
      /::::::\   \:::\    \    ___\:::\   \:::\    \    /:::/    / \:::\    \  
     /:::/\:::\   \:::\    \  /\   \:::\   \:::\    \  /:::/    /   \:::\ ___\ 
    /:::/  \:::\   \:::\____\/::\   \:::\   \:::\____\/:::/____/     \:::|    |
    \::/    \:::\   \::/    /\:::\   \:::\   \::/    /\:::\    \     /:::|____|
     \/____/ \:::\   \/____/  \:::\   \:::\   \/____/  \:::\    \   /:::/    / 
              \:::\    \       \:::\   \:::\    \       \:::\    \ /:::/    /  
               \:::\____\       \:::\   \:::\____\       \:::\    /:::/    /   
                \::/    /        \:::\  /:::/    /        \:::\  /:::/    /    
                 \/____/          \:::\/:::/    /          \:::\/:::/    /     
                                   \::::::/    /            \::::::/    /      
                                    \::::/    /              \::::/    /       
                                     \::/    /                \::/____/        
                                      \/____/                  ~~                                                                                           

             )" ;

  cout << endl << "\t***Fizika sta drugo***" << endl;
  cout << "Verzija 3.1415" << endl << endl;
  cout << "U sjecanje na Nikolu M." << endl << endl;;
  cout << "Napravio: Filip Milkovic" << endl;
}

void PrintUsage(){
  cout << fsd_usage_string << endl;
}

void ClearScreen(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

