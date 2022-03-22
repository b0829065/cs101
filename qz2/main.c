#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define REPORT "Report.txt"
#define recordFile "records.bin"

typedef struct lotto_record {
    int lotto_no;  //編號(counter)
    int lotto_receipt;  //收據(組數*50*1.1)
    int emp_id;  //id(input)
    char lotto_date[16];  //日期
    char lotto_time[16];  //時間
} lotto_record_t;
lotto_record_t record;

void record_data() {  
	FILE* tmpfp = fopen(recordFile, "r");  //唯讀
	lotto_record_t tmp[1];
	char today[16];
	char lastday[16];
	int i = 0;
	
	fread(tmp,sizeof(lotto_record_t),1,tmpfp);
	for (int j = 0;j < 16; j++) {
        lastday[j] = tmp[0].lotto_date[j];
    }
	    
	while (fread(tmp,sizeof(lotto_record_t),1,tmpfp)) {
	    for (int j = 0;j < 16; j++) {
	        today[j] = tmp[0].lotto_date[j];
	    }
	    if(today == lastday){
	        
	        
	    } else {
	        lastday = today;
	    }
	    i++;
	}
	fclose(tmpfp);
}

/*void print_report() {

	FILE* tmpfp = fopen(REPORT, "w+"); 
	fprintf(tmpfp, "========= lotto649 Report =========\n");
	fprintf(tmpfp, "= Date =======+ Num. +======= Receipt =\n");
	fprintf(tmpfp, "= %.*s =\n", 24, ctime(&curtime));  //印目前時間，限制寫24格
	
	for(int i = 0 ; i < maxLottoNumSet ; i++) {  //印中間五行 
		if(i < numSet) {
			print_lotto_row(tmpfp, i+1);
		} else {
			fprintf(tmpfp, "[%d] : -- -- -- -- -- -- --\n", i+1);
		}
	}
	
	fprintf(tmpfp, "========* Op.%05d *========\n", operator_id);
	fprintf(tmpfp, "========= csie@CGU =========\n");
	fclose(tmpfp);
}*/

int main()
{
    record_data();
    return 0;
}

