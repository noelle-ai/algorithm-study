/*�Ҿ���� ��ȣ: ��ȣ�ļ� ���� �� �ּҷ� �����*/
#include <iostream>
using namespace std;


int main(){
	string s;
	cin >> s;
	
	int flag = 0, res=0, num=0;
	int i=0;
	while(i!=s.length()){
		
		//���� ���� 
		if('0' <= s[i] && '9'>= s[i]) {
			int tmp = s[i]-'0';
			num = num*10 +tmp;
		}
		else{ //������ 
			
			if(flag == 0 ) res += num;	//���̳ʽ� �ȸ��� 
			else res -=num; //���̳ʽ� ���� ���� 
			
			if (s[i]=='-' && flag ==0) {	//���̳ʽ� ó�� ���� 
				flag = 1;
			}
			
			num = 0; //�ӽ� ���� �ʱ�ȭ 
		}
		i++;
	}
	
	//������ �� ����
	if(flag==0) res+=num;
	else res -=num;
	
	cout<<res;
}
