//����һ���������û��Բ���������ĳ���
//��Ҫ�û�������������������д�𰸣��������ʾ��ȷ����


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//�ṹ�壬��ţ������������
struct symble
{
	int _num;
	char _sym;
	int level;
}sym[4]={{0,'+',1},{1,'-',1},{2,'*',2},{3,'/',2}};


int chu(int a,int b)//����
{
	if(b!=0)
		return a/b;
	else
		return (0);
}

//�������㺯��
int complex(int num,int a,int b)
{
	switch (num) 
	{
case 0:return a+b;
	break;
case 1:return a-b;	
	break;
case 2:return a*b;
	break;
case 3:return chu(a,b);	
	break;
	}
}

//�������
int print_1(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	int result;
	printf("%d %c %d %c %d %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	result=complex(sym[c_3]._num,complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),th),fo);
	return result;
}
int print_1_1(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	int result;
	printf("%d %c %d %c %d %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	result=complex(sym[c_3]._num,complex(sym[c_1]._num,on,complex(sym[c_2]._num,tw,th)),fo);
	return result;
}
int print_1_2(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	int result;
	printf("%d %c %d %c %d %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	result=complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),complex(sym[c_3]._num,th,fo));
	return result;
}
int print_1_3(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	int result;
	printf("%d %c %d %c %d %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	result=complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),complex(sym[c_3]._num,th,fo));
	return result;
}
int print_1_4(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	int result;
	printf("%d %c %d %c %d %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	result=complex(sym[c_1]._num,on,complex(sym[c_3]._num,complex(sym[c_2]._num,tw,th),fo));
	return result;
}
int print_2(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
    int result;
	printf("%d %c (%d %c %d) %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	result=complex(sym[c_3]._num,complex(sym[c_1]._num,on,complex(sym[c_2]._num,tw,th)),fo);
	return result;
}
int print_2_1(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
    int result;
	printf("%d %c (%d %c %d) %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	result=complex(sym[c_1]._num,on,complex(sym[c_3]._num,complex(sym[c_2]._num,tw,th),fo));
	return result;
}
int print_3(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	int result;
	printf("%d %c (%d %c %d %c %d) = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	result=complex(sym[c_1]._num,on,complex(sym[c_3]._num,complex(sym[c_2]._num,tw,th),fo));
	return result;
}
int print_4(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	int result;
	printf("(%d %c %d) %c (%d %c %d) = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	result=complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),complex(sym[c_3]._num,th,fo));
	return result;
}
int print_5(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	int result;
	printf("%d %c %d %c (%d %c %d) = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	result=complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),complex(sym[c_3]._num,th,fo));
	return result;
}
int print_6(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
    int result;
	printf("(%d %c %d %c %d) %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	result=complex(sym[c_3]._num,complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),th),fo);
	return result;
}
int print_7(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	int result;
	printf("(%d %c %d) %c %d %c %d = ",on,sym[c_1]._sym,tw,sym[c_2]._sym,th,sym[c_3]._sym,fo);
	result=complex(sym[c_3]._num,complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),th),fo);
	return result;
}


//�ӷֺ���
int sco(int answer,int sum_int)
{
	if(answer==sum_int)
		return(10);
	else
		return(0);
}


//operation����������������ʽ��
int operation(int score)
{
	srand((unsigned)time(0));
	int answer;         //���մ�
	int one=rand()%10+1,two=rand()%10+1,three=rand()%10+1,four=rand()%10+1,sum_int;  //sum_int��������
	int chioce_1=rand()%4,chioce_2=rand()%4,chioce_3=rand()%4;           //�����������
	if(sym[chioce_1].level==sym[chioce_2].level==sym[chioce_3].level)    //���Ŷ�һ�������
	{
		sum_int=print_1(chioce_1,chioce_2,chioce_3,one,two,three,four);
		scanf("%d",&answer);
		score+=sco(answer,sum_int);
	}
	else if(sym[chioce_1].level>sym[chioce_2].level&&sym[chioce_2].level==sym[chioce_3].level)  //������һ����һ�������
	{
		switch(rand()%3)
		{
		case 0:sum_int=print_1(chioce_1,chioce_2,chioce_3,one,two,three,four);
			break;
		case 1:sum_int=print_2(chioce_1,chioce_2,chioce_3,one,two,three,four);
			break;
		case 2:sum_int=print_3(chioce_1,chioce_2,chioce_3,one,two,three,four);
			break;
		}
		scanf("%d",&answer);
		score+=sco(answer,sum_int);
	}
	else if(sym[chioce_2].level>sym[chioce_1].level&&sym[chioce_1].level==sym[chioce_3].level)  //һ����������һ�������
	{
		switch(rand()%2)
		{
		case 0:sum_int=print_1_1(chioce_1,chioce_2,chioce_3,one,two,three,four);
			break;
		case 1:sum_int=print_4(chioce_1,chioce_2,chioce_3,one,two,three,four);
			break;
		}
		scanf("%d",&answer);
		score+=sco(answer,sum_int);
	}
		else if(sym[chioce_3].level>sym[chioce_2].level&&sym[chioce_2].level==sym[chioce_1].level)  //һ����һ�������������
	{
		switch(rand()%3)
		{
		case 0:sum_int=print_1_2(chioce_1,chioce_2,chioce_3,one,two,three,four);
			break;
		case 1:sum_int=print_2_1(chioce_1,chioce_2,chioce_3,one,two,three,four);
			break;
		case 2:sum_int=print_6(chioce_1,chioce_2,chioce_3,one,two,three,four);
			break;
		}
		scanf("%d",&answer);
		score+=sco(answer,sum_int);
	}
	else if(sym[chioce_1].level==sym[chioce_2].level&&sym[chioce_2].level>sym[chioce_3].level)  //������������һ�������
	{
		switch(rand()%2)
		{
		case 0:sum_int=print_1(chioce_1,chioce_2,chioce_3,one,two,three,four);
			break;
		case 1:sum_int=print_5(chioce_1,chioce_2,chioce_3,one,two,three,four);
			break;
		}
		scanf("%d",&answer);
		score+=sco(answer,sum_int);
	}
	else if(sym[chioce_1].level>sym[chioce_2].level&&sym[chioce_1].level==sym[chioce_3].level)  //������һ�������������
	{
		switch(rand()%3)
		{
		case 0:sum_int=print_1_3(chioce_1,chioce_2,chioce_3,one,two,three,four);
			break;
		case 1:sum_int=print_2(chioce_1,chioce_2,chioce_3,one,two,three,four);
			break;
		case 2:sum_int=print_6(chioce_1,chioce_2,chioce_3,one,two,three,four);
			break;
		}
		scanf("%d",&answer);
		score+=sco(answer,sum_int);
	}
	else if(sym[chioce_1].level>sym[chioce_2].level&&sym[chioce_2].level==sym[chioce_3].level)  //һ�������������������
	{
		switch(rand()%2)
		{
		case 0:sum_int=print_1_4(chioce_1,chioce_2,chioce_3,one,two,three,four);
			break;
		case 1:sum_int=print_7(chioce_1,chioce_2,chioce_3,one,two,three,four);
			break;
		}
		scanf("%d",&answer);
		score+=sco(answer,sum_int);
	}
	return score;
}


//������
int main()
{
	int i;
	int number;//�û���������
	char Q;
	printf("���������롰C��(Please input 'E' for English) :");
	scanf("%c",&Q);
	if(Q=='C')
	{
		do
		{
			int score=0;  //�Ʒ�
			printf("������������");
			scanf("%d",&number);
			for(i=0;i<number;i++)
				score=operation(score);//���㺯��
			printf("���ĵ÷���%d��\n",score);
			getchar();
			printf("�����밴����������������롰e����");
	    	if(getchar()=='e')//�û�����e�ɽ�������
		    	break;
		}while(1);
	}
	else
	{
		do
		{
			int score=0;  //�Ʒ�
			printf("Please input number��");
			scanf("%d",&number);
			for(i=0;i<number;i++)
				score=operation(score);//���㺯��
			printf("Your score are %d\n",score);
			getchar();
			printf("Please press any key to continue,input ��e��to end��");
	    	if(getchar()=='e')//�û�����e�ɽ�������
		    	break;
		}while(1);
	}
	return 0;
}

