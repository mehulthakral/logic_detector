class Solution {
public:
	vector<vector<char>> B;
	bool isValid(int x, int y, char c){
		for(int i=0;i<9;i++){
			if(B[x][i]==c) return false;
		}

		for(int i=0;i<9;i++){
			if(B[i][y]==c) return false;
		}

		int a=(x/3)*3;
		int b=(y/3)*3;
		for(int i=a;i<a+3;i++){
			for(int j=b;j<b+3;j++){
				if(B[i][j]==c){
					return false;
				}
			}
		}



		return true;
	}

	bool backtrack(int x, int y){
		int nextR=-1;
		int nextC=-1;

		bool flag=false;
		bool flag2=false;
		for(int i=y+1;i<9;i++){
			if(B[x][i]=='.'){
				nextR=x;
				nextC=i;
				flag=true;
				break;
			}
		}
		if(!flag){
			for(int i=x+1;i<9;i++){
				for(int j=0;j<9;j++){
					if(B[i][j]=='.'){
						nextR=i;
						nextC=j;
						flag2=true;
						break;
					}
				}
				if(flag2){
					break;
				}
			}
		}




		for(int i=1;i<=9;i++){
			char temp='0'+i;
			if(isValid(x,y,temp)){
				B[x][y]=temp;
				if(nextR==-1) return true;
				bool res=backtrack(nextR,nextC);
				if(res) return true;
				B[x][y]='.'; 



			}
		}

		return false;
	}
	void solveSudoku(vector<vector<char>>& board) {
		B=board;
		int startX;
		int startY;
		bool stop=false;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(B[i][j]=='.'){
					startX=i;
					startY=j;
					stop=true;
					break;
				}
			}
			if(stop){
				break;
			}
		}

		backtrack(startX,startY);
		board=B;
	}
};