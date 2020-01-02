/*1918 ���� ǥ���: ����ǥ���-> ����ǥ������� ��ȯ */
#include <iostream>
#include <stack>
using namespace std;

int getPriority(char op){	
	if(op=='(' ) return 0;
	else if(op=='+' || op=='-') return 1;
	else return 2;
}

int main(){
	
	string s;
	cin >> s;
	
	stack <char> op;
	
	for(int i=0 ; i<s.length(); i++){
		
		if(s[i] =='('){ 	//1. ���ʰ�ȣ�� push 
			op.push(s.at(i));
		}
		else if(s[i] ==')'){	 //2. ���� ��ȣ ���ö����� pop 
			while(op.top()!='('){	
				cout << op.top();
				op.pop();
			}
			if(op.top()=='(') op.pop(); 	
		}
		else if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'){	//3. �������ϰ�� push 
			
			while(!op.empty() && (getPriority(s.at(i))<=getPriority(op.top())) ){	//3-����: ������ ���� �켱���� ���ų� ������ ���������� pop
				cout << op.top();
				op.pop();
			}
			op.push(s.at(i));
		}
		else // �ǿ�����(A~Z)�� �ٷ� ��� 
			cout << s[i] ;
	}
	
	while(!op.empty()){ 	//������ ������ ������ ��� 
		cout << op.top();
		op.pop();
	}
	return 0;
}

