#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define N 5

sem_t chopsticks[N];
sem_t m;

int philosophers[N]={0,1,2,3,4};

void delay(int len){
	int i=rand()%len;
	int x;
	while(i>0){
		x=rand()%len;
		while(x>0){
			x--;
		}
		i--;
	}
}

void *philosopher(void *arg){
	int i=*(int *)arg;
	int left=i;
	int right=(i+1)%N;
	while(1){
		printf("哲学家%d正在思考问题\n",i);
		delay(60000);

		printf("哲学家%d饿了\n",i);
		sem_wait(&m);
		sem_wait(&chopsticks[left]);
		printf("哲学家%d拿起了%d号筷子，现在只有一直筷子，不能进餐\n",i,left);
		sem_wait(&chopsticks[right]);
		printf("哲学家%d拿起了%d号筷子，现在有两只筷子，开始进餐\n",i,right);
		delay(60000);
		sem_post(&chopsticks[left]);
		printf("哲学家%d放下了%d号筷子\n",i,left);
		sem_post(&m);
		sem_post(&chopsticks[right]);
		printf("哲学家%d放下了%d号筷子\n",i,right);
	}
}

int main (int argc,char **argv){
	int i;
	srand(time(NULL));
	pthread_t philo[N];

	for(i=0;i<N;i++){
		sem_init(&chopsticks[i],0,1);
	}
	sem_init(&m,0,4);

	for(i=0;i<N;i++){
		pthread_create(&philo[i],NULL,philosopher,&philosophers[i]);
	}

	for(i=0;i<N;i++){
		pthread_join(philo[i],NULL);
	}

	for(i=0;i<N;i++){
		sem_destroy(&chopsticks[i]);
	}
	sem_destroy(&m);
}
