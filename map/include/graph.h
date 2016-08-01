# pragma once

# include <map>
# include <vector>
# include <iostream>
# include <set>


using std::map;
using std::vector;
using std::copy;


class GraphNode{
  public:
    GraphNode(int value=0):intvalue(value){
    }
    ~GraphNode(){
      for(const auto& pair : weights)
        delete pair.first;
    }

    int value() const {
      return intvalue;
    }

    GraphNode* addEdge(GraphNode* other,int weight){
      weights[other]=weight;
      return this;
    }

    vector<GraphNode*> Nodes() const {
      vector<GraphNode*> temp;
      for(const auto& pairs : weights) temp.push_back(pairs.first);
      return temp;
    }

    int Weight(GraphNode* node) const{
      return weights.at(node);
    }

  protected:
    int intvalue;
    map<GraphNode*,int> weights;
};

