#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define N 200005
#define pi acos(-1.0) //PIֵ 
using namespace std;

struct complex
{
	double r,i;
	complex(double real=0.0,double image=0.0)
	{
		r=real;
		i=image;
	}
	//����Ϊ������������Ķ��� 
	complex operator+(const complex o)
	{
		return complex(r+o.r,i+o.i);
	}
	complex operator-(const complex o)
	{
		return complex(r-o.r,i-o.i);
	}
	complex operator*(const complex o)
	{
		return complex(r*o.r-i*o.i,r*o.i+i*o.r);
	}
}x1[N],x2[N];
char a[N/2],b[N/2];
int sum[N]; //�������sum�� 

void brc(complex *y,int l) //������ƽ̯��ת�û� O(logn) 
{
	register int i,j,k;
	for(i=1,j=l/2;i<l-1;i++)
	{
		if(i<j)	swap(y[i],y[j]); //������Ϊ�±귴ת��Ԫ��  
								 //i<j��ֻ֤����һ�� 
		k=l/2;
		while(j>=k) //�����λ��������1��0����0��1������ 
		{
			j-=k;
			k/=2;
		}
		if(j<k)	j+=k;
	}
}

void fft(complex *y,int l,double on) //FFT O(nlogn) 
//����on==1ʱΪDFT��on==-1ΪIDFT 
{
	register int h,i,j,k;
	complex u,t; 
	brc(y,l); //���÷�ת�û� 
	for(h=2;h<=l;h<<=1) //���Ʋ��� 
	{
		//��ʼ����λ���� 
		complex wn(cos(on*2*pi/h),sin(on*2*pi/h));
		for(j=0;j<l;j+=h) //������ʼ�±� 
		{
			complex w(1,0); //��ʼ���������� 
			for(k=j;k<j+h/2;k++) //��� 
			{
				u=y[k];
				t=w*y[k+h/2];
				y[k]=u+t;
				y[k+h/2]=u-t;
				w=w*wn; //������������ 
			} //����Ĳ����к������� 
		}
	}
	if(on==-1)
		for(i=0;i<l;i++)
			y[i].r/=l; //IDFT 
}

int main()
{
	int l1,l2,l;
	register int i;
	while(~scanf("%s%s",a,b))
	{
		l1=strlen(a);
		l2=strlen(b);
		l=1;
		while(l<l1*2 || l<l2*2)	l<<=1; //����������2^n 
					      			   //��϶����뷴ת�û� 
		for(i=0;i<l1;i++) //���ô��� 
		{
			x1[i].r=a[l1-i-1]-'0';
			x1[i].i=0.0;
		}
		for(;i<l;i++)
			x1[i].r=x1[i].i=0.0;
		//������������ʼ��Ϊ0 
		for(i=0;i<l2;i++)
		{
			x2[i].r=b[l2-i-1]-'0';
			x2[i].i=0.0;
		}
		for(;i<l;i++)
			x2[i].r=x2[i].i=0.0;
		fft(x1,l,1); //DFT(a) 
		fft(x2,l,1); //DFT(b) 
		for(i=0;i<l;i++)
			x1[i]=x1[i]*x2[i]; //��˽������a 
		fft(x1,l,-1); //IDFT(a*b) 
		for(i=0;i<l;i++)
			sum[i]=x1[i].r+0.5; //�������� 
		for(i=0;i<l;i++) //��λ 
		{
			sum[i+1]+=sum[i]/10;
			sum[i]%=10;
		}
		l=l1+l2-1;
		while(sum[l]<=0 && l>0)	l--; //�������λ 
		for(i=l;i>=0;i--)
			putchar(sum[i]+'0'); //������� 
		printf("\n");
	}
	return 0;
}
