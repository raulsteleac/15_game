//@@ -0,0 +1,26 @@
#ifndef _FIELD_HPP_

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
class Field{

vector<vector <int> > matr_;
int domain_;
int w_locw;
int w_loch;

public:
  Field();
  int size();
  vector<int> &operator [](int i);
  void move(int nr);
  bool check_solution();

};



#endif