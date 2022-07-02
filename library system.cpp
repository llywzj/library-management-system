#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct time{
    char year[5];
	char month[3];
	char day[3];
};
struct administrator{
	char number[10];
	char name[20];
	char password[20];
}ad;
struct reader{
	char number[10];
	char name[20];
	char book_number[10];
	struct time time1;
	struct time time2;
}rd;
struct book{
	char number[10];
	char name[20];
	char exist; 
}bk;

administrator savedAd[100];
reader savedReader[10000];
book savedBook[20000];
char str[50];
FILE *saved_ad;
FILE *saved_reader;
FILE *saved_book;
int adsum=0;
int rdsum=0;
int bksum=0;
char ad_number[10];
char rd_number[10];
char password[20];
int adnumber;
int rdnumber;
int bknumber;
char out[2]={'0','\0'}; 

void read_administrator()
{
	if ((saved_ad=fopen("D:\\Library System\\administrator.txt","r"))==NULL)
	{
		puts("Fail to open file!");
		exit(0);
	}
	while(fgets(str,50,saved_ad)!=NULL)
	{
		int i=0;
		for (;str[i]!=' ';i++) 
		{
		    savedAd[adsum].number[i]=str[i];
		    savedAd[adsum].number[i+1]='\0';
		}
		i++; 
		for (int j=0;str[i]!=' ';j++,i++)
		{
			savedAd[adsum].name[j]=str[i];
			savedAd[adsum].name[j+1]='\0';
		}
		i++; 
		for (int j=0;str[i]!='\n';j++,i++)
		{
			savedAd[adsum].password[j]=str[i];
			savedAd[adsum].password[j+1]='\0';
		}
		adsum++;
	}
	fclose(saved_ad);
}
void read_reader()
{
	if ((saved_reader=fopen("D:\\Library System\\reader.txt","r"))==NULL)
	{
		puts("Fail to open file!");
		exit(0);
	}
	while(fgets(str,50,saved_reader)!=NULL)
	{
		int i=0;
		for (;str[i]!=' ';i++) 
		{
		    savedReader[rdsum].number[i]=str[i];
		    savedReader[rdsum].number[i+1]='\0';
		}
		i++; 
		for (int j=0;str[i]!=' ';j++,i++)
		{
			savedReader[rdsum].name[j]=str[i];
			savedReader[rdsum].name[j+1]='\0';
		}
		i++; 
		for (int j=0;str[i]!=' ';j++,i++)
		{
			savedReader[rdsum].book_number[j]=str[i];
			savedReader[rdsum].book_number[j+1]='\0';
		}
		i++;
		for (int j=0;str[i]!='.';j++,i++)
		{
			savedReader[rdsum].time1.year[j]=str[i];
		}
		i++; 
		for (int j=0;str[i]!='.';j++,i++)
		{
			savedReader[rdsum].time1.month[j]=str[i];
		}
		i++; 
		for (int j=0;str[i]!='\n';j++,i++)
		{
			savedReader[rdsum].time1.day[j]=str[i];
		}
		rdsum++;
	}
	fclose(saved_reader);
}
void read_book()
{
	if ((saved_book=fopen("D:\\Library System\\book.txt","r"))==NULL)
	{
		puts("Fail to open file!");
		exit(0);
	}
	while(fgets(str,50,saved_book)!=NULL)
	{ 
		int i=0;
		for (;str[i]!=' ';i++) 
		{
		    savedBook[bksum].number[i]=str[i];
		    savedBook[bksum].number[i+1]='\0';
		}
		i++; 
		for (int j=0;str[i]!=' ';j++,i++)
		{
			savedBook[bksum].name[j]=str[i];
			savedBook[bksum].name[j+1]='\0';
		}
		i++; 
		for (int j=0;str[i]!='\n';j++,i++)
		{
			savedBook[bksum].exist=str[i];
		}
		bksum++;
	}
	fclose(saved_book);
}

int checkAdnumber()
{
	for (int i=0;i<adsum;i++)
	{
		if (strcmp(savedAd[i].number,ad_number)==0)
		{
			adnumber=i;
			return 1;
		}
	} 
	return 0;
}
int checkPassword()
{
	if (strcmp(savedAd[adnumber].password,password)==0)
	{
		return 1;
	}
	return 0;
}
int checkRdnumber()
{
	for (int i=0;i<rdsum;i++)
	{
		if (strcmp(savedReader[i].number,rd_number)==0)
		{
			rdnumber=i;
			return 1;
		}
	} 
	return 0;
}

void addBook()
{
	int c; 
	printf("---------¼��ͼ����Ϣ---------\n");
	while(1)
	{
		printf("������¼��ͼ���ţ�");
    	scanf("%s",bk.number);
	    getchar();
	    printf("������¼��ͼ�����ƣ�");
	    scanf("%s",bk.name); 
	    getchar();
	    printf("��ȷ��¼��ͼ����Ϣ��\n");
	    printf("%s %s\n",bk.number,bk.name);
	    printf("��1 ��Ϣ����\n");
		printf("��2 ��Ϣ������������\n"); 
		printf("��3 ��������\n");
		printf("�������Ӧ���֣�");
		scanf("%d",&c);
		if (c==1) 
		{
			savedBook[bksum]=bk;
			savedBook[bksum].exist='y';
			bksum++;
			printf("--------���ѳɹ�¼�룡--------\n"); 
		}
		else if (c==2) continue;
		else if (c==3) break;
		printf("�Ƿ����¼�룺\n");
		printf("��1 ����¼��\n");
		printf("��2 ���¼��\n");
		printf("�������Ӧ���֣�"); 
		scanf("%d",&c);
		if (c==1) continue;
		else if (c==2) 
		{
			printf("-----------¼�����-----------\n");break;
		} 
	} 
}
void changeBook()
{
	int c;
	printf("---------�޸�ͼ����Ϣ---------\n");
	while(1)
	{
		printf("�������޸�ͼ����룺");
	    scanf("%s",bk.number);
	    if (strcmp(bk.number,out)==0) break; 
	    int i=0;
	    for (;i<bksum;i++)
	    {
	    	if (strcmp(bk.number,savedBook[i].number)==0) 
			{
				bk=savedBook[i];
				printf("��ͼ����ϢΪ��\n"); 
				printf("%s %s %c��y���� n���ޣ�\n",bk.number,bk.name,bk.exist);
				break;
			}
		}
		if (i==bksum) 
		{
			printf("�������޴˱��ͼ�飬���������루������0�˳��˹��ܣ�\n");
		}
		else
		{
			while(1)
			{
				printf("��ѡ���޸���Ϣ��\n");
		    	printf("��1 ���\n");
			    printf("��2 ����\n");
			    printf("��3 ״̬\n");
				scanf("%d",&c);
				if (c==1)
				{
					printf("�������޸ĺ�ı�ţ�");
					scanf("%s",bk.number);
				} 
				else if (c==2)
				{
					printf("�������޸ĺ�����ƣ�");
					scanf("%s",bk.name);
				}
				else if (c==3)
				{
					printf("�������޸ĺ��״̬��y���� n���ޣ���");
					scanf("%c",bk.exist); 
				} 
				printf("�޸ĺ�ͼ����ϢΪ��\n");
				printf("%s %s %c��y���� n���ޣ�\n",bk.number,bk.name);
				savedBook[i]=bk;
				printf("--------���ѳɹ��޸ģ�--------\n"); 
				printf("�Ƿ�����޸ģ�\n");
				printf("��1 �޸Ĵ�ͼ��������Ϣ\n"); 
				printf("��2 �޸�����ͼ��\n");
				printf("��3 �����޸�\n"); 
				scanf("%d",&c);
				if (c==1) continue;
				else if (c==2) break;
				else if (c==3) break;
			} 
			if (c==3) 
			{
				printf("-----------�޸����-----------\n");break;
			}
		}
	}
}
void deleteBook()
{
	int c;
	printf("---------ɾ��ͼ����Ϣ---------\n");
	while (1)
	{
		printf("��������Ҫɾ����ͼ���ţ�");
		scanf("%s",bk.number);
		if (strcmp(bk.number,out)==0) break; 
	    int i=0;
	    for (;i<bksum;i++)
	    {
	    	if (strcmp(bk.number,savedBook[i].number)==0) 
			{
				bk=savedBook[i];
				printf("��ͼ����ϢΪ��\n"); 
				printf("%s %s %c��y���� n���ޣ�\n",bk.number,bk.name,bk.exist);
				break;
			}
		}
		if (i==bksum) 
		{
			printf("�������޴˱��ͼ�飬���������루������0�˳��˹��ܣ�\n");
		}
		else
		{
			printf("���Ƿ�Ҫɾ����ͼ����Ϣ��\n");
			printf("��1 ��\n");
			printf("��2 ��\n");
			printf("�������Ӧ���֣�");
			scanf("%d",&c);
			if (c==1)
			{
				if (i!=bksum-1)
				{
					for (int j=i;j<bksum-1;j++)
					{
						savedBook[j]=savedBook[j+1];
					}
				}
				bksum--; 
				printf("--------���ѳɹ�ɾ����--------\n");
			}
			printf("�Ƿ����ɾ����\n");
			printf("��1 ����ɾ��\n");
			printf("��2 ���ɾ��\n");
			printf("�������Ӧ���֣�");
			scanf("%d",&c);
			if (c==1) continue;
			else if (c==2)
			{
				printf("-----------ɾ�����-----------\n");break;
			}
		}
	}
}
void searchBook()
{
	int c; 
	printf("---------��ѯͼ����Ϣ---------\n");
	while (1)
	{
		printf("��ѡ���ѯ���ݣ�\n");
		printf("��1 ��ʾͼ����Ϣ\n");
		printf("��2 ��ʾ�������\n");
		printf("�������Ӧ���֣�");
		scanf("%d",&c);
		if (c==1)
		{
			printf("��ѡ���ѯ��ʽ��\n");
			printf("��1 ����ͼ������ѯ\n");
			printf("��2 ����ͼ�����Ʋ�ѯ\n");
			printf("��3 ��ʾȫ��ͼ����Ϣ\n");
			printf("�������Ӧ���֣�"); 
			scanf("%d",&c);
			if (c==1)
			{
				printf("������ͼ����룺");
				scanf("%s",bk.number);
				if (strcmp(bk.number,out)==0) break; 
	    		int i=0;
	    		for (;i<bksum;i++)
	    		{
	    			if (strcmp(bk.number,savedBook[i].number)==0) 
					{
						bk=savedBook[i];
						printf("��ͼ����ϢΪ��\n"); 
						printf("%s %s %c��y���� n���ޣ�\n",bk.number,bk.name,bk.exist);
						break;
					}
				}
				if (i==bksum) 
				{
					printf("�������޴˱��ͼ�飬���������루������0�˳��˹��ܣ�\n");
				}
			}
			else if (c==2)
			{
				printf("������ͼ�����ƣ�");
				scanf("%s",bk.name);
				if (strcmp(bk.name,out)==0) break; 
	    		int i=0;
	    		for (;i<bksum;i++)
	    		{
	    			if (strcmp(bk.name,savedBook[i].name)==0) 
					{
						bk=savedBook[i];
						printf("��ͼ����ϢΪ��\n"); 
						printf("%s %s %c��y���� n���ޣ�\n",bk.number,bk.name,bk.exist);
					}
				}
				if (i==bksum) 
				{
					printf("�������޴�����ͼ�飬���������루������0�˳��˹��ܣ�\n");
				}
			}
			else if (c==3)
			{
				for (int i=0;i<bksum;i++)
				{
					printf("%s %s\n",savedBook[i].number,savedBook[i].name);
				}
			}
		}
		else if (c==2)
		{
			printf("��ѡ���ѯ��ʽ��\n");
			printf("��1 ����ͼ������ѯ\n");
			printf("��2 ����ͼ�����Ʋ�ѯ\n");
			printf("�������Ӧ���֣�"); 
			scanf("%d",&c);
			if (c==1)
			{
				printf("������ͼ����룺");
				scanf("%s",bk.number);
				if (strcmp(bk.number,out)==0) break; 
				for (int i=0;i<bksum;i++)
				{
					if (strcmp(bk.number,savedBook[i].number)==0) 
					{
						bk=savedBook[i];break;
					}
				}
	    		int flag=0;
	    		for (int i=0;i<rdsum;i++)
	    		{
	    			if (strcmp(bk.number,savedReader[i].book_number)==0) 
					{
						printf("��ͼ��������Ϊ��\n"); 
						printf("%s %s �����ߣ�%s %s ����ʱ�䣺%s.%s.%s\n",bk.number,bk.name,savedReader[i].number,savedReader[i].name,savedReader[i].time1.year,savedReader[i].time1.month,savedReader[i].time1.day);
					    flag=1;
					}
				}
				if (flag==0) 
				{
					printf("��ͼ����δ�н�����������������루������0�˳��˹��ܣ�\n");
				}
			} 
			else if (c==2)
			{
				printf("������ͼ�����ƣ�");
				scanf("%s",bk.name);
				for (int i=0;i<bksum;i++)
				{
					if (strcmp(bk.name,savedBook[i].name)==0) 
					{
						bk=savedBook[i];break;
					}
				}
				if (strcmp(bk.name,out)==0) break; 
	    		int flag=0;
	    		for (int i;i<rdsum;i++)
	    		{
	    			if (strcmp(bk.number,savedReader[i].book_number)==0) 
					{
						bk=savedBook[i];
						printf("��ͼ��������Ϊ��\n"); 
						printf("%s %s �����ߣ�%s %s ����ʱ�䣺%s.%s.%s\n",bk.number,bk.name,savedReader[i].number,savedReader[i].name,savedReader[i].time1.year,savedReader[i].time1.month,savedReader[i].time1.day);
					    flag=1;
					}
				}
				if (flag==0) 
				{
					printf("��ͼ����δ�н�����������������루������0�˳��˹��ܣ�\n");
				}
			}
		}
		printf("�Ƿ������Ѥ��\n");
		printf("��1 ������ѯ\n");
		printf("��2 ��ɲ�ѯ\n");
		printf("�������Ӧ���֣�");
		scanf("%d",&c);
		if (c==1) continue;
		else if(c==2)
		{
			printf("-----------��ѯ���-----------\n");break;
		}
    }
}
void addReader()
{
	int c; 
	printf("---------¼�������Ϣ---------\n");
	while(1)
	{
		printf("������¼����߱�ţ�");
    	scanf("%s",rd.number);
	    getchar();
	    printf("������¼�����������");
	    scanf("%s",rd.name); 
	    getchar();
	    printf("��ȷ��¼�������Ϣ��\n");
	    printf("%s %s\n",rd.number,rd.name);
	    printf("��1 ��Ϣ����\n");
		printf("��2 ��Ϣ������������\n"); 
		printf("��3 ��������\n");
		printf("�������Ӧ���֣�");
		scanf("%d",&c);
		if (c==1) 
		{
			savedReader[rdsum]=rd;
			strcpy(savedReader[rdsum].book_number,out);
			rdsum++;
			printf("--------���ѳɹ�¼�룡--------\n"); 
		}
		else if (c==2) continue;
		else if (c==3) break;
		printf("�Ƿ����¼�룺\n");
		printf("��1 ����¼��\n");
		printf("��2 ���¼��\n");
		printf("�������Ӧ���֣�"); 
		scanf("%d",&c);
		if (c==1) continue;
		else if (c==2) 
		{
			printf("-----------¼�����-----------\n");break;
		} 
	} 
}
void changeReader()
{
	int c;
	printf("---------�޸Ķ�����Ϣ---------\n");
	while(1)
	{
		printf("�������޸Ķ��߱��룺");
	    scanf("%s",rd.number);
	    if (strcmp(rd.number,out)==0) break; 
	    int i=0;
	    for (;i<rdsum;i++)
	    {
	    	if (strcmp(rd.number,savedReader[i].number)==0) 
			{
				rd=savedReader[i];
				printf("�˶�����ϢΪ��\n"); 
				printf("%s %s\n",rd.number,rd.name);
				break;
			}
		}
		if (i==rdsum) 
		{
			printf("�������޴˱�Ŷ��ߣ����������루������0�˳��˹��ܣ�\n");
		}
		else
		{
			while(1)
			{
				printf("��ѡ���޸���Ϣ��\n");
		    	printf("��1 ���\n");
			    printf("��2 ����\n");
				scanf("%d",&c);
				if (c==1)
				{
					printf("�������޸ĺ�ı�ţ�");
					scanf("%s",rd.number);
				} 
				else if (c==2)
				{
					printf("�������޸ĺ�����ƣ�");
					scanf("%s",rd.name);
				}
				printf("�޸ĺ������ϢΪ��\n");
				printf("%s %s\n",rd.number,rd.name);
				savedReader[i]=rd;
				printf("--------���ѳɹ��޸ģ�--------\n"); 
				printf("�Ƿ�����޸ģ�\n");
				printf("��1 �޸Ĵ�ͼ��������Ϣ\n"); 
				printf("��2 �޸�����ͼ��\n");
				printf("��3 �����޸�\n"); 
				scanf("%d",&c);
				if (c==1) continue;
				else if (c==2) break;
				else if (c==3) break;
			} 
			if (c==3) 
			{
				printf("-----------�޸����-----------\n");break;
			}
		}
	}
}
void deleteReader()
{
	int c;
	printf("---------ɾ��������Ϣ---------\n");
	while (1)
	{
		printf("��������Ҫɾ���Ķ��߱�ţ�");
		scanf("%s",rd.number);
		if (strcmp(rd.number,out)==0) break; 
	    int i=0;
	    for (;i<rdsum;i++)
	    {
	    	if (strcmp(rd.number,savedReader[i].number)==0) 
			{
				rd=savedReader[i];
				printf("��ͼ����ϢΪ��\n"); 
				printf("%s %s\n",rd.number,rd.name);
				break;
			}
		}
		if (i==rdsum) 
		{
			printf("�������޴˱��ͼ�飬���������루������0�˳��˹��ܣ�\n");
		}
		else
		{
			printf("���Ƿ�Ҫɾ����ͼ����Ϣ��\n");
			printf("��1 ��\n");
			printf("��2 ��\n");
			printf("�������Ӧ���֣�");
			scanf("%d",&c);
			if (c==1)
			{
				if (i!=rdsum-1)
				{
					for (int j=i-1;j<rdsum-1;j++)
					{
						savedReader[j]=savedReader[j+1];
					}
				}
				rdsum--; 
				printf("--------���ѳɹ�ɾ����--------\n");
			}
			printf("�Ƿ����ɾ����\n");
			printf("��1 ����ɾ��\n");
			printf("��2 ���ɾ��\n");
			printf("�������Ӧ���֣�");
			scanf("%d",&c);
			if (c==1) continue;
			else if (c==2)
			{
				printf("-----------ɾ�����-----------\n");break;
			}
		}
	}
}
void searchReader()
{
	int c;
	printf("---------��ѯ������Ϣ---------\n");
	while(1)
	{
		printf("��ѡ���ѯ��ʽ��\n");
		printf("��1 ���ݶ��߱����ѯ\n");
		printf("��2 ���ݶ������Ʋ�ѯ\n");
		printf("��3 ��ʾȫ��������Ϣ\n");
		printf("�������Ӧ���֣�"); 
		scanf("%d",&c);
		if (c==1)
		{
			printf("��������߱��룺");
			scanf("%s",rd.number);
			if (strcmp(rd.number,out)==0) break; 
	   		int i=0;
	    	for (;i<rdsum;i++)
	    	{
	    		if (strcmp(rd.number,savedReader[i].number)==0) 
				{
					rd=savedReader[i];
					printf("�˶�����ϢΪ��\n");  
					if (strcmp(rd.book_number,out)==0)
					{
						printf("%s %s δ����ͼ��",rd.number,rd.name);
					}
				    else
				    {
				    	printf("%s %s ������ͼ���ţ�%s ����ʱ�䣺%s.%s.%s\n",rd.number,rd.name,rd.book_number,rd.time1.year,rd.time1.month,rd.time1.day); 
					}
					break;
				}
				if (i==bksum) 
				{
					printf("�������޴˱�Ŷ��ߣ����������루������0�˳��˹��ܣ�\n");
				}
			}
		}
		else if (c==2)
		{
			printf("���������������");
			scanf("%s",rd.name);
			if (strcmp(rd.name,out)==0) break; 
	   		int i=0;
    		for (;i<rdsum;i++)
    		{
    			if (strcmp(rd.name,savedReader[i].name)==0) 
				{
					rd=savedReader[i];
					printf("�˶�����ϢΪ��\n"); 
					if (strcmp(rd.book_number,out)==0)
					{
						printf("%s %s δ����ͼ��",rd.number,rd.name);
					}
			    	else
			    	{
			    		printf("%s %s ������ͼ���ţ�%s ����ʱ�䣺%s.%s.%s\n",rd.number,rd.name,rd.book_number,rd.time1.year,rd.time1.month,rd.time1.day); 
					}
					break;
				}
			}
			if (i==bksum) 
			{
				printf("�������޴��������ߣ����������루������0�˳��˹��ܣ�\n");
			}
		}
		else if (c==3)
		{
			for (int i=0;i<rdsum;i++)
			{
				if (strcmp(rd.book_number,out)==0)
				{
					printf("%s %s δ����ͼ��",rd.number,rd.name);
				}
		    	else
			   	{
			   		printf("%s %s ������ͼ���ţ�%s ����ʱ�䣺%s.%s.%s\n",rd.number,rd.name,rd.book_number,rd.time1.year,rd.time1.month,rd.time1.day); 
				}
			}
		}
		printf("�Ƿ������Ѥ��\n");
		printf("��1 ������ѯ\n");
		printf("��2 ��ɲ�ѯ\n");
		printf("�������Ӧ���֣�");
		scanf("%d",&c);
		if (c==1) continue;
		else if(c==2)
		{
			printf("-----------��ѯ���-----------\n");break;
		}
	} 
}
void borrowBook()
{
	int c;
	printf("-----------����ͼ��-----------\n");
	if (strcmp(rd.book_number,out)!=0)
	{
		printf("%s %s ������ͼ���ţ�%s ����ʱ�䣺%s.%s.%s\n",rd.number,rd.name,rd.book_number,rd.time1.year,rd.time1.month,rd.time1.day); 
		printf("���ѽ��Ĵ�ͼ�飬��黹���ٽ�������ͼ��\n");
	}
	else
	{
		printf("��������Ҫ����ͼ��ı��룺"); 
		scanf("%s",bk.number);
		for (int i=0;i<bksum;i++)
		{
			if (strcmp(bk.number,savedBook[i].number)==0)
			{
				bk=savedBook[i];
				printf("��ȷ��ͼ����Ϣ��\n");
				printf("%s %s %c��y���� n���ޣ�\n",bk.number,bk.name,bk.exist);
				if (bk.exist=='n')
				{
					printf("��Ǹ�������ѱ����ģ��������´�����������������鼮��\n");
				} 
				else
				{
					printf("��1 ���Ĵ���\n");
					printf("��2 ��������\n");
					printf("���ڴ������Ӧ���֣�"); 
					scanf("%d",&c);
					if (c==1) 
					{
						bk.exist='n';
						strcpy(rd.book_number,bk.number);
						printf("���������ʱ�䣨�� �� �գ���");
						scanf("%s %s %s",rd.time1.year,rd.time1.month,rd.time1.day);
						savedReader[rdnumber]=rd;
						savedBook[i]=bk;
						printf("���ν��ĳɹ�������30���ڹ黹���飬������Ҫ���ɷ��\n");  
					}
				}
			}
			break;
		}
	} 
	printf("-----------�������-----------\n");
}
void pay_fine()
{
	int c;
	printf("-----------���ɷ���-----------\n");
	printf("��ɨ�븶�\n");
	printf("    ��ά��\n");
	printf("����1�򸶿���ɣ�");
	scanf("%d",&c);
	if (c==1)
	{
		for (int i=0;i<bksum;i++)
		{
			if (strcmp(rd.book_number,savedBook[i].number)==0)
			{
				savedBook[i].exist='y';break;
			}
		}
		strcpy(rd.book_number,out); 
		savedReader[rdnumber]=rd;
		printf("������ɱ��ι黹�ɹ���\n");
	} 
}


void save_read()
{
	if ((saved_reader=fopen("D:\\Library System\\reader.txt","w"))==NULL)
	{
		puts("Fail to open file!");
		exit(0);
	}
	for (int i=0;i<rdsum;i++)
	{
		if (strcmp(savedReader[i].book_number,out)==0)
		{
			fprintf(saved_reader,"%s %s 0 0.0.0\n",savedReader[i].number,savedReader[i].name);
		}
		else
		{
			fprintf(saved_reader,"%s %s %s %s.%s.%s\n",savedReader[i].number,savedReader[i].name,savedReader[i].book_number,savedReader[i].time1.year,savedReader[i].time1.month,savedReader[i].time1.day);
		} 
	}
	fclose(saved_reader);
}
void save_book()
{
	if ((saved_book=fopen("D:\\Library System\\book.txt","w"))==NULL)
	{
		puts("Fail to open file!");
		exit(0);
	}
	for (int i=0;i<bksum;i++)
	{
		fprintf(saved_book,"%s %s %c\n",savedBook[i].number,savedBook[i].name,savedBook[i].exist);
	}
	fclose(saved_book);
}

int main()
{
	read_administrator();
	read_reader();
	read_book();
	
	int identity; 
	int choice;
	
	printf("******��ӭʹ��ͼ���ϵͳ******\n"); 
	printf("--------��ѡ���������--------\n");
	printf("��0 �˳�ϵͳ\n");
	printf("��1 ����Ա\n");
	printf("��2 ����\n"); 
	
	while(1)
	{
		printf("���ڴ������Ӧ���֣�");
		scanf("%d",&identity);
		getchar();
		if(identity==1)
		{
			while(1)
			{
				printf("���������ı�ţ�������0�˳�ϵͳ����");
		    	scanf("%s",ad_number);
			    getchar();
			    if (strcmp(ad_number,out)==0) break; 
			    if (checkAdnumber()) break;
			    else
			    {
			    	printf("ϵͳ�����޴˹���Ա�û������������롣\n"); 
				}
			}
			if (strcmp(ad_number,out)==0) break;
			while(1)
			{
				printf("���������Ĺ���Ա���루������0�˳�ϵͳ����"); 
			    scanf("%s",password);
			    getchar();
			    if (strcmp(out,password)==0) break; 
			    if (checkPassword())
			    {
				    printf("*****%s,���ѳɹ���¼��*****\n",savedAd[adnumber].name);
				    break; 
			    }
			    else
			    {
				    printf("��������������������롣\n");
			    }
			} 
			if (strcmp(out,password)==0) break;
			while(1)
			{
				printf("--------��ѡ�����蹦��--------\n");
				printf("��0 �˳�ϵͳ\n");
				printf("��1 ¼��ͼ����Ϣ\n"); 
				printf("��2 ɾ��ͼ����Ϣ\n"); 
				printf("��3 �޸�ͼ����Ϣ\n"); 
				printf("��4 ¼�������Ϣ\n"); 
				printf("��5 ɾ��������Ϣ\n"); 
				printf("��6 �޸Ķ�����Ϣ\n"); 
				printf("��7 ��ѯͼ����Ϣ\n"); 
				printf("��8 ��ѯ������Ϣ\n"); 
				printf("���ڴ������Ӧ���֣�");
				scanf("%d",&choice); 
				switch (choice)
				{
					case 1:addBook();break;
					case 2:deleteBook();break;
					case 3:changeBook();break;
					case 4:addReader();break;
					case 5:deleteReader();break;
					case 6:changeReader();break;
					case 7:searchBook();break;
					case 8:searchReader();break;
					case 0:break;
					default :printf("��Ǹ��û�д�ѡ����������롣\n");
				}
				if (choice==0) break; 
			} 
		}
		else if (identity==2)
		{
			while(1)
			{
				printf("���������ı�ţ�������0�˳�ϵͳ����");
		    	scanf("%s",rd_number);
			    getchar();
			    if (strcmp(rd_number,out)==0) break; 
			    if (checkRdnumber()) 
			    {
			    	printf("*****%s,���ѳɹ���¼��*****\n",savedReader[rdnumber].name);
			    	rd=savedReader[rdnumber];
				    break; 
				}
			    else
			    {
			    	printf("ϵͳ�����޴˶����û������������룬��Ѱ�����Աע���±��롣\n"); 
				}
			}
			if (strcmp(rd_number,out)==0) break; 
			while(1)
			{
				printf("--------��ѡ�����蹦��--------\n");
				printf("��0 �˳�ϵͳ\n");
				printf("��1 ��ѯͼ����Ϣ\n"); 
				printf("��2 ����ͼ��\n"); 
				printf("��3 �黹ͼ��\n");  
				printf("���ڴ������Ӧ���֣�");
				scanf("%d",&choice); 
				switch (choice)
				{
					case 1:searchBook();break;
					case 2:borrowBook();break;
					case 0:break;
					default :printf("��Ǹ��û�д�ѡ����������롣\n");
				}
				if (choice==0) break; 
			} 
		}
		else if (identity==0) break;
		else
		{
			printf("��Ǹ��û�д�ѡ����������롣\n");
		}
		if (choice==0) break;
	}
	save_read();
	save_book();
	printf("���ѳɹ��˳�ϵͳ����ӭ�´�ʹ�ã�\n");
	return 0;
} 
