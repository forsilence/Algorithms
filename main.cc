# include<iostream>
# include<string>
# include"../include/BaseOperation.h"
int main(){
  std::vector<std::string> diss{"log","infolder/data"};
  std::string basename = "../data/";
  IO::OutBase* outBase = new IO::OutBase(2,diss,basename);
  Algorithms::Base::BaseOperator BO(outBase);
  BO.setOutType(IO::OutBase::outToFile);
  BO.setLevelDiscription(diss);
  IO::OutBase::level l = 1;
  for(int i=0; i<100 ;++i){
    if(i==50){
      l += 1;
    }
    BO.WriteLog(std::to_string(i),l);
  }
  return 0;
}