#include <fstream>

#pragma once

class Output
{
private:
  string current_line;
  ofstream outputfile;
public:
  Output(string file_name){
    outputfile.open(file_name,ios::out);
  }

  ~Output(){
    outputfile.close();
  }

  void writeLine(string s){
    current_line = s;
     outputfile << current_line << endl;
  }
};

