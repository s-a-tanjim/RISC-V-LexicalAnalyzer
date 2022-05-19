#include<iostream>
#include<string>
using namespace std;
#include "datastructure_generator.h"
#include "input.h"
#include "analyzer.h"



int main(){
  DatastructureGenerator *ds = new DatastructureGenerator("../output_datastructure.txt");

  Input *i = new Input("../sampleInput.txt");

  Analyzer *anz = new Analyzer("../output.txt");


  while(!i->isEndOfFile()){
    anz->analyze(i->readLine());
  }

  ds->saveData();
  //DatastructureGenerator::saveData("../output_datastructure.txt");
  cout<<"Datastructure is stored in 'output_datastructure.txt' file\n";
  cout<<"And lexically analyzed output is stored in 'output.txt' file\n\n";
  return 0;
}
