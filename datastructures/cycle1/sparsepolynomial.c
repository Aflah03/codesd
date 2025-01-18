#include<stdio.h>
#define N 100
typedef struct {int coeff;int power;}term;
term p[N];

int  addPolynomial(term p[],int astart,int afinish,int bstart,int bfinish,int avail){
    int apos = astart;
    int bpos = bstart;
    int result = avail; 

    while(apos<= afinish && bpos<= bfinish+1){
        if(p[apos].power == p[bpos].power){
            p[avail].power = p[apos].power;
            p[avail].coeff = p[apos].coeff+ p[bpos].coeff;
            apos++;
            bpos++;
            avail++;
        }else if(p[apos].power> p[bpos].power){
            p[avail].coeff = p[apos].coeff;
            p[avail].power = p[apos].power;
            avail++;
            apos++;
        }else{
            p[avail].coeff = p[bpos].coeff;
            p[avail].power = p[bpos].power;
            avail++;
            bpos++;

        }
    }
    while(apos<= afinish){
        p[avail].power= p[apos].power;
        p[avail].coeff= p[apos].coeff;
        result++;
        avail++;
    }
    while(bpos<= bfinish){
        p[avail].power= p[bpos].power;
        p[avail].coeff= p[bpos].coeff;
        bpos++;
        avail++;
    }
    return avail;
}
int main(){
    //input terms
    int astart = 0;
    int n1,n2;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d",&n1);
    getchar();

    printf("Enter the coeff and power: ");
    for(int i=0;i<n1;i++){
        scanf("%d %d",&p[i].coeff,&p[i].power);
        getchar();
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d",&n2);
    getchar();
    printf("Enter the coeff and power: ");
    for(int i=n1;i<=n1+n2-1;i++){
        scanf("%d %d",&p[i].coeff,&p[i].power);
        getchar();
    }

    int afinish = n1-1;
    int bstart = n1;
    int bfinish = n1+n2-1;
    int avail = n1+n2;
  
    int resultfinish =addPolynomial(p,astart,afinish,bstart,bfinish,avail);
    for(int i=0;i<n1+n2;i++){
        printf("%dx^%d ",p[i].coeff,p[i].power);
    }
    printf("the result is :\n");
    for(int i=n1+n2;i<resultfinish;i++){
        printf("%dx^%d ",p[i].coeff,p[i].power);
    }


}