#include<stdio.h>
#include<string.h>
#include<stdlib.h>



//��ȡ�ַ��� 
void count_char(char* fileName){
	int sum=0;
	char ch;
	FILE* fp;
	fp=fopen(fileName,"r");
	
	if(fp==NULL){
		printf("Can't open this file");
		exit(1);
	}
	
	//���ú�����ȡ�ַ����ַ�����һ 
	while((ch=fgetc(fp))!=EOF){
		sum++;
	}
	printf("�ַ���:%d",sum);
}


//��ȡ������ 
void count_word(char*fileName){
	int sum=0;
	char ch;
	int flag=1; 
	FILE* fp;
	fp=fopen(fileName,"r");
	
	if(fp==NULL){
		printf("Can't open this file");
		exit(1);
	}
	
	//˼·�� 
	//��־λΪ1ʱ�����ǿո�Ƕ��ŵ��ַ�ʱ����������1���ұ�־λ��Ϊ0 
	//��־λΪ0ʱ�����ǿո�Ƕ��ŵ��ַ�ʱ�����������ı� 
	//�������ո�򶺺�ʱ����λ��Ϊ1 
	while((ch=fgetc(fp))!=EOF){ 
		if(ch==' '||ch==','){
			flag=1;
		}
		else{
			if(flag==1){
				flag=0;
				sum++;
			}
		}
	}
	printf("������:%d",sum);
}

//������ 
int main(int argc, char* argv[]) { 
	char *model = argv[1];//��ȡģʽ
	char *fileName = argv[2];//��ȡ�ļ��� 
	char Wmodel[] = { '-','w','\0' };
	char Cmodel[] = { '-','c','\0' };
	
	//�ж�ѡ���ģʽ�������ö�Ӧ�ķ��� 
	if (strcmp(model, Wmodel) == 0) {
		count_word(fileName); 
	}else if (strcmp(model, Cmodel) == 0) {
		count_char(fileName);
	}else{
		printf("Can't find this model"); 
	}
	return 0;
}
