/*2841 �ܰ����� ��Ÿ����: �� ���ֽ� �հ��� ���� ���� �����̴� Ƚ��*/
#include <iostream> 
#include <stack>
using namespace std;

int main(){
	
	int N, P; //N: (������)���� ��, P: ������ ��
	int cnt=0; //������ count 
	stack <int> s[7]; //�� 6��  (�ε��� 1~6 ���)
	
	cin >> N >> P;
	for(int i=0;i<N;i++) {
		int line, pret;	//���� ��ȣ, ������ ��ȣ 
		cin >> line >> pret;
			
		//�������� ������ ������ ���� �ͺ��� �� ���� case
		while (!s[line].empty()&& s[line].top() > pret) {	
			 s[line].pop();
			 cnt++;	//���� Ƚ�� count 
		}
		if(!s[line].empty()&& s[line].top() == pret) continue; //������ �ʴ� ������ case 
		
		//������ ��� case 
		cnt++;	
		s[line].push(pret);
	}
	
	cout << cnt;
}
