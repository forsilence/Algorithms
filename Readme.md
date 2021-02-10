## Algorithm

#### BaseOperation using example
> code
```c++
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
```
#### 字符串匹配算法
> BF算法 (Brute Force)  
> KMP算法  
> [StringMatch.h]
> using example  
```c++
  std::string target = "dajksdaj";
  std::string pattern = "aj";
  std::vector<std::string> diss{"mathResult","infolder/data"};
  std::string basename = "../data/";
  IO::OutBase* outBase = new IO::OutBase(1,diss,basename);
  Algorithms::StringMatch::BFAlgorithm BO(outBase);
  BO.setLevelDiscription(diss);
  BO(target,pattern);
  std::vector<std::string> nextdiss{"nexttest","KMP"};
  IO::OutBase* outBaseNext = new IO::OutBase(2,nextdiss,basename);
  Algorithms::StringMatch::KMPAlgorithm KMP(outBaseNext);
  KMP(target,pattern);
```
#### 并查集
> [UnionFind.h]  
```c++
  std::vector<int> inner{0,1,2,3,4,5,6};
  Algorithms::UnionFind::UnionFindInt ufi(inner);
  ufi.unionOperation(0,1);
  ufi.unionOperation(2,3);
  ufi.PrintOut(std::cout);
  std::cout << "*****************" << std::endl;
  ufi.unionOperation(4,3);
  ufi.PrintOut(std::cout);
  std::cout << "*****************" << std::endl;
  ufi.unionOperation(5,4);
  ufi.PrintOut(std::cout);
```