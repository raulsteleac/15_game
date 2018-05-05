//@@ -0,0 +1,26 @@
#ifndef _FIELD_HPP_

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
enum moves {n,u,d,l,r};
class Field{

vector<vector <int> > matr_;
int domain_;


public:
  Field();
  Field(const & Field f);
  int size();
  vector<int> &operator [](int i);
  void move(int nr);
  bool check_solution();
  int w_locw;
  int w_loch;
  int depth;
  moves move_;
  int parent;
};



#endif