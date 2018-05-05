#ifndef _SEARCH_TREE_HPP_
#include "Field.hpp"
#include <memory>
#include <queue>
#include <pair>
class STree{
	std::vector<std::pair<move,int>> v;
	std::priority_queue<std::pair<Field,int>, std::vector<std::pair<Field,int>>, 
			function<bool(const & std::pair<Field,int> const & std::pair<Field,int>)>> pq;

	public:
	STree(const & Field f):pq([](const & std::pair<Field,int> f1,const & std::pair<Field,int> f2){return f1.second<=f2.second;}))
			{
				add(f);
			}
	void add(const & Field f);
	int heuristic(const & Field f);
	void compute();
	void a_star();
};



#endif