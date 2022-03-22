#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define REPORT "Report.txt"
#define RECORD_FILE "records.bin"

typedef struct lotto_record {
    int lotto_no;  //編號(counter)
    int lotto_receipt;  //收據(組數*50*1.1)
    int emp_id;  //id(input)
    char lotto_date[16];  //日期
    char lotto_time[16];  //時間
} lotto_record_t;
lotto_record_t record;

void print_report() {
 FILE* recordFile = fopen(RECORD_FILE, "r");  //唯讀
 lotto_record_t tmp[256];
 int i = 0;
 while (fread(&tmp[i], sizeof(lotto_record_t), 1, recordFile)) {
     i++;
 }
 fclose(recordFile);
 
 
    FILE* reportFile = fopen(REPORT,"w+");
    
 fprintf(reportFile,"========= lotto649 Report =========\n");
 fprintf(reportFile,"- Date ------- Num. ------ Receipt -\n");
  
    char today[32];
    time_t now = time(0);
    strftime (today,100,"%Y%m%d",localtime(&now));

    int dateSum = 0, noSum = 0, setsSum = 0, receiptSum = 0;
    int Day = 0, SameDay = 0;
    int D_no = 0;
    
    while (Day < i) {
        int D_receipt = 0;
        int D_sets = 0;
        
        while(strcmp(tmp[Day].lotto_date,tmp[Day+1].lotto_date)==0) Day++;
        
        for (; SameDay <= Day ; SameDay++) {
            D_sets = D_sets + (tmp[SameDay].lotto_receipt/55);
            D_receipt = D_receipt + tmp[SameDay].lotto_receipt;
        }
        SameDay = SameDay - 1;
        D_no = tmp[SameDay].lotto_no - noSum ;
        dateSum = dateSum + 1;
        setsSum = setsSum + D_sets;
        receiptSum = receiptSum + D_receipt;
        noSum = tmp[SameDay].lotto_no;
        
        fprintf(reportFile,"%s\t\t%d/%d\t\t%d\n",tmp[SameDay].lotto_date,D_no,D_sets,D_receipt);
        Day++;
        SameDay++;
    }
    fprintf(reportFile,"-----------------------------------\n");
    fprintf(reportFile,"\t\t%d\t\t%d/%d\t\t%d\n",dateSum,tmp[i-1].lotto_no,setsSum,receiptSum);
    fprintf(reportFile,"======== %s Printed =========",today);
    
    fclose(reportFile);
}

int main()
{
    print_report();
    return 0;
}
