#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <fstream>
#include <chrono>

#include "graph.hpp"

#define TOPOLOGY "topology"
#define SHOW "show"
#define MODIFY "modify"
#define REMOVE "remove"
#define BGP "bgp"
#define LSRP "lsrp"
#define DVRP "dvrp"
#define EXIT "exit"

using namespace std;

void PressEntertoContinue()
{
  // stay in this fution until user type Enter
  cout << "Press Enter to continue...";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  // clear screen
  // it's wierd, Idon't know why, but it doesn't work.
  system("cls"); // windows
  // system("clear"); // linux

}
vector<string> get_space_seprated_str(string str)
{
  stringstream ss(str);
  vector<string> result;
  while(ss >> str) {
    result.push_back(str);
  }
  return result;
}
vector<int> get_dash_seperated_int(string input, int num_of_int)
{
  vector<int> result;
  stringstream ss(input);
  string temp;
  for (size_t i = 0; i < num_of_int; i++)
  {
    getline(ss, temp, '-');
    result.push_back(stoi(temp));
  }
  return result;
}

bool get_input(Graph &networkGraph)
{
  string command;
  cin >> command;
  if (command == EXIT)
  {
    return false;
  }
  else if (command == TOPOLOGY)
  {
    string str;
    vector<vector<int>> input;
    getline(cin, str);
    vector<string> params;
    params = get_space_seprated_str(str);
    for (size_t i = 0; i < params.size(); i++)
    {
      /* code */
      input.push_back(get_dash_seperated_int(params[i], 3));
    }
    Status status = networkGraph.init(input);
    if (status == Status::ERROR)
    {
      cout << "Error: source and destination node can NOT be identical!" << endl;
    }
    else
    {
      cout << "Done!" << endl;
    }
  }
  else if (command == SHOW)
  {
    networkGraph.print();
  }
  else if (command == MODIFY)
  {
    string str;
    vector<int> input;
    getline(cin, str);
    vector<string> params;
    params = get_space_seprated_str(str);
    str = params[0];
    input = get_dash_seperated_int(str, 3);

    Status status = networkGraph.modify(input);
    if (status == Status::ERROR)
    {
      cout << "Error: source and destination node can NOT be identical!" << endl;
    }
    else
    {
      cout << "Done!" << endl;
    }
  }
  else if (command == REMOVE)
  {
    string str;
    vector<int> input;
    getline(cin, str);
    vector<string> params;
    params = get_space_seprated_str(str);
    str = params[0];
    input = get_dash_seperated_int(str, 2);

    Status status = networkGraph.modify(input);
    if (status == Status::ERROR)
    {
      cout << "Error: source and destination node can NOT be identical!" << endl;
    }
    else
    {
      cout << "Done!" << endl;
    }
  }
  else if (command == BGP)
  {
  }
  else if (command == LSRP)
  {
  }
  else if (command == DVRP)
  {
  }
  else
  {
    cout << "Error: " << command << " is not a valid command line" << endl;
  }
  return true;
}

// input should be in this format:
// <s1>-<d1>-<c1> <s2>-<d2>-<c2>
// 1-2-19 1-3-9 2-4-3 2-5-3 2-6-4 7-5-4 4-5-3 7-6-4
int main()
{
  Graph networkGraph;
  while (get_input(networkGraph))
  {
    PressEntertoContinue();
  }
}

void print_menu()
{
  cout << "****************commands****************" << endl;
  cout << "topology <s1>-<d1>-<c1> <s2>-<d2>-<c2> ..." << endl;
  cout << "show" << endl;
  cout << "modify <s>-<d>-<c>" << endl;
  cout << "remove <s>-<d>" << endl;
  cout << "bgp <source>" << endl;
  cout << "lsrp <source>" << endl;
  cout << "dvrp <source>" << endl;
  cout << "type exit for terminate" << endl;
}