#include "Search_tree.hpp"
#include <cmath>

void STree::add(Field & f){
	pq.push(std::make_pair(f,heuristic(f)+f.depth));
}

int STree::heuristic(Field & f){
	int sum=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			sum+=abs(f[i][j]/N -i)+abs(f[i][j]%N-j);
	return sum;
}

void STree::compute(){
	std::priority_queue<int,std::vector<int>, std::greater<int>> poz;
	int count_poz=0;
	if(pq.top().first.w_locw-1>=0)
		{
			poz.push(pq.top().first[pq.top().first.w_locw-1][pq.top().first.w_loch]);
			count_poz++;
		}
	if(pq.top().first.w_locw+1<N) 
		{
			poz.push(pq.top().first[pq.top().first.w_locw+1][pq.top().first.w_loch]);
			count_poz++;
		}
	if(pq.top().first.w_loch-1>=0)
		{
			poz.push(pq.top().first[pq.top().first.w_locw][pq.top().first.w_loch-1]);
			count_poz++;
		}
	if(pq.top().first.w_loch+1<N)
		{
			poz.push(pq.top().first[pq.top().first.w_locw][pq.top().first.w_loch+1]);
			count_poz++;
		}

	v.push_back(std::make_pair(pq.top().first.move_,pq.top().first.parent));

	for(int i=0;i<count_poz;i++)
	{
		Field f(pq.top().first);
		cout<<"XXXXXXXXXXXXXXX : "<<poz.top()<<endl;
		f.move(poz.top(),v.size()-1);
		f.depth*=2;
		add(f);
		poz.pop();
	}
	pq.pop();

}
/*void STree::present_solution(Field & f,int i)
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
*/
void STree::a_star(){
	while(!pq.top().first.check_solution())
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
				cout<<pq.top().first[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
		cout<<endl;
		cout<<endl;
		compute();
	}
	cout<<"SOLUTIE: "<<endl;
	for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
				cout<<pq.top().first[i][j]<<" ";
			cout<<endl;
		}
	
	//present_solution(pq.top(),pq.top().parent)
}