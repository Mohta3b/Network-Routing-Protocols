#include <vector>
#include <iostream>
#include <string>
#include <map>
// pair
#include <utility>
#define INFINITY 999999
#define SPACE_LENGTH 6
using namespace std;

enum Status
{
  OK,
  ERROR,
  NOT_EXIST
};

void print_space(int num)
{
  if (num < 0)
  {
    cout << " ";
    return;
  }
  for (size_t i = 0; i < num; i++)
  {
    /* code */
    cout << ' ';
  }
}

class Graph
{
private:
  // make mapping from the node value to the corresponding index in adjacency list
  map<int, int> nodes;
  // vector of destination,cost pairs for each node
  vector<map<int, int>> adj_nodes;

public:
  void print();
  Status init(vector<vector<int>> input);
  Status modify(vector<int> const &input);
  Status remove(vector<int> const &input);
  void lsrp(int source = -1);
  void dijkstra(int source);
  void print_iteration(int iter,map<int, int> distance);
  void print_lsrp(int source, map<int, int> distance, map<int, int> previous);

  void dvrp(int source = -1);
  void bellman_ford(int source);
  void print_dvrp(map<int, int> distance, map<int, int> previous);

};

// 1-2-19 1-3-9 2-4-3 2-5-3 2-6-4 7-5-4 4-5-3 7-6-4
// s-d-c
void Graph::print()
{
  cout << "   \t| ";
  for (auto it : nodes)
  {
    cout << it.first;
    print_space(SPACE_LENGTH - to_string(it.first).size());
  }
  cout << "\n==============================================" << endl;
  for (auto it : nodes)
  {
    // 3 = maximum number of digits;
    cout << it.first;
    print_space(3 - to_string(it.first).size());
    cout << "\t| ";
    for (auto it1 : nodes)
    {
      if (it.first == it1.first)
      {
        cout << '0';
        print_space(SPACE_LENGTH - 1);
      }
      else
      {
        int distance = (adj_nodes[it.second].find(it1.first) != adj_nodes[it.second].end())
                           ? adj_nodes[it.second][it1.first]
                           : -1;
        cout << distance;
        print_space(SPACE_LENGTH - to_string(distance).size());
        // cout << adj_nodes[it.second].first << " " << adj_nodes[it.second][j].second << '\t';
      }
    }
    cout << endl;
  }
  cout << endl;
}

Status Graph::init(vector<vector<int>> input)
{
  adj_nodes = vector<map<int, int>>(input.size());
  nodes.clear();
  int counter = 0;
  for (size_t i = 0; i < input.size(); i++)
  {
    // check no duplucate
    if (input[i][0] == input[i][1])
    {
      adj_nodes = vector<map<int, int>>(input.size());
      nodes.clear();
      return Status::ERROR;
    }
    // find in map
    if (nodes.find(input[i][0]) == nodes.end())
    {
      nodes.insert({input[i][0], counter++});
    }
    if (nodes.find(input[i][1]) == nodes.end())
    {
      nodes.insert({input[i][1], counter++});
    }
    int index_s = nodes[input[i][0]];
    int index_d = nodes[input[i][1]];
    adj_nodes[index_s].insert({input[i][1], input[i][2]});
    adj_nodes[index_d].insert({input[i][0], input[i][2]});
  }
  return Status::OK;
}

Status Graph::modify(vector<int> const &input)
{
  // if any node does not exist --> error
  //  if (nodes.find(input[0]) == nodes.end() || nodes.find(input[1]) == nodes.end())
  //  {
  //    return Status::NOT_EXIST;
  //  }

  //  maybe we can add new node with this command:
  if (input[0] == input[1])
  {
    return Status::ERROR;
  }
  if (nodes.find(input[0]) == nodes.end())
  {
    nodes[input[0]] = adj_nodes.size();
    adj_nodes.push_back(map<int, int>());
  }
  if (nodes.find(input[1]) == nodes.end())
  {
    nodes[input[1]] = adj_nodes.size();
    adj_nodes.push_back(map<int, int>());
  }
  int index_s = nodes[input[0]];
  int index_d = nodes[input[1]];

  adj_nodes[index_s][input[1]] = input[2];
  adj_nodes[index_d][input[0]] = input[2];
  return Status::OK;
}

Status Graph::remove(vector<int> const &input)
{
  if (nodes.find(input[0]) == nodes.end() || nodes.find(input[1]) == nodes.end())
  {
    return Status::NOT_EXIST;
  }
  int index_s = nodes[input[0]];
  int index_d = nodes[input[1]];
  if (adj_nodes[index_s].find(input[1]) == adj_nodes[index_s].end()) {
    return Status::NOT_EXIST;
  }
  // cout << adj_nodes[index_s].size();
  adj_nodes[index_s].erase(input[1]);
  // cout << adj_nodes[index_s].size();
  adj_nodes[index_d].erase(input[0]);

  // if(adj_nodes[index_s].find(input[1]) == adj_nodes[index_s].end()) {
  //   cout << "yes" << endl;
  // }
  // we can delete a node if it doesn't have any neighbour, using map.size() == 0;
  return Status::OK;
}
