# pragma once

// this file to generator dot file by graph
//

# include <iostream>
# include <vector>
# include "./graph.h"
# include <string>
# include <fstream>

using std::vector;
using std::string;
using std::ofstream;
using std::find;
using std::endl;


bool createDotFile(vector<GraphNode*> nodes,string filename,string graphname="samplegraph",bool haveDir=false){
  vector<GraphNode*> overNodes;
  ofstream out;
  out.open(filename);

  if(!out.is_open()) return false;

  out<<(haveDir?"digraph ":"graph ")<<graphname<<"{"<<endl;

  for(const auto &node : nodes){
    if(find(overNodes.begin(),overNodes.end(),node)!=overNodes.end()) continue;
    overNodes.push_back(node);

    for(const auto& dst : node->Nodes()){
      out<<node->value()<<(haveDir?"->":" -- ")<<dst->value()<<"[label="<<node->Weight(dst)<<"];"<<endl;
    }
  }

  out<<"}";
  out.close();
  return true;
}
