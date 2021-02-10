# if !defined (BASE_SORT_H)
# define BASE_SORT_H
# include"BaseOperation.h"
namespace Algorithms{
namespace BaseSort{
class BubbleSort: public Base::BaseOperator{
  public:
  BubbleSort():Base::BaseOperator(){}
  BubbleSort(IO::OutBase* OutOperation): Base::BaseOperator(OutOperation){}
  std::vector<int> operator()(std::vector<int> array);
};

class SelectSort: public Base::BaseOperator{
  public:
  SelectSort(): Base::BaseOperator(){}
  SelectSort(IO::OutBase* OutOperation): Base::BaseOperator(OutOperation){}
  std::vector<int> operator()(std::vector<int> array);
};

class QuikSort: public Base::BaseOperator{
  public:
  QuikSort(): Base::BaseOperator(){}
  QuikSort(IO::OutBase* OutOperation): Base::BaseOperator(OutOperation){}
  std::vector<int> operator()(std::vector<int> array);
  void realQuikSort(std::vector<int>& array, int start, int end);
  int Partition(std::vector<int>& array,int start ,int end);
};
} // BaseSort
} // Algorithms
# endif