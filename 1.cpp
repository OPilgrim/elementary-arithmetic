 //����һ���������û��Բ���������ĳ���
//��Ҫ�û�������������������д�𰸣��������ʾ��ȷ����


#include<iostream>
#include<cstdlib>
#include<time.h>
#include<cstring>
using namespace std;
//�����Ż�
void Menu()
{
	cout<< "---------------------------------------------------------------------------------\n" << endl;
	cout<< "*****************Please enter number to chioce your language:****************\n" << endl;
	cout<< "*******      1:Chinese  2:English  3:Japanese  4:Franch  5:German       **********\n" << endl;
	cout<< "---------------------------------------------------------------------------------\n\n" << endl;

}
//�ı�����
void lang(int a,int b)
{
	FILE *p;
	if(a==1) p=fopen("Chinese.txt","r");
	if(a==2) p=fopen("English.txt","r");
	if(a==3) p=fopen("Japanese.txt","r");
	if(a==4) p=fopen("Franch.txt","r");
	if(a==5) p=fopen("German.txt","r");
	int line=1;
	char StrLine[100];
	while(!feof(p))
	{
		if(line==b)
		{
			fgets(StrLine,100,p);
		    cout<< "\n" << StrLine << endl;
		}
		fgets(StrLine,100,p);
		line++;
	}
	fclose(p);
	
}

//�ṹ�壬��ţ������������
struct symble
{
	int _num;
	char _sym;
	int level;
}sym[4]={{0,'+',1},{1,'-',1},{2,'*',2},{3,'/',2}};

//�ṹ�壬ǰ����Ƿ��ӣ�������Ƿ�ĸ
struct frac
{
	int member;
	int deno;
};


//�������㺯�������˳���
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
	}
}





//�������
frac print_1(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	frac result;
	cout<< on << sym[c_1]._sym << tw << sym[c_2]._sym << th << sym[c_3]._sym << fo << "=" << endl;
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)     
	{ 
		result.member=complex(sym[c_3]._num,complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),th),fo);
		result.deno=0;
	}
	else
	{
		if(sym[c_2].level==1) {result.member=complex(sym[c_2]._num,on,tw*complex(sym[c_3]._num,th,fo)); result.deno=tw;}
		else if(sym[c_3].level==1)
		{
			if(sym[c_1]._num==3 && sym[c_2]._num==3) {result.member=complex(sym[c_3]._num,on,tw*th*fo); result.deno=th*fo;}
			else if(sym[c_1]._num==3 && sym[c_2]._num==2) {result.member=complex(sym[c_3]._num,on*th,fo*tw); result.deno=tw;}
			else {result.member=complex(sym[c_3]._num,on*tw,fo); result.deno=th;}
		}
		else
		{
			if(sym[c_1]._num==3)
			{
				if(sym[c_2]._num==3)
				{
					if(sym[c_3]._num==3) {result.member=on; result.deno=tw*th*fo;}
					else {result.member=on*fo; result.deno=tw*th;}
				}
				else
				{
					if(sym[c_3]._num==3) {result.member=on*th; result.deno=tw*fo;}
					else {result.member=on*th*fo; result.deno=tw;}
				}
			}
			else
			{
				if(sym[c_2]._num==3)
				{
					if(sym[c_3]._num==3) {result.member=on*tw; result.deno=th*fo;}
					else {result.member=on*tw*fo; result.deno=th;}
				}
				else {result.member=on*tw*th; result.deno=fo;}
			}
		}
	}
	return result;
}

frac print_1_1(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	frac result;
	cout<< on << sym[c_1]._sym << tw << sym[c_2]._sym << th << sym[c_3]._sym << fo << "=" << endl;
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_3]._num,complex(sym[c_1]._num,on,complex(sym[c_2]._num,tw,th)),fo);
		result.deno=0;
	}
    else
	{
		result.member=complex(sym[c_1]._num,complex(sym[c_3]._num,on,fo)*th,tw);
		result.deno=th;
	}
	return result;
}
frac print_1_2(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	frac result;
	cout<< on << sym[c_1]._sym << tw << sym[c_2]._sym << th << sym[c_3]._sym << fo << "=" << endl;
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),complex(sym[c_3]._num,th,fo));
		result.deno=0;
	}
	else
	{
		result.member=complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw)*fo,th);
		result.deno=fo;
	}
	return result;
}
frac print_1_3(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)     //                                    
{
	frac result;
	cout<< on << sym[c_1]._sym << tw << sym[c_2]._sym << th << sym[c_3]._sym << fo << "=" << endl;
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{	
		result.member=complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),complex(sym[c_3]._num,th,fo));
		result.deno=0;
	}
	else
	{
		if(sym[c_1]._num==3 && sym[c_3]._num==3) {result.member=complex(sym[c_2]._num,on*fo,tw*th); result.deno=tw*fo;}
		else 
			if(sym[c_1]._num==3 && sym[c_3]._num==2) { result.member=complex(sym[c_2]._num,on,th*fo*tw); result.deno=tw;}
			else { result.member=complex(sym[c_2]._num,on*tw*fo,th); result.deno=fo;}
	}

	return result;
}
frac print_1_4(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)       //                                    
{
	frac result;
	cout<< on << sym[c_1]._sym << tw << sym[c_2]._sym << th << sym[c_3]._sym << fo << "=" <<endl;
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_1]._num,on,complex(sym[c_3]._num,complex(sym[c_2]._num,tw,th),fo));
		result.deno=0;
	}
	else
	{
		if(sym[c_2]._num==3 && sym[c_3]._num==3) { result.member=complex(sym[c_1]._num,on*th*fo,tw); result.deno=fo*th;}
		else
			if(sym[c_2]._num==3 && sym[c_3]._num==2) { result.member=complex(sym[c_1]._num,on*th,tw*fo); result.deno=th;}
			else { result.member=complex(sym[c_1]._num,on*fo,tw*th); result.deno=fo;}
	}
	return result;
}
frac print_2(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)               // 
{
    frac result;
	cout<< on << sym[c_1]._sym << "(" << tw <<sym[c_2]._sym <<th << ")" << sym[c_3]._sym << fo << "=" << endl;
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_3]._num,complex(sym[c_1]._num,on,complex(sym[c_2]._num,tw,th)),fo);
		result.deno=0;
	}
	else
	{
		if(sym[c_3].level==1) {result.member=complex(sym[c_3]._num,on,fo*complex(sym[c_2]._num,tw,th)); result.deno=complex(sym[c_2]._num,tw,th);}
		else
			if(sym[c_1]._num==3 && sym[c_3]._num==3) {result.member=on; result.deno=complex(sym[c_2]._num,tw,th)*fo;}
			else 
				if(sym[c_1]._num==3 && sym[c_3]._num==2) { result.member=on*fo;result.deno=complex(sym[c_2]._num,tw,th);}
				else {result.member=on*complex(sym[c_2]._num,tw,th); result.deno=fo;}
	}
	return result;
}
frac print_2_1(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)                            
{
    frac result;
	cout<< on << sym[c_1]._sym << "(" << tw << sym[c_2]._sym << th << ")" << sym[c_3]._sym << fo << "=" <<endl;
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_1]._num,on,complex(sym[c_3]._num,complex(sym[c_2]._num,tw,th),fo));
		result.deno=0;
	}
	else
	{
		result.member=complex(sym[c_1]._num,on*fo,complex(sym[c_2]._num,tw,th));
		result.deno=fo;
	}

	return result;
}
frac print_3(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	frac result;
	cout<< on << sym[c_1]._sym << "(" <<tw << sym[c_2]._sym << th << sym[c_3]._sym << fo << ") =" << endl;
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_1]._num,on,complex(sym[c_3]._num,complex(sym[c_2]._num,tw,th),fo));
		result.deno=0;
	}
	else
	{
			result.member=on;
			result.deno=complex(sym[c_3]._num,complex(sym[c_2]._num,tw,th),fo);
	}
	return result;
}
frac print_4(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)
{
	frac result;
	cout<< "(" << on << sym[c_1]._sym << tw << ")" << sym[c_2]._sym << "(" <<th << sym[c_3]._sym << fo << ") =" << endl;
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),complex(sym[c_3]._num,th,fo));
		result.deno=0;
	}
	else
	{
		result.member=complex(sym[c_1]._num,on,tw);
		result.deno=complex(sym[c_3]._num,th,fo);
	}

	return result;
}
frac print_5(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)            //
{
	frac result;
	cout<< on << sym[c_1]._sym << tw << sym[c_2]._sym << "(" << th << sym[c_3]._sym << fo << ") =" <<endl;
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),complex(sym[c_3]._num,th,fo));
		result.deno=0;
	}
	else
	{
		if(sym[c_1]._num==3 && sym[c_2]._num==3) {result.member=on; result.deno=tw*complex(sym[c_3]._num,th,fo); }
		else
			if(sym[c_1]._num==3 && sym[c_2]._num==2) {result.member=on*complex(sym[c_3]._num,th,fo); result.deno=tw;}
			else { result.member=on*tw; result.deno=complex(sym[c_2]._num,th,fo);}
	}
	return result;
}
frac print_6(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)            //
{
    frac result;
	cout<< "(" << on<< sym[c_1]._sym << tw << sym[c_2]._sym << th << ")" << sym[c_3]._sym << fo << "=" << endl;
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_3]._num,complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),th),fo);
		result.deno=0;
	}
	else
	{
		if(sym[c_1]._num==3 && sym[c_3]._num==3) {result.member=complex(sym[c_2]._num,on,tw*th); result.deno=tw*fo;}
		else
			if(sym[c_1]._num==3 && sym[c_3]._num==2) {result.member=fo*complex(sym[c_2]._num,on,tw*th); result.deno=tw;}
			else { result.member=complex(sym[c_2]._num,on*tw,th); result.deno=fo;}
	}
	return result;
}
frac print_7(int c_1,int c_2,int c_3,int on,int tw,int th,int fo)              //
{
	frac result;
	cout<< "(" << on << sym[c_1]._sym << tw << ")" << sym[c_2]._sym << th << sym[c_3]._sym << fo << "=" << endl;
	if(sym[c_1]._num!=3 && sym[c_2]._num!=3 && sym[c_3]._num!=3)
	{
		result.member=complex(sym[c_3]._num,complex(sym[c_2]._num,complex(sym[c_1]._num,on,tw),th),fo);
		result.deno=0;
	
	}
	else
	{
		if(sym[c_2]._num==3 && sym[c_3]._num==3) {result.member=complex(sym[c_1]._num,on,tw); result.deno=th*fo;}
		else 
			if(sym[c_2]._num==3 && sym[c_3]._num==2) {result.member=fo*complex(sym[c_1]._num,on,tw); result.deno=th;}
			else {result.member=th*complex(sym[c_1]._num,on,tw); result.deno=fo;}
	}
	return result;
}



//������
frac judge(frac t)
{
	int x,y,z;
	if(t.deno!=0 && t.member!=0)
	{
		x=t.member>t.deno ? t.member : t.deno;
		y=t.member<=t.deno ? t.member : t.deno;
		while(y!=0)
		{
			z=x;
			x=y;
			y=z%y;
		}
		t.member=t.member/x;
		t.deno=t.deno/x;
		t.deno=(t.deno==1)? 0 : t.deno;
		return t;
	}
	else 
		if(t.member==0) {t.deno=0;  return t;}
    	else
	    	return t;

}

//�ӷֺ���
int sco(frac result)
{
	int me,de,answer;   //���ӣ���ĸ���û�������
	char ch;   //����
	if(result.deno!=0)  //�����Ƿ�ʽ
	{
		cin>>me;
		cin>>ch;
		cin>>de;
		if(me==result.member && de==result.deno && ch=='/')
		{
			cout<<"R\n"<<endl;
			return(1);
		}
		else
		{
			cout<<"W\n"<<endl;
			return(0);
		}
	}
	else               //����������
	{
		cin>>answer;
		if(answer==result.member)
		{
			cout<<"R\n"<<endl;
			return(1);
		}
		else
		{
			cout<<"W\n"<<endl;
			return(0);
		}
	}
}

 

//operation������������������ʲô��ʽ��
int operation(int score)
{
	frac sum_int;   //����ṹ
	srand((unsigned)time(0));   //���������
	int one=rand()%10+1,two=rand()%10+1,three=rand()%10+1,four=rand()%10+1;
	int chioce_1=rand()%4,chioce_2=rand()%4,chioce_3=rand()%4;           //������������
	if(sym[chioce_1].level==sym[chioce_2].level&&sym[chioce_2].level==sym[chioce_3].level)    //����һ�������
	{
		sum_int=judge(print_1(chioce_1,chioce_2,chioce_3,one,two,three,four));                
		score+=sco(sum_int);         
	}
	else if(sym[chioce_1].level>sym[chioce_2].level&&sym[chioce_2].level==sym[chioce_3].level)  //������һ����һ�������
	{
		switch(rand()%3) 
		{
		case 0:sum_int=judge(print_1(chioce_1,chioce_2,chioce_3,one,two,three,four));          
			break;
		case 1:sum_int=judge(print_2(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		case 2:sum_int=judge(print_3(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		}
		score+=sco(sum_int);
	}
	else if(sym[chioce_2].level>sym[chioce_1].level&&sym[chioce_1].level==sym[chioce_3].level)  //һ����������һ�������
	{
		switch(rand()%2)
		{
		case 0:sum_int=judge(print_1_1(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		case 1:sum_int=judge(print_4(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		}
		score+=sco(sum_int);
	}
		else if(sym[chioce_3].level>sym[chioce_2].level&&sym[chioce_2].level==sym[chioce_1].level)  //һ����һ�������������
	{
		switch(rand()%3)
		{
		case 0:sum_int=judge(print_1_2(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		case 1:sum_int=judge(print_2_1(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		case 2:sum_int=judge(print_6(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		}
		score+=sco(sum_int);
	}
	else if(sym[chioce_1].level==sym[chioce_2].level&&sym[chioce_2].level>sym[chioce_3].level)  //������������һ�������
	{
		switch(rand()%2)
		{
		case 0:sum_int=judge(print_1(chioce_1,chioce_2,chioce_3,one,two,three,four));         
			break;
		case 1:sum_int=judge(print_5(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		}
		score+=sco(sum_int);
	}
	else if(sym[chioce_1].level>sym[chioce_2].level&&sym[chioce_1].level==sym[chioce_3].level)  //������һ�������������
	{
		switch(rand()%3)
		{
		case 0:sum_int=judge(print_1_3(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		case 1:sum_int=judge(print_2(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		case 2:sum_int=judge(print_6(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		}
		score+=sco(sum_int);
	}
	else if(sym[chioce_1].level>sym[chioce_2].level&&sym[chioce_2].level==sym[chioce_3].level)  //һ�������������������
	{
		switch(rand()%2)
		{
		case 0:sum_int=judge(print_1_4(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		case 1:sum_int=judge(print_7(chioce_1,chioce_2,chioce_3,one,two,three,four));
			break;
		}
		score+=sco(sum_int);
	}
	return score;
}


//������
int main()
{
	int i;
	int number;//�û���������
	int Q,score;
	Menu();
	cin>>Q;
	for(;Q<1||Q>5;)
    {
    	cout<<"The language is beyond our ability, please try again.\n"<<endl;
    	cin>>Q; 
    }
	do
	{
			score=0;  //�Ʒ�
			/*printf("��������������Ĵ���ȷ���������R,��������W\n");*/
			lang(Q,1);
			/*printf("������������");*/ 
			lang(Q,2);
			cin>>number;
			for(i=0;i<number;i++)
				score=operation(score);//���㺯��
			/*printf("�����%d��\n",score);  */
			lang(Q,3); 
			cout<<score;
			/*printf("���%d��\n",number-score);*/
			lang(Q,4); 
			cout<<number-score;
			getchar();
			/*printf("�����밴����������������롰e����");*/
			lang(Q,5);
	    	if(getchar()=='e')//�û�����e�ɽ�������
		    	break;
	}while(1);
/*	if(Q=='C')
	{
		do
		{
			int score=0;  //�Ʒ�
			printf("��������������Ĵ���ȷ���������R,��������W\n");
			printf("������������");
			scanf("%d",&number);
			for(i=0;i<number;i++)
				score=operation(score);//���㺯��
			printf("�����%d��\n",score);
			printf("���%d��\n",number-score);
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
			printf("The next,if your answer is right, you will see R,otherwise, you will see W\n");
			printf("Please input number��");
			scanf("%d",&number);
			for(i=0;i<number;i++)
				score=operation(score);//���㺯��
			printf("Correct answer��s number are��%d\n",score);
			printf("Wrong answer��s number are��%d\n",number-score);
			getchar();
			printf("Please press any key to continue,input 'e'to end��");
	    	if(getchar()=='e')//�û�����e�ɽ�������
		    	break;
		}while(1);
	}
	*/
	return 0;
}