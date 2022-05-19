#include<iostream>
#include<string>
using namespace std;
#include "rules.h"
#include "data.h"
#include "input.h"
#include "analyzer.h"


int main(){
  Input i("../sampleInput.txt");

  Analyzer anz("../output.txt");

  while(!i.isEndOfFile()){
    anz.analyze(i.readLine());
  }

  anz.saveData();

  cout<<"Datastructure is stored in 'output.txt' file\n";
  //cout<<"And lexically analyzed output is stored in 'output.txt' file\n\n";
  return 0;
}
