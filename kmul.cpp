#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SI 2001

void add(char *c1, char *c2, char *sum, int n1_end, int n2_end,int *n3_end);
void sub(char *a, char *b, char *result, int ae, int be, int *rese);
void printNUM(char *n, int e);
void time_two(char *n, int *e);
int  divi_two(char *n, int *e);
void kmul(char *n1, char *n2, char *n3, int e1, int e2, int *e3);
int ai(char c);

int times = 1;

int main() {
	char *n1, *n2, n3[SI] = { '0' };
	int n3_end = 0;
	n1 = (char*)(malloc(sizeof(char)));
	n2 = (char*)(malloc(sizeof(char)));
	while(true){
		n3_end = 0;
		printf("輸入你的第一個數: ");
		scanf("%s", n1);
		int n1_end = strlen(n1)-1;

		printf("輸入你的第二個數: ");
		scanf("%s", n2);
		int n2_end = strlen(n2)-1;

		bool isNum = true;
		for(int i=0;i<=n1_end;i++){
			if(ai(n1[i]) == -1){
				printf("你的輸入並非數字，請重新輸入\n");
				isNum = false;
				break;
			}
		}
		if(!isNum) continue;

		for(int i=0;i<=n2_end;i++){
			if(ai(n2[i]) == -1){
				printf("你的輸入並非數字，請重新輸入\n");
				isNum = false;
				break;
			}
		}
		if(!isNum) continue;

		else{
			kmul(n1, n2, n3, n1_end, n2_end, &n3_end);
			printf("答案: ");
			printNUM(n3, n3_end);
		}
	} 
	system("pause");
	return 0;
}

int ai(char c) {
	if      (c == '0') return 0;
	else if (c == '1') return 1;
	else if (c == '2') return 2;
	else if (c == '3') return 3;
	else if (c == '4') return 4;
	else if (c == '5') return 5;
	else if (c == '6') return 6;
	else if (c == '7') return 7;
	else if (c == '8') return 8;
	else if (c == '9') return 9;
	else               return -1;
}

char ia(int i) {
		 if	(i == 0) return '0';
	else if (i == 1) return '1';
	else if (i == 2) return '2';
	else if (i == 3) return '3';
	else if (i == 4) return '4';
	else if (i == 5) return '5';
	else if (i == 6) return '6';
	else if (i == 7) return '7';
	else if (i == 8) return '8';
	else if (i == 9) return '9';
}

void time_two(char *n, int *e) {
	add(n, n, n, *e, *e, e);
}

void add(char *c1, char *c2, char *sum, int n1_end, int n2_end, int *n3_end) {
	int temcarry = 0, temsum = 0, numend = SI-1;
	char temre[SI];

	for (int i = n1_end, j = n2_end; (i >= 0) || (j >= 0); i--, j--, numend--) {
		if (i >= 0 && j >= 0) { temsum = ai(c1[i]) + ai(c2[j]) + temcarry; }  //等長加法
		else if (i >= 0 && j < 0) { temsum = ai(c1[i]) + temcarry; }		  //第一個數較長
		else if (i < 0 && j >= 0) { temsum = ai(c2[j]) + temcarry; }		  //第二個數較長

		temcarry = temsum / 10;
		temsum %= 10;

		temre[numend] = ia(temsum);
	}
	if (temcarry == 1) {temre[numend] = ia(temcarry);} else{numend++;}  	  //進位進去

	for (int i = numend,j=0; i <= SI-1; i++,j++) {              		      //把TEM放進結果
		sum[j] = temre[i];
		*n3_end = j;
	}
}

void printNUM(char *n, int e) {
	for (int i = 0; i <= e; i++) {
		printf("%c", n[i]);
	}printf("\n");
}

int divi_two(char *n, int *e) {
	int left = 0, num = 0, head = 0;

	for (int i = 0; i <= *e; i++, head++) {
		num = (left * 10 + ai(n[i])) / 2;
		left = (left * 10 + ai(n[i])) % 2;
		if (i == 0 && num == 0) { head--; }
		else { n[head] = ia(num); }
	}
	*e = head - 1;
	return left;
}

void sub(char *a, char *b, char *result, int ae, int be, int *rese) {
	if (ae < be) { printf("懶得算負數1\n"); }
	else {
		int de = 0,re=0,te=SI;
		char tem[SI];
		for (int i = ae, j = be; i >= 0 || j >= 0; i--, j--) {
			if (i >= 0 && j >= 0) { re = ai(a[i]) - ai(b[j]) - de; }
			else { re = ai(a[i])- de; }
			
			if (re < 0) { re += 10; de = 1; }
			else { de = 0; }
			te--;
			tem[te] =ia(re);
		}
		if (de == 1) { printf("懶得算負數2\n"); }
		else {
			if (tem[te] == '0') { te++; }
			for (int i = 0, j = te; j < SI; i++, j++) {
				result[i] = tem[j];
				*rese = i;
			}
		}
	}
}

void kmul(char *n1, char *n2, char *n3, int e1, int e2, int *e3) {
	if (e2 == 0){
		if (n2[0] == '0') {
			n3[0] = '0';
			*e3 = 0;	}
		else {
			add(n1, n1, n3, e1, e1, e3); //把數字放到RESULT
			divi_two(n3, e3);
			for (int i = ai(n2[0]); i > 1; i--) {
				add(n1, n3, n3, e1, *e3, e3);	}}}
	else if (e1 == 0) {
		if (n1[0] == '0') {
			n3[0] = '0';
			*e3 = 0;	
		}
		else {
			add(n2, n2, n3, e2, e2, e3); //把數字放到RESULT
			divi_two(n3, e3);
			for (int i = ai(n1[0]); i > 1; i--) {
				add(n2, n3, n3, e2, *e3, e3);}}}
	else {
		int len = e1 >= e2 ? (e2 + 1) / 2 : (e1 + 1) / 2, ae = 0, be = 0, re = 0, wye = 0, xze = 0; //len等於長度較小的一半  a跟b取的LEN一樣長
		char a[SI], b[SI], r[SI], wy[SI], xz[SI];

		add(n1, n1 + e1 - len + 1, a, e1 - len, len - 1, &ae);					//a=(w+x)
		add(n2, n2 + e2 - len + 1, b, e2 - len, len - 1, &be);					//b=(y+z)
		kmul(a, b, r, ae, be, &re);												//r=(w+x)(y+z)

		kmul(n1, n2, wy, e1 - len, e2 - len, &wye);								//wy
		kmul(n1 + e1 - len + 1, n2 + e2 - len + 1, xz, len - 1, len - 1, &xze);	//xz

		sub(r, wy, r, re, wye, &re); 
		sub(r, xz, r, re, xze, &re);	//r=(wz+xy)

		int expwx = len * 2, expr = len;
		for (int i = 1; i <= expwx; i++) {  wy[wye + i] = '0';	}
		wye = wye + expwx;
		for (int i = 1; i <= expr; i++)  {	r[re + i] = '0';	}
		re = re + expr;
		add(wy, xz, n3, wye, xze, e3);
		add(r, n3, n3, re , *e3, e3);
	}
}
