#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    int score[6];
    int num;
    char str[16];
}STUDENT;
void ReadscoreAndNum(STUDENT stu[],int n,int h);
void SumAndAverage(STUDENT stu[],int n,int t,int h,int s[],int psum[],float pa[]);
void DataSort(STUDENT stu[],int n,int (*compare)(int a,int b),int cp,int h,int s[]);
int  Ascending(int a,int b);
int  Descending(int a,int b);
void Search(STUDENT stu[],int n,int ct,int h,int s[]);
void SortOut(STUDENT stu[],int n,int h);
void Print(STUDENT stu[],int n,int h,int s[]);
#define N 30
int psum[N];
float pa[N];
int main()
{
    int s[N],flag=0,n,i,j,cp,ct,h,t;
    char c;
    STUDENT stu[N];
    do
   {
    printf("1.Input Record\n");
    printf("2.Calculate total and average score of every course\n");
    printf("3.Calculate total and average score of every student\n");
    printf("4.Sort in descending order by total score of every student\n");
    printf("5.Sort in ascending order by total score of every student\n");
    printf("6.Sort in ascending order by number\n");
    printf("7.Sort in dictionary order by name\n");
    printf("8.Search by number\n");
    printf("9.Search by name\n");
    printf("10.Statistic analysis for every course\n");
    printf("11.List record\n");
    printf("0.Exit\n");
    printf("Please enter your choice:\n");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        printf("Please input total numbers of students and classes:");
        scanf("%d%*c%d",&n,&h);
        ReadscoreAndNum(stu,n,h);
        printf("total number is:%d人，%d门课\n",n,h);
        flag=1;
        break;
    case 2:
        if(flag==0)
    {
        printf("No Score!");
        break;
    }
    else
    {
        t=0;
        SumAndAverage(stu,n,t,h,s,psum,pa);
        for(i=0;i<h;i++)
        {
        printf("sum and average of class %d are:%d  %f\n",i+1,psum[i],pa[i]);
        }
        break;
    }
    case 3:
        if(flag==0)
    {
        printf("No Score!");
        break;
    }
    else
    {
        t=1;
        SumAndAverage(stu,n,t,h,s,psum,pa);
        for(i=0;i<n;i++)
        {
        printf("sum and average of student %d are:%d  %f\n",i+1,psum[i],pa[i]);
        }
        break;
    }

    case 4:
        if(flag==0)
        {
         printf("No Score!");
         break;
        }
        else
        {
        cp=0;
        DataSort(stu,n,Descending,cp,h,s);
        for(i=0;i<n;i++)
            {
            printf("%d   %s   ",stu[i].num,stu[i].str);
            for(j=0;j<h;j++)
            {
                printf("%d  ",stu[i].score[j]);
            }
            printf("sum:%d \n",s[i]);
            }
        break;
        }
    case 5:
         if(flag==0)
        {
         printf("No Score!");
         break;
        }
        else
        {
        cp=0;
        DataSort(stu,n,Ascending,cp,h,s);
        for(i=0;i<n;i++)
            {
            printf("%d   %s   ",stu[i].num,stu[i].str);
            for(j=0;j<h;j++)
            {
                printf("%d  ",stu[i].score[j]);
            }
            printf("sum:%d \n",s[i]);
            }
        break;
        }
    case 6:
          if(flag==0)
        {
         printf("No Score!");
         break;
        }
        else
        {
        cp=1;
        DataSort(stu,n,Ascending,cp,h,s);
        for(i=0;i<n;i++)
            {
            printf("%d   %s   ",stu[i].num,stu[i].str);
            for(j=0;j<h;j++)
            {
            printf("%d  ",stu[i].score[j]);
            }
            printf("sum:%d \n",s[i]);
            }
        break;
        }
    case 7:
         if(flag==0)
        {
         printf("No Score!");
         break;
        }
        else
        {
        cp=2;
        DataSort(stu,n,Ascending,cp,h,s);
        for(i=0;i<n;i++)
            {
            printf("%d   %s   ",stu[i].num,stu[i].str);
            for(j=0;j<h;j++)
            {
                printf("%d  ",stu[i].score[j]);
            }
            printf("sum:%d \n",s[i]);
            }
        break;
        }

    case 8:
        if(flag==0)
        {
         printf("No Score!");
         break;
        }
        else
        {
        ct=0;
        Search(stu,n,ct,h,s);
        break;
        }
    case 9:
    if(flag==0)
        {
         printf("No Score!");
         break;
        }
        else
        {
        ct=1;
        Search(stu,n,ct,h,s);
        break;
        }
    case 10:
          if(flag==0)
        {
         printf("No Score!");
         break;
        }
        else
        {
        SortOut(stu,n,h);
        break;
        }
    case 11:
          if(flag==0)
        {
         printf("No Score!");
         break;
        }
        else
        {
       Print(stu,n,h,s);
        break;
        }
    default:
        exit(0);
    }
    while(getchar()!='\n');
    printf("do you want to continue?(y/n)");
    scanf("%c",&c);
   }while(c=='y');
   return 0;
}
//函数功能：读入成绩
void ReadscoreAndNum(STUDENT stu[],int n,int h)
{
    int i,j,ret;
    for(i=0;i<n;i++)
    {
    while(getchar()!='\n');
    printf("please input number and name:");
    scanf("%d%*c%s",&stu[i].num,stu[i].str);
    for(j=0;j<h;j++)
     {
    do
    {
        while(getchar()!='\n');
        printf("请输入第%d门课的成绩：",j+1);
        ret=scanf("%d",&stu[i].score[j]);
    }while(ret!=1);
     }
}
}
//函数功能：计算平均分与总分
void SumAndAverage(STUDENT stu[],int n,int t,int h,int s[],int psum[],float pa[])
{
    int i,j;
    if(t==0)
    {
    for(i=0;i<h;i++)
    {
      psum[i]=0;
      pa[i]=0;
        for(j=0;j<n;j++)
        {
        psum[i]+=stu[j].score[i];
        }
     pa[i]=(float)psum[i]/n;
    }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            psum[i]=0;
            pa[i]=0;
            for(j=0;j<h;j++)
            {
                psum[i]+=stu[i].score[j];
            }
            s[i]=psum[i];
            pa[i]=(float)psum[i]/h;
        }
    }
}
//函数功能：排序
void DataSort(STUDENT stu[],int n,int (*compare)(int a,int b),int cp,int h,int s[])
{
    int i,j,k,m,temp1,temp2,temp3;
    char temp[16];
    SumAndAverage(stu,n,1,h,s,psum,pa);
        if(cp==0)
        {
            for(i=0;i<n-1;i++)
            {
            k=i;
            for(j=i+1;j<n;j++)
            {
                if((*compare)(s[k],s[j]))
                    k=j;
            }
                if(k!=i)
                {
                    temp3=s[i];
                    s[i]=s[k];
                    s[k]=temp3;
                    temp2=stu[i].num;
                    stu[i].num=stu[k].num;
                    stu[k].num=temp2;
                    strcpy(temp,stu[i].str);
                    strcpy(stu[i].str,stu[k].str);
                    strcpy(stu[k].str,temp);
                    for(m=0;m<h;m++)
                    {
                        temp1=0;
                        temp1=stu[i].score[m];
                        stu[i].score[m]=stu[k].score[m];
                        stu[k].score[m]=temp1;
                    }
                }
            }
        }
        else if(cp==1)
        {
            for(i=0;i<n-1;i++)
           {
            k=i;
            for(j=i+1;j<n;j++)
            {
                if((*compare)(stu[k].num,stu[j].num))
                    k=j;
            }
                if(k!=i)
                {
                    temp3=s[i];
                    s[i]=s[k];
                    s[k]=temp3;
                    temp2=stu[i].num;
                    stu[i].num=stu[k].num;
                    stu[k].num=temp2;
                    strcpy(temp,stu[i].str);
                    strcpy(stu[i].str,stu[k].str);
                    strcpy(stu[k].str,temp);
                    for(m=0;m<h;m++)
                    {
                        temp1=0;
                        temp1=stu[i].score[m];
                        stu[i].score[m]=stu[k].score[m];
                        stu[k].score[m]=temp1;
                    }
                }
           }
        }
        else
        {
            for(i=0;i<n-1;i++)
            {
                k=i;
                for(j=i+1;j<n;j++)
                {
                    if(strcmp(stu[j].str,stu[k].str)<0)
                     {
                         k=j;
                    }
                }
                if(k!=i)
                {
                   temp3=s[i];
                    s[i]=s[k];
                    s[k]=temp3;
                    temp2=stu[i].num;
                    stu[i].num=stu[k].num;
                    stu[k].num=temp2;
                    strcpy(temp,stu[i].str);
                    strcpy(stu[i].str,stu[k].str);
                    strcpy(stu[k].str,temp);
                    for(m=0;m<h;m++)
                    {
                        temp1=0;
                        temp1=stu[i].score[m];
                        stu[i].score[m]=stu[k].score[m];
                        stu[k].score[m]=temp1;
                    }
                }
            }
        }

}
//函数功能：由高到低
int  Ascending(int a,int b)
{
    return a>b;
}
//函数功能：由低到高
int Descending(int a,int b)
{
    return a<b;
}
//函数功能：查询
void Search(STUDENT stu[] ,int n,int ct,int h,int s[])
{
    int result,i,j,flag=0;
    char t[16];
    SumAndAverage(stu,n,1,h,s,psum,pa);
    DataSort(stu,n,Descending,0,h,s);
    if(ct==0)
    {
    printf("please input number:");
    scanf("%d",&result);
    for(i=0;i<n;i++)
    {
        if(result==stu[i].num)
        {
            printf("rank is %d  name is %s  ",i+1,stu[i].str);
            for(j=0;j<h;j++)
            {
                printf("%d  ",stu[i].score[j]);
            }
            printf("sum:%d \n",s[i]);
            flag=1;
            break;
        }
    }
    if(!flag)
    printf("NOT FOUND!\n");
    }
    if(ct==1)
    {
    while(getchar()!='\n');
    printf("please input name:");
    gets(t);
    for(i=0;i<n;i++)
{
           if(strcmp(stu[i].str,t)==0)
{
            printf("rank is %d  name is %s  ",i+1,stu[i].str);
            for(j=0;j<h;j++)
            {
                printf("%d  ",stu[i].score[j]);
            }
            printf("sum:%d \n",s[i]);
            flag=1;
            break;
}
}
    if(!flag)
    printf("NOT FOUND!\n");
    }
}
//函数功能：分类
void SortOut(STUDENT stu[],int n,int h)
{
    int count[5],i,j,k;
    for(i=0;i<h;i++)
    {
        for(k=0;k<5;k++)
        {
            count[k]=0;
        }
        for(j=0;j<n;j++)
       {
        if(stu[j].score[i]>=90&&stu[j].score[i]<=100)
        count[0]++;
        else if(stu[j].score[i]>=80&&stu[j].score[i]<=89)
        count[1]++;
        else if(stu[j].score[i]>=70&&stu[j].score[i]<=79)
        count[2]++;
        else if(stu[j].score[i]>=60&&stu[j].score[i]<=69)
        count[3]++;
        else if(stu[j].score[i]>=0&&stu[j].score[i]<=69)
        count[4]++;
       }
    printf("第%d门课的情况：\n",i+1);
    printf("优秀 is %d %.2f%%\n",count[0],100*(float)count[0]/n);
    printf("良好 is %d %.2f%%\n",count[1],100*(float)count[1]/n);
    printf("中等 is %d %.2f%%\n",count[2],100*(float)count[2]/n);
    printf("及格 is %d %.2f%%\n",count[3],100*(float)count[3]/n);
    printf("不及格 is %d %.2f%%\n",count[4],100*(float)count[4]/n);
    }
}
//函数功能：输出
void Print(STUDENT stu[],int n,int h,int s[])
{
    int i,j;
    SumAndAverage(stu,n,1,h,s,psum,pa);
    DataSort(stu,n,Ascending,1,h,s);
    for(i=0;i<n;i++)
    {
              printf("%d   %s   ",stu[i].num,stu[i].str);
              for(j=0;j<h;j++)
            {
                printf("%d  ",stu[i].score[j]);
            }
              printf("sum:%d  average:%f \n",s[i],(float)s[i]/h);
    }
}
