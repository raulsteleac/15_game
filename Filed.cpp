@@ -0,0 +1,99 @@
#include "Field.hpp"

Field::Field():domain_(4),matr_(4,vector<int>(4)){

  	//dummy

  	matr_[0][0]=15;
  	matr_[0][1]=2;
  	matr_[0][2]=1;
  	matr_[0][3]=12;

  	matr_[1][0]=8;
  	matr_[1][1]=5;
  	matr_[1][2]=6;
  	matr_[1][3]=11;

  	matr_[2][0]=4;
  	matr_[2][1]=9;
  	matr_[2][2]=10;
  	matr_[2][3]=7;

  	matr_[3][0]=3;
  	matr_[3][1]=14;
  	matr_[3][2]=13;
  	matr_[3][3]=0;

  	w_locw=3;
  	w_loch=3;

  }
int Field::size()
  {
  	return matr_.size()*matr_[1].size();
  }
vector<int> & Field::operator [](int i){
  	if(i<4)
  	{
  		return matr_[i];
  	}
}
void Field::move(int nr)
{
	if(w_locw-1>0)
		if(matr_[w_locw-1][w_loch]==nr)
		{
			matr_[w_locw-1][w_loch]=0;
			matr_[w_locw][w_loch]=nr;
			w_locw--;
			return ;
		}

	if(w_locw+1<n)
		if(matr_[w_locw+1][w_loch]==nr)
		{
			matr_[w_locw+1][w_loch]=0;
			matr_[w_locw][w_loch]=nr;
			w_locw++;
			return ;
		}

	if(w_loch-1>0)
		if(matr_[w_locw][w_loch-1]==nr)
		{
			matr_[w_locw][w_loch-1]=0;
			matr_[w_locw][w_loch]=nr;
			w_loch--;
			return ;
		}

	if(w_loch+1<n)
		if(matr_[w_locw][w_loch+1]==nr)
		{
			matr_[w_locw][w_loch+1]=0;
			matr_[w_locw][w_loch]=nr;
			w_loch++;
			return ;
		}

	cout<<"Alegere gresita \n\n\n";
}

bool Field::check_solution()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
				if(matr_[i][j]!=(i*4+(j+1))%16)
					return false;
return false;
}


int main()
{

Field f;
cout<<f[3][0]<<endl;
cout<<f.check_solution()<<endl;

}