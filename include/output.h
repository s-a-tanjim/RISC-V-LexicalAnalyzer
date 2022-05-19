#include <fstream>

#pragma once

class Output
{
private:
  ofstream outputfile;
public:
  Output(string file_name){
    cout<<file_name<<endl;
    outputfile.open(file_name,ios::out);
  }

  ~Output(){
    outputfile.close();
  }

  void writeLine(string s){
    cout<<s;
    outputfile << s;
  }
};

