# if !defined(UNOIN_FIND_FORSILENCE_H)
# define UNOIN_FIND_FORSILENCE_H
# include"BaseOperation.h"
# include<vector>
# include<iostream>
namespace Algorithms{
namespace UnionFind{
class UnionFindInt: public Base::BaseOperator{
  public:
  UnionFindInt(): innerArray(),Base::BaseOperator(){}
  UnionFindInt( std::vector<int> UnionFindArray):innerArray(UnionFindArray),Base::BaseOperator(){}
  UnionFindInt( std::vector<int> UnionFindArray, IO::OutBase* OutOperation): innerArray(UnionFindArray),Base::BaseOperator(OutOperation){}
  void setUnionFind(std::size_t size_);
  int find(int v);
  void unionOperation( int a , int b);
  bool isSame(int a, int b);
  bool findingFailed(int v);
  void alterToRoot(int v);
  bool isRoot(int v);
  std::ostream& PrintOut(std::ostream& Print);
  private:
  std::vector<int> innerArray;
};
} // UnionFind
} // Algorithms
#endif