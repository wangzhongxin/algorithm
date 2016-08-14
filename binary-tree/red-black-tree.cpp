# include <iostream>
# include "./include/red-black-node.h"
# include "./include/dot.h"

using std::cout;
using std::endl;

int main(){
  red_black_node<int>* root=NULL;
  int array[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,0};

  for(int i: array){
    if(!root) root=new red_black_node<int>(i,BLACK);
    else root = root->insert(new red_black_node<int>(i,RED));
  }

  //then we will print this tree
  createDotFile("mydot.dot",root);

  cout << "done!" <<endl;

  return 0;
}
