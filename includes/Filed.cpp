//@@ -0,0 +1,99 @@
#include "Field.hpp"

Field::Field():domain_(N),matr_(N,vector<int>(N)){

  	//dummy
  	matr_={{1,6,3,4},
		   {5,2,7,8},
		   {9,12,10,11},
		   {13,14,15,0}}; 

	// matr_={{15,2,1,12},
	// 	   {8,5,6,11},
	// 	   {4,9,10,7},
	// 	   {3,14,13,0}}; 
  	
  	w_locw=3;
  	w_loch=3;
  	depth=5;
  	move_=n;
  	parent=-1;
  }
 Field::Field(const Field & f):domain_(N),matr_(N,vector<int>(N)),w_loch(f.w_loch),w_locw(f.w_locw),depth(f.depth),move_(f.move_){

 	for(int i=0;i<N;i++)
 		for(int j=0;j<N;j++)
 			matr_[i][j]=f.matr_[i][j];
 }
int Field::size()
  {
  	return matr_.size()*matr_[1].size();
  }
const vector<int> & Field::operator [](int i) const{
  	if(i<N)
  	{
  		return matr_[i];
  	}
}
void Field::move(int nr,int par)
{
	parent=par;
	if(w_locw-1>0)
		if(matr_[w_locw-1][w_loch]==nr)
		{
			matr_[w_locw-1][w_loch]=0;
			matr_[w_locw][w_loch]=nr;
			w_locw--;
			move_=l;
			return ;
		}

	if(w_locw+1<N)
		if(matr_[w_locw+1][w_loch]==nr)
		{
			matr_[w_locw+1][w_loch]=0;
			matr_[w_locw][w_loch]=nr;
			w_locw++;
			move_=r;
			return ;
		}

	if(w_loch-1>0)
		if(matr_[w_locw][w_loch-1]==nr)
		{
			matr_[w_locw][w_loch-1]=0;
			matr_[w_locw][w_loch]=nr;
			w_loch--;
			move_=d;
			return ;
		}

	if(w_loch+1<N)
		if(matr_[w_locw][w_loch+1]==nr)
		{
			matr_[w_locw][w_loch+1]=0;
			matr_[w_locw][w_loch]=nr;
			w_loch++;
			move_=u;
			return ;
		}

}

bool Field::check_solution() const{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
				if(matr_[i][j]!=(i*N+(j+1))%16)
					return false;
return true;
}
