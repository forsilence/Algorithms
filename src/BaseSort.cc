# include"../include/BaseSort.h"
# include<utility>
namespace Algorithms{
namespace BaseSort{
std::vector<int> BubbleSort::operator()(std::vector<int> array){
  for( int i=0; i<array.size() - 1; ++i){
    for(int j=i; j<array.size()-1; ++j){
      if (array[j] > array[j+1]){
        std::swap(array[j],array[j+1]);
      }
    }
  }
  return array;
}

std::vector<int> SelectSort::operator()(std::vector<int> array){
  int min_v = 0;
  for (int i=0; i < array.size() - 1; ++i){
    min_v = i;
    for ( int j=i; j < array.size(); ++j){
      if ( array[min_v] > array[j]){
        min_v = j;
      }
    }
    std::swap(array[min_v],array[i]);
  }
  return array;
}

std::vector<int> QuikSort::operator()(std::vector<int> array){
  auto res = array;
  realQuikSort(res ,0 ,array.size() - 1);
  return res;
}

void QuikSort::realQuikSort(std::vector<int>& array, int start, int end){
  if (start < end){
    int tmp = Partition(array ,start, end);
    realQuikSort(array, start, tmp - 1);
    realQuikSort(array, tmp + 1, end);
  }
}

int QuikSort::Partition(std::vector<int>& array,int start ,int end){
  int flag = array[end];
  int slower = start - 1;
  for (int i = start; i < end; ++i){
    if (array[i] < flag){
      std::swap(array[i],array[++slower]);
    }
  }
  std::swap(array[++slower],array[end]);
  return slower;
}

} // BaseSort
} // Algorithms