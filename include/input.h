#include <fstream>

#pragma once

class Input
{
private:
  string current_line;
  ifstream inputfile;
public:
  Input(string file_name){
    inputfile.open(file_name,ios::in);
  }

  ~Input(){
    inputfile.close();
  }

  string readLine(){
    getline(inputfile, current_line);
    return current_line;
  }

  bool isEndOfFile(){
    return inputfile.eof();
  }
};

