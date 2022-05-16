#include<string>
#include <fstream>

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
    //inputfile >> current_line;
    getline(inputfile, current_line);
    //cout<<current_line<<"\n";
    return current_line;
  }

  bool isEndOfFile(){
    return inputfile.eof();
  }
};

