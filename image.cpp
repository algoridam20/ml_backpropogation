#include <bits/stdc++.h>
using namespace std; 

vector<long> v ;
int cyx=0;


int main(void)
{
	int i, j;
	char d;
	int N, M, Q;		// N=Rows   M=Cols   Q=GreyLevels
	cout << "INPUT image file: ? ";
	v.reserve(1005);
	string s ;
	cin >> s ; 			// name of input file
	
	//	ReadImage

	ifstream ifp;

	ifp.open(s.c_str(), ios::binary);

	char header [100], *ptr;

	if (!ifp)
	{
		cout << "Can't read image: <" << s << '>' << endl;
		//getch();
		exit(1);
	}

	ifp.getline(header,100,'\n');
	if((header[0]!='P') || header[1]!='5')   // 'P5' Forma 
	{
		cout << "Image <" << s << "> is not in binary PGM 'P5' format." << endl;
		//getch();
		exit(1);
	}

		ifp.getline(header,100,'\n');
		while(header[0]=='#')
		ifp.getline(header,100,'\n');


	M=strtol(header,&ptr,0);
	N=atoi(ptr);

	ifp.getline(header,100,'\n');

	Q=strtol(header,&ptr,0);

	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			d = ifp.get();

			v[cyx++]=(long)d;
			cout << (long)d << endl;
		}
	}




	cout << endl << cyx << endl << endl ; 
	return  0 ;
}