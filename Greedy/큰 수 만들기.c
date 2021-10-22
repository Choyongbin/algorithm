#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* number, int k) {
    char* answer = (char*)calloc(strlen(number) - k + 1, sizeof(char));
    int index = -1;
    int answerIndex = 0;
    for (int i = 0; i < strlen(number) - k; i++) {
        char maxChar = "0";
        for (int j = index + 1; j <= k + i; j++) {
            if ((int)maxChar < (int)number[j]) {
                index = j;
                maxChar = number[j];
            }
        }
        answer[answerIndex] = maxChar;
        answerIndex++;
    }
    return answer;
}