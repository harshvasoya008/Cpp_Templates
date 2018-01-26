/* Generating the Grundy array */
Grundy[0][0]=0;

int row[] = {0,-1,-1};
int col[] = {-1,0,-1};

for (int i = 0; i < 1000; ++i) {
	for (int j = 0; j < 1000; ++j){
		Hashset<int> hs;
		for (int k = 0; k < 3; ++k) {
		int x = i + row[k];
		int y = j + col[k];
		if (isValid(x,y,1000))
			hs.insert(Grundy[x][y]);
		}
		
		int Mex=0;
		while (hs.find(Mex)!=hs.end())
			Mex++;
		Grundy[i][j]=Mex;
	}
}
