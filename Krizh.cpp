#include <stdlib.h>
#include <stdio.h>

int find_max(int* how_many_people_who_have_less)
{
    int i,maxx=how_many_people_who_have_less[1],index=1;

    for(i=1;i<=101;i++)
        if(how_many_people_who_have_less[i]>maxx)
        {
           maxx=how_many_people_who_have_less[i];
           index=i;
        }

    return index;
}

int find_man(int* answer, int k, int N)
{
    int i;

    for(i=0;i<N;i++)
        if(answer[i]==k) return i;
}

int hm_people_more(int* score, int N)
{
    int i,k=0;

    for(i=0;i<N-1;i++)
        if(score[i]<score[N-1]) k++;

    return k;
}

int who_is_the_winner(int* numbers)
{
    int i;

    for(i=1;i<=101;i++)
        if(numbers[i]==1) return i;

    return -1;
}

int what_my_answer(int* score, int* answer, int* numbers, int* how_many_people_who_have_less, int N)
{
   int i,k,winner,answ;

   //if(numbers[1]==0) return 1;

   for(i=1;i<=101;i++)
   {
      numbers[i]++;
      answer[N-1]=i;

      k=who_is_the_winner(numbers);

      if(k==-1)
      {
          how_many_people_who_have_less[i]=hm_people_more(score,N);
      }
      else
      {
          winner=find_man(answer,k,N);
          score[winner]+=k;
          how_many_people_who_have_less[i]=hm_people_more(score,N);

          score[winner]-=k;
      }

      numbers[i]--;
   }

   answ=find_max(how_many_people_who_have_less);

   return answ;
}

void my_sort(int* numbers, int* answer, int N)
{
    int i;

    for(i=0;i<N-1;i++)
        numbers[answer[i]]++;
}

void init(int* score, int* answer, int* numbers, int N)
{
    int i;

    for(i=0;i<N;i++)
        scanf("%d",&score[i]);
    for(i=0;i<N-1;i++)
        scanf("%d",&answer[i]);

    for(i=1;i<=101;i++)
        numbers[i]=0;
}

int main(void)
{
	int N,answ;
	int *score, *answer, *numbers, *how_many_people_who_have_less;

    scanf("%d",&N);

    score=(int*)malloc(N*sizeof(int));
    answer=(int*)malloc(N*sizeof(int));
    numbers=(int*)malloc(101*sizeof(int));
    how_many_people_who_have_less=(int*)malloc(100*sizeof(int));

    init(score,answer,numbers,N);
    my_sort(numbers,answer,N);

    answ=what_my_answer(score,answer,numbers,how_many_people_who_have_less,N);

    printf("%d",answ);

	return 0;
}
