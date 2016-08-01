# include <iostream>
# include "./include/tree-node.h"
# include <time.h>
# include <stdlib.h>


void sort_output(TREE_NODE* head){
  if(head->left()) sort_output(head->left());
  std::cout<<head->value()<<" ";
  if(head->right()) sort_output(head->right());
}

int main(){

  const int n=10;

  //init random seed
  srand(time(0));

  TREE_NODE* head=NULL;
  for(int i=0;i<n;++i){
    int value=random()%255;
    std::cout<<value<<" ";

    if(!head) head=new TREE_NODE(value);
    else head->insert(new TREE_NODE(value));
  }
  std::cout<<std::endl;

  sort_output(head);

  std::cout<<std::endl;

  std::cout<<"---------sort over ----------"<<std::endl;



  return 0;
}
