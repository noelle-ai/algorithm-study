/*2164 ī��2 : ī�� ������ ������ �ű�� �ݺ��ϱ�*/
#include <iostream>
#include <queue>

using namespace std;

int main(){
	
	int N;
	queue <int> q;

	cin >> N;
	for(int i=1;i<=N;i++){
		q.push(i);
	}
	
	while(q.size()>1){
		q.pop();	//���� ���� ī�� ������
		if(q.size()==1) break;
		
		//���� ���� ī�� ���� ������ �ű�� 
		q.push(q.front()); 	
		q.pop(); 
	}
	
	cout << q.front(); //�������� ���� ī�� 
	
}
