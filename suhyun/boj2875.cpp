/*2875 ����or��ȸ: �����ؾ��ϴ� �ο� �־����� �ִ� �� ���� */
#include<iostream>

using namespace std;

int main(){
	int n, m, k;
	
	cin >> n >> m >>k;
	
	while(k!=0){
		
		if(n>=m*2){	//���л� ���Ͻ����� ����
			k--;
			n--;
		}
		else{ 		//���л� ���� 
			k--;
			m--;
		}
	}
	cout << (n>=m*2? m: n/2); 	//�ִ� �� ���� ���ϱ� 
}
