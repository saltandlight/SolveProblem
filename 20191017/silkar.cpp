#include <stdio.h>
#include <queue>

using namespace std;

const int MAX = 50;
char arr[MAX][MAX];
int gan_x[4] = { -1,1,0,0 };
int gan_y[4] = { 0,0,1,-1 };
int check_water[MAX][MAX] = { 0, };
int r, c;

void waterBFS() {
	bool flag = false;
	queue <int> Queue_x;
	queue <int> Queue_y;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == '*') { //현재 좌표 
				Queue_x.push(i); Queue_y.push(j);
				check_water[i][j]++;

				while (!Queue_x.empty() && !Queue_y.empty()) {
					int cur_x = Queue_x.front();
					int cur_y = Queue_y.front();

					Queue_x.pop(); Queue_y.pop();

					for (int m = 0; m < 4; m++) {
						int new_x = cur_x + gan_x[m]; int new_y = cur_y + gan_y[m];
						if (new_x > -1 && new_y > -1 && new_x < r && new_y < c && arr[new_x][new_y] != 'D' && arr[new_x][new_y] != 'X' && check_water[new_x][new_y] == 0) {
							// printf("%d %d\n", new_x, new_y);
							Queue_x.push(new_x); Queue_y.push(new_y);
							check_water[new_x][new_y] = check_water[cur_x][cur_y] + 1;
							arr[new_x][new_y] = '*';

						}//end-if
					}//end-for

					for (int i = 0; i < r; i++) {
						for (int j = 0; j < c; j++) {
							if (arr[i][j] == '*') {
								printf("%d ", check_water[i][j]);
							}
							else printf("%c ", arr[i][j]);
						}printf("\n");
					}printf("\n");

				}

				//확인하는 애 

			}//end-if



		}
	}//end-for






}




int main() {
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++) {
		scanf("%s", &arr[i]);
	}

	waterBFS();

	return 0;
}