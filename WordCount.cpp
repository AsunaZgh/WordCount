#include<stdio.h>
#include<string.h>
#include<stdlib.h>



//获取字符数 
void count_char(char* fileName){
	int sum=0;
	char ch;
	FILE* fp;
	fp=fopen(fileName,"r");
	
	if(fp==NULL){
		printf("Can't open this file");
		exit(1);
	}
	
	//调用函数获取字符并字符数加一 
	while((ch=fgetc(fp))!=EOF){
		sum++;
	}
	printf("字符数:%d",sum);
}


//获取单词数 
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
	
	//思路： 
	//标志位为1时遇到非空格非逗号的字符时，单词数加1并且标志位置为0 
	//标志位为0时遇到非空格非逗号的字符时，单词数不改变 
	//当遇到空格或逗号时符号位置为1 
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
	printf("单词数:%d",sum);
}

//主函数 
int main(int argc, char* argv[]) { 
	char *model = argv[1];//获取模式
	char *fileName = argv[2];//获取文件名 
	char Wmodel[] = { '-','w','\0' };
	char Cmodel[] = { '-','c','\0' };
	
	//判断选择的模式，并调用对应的方法 
	if (strcmp(model, Wmodel) == 0) {
		count_word(fileName); 
	}else if (strcmp(model, Cmodel) == 0) {
		count_char(fileName);
	}else{
		printf("Can't find this model"); 
	}
	return 0;
}
