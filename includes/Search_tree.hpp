#ifndef _SEARCH_TREE_HPP_
#include "Field.hpp"
#include <memory>
#include <queue>
#include <utility>
#include <functional>
class compare{
public:
	bool operator()(const std::pair<Field,int> & f1,const std::pair<Field,int> & f2){
		return f1.second>f2.second;
	}
};
class STree{

	std::vector<std::pair<moves,int>> v;
	std::priority_queue<std::pair<Field,int>, std::vector<std::pair<Field,int>>, compare> pq;


	public:
	STree( Field & f)	
			{
				add(f);
			}
	void add( Field & f);
	int heuristic( Field & f);
	void compute();
	void a_star();
};



#endif