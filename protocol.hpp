#include"graph.hpp"
#include "math.h"

  void Graph::print_iteration( int iter, map<int, int> distance)
  {
    cout << "Iteration " << iter << ":" << endl;
    // cout << "Node\t| Distance" << endl;
    cout << "Dest\t";
    for (auto it : distance)
    {
      cout << it.first;
      print_space(SPACE_LENGTH - to_string(it.first).size());
      cout << "| ";
     
    }
    cout << endl;
    for (auto it : distance)
    {
      cout << "Cost\t";
      if (it.second == INFINITY)
      {
        cout << "-1";
        print_space(SPACE_LENGTH - 2);
        cout << "| ";
      }
      else
      {
        cout << it.second;
        print_space(SPACE_LENGTH - to_string(it.second).size());
        cout << "| ";
      }
      
    }
    cout << "----------------" << endl;
  }

  void print_lsrp(int source, map<int, int> distance, map<int, int> previous)
  {
    // Path [s] -> [d] | Min-Cost | Shortest-Path
    cout << "Path [s] -> [d] | Min-Cost | Shortest-Path" << endl;
    for (auto it : distance)
    {
      if (it.first == source)
      {
        continue;
      }
      cout << "[" << source << "] -> [" << it.first << "]";
      print_space(SPACE_LENGTH - to_string(it.first).size());
      cout << "| ";
      if (it.second == INFINITY)
      {
        cout << "-1";
        print_space(SPACE_LENGTH - 2);
        cout << "| ";
      }
      else
      {
        cout << it.second;
        print_space(SPACE_LENGTH - to_string(it.second).size());
        cout << "| ";
      }
      if (it.second == INFINITY)
      {
        cout << "No Path" << endl;
      }
      else
      {
        vector<int> path;
        int current = it.first;
        while (current != source)
        {
          path.push_back(current);
          current = previous[current];
        }
        path.push_back(source);
        for (int i = path.size() - 1; i >= 0; i--)
        {
          cout << path[i];
          if (i != 0)
          {
            cout << " -> ";
          }
        }
        cout << endl;
      }
    }
    

  }

  void Graph::dijkstra(int source)
  {
    int network_size = nodes.size();
    map<int, int> distance;
    for (auto it : nodes)
    {
      distance[it.first] = INFINITY;
    }
    map<int, int> previous;
    for (auto it : nodes)
    {
      previous[it.first] = -1;
    }
    map<int, bool> visited;
    for (auto it : nodes)
    {
      visited[it.first] = false;
    }

    distance[source] = 0;
    int current_index = nodes.at(source);
    int current_value = source;
    int iteration_number = 1;
    while (true)
    {
      visited[current_value] = true;
      for (auto it : adj_nodes[current_index])
      {
        if (distance[it.first] > distance[current_value] + it.second)
        {
          distance[it.first] = distance[current_value] + it.second;
          previous[it.first] = current_value;
        }
      }
      // print iteration
      print_iteration(iteration_number++, distance);

      int min = INFINITY;
      int min_index = -1;
      for (auto it : nodes)
      {
        if (visited[it.first] == false && distance[it.first] < min)
        {
          min = distance[it.first];
          min_index = it.first;
        }
      }
      if (min_index == -1)
      {
        break;
      }
      current_index = nodes.at(min_index);
      current_value = min_index;
    }
    print_lsrp(source, distance, previous);

      
  }

  void Graph::lsrp(int source=-1)
  {
    vector<int> sourceNodes;
    if (source == -1)
    {
      for (auto it : nodes)
      {
        sourceNodes.push_back(it.first);
      }
    }
    else
    {
      sourceNodes.push_back(source);
    }
    for (auto it : sourceNodes)
    {
      Graph::dijkstra(it);
    }
  }
  

  void Graph::dvrp(int source=-1)
  {



  }

  void dvrp_print() {

  }