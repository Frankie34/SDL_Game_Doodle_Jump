 /*****Ê±¼äÆ¬ÂÖ×ª·¨½øÐÐCPUµ÷¶ÈËã·¨********/
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define N 3  //¶¨Òå×î´ó½ø³ÌÊý
#define TIME 2//¶¨ÒåÊ±¼äÆ¬´óÐ¡
typedef struct pcb{
    char id[10];//½ø³Ì±êÊ¶Êý
    int runtime;//½ø³ÌÒÑ¾­Õ¼ÓÃµÄcpuÊ±¼ä
    int needtime;//½ø³Ì»¹ÐèÒªµÄÊ±¼ä
    int count;
    char state;//½ø³ÌÔËÐÐ×´Ì¬£ºwait or runing
}pcb;

void main(){
    int processCreate;
    int processFinish;
    int num1 = 0;
    printf("****************************\n");
    pcb p_test[N];
    CreateProcess(p_test);
    Priority_Sorting(p_test);
    p_test[0].state = 'R';
    ShowProcess(p_test,num1);
    int FINISH = 0;
    int n5=0;
    for(n5=0;n5<N;n5++){
            FINISH = FINISH + p_test[n5].needtime;
        }

    while(FINISH!=0){
        RR_RunProcess(p_test);//¼òµ¥ÂÖ×ª·¨Round Robin
        //printf("\n%d\n",num1);
        Priority_Sorting(p_test);
        num1 = 0;
        ShowProcess(p_test,num1);
        //printf("\n%d\n",num2);

        FINISH = 0;
        for(n5=0;n5<N;n5++){
            FINISH = FINISH + p_test[n5].needtime;
        }
        //ResetProcess(p_test,num);
    }
}

void CreateProcess(pcb p[]){
    int n1;
    printf("input id and needtime:\n");
    for(n1=0;n1<=N-1;n1++)
    {
        scanf("%s%d",&p[n1].id,&p[n1].needtime);
        p[n1].runtime = 0;
        p[n1].count = 0;
        p[n1].state = 'W';
    }
}

int RR_RunProcess(pcb p[],int n4){
    int RUN = 1;
    int n5 = (n4+1)%N;

    while(RUN){
        if(p[n4].needtime==0){
        n4=(n4+1)%N;
        }else if(p[n4].needtime==1){
        p[n4].runtime++;
        p[n4].needtime--;
        p[n4].count++;
        p[n4].state = 'F';
        RUN = 0;
        }else if(p[n4].needtime==2){
        p[n4].runtime=p[n4].runtime+2;
        p[n4].needtime=p[n4].needtime-2;
        p[n4].count++;
        p[n4].state = 'F';
        RUN = 0;
        }else {
        p[n4].runtime=p[n4].runtime+2;
        p[n4].needtime=p[n4].needtime-2;
        p[n4].count++;
        p[n4].state = 'W';
        RUN = 0;
        }
    }
    RUN = 1;
    int n6=0;
    while(RUN){
            if(p[n5].state=='W'){
                p[n5].state='R';
                RUN=0;
                return n5;
            }else if(n6<=N-1){
                n5 = (n5+1)%N;
                n6++;
            }else{
            n5=n4;
            return n5;
            }
    }
}

void ShowProcess(pcb p[],int n2){
    int n3;
    printf("\nid\t   cputime\t needtime\tcount\tpriority\tstate\n");
    for(n3=0;n3<N;n3++){

                printf("%s\t\t%d\t %d\t\t%d\t%d\t%c\n",p[n2].id,p[n2].runtime,p[n2].needtime,p[n2].count,p[n2].priority,p[n2].state);
                n2=(n2+1)%N;
    }
    n2=(n2+1)%N;
    printf("queue1:");
    for(n3=0;n3<N;n3++){
        if(p[n2].state=='W'){
        printf("%s",p[n2].id);
        n2=(n2+1)%N;}}
    printf("\nqueue2:");
      for(n3=0;n3<N;n3++){
        if(p[n2].state=='F'){
        printf("%s",p[n2].id);
        n2=(n2+1)%N;}}
}

void   Priority_Sorting(pcb p1[]){
    for (int i = (p1.length - 1); i >= 0; i--)
   {
      for (int j = 1; j <= i; j++)
      {
         if (p1[j-1].needtime > p1[j].needtime)
         {
              pcb temp = p1[j-1];
              p1[j-1] = p1[j];
              p1[j] = temp;
   } } } 


}

