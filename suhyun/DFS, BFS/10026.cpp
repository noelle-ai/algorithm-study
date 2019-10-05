/*10026 ���ϻ���: RGB�׸����� ���ϻ����� ����� �׷��� ���� ��� �������� ������ �� ���ϱ�*/
#include <iostream>
using namespace std;

int N;
bool visited[101][101];
char pic[101][101];

int x0[4] = {-1, 1, 0, 0};
int y0[4] = {0, 0, -1, 1};

void DFS(int x, int y){
	visited[x][y]  = true;
	
	//�����¿�� ���� ���� ������ Ž�� 
	for(int i=0;i<4;i++){
		int dx = x+x0[i];
		int dy = y+y0[i];
		if(dx>=0&& dx<N && dy>=0 && dy<N){
			if(pic[x][y]==pic[dx][dy] &&!visited[dx][dy])	 
				DFS(dx,dy);
		}	
	}
	
}

int main(){
	
	int size;
	cin >> size;
	
	N = size;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> pic[i][j];
			visited[i][j]=false;
		}
	}
		
	//���ϻ��� �ƴ� ��� ������ ���� Ž��	
	int cnt=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!visited[i][j]){
				DFS(i,j);
				cnt++;	
			}
		}	
	}
	cout << cnt <<" ";
	
	//R->G�� ���� �� visited�迭 �ʱ�ȭ
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			visited[i][j] =false;
			if(pic[i][j]=='R') pic[i][j]='G';
		}
			
 
	//���ϻ����� ��� ������ ���� Ž��	
	cnt=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!visited[i][j]){
				DFS(i,j);
				cnt++;	
			}
		}	
	}
		
	cout << cnt;
			
}
