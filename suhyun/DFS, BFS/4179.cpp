/*4179 ��!: 1�ʿ� ���� �׹������� Ȯ��ǰ� ���� ��ĭ ������ ��, �̷� Ż���ϴ� ���� ���� Ż��ð�*/
#include <iostream> 
#include <queue>
#define MAX 1001
using namespace std;

bool visited[MAX][MAX];
char map[MAX][MAX];

int R, C;
queue <pair<int, int> > fire, jh;
int x0[4] = {-1, 1, 0, 0};
int y0[4] = {0, 0, -1, 1};

int moveBFS(){
	
	int sec=0;
	
	while(!jh.empty()){
		int size = fire.size();
		for(int i=0;i<size;i++){ 	//��� �� ��ġ���� ���� 
			
			int y = fire.front().first;
			int x = fire.front().second;
			fire.pop();
			
			for(int j=0;j<4;j++){	// �����¿� Ȯ�� 
				int dx = x+x0[j];
				int dy = y+y0[j];
				if(dx>=0&& dx<C && dy>=0 && dy<R && (map[dy][dx]=='.'||map[dy][dx]=='J')){	
				//if�� ���� ���ǿ��� map[dy][dx]!='#' �� �־��µ�, �������� ��?? 
					map[dy][dx]='F';
					fire.push(pair<int,int>(dy, dx));
				}
			}
		}
			
			
		size = jh.size();
		for(int i=0;i<size;i++){ 	
			int y = jh.front().first;
			int x = jh.front().second;
			jh.pop();
			
			for(int j=0;j<4;j++){	// �����¿�� �̵��õ� 
				int dx = x+x0[j];
				int dy = y+y0[j];
		
				//Ż�� ���� ���� 
				if((dx<0 || dx>=C || dy<0 || dy>=R)){	
					return sec+1;
				}
				if(!visited[dy][dx]&&map[dy][dx]=='.'){	//�湮���� ����, ������ �� �ִ� ���̸�  
					jh.push(pair<int,int>(dy, dx));
					visited[dy][dx] = true;
					map[dy][dx]='J';
				}
				
			}
		}
		sec++;
	}
	return -1;
}

int main(){
	
	cin >> R >> C;
	
	for(int i=0; i<R;i++){
		for(int j=0;j<C;j++){
			cin >> map[i][j];
			visited[i][j] = false;
			
			if(map[i][j]=='J'){
				jh.push(pair<int,int>(i,j));
				visited[i][j] = true;
			}
			else if (map[i][j]=='F'){
				fire.push(pair<int,int>(i,j));
			}
		}
	}
	
	int result = moveBFS();
	if(result == -1)
		cout << "IMPOSSIBLE";
	else
		cout << result; 
			
}
