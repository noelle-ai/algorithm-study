#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int n1, n2;
	int total = 153; //��ü ����Ǽ� 
	int numOfCase=0, digit; //����� ��, ���� �����ڸ� 
	
	cin >> n1 >> n2;
	
	if(n1==n2){	//���� ��� 
		numOfCase = 143+n1;
	}
	else{
		digit = (n1+n2)%10; //���� �����ڸ� 
		
		for(int i=1;i<=10;i++){
			for(int j=1;j<=10;j++){
				if( (i<j) && ((i+j)%10 < digit)){	
					
					if(i==n1 || i==n2 || j==n1 || j==n2) //�̹� ���� �Ͱ� �ߺ��Ǵ� ��� 
						numOfCase+=2;
						
					else
						numOfCase+=4;
				}
			}
		}
	}
	printf("%.3f", (float)numOfCase/total);
	
}
