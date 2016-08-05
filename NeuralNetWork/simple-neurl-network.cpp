# include <iostream>
# include <vector>
# include "./include/network.h"
# include <math.h>

using std::endl;
using std::vector;
using std::cout;

int main(){
  NetWork<double> mynetwork;
  mynetwork.addLayer((new Layer<double>)->addNodes(1));
  mynetwork.addLayer((new Layer<double>)->addNodes(6));
  mynetwork.addLayer((new Layer<double>)->addNodes(5));
  mynetwork.addLayer((new Layer<double>)->addNodes(1));

  mynetwork.begin();
  for(int i=0;i<1000;++i){
    vector<double> in = {i*1.0};
    vector<double> out = {sqrt(i)};
    mynetwork.train(in,out);
  }
  mynetwork.end();

  for(int i=0;i<10;++i){
    vector<double> in = { i*30.0 };
    cout<<" input " << i*30 << " and output "<< mynetwork.Input(in)[0]<<endl;
  }
  return 0;
}
