# pragma once
# include <iostream>
# include <vector>
# include <stdlib.h>
# include <math.h>

using std::vector; 
using std::copy;
using std::cout;
using std::endl;

//reference http://www.ibm.com/developerworks/cn/linux/other/l-neural/index.html


template<class ValueType>
class TAN_TLU {
  protected:
    vector<ValueType> input;
    double weight;
    double storeweight;
    double storebestweight;
  public:
    TAN_TLU(){
      randomState();
    }
    TAN_TLU* Input(vector<ValueType> input){
      this->input=input;
      return this;
    }
    ValueType Output() const{
      ValueType output=0;
      for(const auto& in : this->input){
        output+=in*weight;
      }
      return output;
    }
    TAN_TLU* setWeight(double weight){
      this->weight=weight;
    }
    double getWeight() const{
      return this->weight;
    }
    double storeState(){
      this->storeweight=weight;
      return weight;
    }
    double restoreState(){
      this->weight=this->storeweight;
      return weight;
    }
    double storeBestState(){
      this->storebestweight=weight;
      return weight;
    }
    double restoreBestState(){
      this->weight=this->storebestweight;
      return weight;
    }
    double randomState(){
      this->weight= (random()%1000)/1000.0;
      return weight;
    }
};

template<class ValueType>
class Layer{
  public:
    //Calc & Output
    vector<ValueType> Output() const{
      vector<ValueType> output;
      for(const auto& node : nodes){
        output.push_back(node->Input(this->input)->Output());
      }
      return output;
    }
    //Set Input Value
    Layer* Input(vector<ValueType>& input){
      this->input=input;
      return this;
    }

    Layer* addNodes(int num){
      for(int i=0;i<num;++i)
        this->nodes.push_back(new TAN_TLU<double>());
      return this;
    }

    Layer* randomState(){
      for(const auto& node : nodes) node->randomState();
      return this;
    }

    Layer* storeState(){
      for(const auto& node : nodes) node->storeState();
      return this;
    }
    Layer* restoreState(){
      for(const auto& node : nodes) node->restoreState();
      return this;
    }
    Layer* storeBestState(){
      for(const auto& node : nodes) node->storeBestState();
      return this;
    }
    Layer* restoreBestState(){
      for(const auto& node : nodes) node->restoreBestState();
      return this;
    }
  protected:
    vector<TAN_TLU<ValueType>*> nodes;
    vector<ValueType> input;
};


// neurl Network
template <class ValueType>
class NetWork{
  public:
    NetWork* addLayer(Layer<ValueType>* layer){
      layers.push_back(layer);
      return this;
    }

    void begin(){
      this->begintrain=true;
      this->minerror=999;
      this->lasterror=999;
    }

    //训练方法,次数越多网络训练效果越好(or not)
    NetWork* train(vector<ValueType> &input,vector<ValueType> &output){
      //精读
      const double peruse = 0.01;
      // 最大循环次数
      int nmax = 100;
      //本次误差
      int error = 0;

      do{

        //保存原始状态
        for(const auto layer : layers) layer->storeState();
        //随机状态
        for(const auto layer : layers) layer->randomState();
        //获取随机状态输出
        vector<ValueType> tmp_output = this->Input(input);

        //计算本次误差
        for(int i=0; i<tmp_output.size() ; ++i){
          error+= fabs(output[i]-tmp_output[i]);
        }

        if( error < lasterror ){
          //误差减小
          this->lasterror = error;
        }else{
          //误差增大
          if(random()%200>180){
            this->lasterror = error;
          }else{
            //恢复原始状态
            for(const auto layer : layers) layer->restoreState();
          }
        }

        if(error < this->minerror){
          for(const auto layer : layers) layer->storeBestState();
        }

      }while( error > peruse && nmax--);

      return this;
    }

    void end(){
      this->begintrain=false;
      for(const auto layer : layers) layer->restoreBestState();
    }


    //输入神经网络得出结果
    vector<ValueType> Input(vector<ValueType>& input){
      auto raw_input =  input;
      for(const auto& layer : layers){
        raw_input = layer->Input(raw_input)->Output();
      }
      return raw_input;
    }

    int Length() const {
      return layers.size();
    }
  protected:
    vector<Layer<ValueType>*> layers;
    bool begintrain;
    double minerror=999;
    double lasterror = 999;
};
