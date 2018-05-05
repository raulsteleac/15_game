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
	int count_poz=0;
	if(w_locw-1>=0)
		{
			poz.push(pq.top()[pq.top().w_locw-1][pq.top().w_loch]);
			count_poz++;
		}
	if(w_locw+1<n) 
		{
			poz.push(pq.top()[pq.top().w_locw+1][pq.top().w_loch]);
			count_poz++;
		}
	if(w_loch-1>=0)
		{
			poz.push(pq.top()[pq.top().w_locw][pq.top().w_loch-1]);
			count_poz++;
		}
	if(w_loch+1<n)
		{
			poz.push(pq.top()[pq.top().w_locw][pq.top().w_loch+1]);
			count_poz++;
		}

	v.push_back(std::make_pair(pq.top().move_,pq.top().parent);

	for(int i=0;i<count_poz;i++)
	{
		Field f(pq.top());
		f.move(poz.top(),v.size()-1);
		f.depth++;
		add(f);
		poz.pop();
	}
	pq.pop();

}
void STree::present_solution(Field & f,int i)
{
	if(i>0)
	{
// trebe facutr ceva cu miscarile mai destept 
// si aici trene facut contra move
// dupa afisat 
// si debugging
	}
	for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
				cout<<f[i][j]<<" ";
			cout<<endl;
		}

}

void STree::a_star(){
	while(pq.top().check_solution())
	{
		compute();
	}

	
	present_solution(pq.top(),pq.top().parent)
}