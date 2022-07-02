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
	printf("---------录入图书信息---------\n");
	while(1)
	{
		printf("请输入录入图书编号：");
    	scanf("%s",bk.number);
	    getchar();
	    printf("请输入录入图书名称：");
	    scanf("%s",bk.name); 
	    getchar();
	    printf("请确认录入图书信息：\n");
	    printf("%s %s\n",bk.number,bk.name);
	    printf("·1 信息无误\n");
		printf("·2 信息有误，重新输入\n"); 
		printf("·3 放弃输入\n");
		printf("请输入对应数字：");
		scanf("%d",&c);
		if (c==1) 
		{
			savedBook[bksum]=bk;
			savedBook[bksum].exist='y';
			bksum++;
			printf("--------您已成功录入！--------\n"); 
		}
		else if (c==2) continue;
		else if (c==3) break;
		printf("是否继续录入：\n");
		printf("·1 继续录入\n");
		printf("·2 完成录入\n");
		printf("请输入对应数字："); 
		scanf("%d",&c);
		if (c==1) continue;
		else if (c==2) 
		{
			printf("-----------录入完毕-----------\n");break;
		} 
	} 
}
void changeBook()
{
	int c;
	printf("---------修改图书信息---------\n");
	while(1)
	{
		printf("请输入修改图书编码：");
	    scanf("%s",bk.number);
	    if (strcmp(bk.number,out)==0) break; 
	    int i=0;
	    for (;i<bksum;i++)
	    {
	    	if (strcmp(bk.number,savedBook[i].number)==0) 
			{
				bk=savedBook[i];
				printf("此图书信息为：\n"); 
				printf("%s %s %c（y：有 n：无）\n",bk.number,bk.name,bk.exist);
				break;
			}
		}
		if (i==bksum) 
		{
			printf("馆内暂无此编号图书，请重新输入（或输入0退出此功能）\n");
		}
		else
		{
			while(1)
			{
				printf("请选择修改信息：\n");
		    	printf("·1 编号\n");
			    printf("·2 名称\n");
			    printf("·3 状态\n");
				scanf("%d",&c);
				if (c==1)
				{
					printf("请输入修改后的编号：");
					scanf("%s",bk.number);
				} 
				else if (c==2)
				{
					printf("请输入修改后的名称：");
					scanf("%s",bk.name);
				}
				else if (c==3)
				{
					printf("请输入修改后的状态（y：有 n：无）：");
					scanf("%c",bk.exist); 
				} 
				printf("修改后图书信息为：\n");
				printf("%s %s %c（y：有 n：无）\n",bk.number,bk.name);
				savedBook[i]=bk;
				printf("--------您已成功修改！--------\n"); 
				printf("是否继续修改：\n");
				printf("·1 修改此图书其他信息\n"); 
				printf("·2 修改其他图书\n");
				printf("·3 结束修改\n"); 
				scanf("%d",&c);
				if (c==1) continue;
				else if (c==2) break;
				else if (c==3) break;
			} 
			if (c==3) 
			{
				printf("-----------修改完毕-----------\n");break;
			}
		}
	}
}
void deleteBook()
{
	int c;
	printf("---------删除图书信息---------\n");
	while (1)
	{
		printf("请输入您要删除的图书编号：");
		scanf("%s",bk.number);
		if (strcmp(bk.number,out)==0) break; 
	    int i=0;
	    for (;i<bksum;i++)
	    {
	    	if (strcmp(bk.number,savedBook[i].number)==0) 
			{
				bk=savedBook[i];
				printf("此图书信息为：\n"); 
				printf("%s %s %c（y：有 n：无）\n",bk.number,bk.name,bk.exist);
				break;
			}
		}
		if (i==bksum) 
		{
			printf("馆内暂无此编号图书，请重新输入（或输入0退出此功能）\n");
		}
		else
		{
			printf("您是否要删除此图书信息：\n");
			printf("·1 是\n");
			printf("·2 否\n");
			printf("请输入对应数字：");
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
				printf("--------您已成功删除！--------\n");
			}
			printf("是否继续删除：\n");
			printf("·1 继续删除\n");
			printf("·2 完成删除\n");
			printf("请输入对应数字：");
			scanf("%d",&c);
			if (c==1) continue;
			else if (c==2)
			{
				printf("-----------删除完毕-----------\n");break;
			}
		}
	}
}
void searchBook()
{
	int c; 
	printf("---------查询图书信息---------\n");
	while (1)
	{
		printf("请选择查询内容：\n");
		printf("·1 显示图书信息\n");
		printf("·2 显示借阅情况\n");
		printf("请输入对应数字：");
		scanf("%d",&c);
		if (c==1)
		{
			printf("请选择查询方式：\n");
			printf("·1 根据图书编码查询\n");
			printf("·2 根据图书名称查询\n");
			printf("·3 显示全部图书信息\n");
			printf("请输入对应数字："); 
			scanf("%d",&c);
			if (c==1)
			{
				printf("请输入图书编码：");
				scanf("%s",bk.number);
				if (strcmp(bk.number,out)==0) break; 
	    		int i=0;
	    		for (;i<bksum;i++)
	    		{
	    			if (strcmp(bk.number,savedBook[i].number)==0) 
					{
						bk=savedBook[i];
						printf("此图书信息为：\n"); 
						printf("%s %s %c（y：有 n：无）\n",bk.number,bk.name,bk.exist);
						break;
					}
				}
				if (i==bksum) 
				{
					printf("馆内暂无此编号图书，请重新输入（或输入0退出此功能）\n");
				}
			}
			else if (c==2)
			{
				printf("请输入图书名称：");
				scanf("%s",bk.name);
				if (strcmp(bk.name,out)==0) break; 
	    		int i=0;
	    		for (;i<bksum;i++)
	    		{
	    			if (strcmp(bk.name,savedBook[i].name)==0) 
					{
						bk=savedBook[i];
						printf("此图书信息为：\n"); 
						printf("%s %s %c（y：有 n：无）\n",bk.number,bk.name,bk.exist);
					}
				}
				if (i==bksum) 
				{
					printf("馆内暂无此名称图书，请重新输入（或输入0退出此功能）\n");
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
			printf("请选择查询方式：\n");
			printf("·1 根据图书编码查询\n");
			printf("·2 根据图书名称查询\n");
			printf("请输入对应数字："); 
			scanf("%d",&c);
			if (c==1)
			{
				printf("请输入图书编码：");
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
						printf("此图书借阅情况为：\n"); 
						printf("%s %s 借阅者：%s %s 借阅时间：%s.%s.%s\n",bk.number,bk.name,savedReader[i].number,savedReader[i].name,savedReader[i].time1.year,savedReader[i].time1.month,savedReader[i].time1.day);
					    flag=1;
					}
				}
				if (flag==0) 
				{
					printf("此图书暂未有借阅情况，请重新输入（或输入0退出此功能）\n");
				}
			} 
			else if (c==2)
			{
				printf("请输入图书名称：");
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
						printf("此图书借阅情况为：\n"); 
						printf("%s %s 借阅者：%s %s 借阅时间：%s.%s.%s\n",bk.number,bk.name,savedReader[i].number,savedReader[i].name,savedReader[i].time1.year,savedReader[i].time1.month,savedReader[i].time1.day);
					    flag=1;
					}
				}
				if (flag==0) 
				{
					printf("此图书暂未有借阅情况，请重新输入（或输入0退出此功能）\n");
				}
			}
		}
		printf("是否继续查绚：\n");
		printf("·1 继续查询\n");
		printf("·2 完成查询\n");
		printf("请输入对应数字：");
		scanf("%d",&c);
		if (c==1) continue;
		else if(c==2)
		{
			printf("-----------查询完毕-----------\n");break;
		}
    }
}
void addReader()
{
	int c; 
	printf("---------录入读者信息---------\n");
	while(1)
	{
		printf("请输入录入读者编号：");
    	scanf("%s",rd.number);
	    getchar();
	    printf("请输入录入读者姓名：");
	    scanf("%s",rd.name); 
	    getchar();
	    printf("请确认录入读者信息：\n");
	    printf("%s %s\n",rd.number,rd.name);
	    printf("·1 信息无误\n");
		printf("·2 信息有误，重新输入\n"); 
		printf("·3 放弃输入\n");
		printf("请输入对应数字：");
		scanf("%d",&c);
		if (c==1) 
		{
			savedReader[rdsum]=rd;
			strcpy(savedReader[rdsum].book_number,out);
			rdsum++;
			printf("--------您已成功录入！--------\n"); 
		}
		else if (c==2) continue;
		else if (c==3) break;
		printf("是否继续录入：\n");
		printf("·1 继续录入\n");
		printf("·2 完成录入\n");
		printf("请输入对应数字："); 
		scanf("%d",&c);
		if (c==1) continue;
		else if (c==2) 
		{
			printf("-----------录入完毕-----------\n");break;
		} 
	} 
}
void changeReader()
{
	int c;
	printf("---------修改读者信息---------\n");
	while(1)
	{
		printf("请输入修改读者编码：");
	    scanf("%s",rd.number);
	    if (strcmp(rd.number,out)==0) break; 
	    int i=0;
	    for (;i<rdsum;i++)
	    {
	    	if (strcmp(rd.number,savedReader[i].number)==0) 
			{
				rd=savedReader[i];
				printf("此读者信息为：\n"); 
				printf("%s %s\n",rd.number,rd.name);
				break;
			}
		}
		if (i==rdsum) 
		{
			printf("馆内暂无此编号读者，请重新输入（或输入0退出此功能）\n");
		}
		else
		{
			while(1)
			{
				printf("请选择修改信息：\n");
		    	printf("·1 编号\n");
			    printf("·2 名称\n");
				scanf("%d",&c);
				if (c==1)
				{
					printf("请输入修改后的编号：");
					scanf("%s",rd.number);
				} 
				else if (c==2)
				{
					printf("请输入修改后的名称：");
					scanf("%s",rd.name);
				}
				printf("修改后读者信息为：\n");
				printf("%s %s\n",rd.number,rd.name);
				savedReader[i]=rd;
				printf("--------您已成功修改！--------\n"); 
				printf("是否继续修改：\n");
				printf("·1 修改此图书其他信息\n"); 
				printf("·2 修改其他图书\n");
				printf("·3 结束修改\n"); 
				scanf("%d",&c);
				if (c==1) continue;
				else if (c==2) break;
				else if (c==3) break;
			} 
			if (c==3) 
			{
				printf("-----------修改完毕-----------\n");break;
			}
		}
	}
}
void deleteReader()
{
	int c;
	printf("---------删除读者信息---------\n");
	while (1)
	{
		printf("请输入您要删除的读者编号：");
		scanf("%s",rd.number);
		if (strcmp(rd.number,out)==0) break; 
	    int i=0;
	    for (;i<rdsum;i++)
	    {
	    	if (strcmp(rd.number,savedReader[i].number)==0) 
			{
				rd=savedReader[i];
				printf("此图书信息为：\n"); 
				printf("%s %s\n",rd.number,rd.name);
				break;
			}
		}
		if (i==rdsum) 
		{
			printf("馆内暂无此编号图书，请重新输入（或输入0退出此功能）\n");
		}
		else
		{
			printf("您是否要删除此图书信息：\n");
			printf("·1 是\n");
			printf("·2 否\n");
			printf("请输入对应数字：");
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
				printf("--------您已成功删除！--------\n");
			}
			printf("是否继续删除：\n");
			printf("·1 继续删除\n");
			printf("·2 完成删除\n");
			printf("请输入对应数字：");
			scanf("%d",&c);
			if (c==1) continue;
			else if (c==2)
			{
				printf("-----------删除完毕-----------\n");break;
			}
		}
	}
}
void searchReader()
{
	int c;
	printf("---------查询读者信息---------\n");
	while(1)
	{
		printf("请选择查询方式：\n");
		printf("·1 根据读者编码查询\n");
		printf("·2 根据读者名称查询\n");
		printf("·3 显示全部读者信息\n");
		printf("请输入对应数字："); 
		scanf("%d",&c);
		if (c==1)
		{
			printf("请输入读者编码：");
			scanf("%s",rd.number);
			if (strcmp(rd.number,out)==0) break; 
	   		int i=0;
	    	for (;i<rdsum;i++)
	    	{
	    		if (strcmp(rd.number,savedReader[i].number)==0) 
				{
					rd=savedReader[i];
					printf("此读者信息为：\n");  
					if (strcmp(rd.book_number,out)==0)
					{
						printf("%s %s 未借阅图书",rd.number,rd.name);
					}
				    else
				    {
				    	printf("%s %s 正借阅图书编号：%s 借阅时间：%s.%s.%s\n",rd.number,rd.name,rd.book_number,rd.time1.year,rd.time1.month,rd.time1.day); 
					}
					break;
				}
				if (i==bksum) 
				{
					printf("馆内暂无此编号读者，请重新输入（或输入0退出此功能）\n");
				}
			}
		}
		else if (c==2)
		{
			printf("请输入读者姓名：");
			scanf("%s",rd.name);
			if (strcmp(rd.name,out)==0) break; 
	   		int i=0;
    		for (;i<rdsum;i++)
    		{
    			if (strcmp(rd.name,savedReader[i].name)==0) 
				{
					rd=savedReader[i];
					printf("此读者信息为：\n"); 
					if (strcmp(rd.book_number,out)==0)
					{
						printf("%s %s 未借阅图书",rd.number,rd.name);
					}
			    	else
			    	{
			    		printf("%s %s 正借阅图书编号：%s 借阅时间：%s.%s.%s\n",rd.number,rd.name,rd.book_number,rd.time1.year,rd.time1.month,rd.time1.day); 
					}
					break;
				}
			}
			if (i==bksum) 
			{
				printf("馆内暂无此姓名读者，请重新输入（或输入0退出此功能）\n");
			}
		}
		else if (c==3)
		{
			for (int i=0;i<rdsum;i++)
			{
				if (strcmp(rd.book_number,out)==0)
				{
					printf("%s %s 未借阅图书",rd.number,rd.name);
				}
		    	else
			   	{
			   		printf("%s %s 正借阅图书编号：%s 借阅时间：%s.%s.%s\n",rd.number,rd.name,rd.book_number,rd.time1.year,rd.time1.month,rd.time1.day); 
				}
			}
		}
		printf("是否继续查绚：\n");
		printf("·1 继续查询\n");
		printf("·2 完成查询\n");
		printf("请输入对应数字：");
		scanf("%d",&c);
		if (c==1) continue;
		else if(c==2)
		{
			printf("-----------查询完毕-----------\n");break;
		}
	} 
}
void borrowBook()
{
	int c;
	printf("-----------借阅图书-----------\n");
	if (strcmp(rd.book_number,out)!=0)
	{
		printf("%s %s 正借阅图书编号：%s 借阅时间：%s.%s.%s\n",rd.number,rd.name,rd.book_number,rd.time1.year,rd.time1.month,rd.time1.day); 
		printf("您已借阅此图书，请归还后再借阅其他图书\n");
	}
	else
	{
		printf("请输入您要借阅图书的编码："); 
		scanf("%s",bk.number);
		for (int i=0;i<bksum;i++)
		{
			if (strcmp(bk.number,savedBook[i].number)==0)
			{
				bk=savedBook[i];
				printf("请确认图书信息：\n");
				printf("%s %s %c（y：有 n：无）\n",bk.number,bk.name,bk.exist);
				if (bk.exist=='n')
				{
					printf("抱歉！此书已被借阅，您可以下次再来，或借阅其他书籍。\n");
				} 
				else
				{
					printf("·1 借阅此书\n");
					printf("·2 放弃借阅\n");
					printf("请在此输入对应数字："); 
					scanf("%d",&c);
					if (c==1) 
					{
						bk.exist='n';
						strcpy(rd.book_number,bk.number);
						printf("请输入借阅时间（年 月 日）：");
						scanf("%s %s %s",rd.time1.year,rd.time1.month,rd.time1.day);
						savedReader[rdnumber]=rd;
						savedBook[i]=bk;
						printf("本次借阅成功！请在30天内归还此书，否则需要缴纳罚款。\n");  
					}
				}
			}
			break;
		}
	} 
	printf("-----------借阅完毕-----------\n");
}
void pay_fine()
{
	int c;
	printf("-----------缴纳罚款-----------\n");
	printf("请扫码付款：\n");
	printf("    二维码\n");
	printf("输入1则付款完成：");
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
		printf("付款完成本次归还成功！\n");
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
	
	printf("******欢迎使用图书馆系统******\n"); 
	printf("--------请选择您的身份--------\n");
	printf("·0 退出系统\n");
	printf("·1 管理员\n");
	printf("·2 读者\n"); 
	
	while(1)
	{
		printf("请在此输入对应数字：");
		scanf("%d",&identity);
		getchar();
		if(identity==1)
		{
			while(1)
			{
				printf("请输入您的编号（或输入0退出系统）：");
		    	scanf("%s",ad_number);
			    getchar();
			    if (strcmp(ad_number,out)==0) break; 
			    if (checkAdnumber()) break;
			    else
			    {
			    	printf("系统内暂无此管理员用户！请重新输入。\n"); 
				}
			}
			if (strcmp(ad_number,out)==0) break;
			while(1)
			{
				printf("请输入您的管理员密码（或输入0退出系统）："); 
			    scanf("%s",password);
			    getchar();
			    if (strcmp(out,password)==0) break; 
			    if (checkPassword())
			    {
				    printf("*****%s,您已成功登录！*****\n",savedAd[adnumber].name);
				    break; 
			    }
			    else
			    {
				    printf("您的密码错误！请重新输入。\n");
			    }
			} 
			if (strcmp(out,password)==0) break;
			while(1)
			{
				printf("--------请选择所需功能--------\n");
				printf("·0 退出系统\n");
				printf("·1 录入图书信息\n"); 
				printf("·2 删除图书信息\n"); 
				printf("·3 修改图书信息\n"); 
				printf("·4 录入读者信息\n"); 
				printf("·5 删除读者信息\n"); 
				printf("·6 修改读书信息\n"); 
				printf("·7 查询图书信息\n"); 
				printf("·8 查询读者信息\n"); 
				printf("请在此输入对应数字：");
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
					default :printf("抱歉，没有此选项，请重新输入。\n");
				}
				if (choice==0) break; 
			} 
		}
		else if (identity==2)
		{
			while(1)
			{
				printf("请输入您的编号（或输入0退出系统）：");
		    	scanf("%s",rd_number);
			    getchar();
			    if (strcmp(rd_number,out)==0) break; 
			    if (checkRdnumber()) 
			    {
			    	printf("*****%s,您已成功登录！*****\n",savedReader[rdnumber].name);
			    	rd=savedReader[rdnumber];
				    break; 
				}
			    else
			    {
			    	printf("系统内暂无此读者用户！请重新输入，或寻求管理员注册新编码。\n"); 
				}
			}
			if (strcmp(rd_number,out)==0) break; 
			while(1)
			{
				printf("--------请选择所需功能--------\n");
				printf("·0 退出系统\n");
				printf("·1 查询图书信息\n"); 
				printf("·2 借阅图书\n"); 
				printf("·3 归还图书\n");  
				printf("请在此输入对应数字：");
				scanf("%d",&choice); 
				switch (choice)
				{
					case 1:searchBook();break;
					case 2:borrowBook();break;
					case 0:break;
					default :printf("抱歉，没有此选项，请重新输入。\n");
				}
				if (choice==0) break; 
			} 
		}
		else if (identity==0) break;
		else
		{
			printf("抱歉，没有此选项，请重新输入。\n");
		}
		if (choice==0) break;
	}
	save_read();
	save_book();
	printf("您已成功退出系统。欢迎下次使用！\n");
	return 0;
} 
