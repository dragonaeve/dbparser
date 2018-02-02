#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

int eventID;
double windU, windV, temp;
string date;
string head = "EnvironmentPoint(eventID, date, windU, windV, temperature):- ";
int main() {
  // part 1 
  ifstream infile("env_data_1yr_daily.txt");
  if (!infile) {
    cout << "File could not be opened." << endl;
    return -1;
  }
  ofstream out("env_data_1yr.txt");
  for (;;) {
    infile >> eventID; //read 1st entry
    if (infile.eof()) return 1; //check for eof
    infile.get(); //ignore blank
    infile >> date;
    
    infile.get(); //ignore blank
    infile >> windU;
    
    infile.get(); //ignore blank
    infile >> windV;
    
    infile.get(); //ignore blank
    infile >> temp;
    
    out << head << "eventID=" << eventID << ", date=" << "\"" << date
      << "\"" << ", windU=" << windU << ", windV=" << windV
      << ", temperature=" << temp << "." << '\n';
  }
  return 0;
}