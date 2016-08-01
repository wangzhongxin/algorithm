# include <iostream>
# include "./include/dot.h"
# include "./include/graph.h"
# include <vector>
# include <map>
# include <algorithm>


//reference https://zh.wikipedia.org/wiki/%E6%88%B4%E5%85%8B%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::find;
using std::pair;
using std::sort;



int main(){


  GraphNode* node1=new GraphNode(1);
  GraphNode* node2=new GraphNode(2);
  GraphNode* node3=new GraphNode(3);
  GraphNode* node4=new GraphNode(4);
  GraphNode* node5=new GraphNode(5);
  GraphNode* node6=new GraphNode(6);

  node1->addEdge(node2,7);
  node1->addEdge(node3,9);
  node1->addEdge(node6,14);

  node2->addEdge(node1,7);
  node2->addEdge(node3,10);
  node2->addEdge(node4,14);

  node3->addEdge(node1,9);
  node3->addEdge(node2,10);
  node3->addEdge(node4,11);
  node3->addEdge(node6,2);

  node4->addEdge(node2,14);
  node4->addEdge(node3,11);
  node4->addEdge(node5,6);

  node5->addEdge(node4,6);
  node5->addEdge(node6,9);

  node6->addEdge(node1,14);
  node6->addEdge(node3,2);
  node6->addEdge(node5,9);

  //create dot file
  createDotFile(vector<GraphNode*>{node1,node2,node3,node4,node5,node6},"Dijkstra.dot");


  //Dijkstra node1->node5
  map<GraphNode*,int> weights;
  
  GraphNode* srcNode = node1;
  GraphNode* const dstNode = node5;

  vector<GraphNode*> overNodes;
  weights[srcNode] = 0;

  while(srcNode != dstNode){
    overNodes.push_back(srcNode);

    auto nodes=srcNode->Nodes();

    for(auto temp = nodes.begin(); temp!=nodes.end();++temp){
      if(find(overNodes.begin(),overNodes.end(),*temp)!=overNodes.end()) continue;

      int weight = srcNode->Weight(*temp);

      GraphNode* dst=*temp;

      if(weights.find(dst)==weights.end() || (weights[dst] > (weight+weights[srcNode])) ){
        weights[dst]=weight+weights[srcNode];
      }

    }

    int minWeight;
    srcNode=NULL;
    for(const auto &pair : weights){
      if(find(overNodes.begin(),overNodes.end(),pair.first)==overNodes.end()){
        if(!srcNode || minWeight>pair.second){
          srcNode=pair.first;
          minWeight=pair.second;
        }
      }
    }
  }

  cout<<"minimal path : "<<weights[dstNode]<<endl;

  return 0;
}
