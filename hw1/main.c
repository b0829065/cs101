#include <stdio.h>
#include <stdlib.h>
#include <time.h>
FILE* fp;

void NowTime() {
    time_t curtime;
    time(&curtime);
    fprintf(fp,"%s",ctime(&curtime));
}

void HowManyLotto(int *num) {
    int a;
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問你要買幾組: ");
    scanf("%d",&a);
    if((a>=1) && (a<=5)){
        printf("已為您購買的 %d 組樂透組合輸入至 Lotto.txt\n",a);
        *num = a;
    } else {
        printf("只能輸入1~5組樂透\n");
    }
}

int Num(int *num) {
    int numbers[6];
    int c;
    srand(time(0));
    for(int i=0;i<*num;i++) {
        fprintf(fp,"[%d]:",i+1);
        
        for(int j=0;j<6;j++) {
            int temp = rand()%69 + 1;
            numbers[j] = temp;  
        } 
        for(int z=5; z>=1; z--){
            for(int x=0; x<z; x++){
                if(numbers[x+1]<numbers[x]){
                    c=numbers[x+1];
                    numbers[x+1]=numbers[x];
                    numbers[x]=c;
                }
            }
        }
    for(int q = 0; q<6; q++){
        fprintf(fp, " %0*d",2,numbers[q]);
    }
    fprintf(fp," %0*d\n",2,rand()%10 + 1); 
    }   
}

int main(){
    fp = fopen("Lotto.txt","w+");
    int num = 0;
    HowManyLotto(&num);
    fprintf(fp,"========lotto649========\n");
    NowTime();
    Num(&num);
    for(int i=0;i<5-num;i++) {
        fprintf(fp,"[%d]: -- -- -- -- -- -- --\n", num + i + 1);
    }   
    
    fprintf(fp,"======= csie@CGU =======\n");
    fclose(fp);
    return 0;
}