#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include "graph.hpp"
using namespace std;
// input should be in this format:
// <s1>-<d1>-<c1> <s2>-<d2>-<c2> 
// 1-2-19 1-3-9 2-4-3 2-5-3 2-6-4 7-5-4 4-5-3 7-6-4
int main() {
  string str;
  vector<vector<int>> input;

  // getline(cin,str);
  // str = "1-2-19 1-3-9 2-4-3 2-5-3 2-6-4 7-5-4 4-5-3 7-6-4";
  // stringstream in_ss(str);
  // while(in_ss >> str) {
  //   int s,d,c;
  //   string temp;
  //   stringstream ss(str);
  //   getline(ss, temp,'-');
  //   s = stoi(temp);
  //   getline(ss, temp,'-');
  //   d = stoi(temp);
  //   getline(ss, temp,'-');
  //   c = stoi(temp);
  //   ss.clear();
  //   // cout << s << '\t' << d << '\t' << c << '\n';
  //   input.push_back({s,d,c});
  // }

  // for (size_t i = 0; i < input.size(); i++) { 
  //   cout << input[i][0] << '\t' << input[i][1] << '\t' << input[i][2] << endl; 
  // }

  // graph g = graph(input);
  // g.g_print();
  // ----------------------------------------------------------------
  graph g;
  Status status;
  while (true) {
    print_menu();
    getline(cin,str);
    stringstream in_ss(str);
    string command_tye;
    in_ss >> command_tye;
    if (command_tye == "exit") {
      break;
    }else if (command_tye == "topology") {
      while(in_ss >> str) {
        int s,d,c;
        string temp;
        stringstream ss(str);
        getline(ss, temp, '-');
        s = stoi(temp);
        getline(ss, temp, '-');
        d = stoi(temp);
        getline(ss, temp, '-');
        c = stoi(temp);
        ss.clear();
        // cout << s << '\t' << d << '\t' << c << '\n';
        input.push_back({s,d,c});
      }      
      status = g.init(input);
      if (status == Status::ERROR) {
        cout << "Error" << endl;
      } else {
        cout << "OK" << endl;
      }
      
    }else if (command_tye == "show") {
      g.print();
    }else if (command_tye == "modify") {
      int s,d,c;
      string temp;
      getline(in_ss, temp, '-');
      s = stoi(temp);
      getline(in_ss, temp, '-');
      d = stoi(temp);
      getline(in_ss, temp, '-');
      c = stoi(temp);
    }else if (command_tye == "remove") {
      
    }else if (command_tye == "lsrp") {
      
    }else if (command_tye == "bgp") {
      
    }else if (command_tye == "dvrp") {
      
    }else {
      cout << "Error: " << str << " is not a valid command line" << endl; 
    } 
    in_ss.clear();
  }
} 

void print_menu() {
  cout << "****************commands****************" << endl;
  cout << "topology <s>-<d>-<c> <s>-<d>-<c> ..." << endl;
  cout << "show" << endl;
  cout << "modify <s>-<d>-<c>" << endl;
  cout << "remove <s>-<d>" << endl;
  cout << "bgp <source>" << endl;
  cout << "lsrp <source>" << endl;
  cout << "dvrp <source>" << endl;
  cout << "type exit for terminate" << endl;
}