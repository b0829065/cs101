#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
FILE *fp;

void NowTime() {
    time_t curtime;
    time(&curtime);
    char* now = ctime(&curtime);
    now[strlen(now)-1] = 0;
    fprintf(fp,"= %s=\n",now);
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
    srand(time(NULL));
    for (int k = 1; k <= 5; k++) {
        if (k > *num) {
            fprintf(fp,"[%d]: -- -- -- -- -- -- --\n",k);
        } else {
            fprintf(fp,"[%d]: ",k);
            int a[70];
            
            for (int i = 0; i < 70; i++) {
                a[i] = i+1;
            }
    
            for (int i = 0; i < 69; i++) {
                int r = rand() % 69, tmp = a[i];
                a[i] = a[r];
                a[r] = tmp;
            }
    
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5-j; k++) {
                    if (a[k] > a[k+1]) {
                        int b = a[k];
                        a[k] = a[k+1];
                        a[k+1] = b;
                    }
                }
            }
    
            for(int i = 0; i <= 5; i++) {
                fprintf(fp,"%0*d ",2,a[i]);
            }
            for(int i = 6; i <= 68; i++) {
                if(a[i] < 11) {
                    fprintf(fp,"%0*d\n",2,a[i]);
                    break;
                }
            }
        }
    }
}

int countf() {
    int n;
    if ((fp = fopen("count.bin","rb+")) == NULL) {
        n = 0;
        fp = fopen("count.bin","wb");
        fwrite(&n,sizeof(int),1,fp);
        fclose(fp);
    }
    fp = fopen("count.bin","rb+");
    fread(&n,sizeof(int),1,fp);
    
    n = n + 1;
    fp = fopen("count.bin","wb+");
    fwrite(&n,sizeof(int),1,fp);
    fclose(fp);
    return n;
}

void namef(char name[],int c) {
    for (int i = 8; i >= 5; i--,c /= 10) {
        name[i] = (c%10+'0');
    }
}


int main() {
    int num;
    HowManyLotto(&num);
    int count = countf();
    char name[10] = "lotto";
    namef(name,count);
    
    fp = fopen(name,"w+");
    fprintf(fp,"======== lotto649 =========\n");
    fprintf(fp,"=======+ No. %05d +=======\n",count);
    NowTime();
    Num(&num);
    fprintf(fp,"======== csie@CGU =========\n");
    fclose(fp);
    return 0;
}
