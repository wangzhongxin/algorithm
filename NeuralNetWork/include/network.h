# include <iostream>
# include <vector>

using std::vector; 
using std::copy;


class NNode{
};

template<class ValueType>
class NLayer<ValueType>{
  public:
    NLayer(){
    }
    vector<ValueType> output(){
    }
    NLayer* input(vector<ValueType>& input){
      copy(input.begin(),input.end(),internal_input.begin());
    }

  protected:
    vector<ValueType> internal_input;
};

// neurl Network
class NetWork{
  public:
    NetWork* addLayer(NLayer* layer){
      layers.push_back(layer);
    }

    int Length() const {
      return layers.size();
    }
  protected:
    vector<NLayer*> layers;
};
