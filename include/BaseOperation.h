# if ! defined(_BASE_OPERATION_H)
# define _BASE_OPERATION_H
# include"IOFoSilence.h"
# include<iostream>
namespace Algorithms{
namespace Base{
class BaseOperator {
  public:
  BaseOperator():OutOperation(0),discriptions(){}
  BaseOperator(IO::OutBase* OutOperation):OutOperation(OutOperation),discriptions(){}
  BaseOperator& InjectOutOperation(IO::OutBase* OOperation);
  bool OutOperationExist() const;
  BaseOperator& setLevelDiscription(const std::vector<std::string>& discriptions);
  BaseOperator& setOutFileTail(std::string FileTail);
  BaseOperator& DefaultOut(const std::string str,std::string Header);
  BaseOperator& setOutType(IO::OutBase::OutType outType_);
  BaseOperator& WriteLog(std::string str , IO::OutBase::level l);
  virtual ~BaseOperator();
  private:
  std::vector<std::string> discriptions;
  IO::OutBase* OutOperation;
};
} // Base
} // Algorithms
# endif