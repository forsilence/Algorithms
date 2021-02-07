# include"../include/StringMatch.h"
namespace Algorithms{
namespace StringMatch{
std::vector<int> BFAlgorithm::operator()(std::string targetStr,std::string patternStr){
  std::vector<int> res;
  for(int i=0 ; i<targetStr.size()-patternStr.size() + 1; ++i){
    int j = 0;
    for(; j<patternStr.size(); ++j){
      if(patternStr[j]!=targetStr[i+j]){
        break;
      }
    }
    if(j==patternStr.size()){
      res.push_back(i);
      WriteLog(std::to_string(i),1);
    }
  }
  return res;
}

std::vector<int> KMPAlgorithm::operator()(std::string targetStr,std::string patternStr){
  std::vector<int> res;
  auto nextArray = next(patternStr);
  int j=0;
  for(int i=0; i<targetStr.size() - patternStr.size() + 1; ++i){
    j = nextArray[j];
    for(; j < patternStr.size(); ++j){
      if(patternStr[j]!=targetStr[i+j]){
        break;
      }
    }
    if(j==patternStr.size()){
      res.push_back(i);
      WriteLog(std::to_string(i),2);
    }
  }
  return res;
}

std::vector<int> KMPAlgorithm::next(std::string str){
  std::vector<int> res(str.size()+1,0);
  WriteLog(std::to_string(0),1);
  for(int i=1; i<=str.size(); ++i){
    int maxMatch = 0;
    int tmp = i - 1;
    for(int len=0; len < tmp + 1; ++len){
      int match=0;
      for(; match<len; ++match){
        if(str[match] != str[tmp - len + 1 + match]){
          break;
        }
      }
      if(match==len){
        maxMatch = match;
      }
    }
    res[i] = maxMatch;
    WriteLog(std::to_string(res[i]),1);
  }
  return res;
}
} // StringMatch
} // Algorithms