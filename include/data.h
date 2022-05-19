#include<map>
#include<string>
#include "output.h"

#pragma once

class Data
{
private:
  Output *op;
  static map<string,int> all_reg;
  static map<string,int> all_var;
  static map<string,int> all_numb;
  static map<string,int> all_opcode;
public:
  Data(string _output_file){
    op = new Output(_output_file);
  }

  ~Data(){
    delete op;
  }

  static void storeData(string type, string data) {
    if(type=="reg") {
      auto itr = all_reg.find(data);
      if(itr!=all_reg.end()) {
        itr->second++;
      } else {
        all_reg.insert({ data, 1 });
      }
    } else if(type=="var") {
      auto itr = all_var.find(data);
      if(itr!=all_var.end()) {
        itr->second++;
      } else {
        all_var.insert({ data, 1 });
      }
    } else if(type=="numb") {
      auto itr = all_numb.find(data);
      if(itr!=all_numb.end()) {
        itr->second++;
      } else {
        all_numb.insert({ data, 1 });
      }
    } else if(type=="opcode") {
      auto itr = all_opcode.find(data);
      if(itr!=all_opcode.end()) {
        itr->second++;
      } else {
        all_opcode.insert({ data, 1 });
      }
    }
  }

  void saveData(){
    op->writeLine("Opcode: \t");
    for (auto itr=all_opcode.begin();itr!=all_opcode.end();++itr) {
      op->writeLine(itr->first+"(" + to_string(itr->second) +")  ,");
    }

    op->writeLine("\nRegister: \t");
    for (auto itr=all_reg.begin();itr!=all_reg.end();++itr) {
      op->writeLine(itr->first+"(" + to_string(itr->second) +")  ,");
    }

    op->writeLine("\nVariables: \t");
    for (auto itr=all_var.begin();itr!=all_var.end();++itr) {
      op->writeLine(itr->first+"(" + to_string(itr->second) +")  ,");
    }

    op->writeLine("\nNumbers: \t");
    for (auto itr=all_numb.begin();itr!=all_numb.end();++itr) {
      op->writeLine(itr->first+"(" + to_string(itr->second) +")  ,");
    }
    op->writeLine("\n\n");
  }
};

map<string, int>Data::all_reg;
map<string, int>Data::all_var;
map<string, int>Data::all_numb;
map<string, int>Data::all_opcode;
