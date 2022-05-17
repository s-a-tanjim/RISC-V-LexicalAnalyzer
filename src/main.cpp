#include<iostream>
#include<string>
using namespace std;
#include "input.h"
#include "analyzer.h"



int main(){

  Input *i = new Input("../sampleInput.txt");

  Analyzer *anz = new Analyzer("../output.txt");

  while(!i->isEndOfFile()){
    anz->analyze(i->readLine());
  }

  return 0;
}
