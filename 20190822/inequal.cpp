# include <stdio.h>
int k;
int result[10];
bool check[10];
char opt2[20];
int max = 0;
int min = 0;
int stat=0;
int max_stat=0;
void getResult1(int cur, int n, int result[]) {	

	if (cur >= n) {
		int cnt = 0;
		for (int i = 0; i <= k; i++) {
			if (opt2[i] == '>') {
				if (result[i] > result[i + 1]) { 
					cnt++;  
				}
			}
			else if (opt2[i] == '<') {			
				if (result[i] < result[i + 1]) { 
					cnt++;  
				}
			}
		}
   	
		if (cnt == k) {
		  if(stat==0){
		    	for (int i = 0; i <= k ; i++) {
				     printf("%d", result[i]);
		     	}printf("\n");
		  }
		  
		
			stat++;
			max_stat=stat;
			//	printf("stat:%d ",stat);
		}
   
	}
	else {
		for (int i = 9; i >=0; i--) {
			if (check[i] == false) {
				result[cur] = i;
				check[i] = true;
				getResult1(cur + 1, n, result);
				result[cur] = 0;
				check[i] = false;
			}
		}
	}
}

void getResult2(int cur, int n, int result[]) {	

	if (cur >= n) {
		int cnt = 0;
		for (int i = 0; i <= k; i++) {
			if (opt2[i] == '>') {
				if (result[i] > result[i + 1]) { 
					cnt++;  
				}
			}
			else if (opt2[i] == '<') {			
				if (result[i] < result[i + 1]) { 
					cnt++;  
				}
			}
		}
   	
		if (cnt == k) {
		  if(stat==max_stat-1){
		    	for (int i = 0; i <= k ; i++) {
				     printf("%d", result[i]);
		     	}printf("\n");
		  }
		  
		
			stat++;
		}
   
	}
	else {
		for (int i = 9; i >=0; i--) {
			if (check[i] == false) {
				result[cur] = i;
				check[i] = true;
				getResult2(cur + 1, n, result);
				result[cur] = 0;
				check[i] = false;
			}
		}
	}
}


int main() {
	scanf("%d\n", &k);
// 	fgets(opt, 10, stdin);
	
	
// 	int idx=0;
// 	for (int i = 0; i < sizeof(opt); i++) {
// 		if (opt[i] != ' ') {
// 			opt2[idx++]=opt[i];
// 		}
// 	}
  for(int i=0;i<k;i++){
    scanf("%c ",&opt2[i]);
  }
	
	getResult1(0,k+1,result); 
	stat=0;
	getResult2(0,k+1,result); 
	return 0;
}