#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define counterFile "counter.bin"
#define operatorFile "operator_id.bin"
#define recordFile "records.bin"
#define maxLottoNum 7
#define maxLottoNumSet 5

typedef struct lotto_record {
    int lotto_no;  //編號(counter)
    int lotto_receipt;  //收據(組數*50*1.1)
    int emp_id;  //id(input)
    char lotto_date[16];  //日期
    char lotto_time[16];  //時間
} lotto_record_t;
lotto_record_t record;

typedef struct emp_record {
    int emp_id;
    char emp_name[50];
    int emp_salary;
} emp_record_t;
emp_record_t empRecord;

void init_file() {  //判斷有無counter.bin
	int writeArray[1] = {0};
	FILE* fp = fopen(counterFile, "r");  //先打開(唯讀)
	if(fp == NULL) {  //若無此檔案
		FILE* tmpfp = fopen(counterFile, "wb+");  //開一個新的 
		fwrite(writeArray, sizeof(int), 1, tmpfp);  //寫進去"No.0" 
		fclose(tmpfp);
	} else {  //若有 
		fclose(fp);  //直接關掉，不做改變
	}
}

int get_counter() {  //讀取counter.bin(寫入readArray[0]) 
	int readArray[1];
	FILE* tmpfp = fopen(counterFile, "rb");  //唯讀
	fread(readArray, sizeof(int), 1, tmpfp);  //將讀取counter.bin(tmpfp)的結果寫入counterArray
	fclose(tmpfp);
	return readArray[0];
}

int quan = 0;  //記錄numSet 

void do_lotto_main(int counter) {  //開頭 
	char lottoFile[32];  //記錄檔名 
	int numSet = 0;  //買幾組
	int operator_id;  //ID
	char operator_name[50];
	int operator_salary;
	snprintf(lottoFile, 32, "lotto[%05d].txt", counter);  //把後面的檔案名複製到lottoFile
	printf("歡迎光臨長庚樂透彩購買機台\n");
	printf("請輸入操作人員ID : ");
	scanf("%d", &operator_id);
	if(operator_id != 0){  //ID不為0時 
		printf("請問您要購買幾組(1~5) : ");
		scanf("%d", &numSet);
		quan = numSet;
		print_lottofile(numSet, counter, lottoFile, operator_id);
		set_operatorID(operator_id);
		printf("已為您購買的 %d 組樂透組合輸出至 %s\n", numSet, lottoFile);
	} else {
		printf("請輸入要新增操作人員ID(1-99) : \n");
		scanf("%d", &operator_id);
		printf("請輸入要新增操作人員Name : \n");
		scanf("%s", &operator_name);
		printf("請輸入要新增操作人員Salary : \n");
		scanf("%d", &operator_salary);
		printf("輸入完成\n");
		femp(operator_id, operator_name, operator_salary);
	}
	
}

void print_lottofile(int numSet, int counter, char lottoFile[], int operator_id) {
	time_t curtime;
	time(&curtime);
	
	FILE* tmpfp = fopen(lottoFile, "w+");  //lottoFile[32]
	fprintf(tmpfp, "========= lotto649 =========\n");
	fprintf(tmpfp, "========+ No.%05d +========\n", counter);
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
}

void print_lotto_row(FILE* tmpfp, int n) {
	int numSet[maxLottoNum];
	
	//generate lotto row 產生號碼(亂數)  
	fprintf(tmpfp, "[%d] : ", n);
	for(int i = 0 ; i < maxLottoNum-1 ; ) {  //普通數字  
		int num = rand() % 69 + 1;
		if(num_in_numset(num, numSet, maxLottoNum-1)) {  //(下一個函式)
			continue;  //重複就繼續for迴圈 
		} else {
			numSet[i] = num;  //放進陣列
			i++;  //下一輪
		}
	}
	for(int i = 0 ; i < 1 ; ) {  //特別數字
		int num = rand() % 10 + 1;
		if(num_in_numset(num, numSet, maxLottoNum-1)) {
			continue;
		} else {
			numSet[maxLottoNum-1] = num;
			i++;
		}
	}
	
	//sorting lotto row 排序
	for(int i = 0 ; i < maxLottoNum-1 ; ++i) {
		for(int j = 0 ; j < i ; ++j) {
			if(numSet[j] > numSet[i]) {
				int temp = numSet[j];
				numSet[j] = numSet[i];
				numSet[i] = temp;
			}
		}
	}
	
	//output lotto row 印號碼
	for(int i = 0 ; i < maxLottoNum ; i++) {  
		fprintf(tmpfp, "%02d ", numSet[i]);
	}
	fprintf(tmpfp, "\n");
}

int num_in_numset(int num, int numSet[], int Len) {  //檢查是否重複 
	int ret = 0;
	for(int i = 0 ; i < Len ; i++) {
		if(num == numSet[i]) {
			ret = 1;
			break;  //跳出for迴圈 
		}
	}
	return ret;  //1:True  0:False 
}

int ID = 0;  //記錄operator_id 

void set_operatorID(int operator_id) {
	int opArray[1];
	opArray[0] = operator_id;
	ID = opArray[0];
	FILE* tmpfp = fopen(operatorFile, "ab");
	fwrite(opArray, sizeof(int), 1, tmpfp);
	fclose(tmpfp);
}
int femp(int operator_id, char operator_name[], int operator_salary) {
	empRecord.emp_id = operator_id;
	for(int i = 0 ; i < 50 ; i++) {
		empRecord.emp_name[i] = operator_name[i];
	}
	empRecord.emp_salary = operator_salary;
	FILE* fp = fopen(operatorFile, "ab");
	fwrite(&empRecord, sizeof(empRecord), 1, fp);
	fclose(fp);
	return 0;
}

int frecord(int counter, int operator_id, int numSet) {
	time_t curtime = time(0);
    record.lotto_no = counter;
    record.lotto_receipt = ((counter*50) + (numSet*50) * 1.1);
    record.emp_id = operator_id;
    strftime(record.lotto_date, 100, "%Y%m%d", localtime(&curtime));  //日期
    strftime(record.lotto_time, 100, "%H:%M:%S", localtime(&curtime));  //時間
    FILE* fre = fopen(recordFile, "ab");
    fwrite(&record, sizeof(record), 1, fre);
    fclose(fre);
}

void set_counter(int counter) {  ////記錄counter++ 
	int writeArray[1];
	writeArray[0] = counter;
	FILE* tmpfp = fopen(counterFile, "wb");
	fwrite(writeArray, sizeof(int), 1, tmpfp);
	fclose(tmpfp);
}

int main()
{
	int counter;
	init_file();  //初始化記錄檔
	counter = get_counter();  //讀取記錄檔 
	do_lotto_main(++counter);  //中間那大串
	int operator_id = ID;
    int numSet = quan;
    frecord(counter, ID, quan);
	set_counter(counter);  //記錄counter++

    return 0;
}

