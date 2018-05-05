#include "Search_tree.hpp"
#include <cmath>

void STree::add(const & Field f){
	pq.push(std::make_pair(f,heuristic(f)+f.depth));
}

int STree::heuristic(const & Field f){
	int sum=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			sum+=abs(f[i][j]/N -i)+abs(f[i][j]%N-j);
	return sum;
}

void STree::compute(){
	priority_queue<int,vector<int>, std::greater<int>> poz;
	
	poz.push(pq.top()[pq.top().w_locw-1][pq.top().w_loch]);
	poz.push(pq.top()[pq.top().w_locw+1][pq.top().w_loch]);
	poz.push(pq.top()[pq.top().w_locw][pq.top().w_loch-1]);
	poz.push(pq.top()[pq.top().w_locw][pq.top().w_loch+1]);

	for(int i=0;i<N;i++)
	{
		Field f(pq.top());
		f.move(poz.top());
		f.depth++;
		add(f);
		poz.pop();
	}
	pq.pop();
}

