# include"../include/BaseOperation.h"
namespace Algorithms{
namespace Base{
BaseOperator& BaseOperator::InjectOutOperation(IO::OutBase* OOperation){
  if(OutOperationExist()){
    delete OutOperation;
    OutOperation = 0;
  }
  OutOperation = OOperation;
  return *this;
}

bool BaseOperator::OutOperationExist() const{
  return OutOperation!=0;
}

BaseOperator& BaseOperator::setLevelDiscription(const std::vector<std::string>& discriptions_){
  if(OutOperationExist()){
    OutOperation->setLevelDiscription(discriptions_);
  }
  discriptions = discriptions_;
  return *this;
}

BaseOperator& BaseOperator::setOutFileTail(std::string FileTail){
  if(OutOperationExist()){
    OutOperation->setOutFileTail(FileTail);
  }
  return *this;
}

BaseOperator& BaseOperator::DefaultOut(const std::string str,std::string Header){
  std::cout << "[" << Header << "] " << str << std::endl;
  return *this;
}

BaseOperator& BaseOperator::setOutType(IO::OutBase::OutType outType_){
  OutOperation->setOutType(outType_);
  return *this;
}

BaseOperator& BaseOperator::WriteLog(std::string str , IO::OutBase::level l){
  if(OutOperationExist()){
    OutOperation->Out(str,l);
  }else{
    std::string Header("");
    try{
      Header = discriptions[l-1];
    }catch(std::out_of_range e){
      Header = "";
    }
    DefaultOut(str,Header);
  }
  return *this;
}

BaseOperator::~BaseOperator(){
  discriptions.~vector();
  if(OutOperationExist()){
    delete OutOperation;
  }
}
} // Base
} // Algorithms