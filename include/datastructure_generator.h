#include<map>
#include <fstream>

#pragma once

class DatastructureGenerator
{
private:
  static map<string,string>data;
  ofstream outputfile;
  string filename;
public:
  DatastructureGenerator(string _filename){
    filename = _filename;
    //data = map<string,string>();
  }
  static void addData(string type,string value){
    auto itr = data.find(type);
    if(itr!=data.end()) {
      //cout<<"Found dup:  "<<itr->second<<endl;
      itr->second = itr->second+", "+value;
      //cout<<"#####  "<<s<<endl;
    } else {
      data.insert({ type, value });
    }

  }

  void saveData(){
    outputfile.open(filename,ios::out);
    for (auto itr = data.begin(); itr != data.end(); ++itr) {

      outputfile <<itr->first << '\t' << itr->second<< '\n';
      //cout<<"Outputting!!  "<<itr->first<<"   "<<itr->second<<"\n";
    }
    outputfile.close();
  }

};

map<string, string>DatastructureGenerator::data;
