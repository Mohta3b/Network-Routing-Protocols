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
<img src="https://github.com/Mohta3b/CN_CHomeworks_3/assets/86144768/dcca7a97-2e4b-4fae-8110-b974acb97a74">
</p>

#### Modify Cost
```modify``` command is used to modify the cost of a link. It takes source node, destination node, and cost as arguments. If there is no link between source and destination, a new link will be created. 
```text
modify <s>-<d>-<c>
```
***Note:*** Source node and destination node can NOT be identical. 

Sample output:
<p align="center">
<img src="https://github.com/Mohta3b/CN_CHomeworks_3/assets/86144768/ccc637ab-f7a3-4770-a20d-70c7b5012a16">
</p>

#### Remove Link
```remove``` command is used to remove a link. It takes source node and destination node as arguments. 
```text
remove <s>-<d>
```

Sample output:
<p align="center">
<img src="https://github.com/Mohta3b/CN_CHomeworks_3/assets/86144768/bfe92d5b-7c51-4747-a30e-cf0a640c81f3">
</p>

#### Show Topology
```show``` command is used to show the topology. It takes no arguments. 
```text
show
```

Sample output:
<p align="center">
<img src="https://github.com/Mohta3b/CN_CHomeworks_3/assets/86144768/c03f075a-1aa6-425b-86ef-00cce8753dfd">
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

Sample output for input '5':
<p align="center">
<img src="https://github.com/Mohta3b/CN_CHomeworks_3/assets/86144768/3457d9fa-4006-4675-991f-7f78b3dffbf6">
</p>
<p align="center">
<img src="https://github.com/Mohta3b/CN_CHomeworks_3/assets/86144768/1842562a-3753-4242-8c2d-aa0cbcbaf2e1">
</p>

#### Distance Vector
```dvrp``` command is used to run Distance Vector Routing Protocol. You can specify the source node. If you don't specify the source node, it will run for all nodes. 
```text
dvrp <source>
```

Sample output for input '5':
<p align="center">
<img src="https://github.com/Mohta3b/CN_CHomeworks_3/assets/86144768/94cbd7f8-96fe-42b6-b470-d067b8bb9f1d">
</p>

Sample output for all nodes:
<p align="center">
<img src="https://github.com/Mohta3b/CN_CHomeworks_3/assets/86144768/8805323b-f134-46a9-a475-96b2ffb1e2bc">
</p>
<p align="center">
<img src="https://github.com/Mohta3b/CN_CHomeworks_3/assets/86144768/ed341ed4-f59b-4efc-bf3d-bc87b70b11c6">
</p>


### How to use?
You can run the following commands to run the program.
```text
make
./main.out
```
