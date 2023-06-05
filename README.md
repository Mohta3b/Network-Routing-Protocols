# Routing Protocols in Network


- [Commands](#commands)
    - [Topology](#topology)
        - [Setup Topology](#setup-topology)
        - [Modify Cost](#modify-cost) 
        - [Remove Link](#remove-link)
        - [Show Topology](#show-topology) 
    - [Protocols](#protocols)
        - [Border Gateway(BGP)](#border-gateway)
        - [Link State Routing(LSR)](#link-state)
        - [Distance Vector Routing(DVR)](#distance-vector)
    
- [How to use?](#how-to-use)


## Commands

### Topology
By running the following commands, you can setup a topology, modify the cost of a link, remove a link, and show the topology.

#### Setup Topology
```topology``` command is used to setup a topology. It takes source node, destination node, and cost as arguments. 
```text
topology <s1>-<d1>-<c1> <s2>-<d2>-<c2> ...
```
If setup is successful, it will print `Done!` message.
Sample output:
<p align="center">
<img src="">
</p>

#### Modify Cost
```modify``` command is used to modify the cost of a link. It takes source node, destination node, and cost as arguments. If there is no link between source and destination, a new link will be created. 
```text
modify <s>-<d>-<c>
```
***Note:*** Source node and destination node can NOT be identical. 
Sample output:
<p align="center">
<img src="">
</p>

#### Remove Link
```remove``` command is used to remove a link. It takes source node and destination node as arguments. 
```text
remove <s>-<d>
```
Sample output:
<p align="center">
<img src="">
</p>

#### Show Topology
```show``` command is used to show the topology. It takes no arguments. 
```text
show
```
<p align="center">
<img src="">
</p>

### Protocols
By running the following commands, you can run a protocol and show the routing table.

#### Border Gateway
```bgp``` command is used to run Border Gateway Protocol. It takes no arguments. 
```text
bgp
```

#### Link State
```lsr``` command is used to run Link State Routing Protocol. You can specify the source node. If you don't specify the source node, it will run for all nodes. 
```text
lsrp <source>
```
<p align="center">
<img src="">
</p>

#### Distance Vector
```dvrp``` command is used to run Distance Vector Routing Protocol. You can specify the source node. If you don't specify the source node, it will run for all nodes. 
```text
dvrp <source>
```
<p align="center">
<img src="">
</p>

### How to use?
You can run the following commands to run the program.
```text
make
./main.out
```
