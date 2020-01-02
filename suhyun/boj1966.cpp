/*1966 ������ť: queue���� ������ �߿䵵 ����Ͽ� �μ� ���� ���ϱ� */
#include <iostream>
#include <queue>

using namespace std;

int main(){
	
	int testCase;
	cin >> testCase;
	
	for(int i=0;i<testCase;i++){
		
		int N, M;	//N���� ���� �� M��° ���� 
		cin >> N >> M;	
		
		priority_queue <int> imp;	
		queue <pair<int, int> > q;	//(�ε���, �߿䵵)�� ��  
		
		int val;
		for(int j=0;j<N;j++){
			cin >> val;	
			imp.push(val);
			q.push(pair<int,int>(j, val));
		}
		
		int index=0;	//�˰���� ������ ��¼��� 
		while(!q.empty()){
			if(imp.top()== q.front().second){	//���� ������ �߿䵵 ���� ū���� ��� 
				index++;
				if(q.front().first == M)	break; 	//M��° ������ while ���� 
				imp.pop();
				q.pop();
			}
			else{	//������ ������ �߿䵵 �� ū ���: �Ǿ� ������ �ڿ� push 
				int tmp_idx, tmp_val;
				tmp_idx=q.front().first;
				tmp_val=q.front().second;
				q.pop();
				q.push(pair<int,int>(tmp_idx, tmp_val));
			}
			
		}
		cout << index<<endl;	
	}
}
