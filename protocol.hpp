#pragma once
#include"graph.hpp"
#include "chrono"
#include "iomanip"


  void Graph::print_iteration(int iter, map<int, int> distance)
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
    cout << "Cost\t";
    for (auto it : distance)
    {
      if (it.second == int(INFINITY))
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
    cout << endl;
    cout << "----------------" << endl;
  }

  void Graph::print_lsrp(int source, map<int, int> distance, map<int, int> previous)
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
      if (it.second == int(INFINITY))
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
      if (it.second == int(INFINITY))
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
    cout << ">> Source: " << source << endl;
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

  void Graph::lsrp(int source)
  {
    // start time
    auto start = chrono::high_resolution_clock::now();
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
      dijkstra(it);
    }
    // end time
    auto end = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    double time_taken =
        chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time taken by program is : " << time_taken << endl;
  }
  

  void Graph::print_dvrp(map<int, int> distance, map<int, int> previous)
  {
    // Dest | Next Hop | Dist | Shortest-Path
    cout << "Dest\t| Next Hop\t| Dist\t| Shortest-Path" << endl;
    cout << "-------------------------------" << endl;
    for (auto it : distance)
    {
      // Dest
      cout << it.first;
      print_space(SPACE_LENGTH - to_string(it.first).size());
      cout << "| ";
      
      // Next Hop
      if (it.second == int(INFINITY))
      {
        cout << "-1";
        print_space(SPACE_LENGTH - 2);
      }
      else
      {
        vector<int> path;
        int current = it.first;
        while (current != -1)
        {
          path.push_back(current);
          current = previous[current];
        }
        if(path.size() == 1) {
          cout << path[path.size() - 1];
          print_space(SPACE_LENGTH - to_string(path[path.size() - 1]).size());
        } else {
          cout << path[path.size() - 2];
          print_space(SPACE_LENGTH - to_string(path[path.size() - 2]).size());
        }
      }
      cout << "| ";

      // Dist
      if (it.second == int(INFINITY))
      {
        cout << "-1";
        print_space(SPACE_LENGTH - 2);
      }
      else
      {
        cout << it.second;
        print_space(SPACE_LENGTH - to_string(it.second).size());
      }
      cout << "| ";
      
      // Shortest path
      if (it.second == int(INFINITY))
      {
        cout << "No Path" << endl;
      }
      else
      {
        vector<int> path;
        int current = it.first;
        while (current != -1)
        {
          path.push_back(current);
          current = previous[current];
        }
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

  void Graph::bellman_ford(int source)
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

    for (int i = 0; i < network_size; i++)
    {
      for (auto it : nodes)
      {
        for (auto it1 : adj_nodes[nodes[it.first]])
        {
          if (distance[it1.first] > distance[it.first] + it1.second)
          {
            distance[it1.first] = distance[it.first] + it1.second;
            previous[it1.first] = it.first;
          }
        }
      }
    }
    print_dvrp(distance,previous);
  }


  void Graph::dvrp(int source)
  {
    // start time
    auto start = chrono::high_resolution_clock::now();

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
      Graph::bellman_ford(it);
    }
    
    // end time
    auto end = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    double time_taken =
        chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time taken by program is : " << time_taken << endl;

  }
