# include <iostream>
# include <vector>
# include "./include/network.h"
# include <math.h>
# include <time.h>
# include <stdlib.h>

using std::endl;
using std::vector;
using std::cout;

int main(){

  srandom(time(0));
  NetWork<double> mynetwork;
  mynetwork.addLayer((new Layer<double>)->addNodes(1));
  mynetwork.addLayer((new Layer<double>)->addNodes(3));
  mynetwork.addLayer((new Layer<double>)->addNodes(3));
  mynetwork.addLayer((new Layer<double>)->addNodes(1));

  mynetwork.begin();
  for(int i=2;i<10000;++i){
    vector<double> in = {i*1.0};
    vector<double> out = {sqrt(i)};
    mynetwork.train(in,out);
  }
  mynetwork.end();
  cout << "forcast the function of SQRT" << endl;

  for(int i=1;i<10;++i){
    vector<double> in = { i*30.0 };
    double out = mynetwork.Input(in)[0];
    cout<<" input " << i*30 << " and output "<< out << " and error is:"<<sqrt(in[0])-out <<endl;
  }

  cout << "done"<<endl;
  return 0;
}
