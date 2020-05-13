#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"gotoSignInPage.h"
enum shenfen { USER, ADMIN, NOT };
char* gotoSignInPage() {                                                    //输入正确直接返回用户名或管理账号
	while (1)
	{
		system("cls");
		FILE* fp;
		fp = fopen("user.bat", "r");
		if (fp == NULL)
			return "0";                                                          //文件无法打开，返回正常首页就好
		struct user* head1 = NULL;
		struct user* end1 = NULL;
		int i = 0;
		char x[20], y[20], z[10], k[12];
		while (fscanf(fp, "%s%s%s%s", x, y, z, k) != EOF)
		{
			struct user* a = (struct user*)malloc(sizeof(struct user));
			if (i = 0)
			{
				head1 = a;
				end1 = a;
				strcpy(a->username, x);
				strcpy(a->password, y);
				strcpy(a->realName, z);
				strcpy(a->telephone, k);
			}
			else
			{
				end1->next = a;
				end1 = a;
				strcpy(a->username, x);
				strcpy(a->password, y);
				strcpy(a->realName, z);
				strcpy(a->telephone, k);
			}
			i++;
		}
		fclose(fp);
		fp = fopen("admin.bat", "r");
		if (fp == NULL)
			return  "0";                                                               //文件无法打开，返回正常首页就好
		struct admin* head2 = NULL;
		struct admin* end2 = NULL;
		i = 0;
		char x[15], y[15];
		while (fscanf(fp, "%s%s", x, y) != EOF)
		{
			struct admin* a = (struct user*)malloc(sizeof(struct user));
			if (i = 0)
			{
				head2 = a;
				end2 = a;
				strcpy(a->account, x);
				strcpy(a->password, y);
			}
			else
			{
				end2->next = a;
				end2 = a;
				strcpy(a->account, x);
				strcpy(a->password, y);
			}
			i++;
		}
		fclose(fp);
		printf("\n\n\n\n                                   登录\n\n\n\n\n\n\n\n                                       用户名/手机号：");
		char d[20], f[20];
		scanf("%s", d);
		printf("                                                密码：");
		scanf("%s", f);
		while (head1 != NULL)
		{
			if (strcmp(head1->username, d) == 0 || strcmp(head1->telephone, d) == 0)
			{
				if (strcmp(head1->password, f) == 0)
					return head1->username;                                                           //身份改成用户,首页显示出姓名
				else
				{
					goto end;
					printf("密码错误！");
				}
			}
			head1 = head1->next;
		}
		while (head2 != NULL)
		{
			if (strcmp(head2->account, d) == 0 )
			{
				if (strcmp(head2->password, f) == 0)
					return head2->account;                                                           //身份改成管理员
				else
				{
					goto end;
					printf("密码错误！");
				}
			}
			head2 = head2->next;
		}
		printf("账号错误");
	end:;
	}
}
struct user {
	char username[20];
	char password[20];
	char realName[10];
	char telephone[12];
	struct user* next;
};
struct admin {
	char account[15];
	char password[15];
	struct admin* next;
};