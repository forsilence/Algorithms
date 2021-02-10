# include"../include/UnionFind.h"
namespace Algorithms{
namespace UnionFind{

int UnionFindInt::find(int v){
  if ( v >= 0 && v < innerArray.size()){
    if ( innerArray[v] == v ){
      return v;
    }else{
      return find(innerArray[v]);
    }
  }
  return -1;
}

bool UnionFindInt::isSame(int a , int b ){
  return find(a) == find(b);
}

bool UnionFindInt::findingFailed(int v){
  return v == -1;
}

void UnionFindInt::unionOperation( int a, int b){
  if (find(a) == find(b)){
    return ;
  }else{
    if (!isRoot(b)){
      alterToRoot(b);
    }
    innerArray[b] = a;
  }
}

void UnionFindInt::alterToRoot( int v){
  int root = find(v);
  int cur_v = v;
  int parent = innerArray[cur_v];
  while( cur_v != root){
    int temp = innerArray[parent];
    innerArray[parent] = cur_v;
    cur_v = parent;
    parent = temp;
  }
}

std::ostream& UnionFindInt::PrintOut(std::ostream& Print){
  for (int loc=0; loc < innerArray.size(); ++loc){
    Print << loc << " parent " << innerArray[loc] << std::endl;
  }
  return Print;
}

bool UnionFindInt::isRoot( int v){
  return innerArray[v] == v;
}

void UnionFindInt::setUnionFind(std::size_t size_){
  innerArray.clear();
  for (int i=0; i< size_; ++i){
    innerArray.push_back(i);
  }
}
} // UnionFind
} // Algorithms