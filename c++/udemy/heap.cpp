#include <vector>
using namespace std;
class Heap{
private:
  vector<int> heap;
  int leftchile(int index){
    return 2*index;
  }
  int rightchild(int index){
    return 2*index+1;
  }
  int  parent(int index)
{
    return index/2;
  }
};
