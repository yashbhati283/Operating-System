#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

struct num
{
	int a,b;
};

void *addition(void *a1)
{
	struct num *n1=a1;
	int add=(n1->a+n1->b);
	return add;
}
void *sub(void *a2)
{
	struct num *n2=a2;
	int sub=(n2->a-n2->b);
	return sub;
}

int main()
{
	struct num n1,n2,n3,n4;
	pthread_t th1,th2,th3,th4;
	printf("Enter two values :\n");
	scanf("%d%d",&n1.a,&n1.b);
	pthread_create(&th1,NULL,addition,&n1);
	void *a1;
	pthread_join(th1,&a1);
	printf("Addition of %d,%d is %d\n",n1.a,n1.b,a1);
	
	printf("Enter two values :\n");
	scanf("%d%d",&n2.a,&n2.b);
	pthread_create(&th2,NULL,sub,&n2);
	void *a2;
	pthread_join(th2,&a2);
	printf("Addition of %d,%d is %d\n",n2.a,n2.b,a2);

}
