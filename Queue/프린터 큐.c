#include <stdio.h>

int rear = 0, front = 0;

struct Node {
	int pri; //몇 번째
	int data; // 값
};

void push(struct Node *q, int *maxData, int data, int pri) {
	q[rear].data = data;
	q[rear].pri = pri;
	maxData[rear] = data;
	rear++;
}

void pop(struct Node* q, int* maxData, int m, int n) {
	int count = 1;	
	int num = 0;
	int max = maxData[num];
	while (1) {
		//printf("%d\n", max);
		if (q[front].data == max) {
			if (q[front].pri == m) {
				printf("%d\n", count);
				return;
			}
			else {
				front++;
				count++;
				num++;
				max = maxData[num];
			}
		}
		else {
			q[rear] = q[front];
			rear++;
			front++;
		}
	}
}

void swap(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				int temp;
				temp = arr[j+1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}



int main() {
	int t, n, m;
	scanf_s("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf_s("%d %d", &n, &m);
		struct Node queue[5500] = { 0 };
		int maxData[101] = { 0 };
		rear = 0;
		front = 0;
		for (int j = 0; j < n; j++) {
			int pri;
			scanf_s("%d", &pri);
			push(queue, maxData, pri, j);
		}
		swap(maxData, n);
		pop(queue,maxData, m, n);
	}
	
	return 0;
}