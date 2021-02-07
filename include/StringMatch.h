# if !defined(_BFALGORITHM_H)
# define _BFALGORITHM_H
# include"BaseOperation.h"
namespace Algorithms{
namespace StringMatch{
class BFAlgorithm: public Base::BaseOperator{
  public:
  BFAlgorithm():Base::BaseOperator(){}
  BFAlgorithm(IO::OutBase* OutOperation):Base::BaseOperator(OutOperation){}
  std::vector<int> operator()(std::string targetStr,std::string patternStr);
};

class KMPAlgorithm: public Base::BaseOperator{
  public:
  KMPAlgorithm():Base::BaseOperator(){}
  KMPAlgorithm(IO::OutBase* OutOperation):Base::BaseOperator(OutOperation){}
  std::vector<int> operator()(std::string targetStr,std::string patternStr);
  std::vector<int> next(std::string str);
};
}
} // Algorithms
# endif