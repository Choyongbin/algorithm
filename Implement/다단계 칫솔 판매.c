#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* getReferral(char* name, size_t enroll_len, const char* enroll[], const char* referral[], int* answer, int amount) {
    for (int i = 0; i < enroll_len; i++) {
        if (strcmp(name, enroll[i]) == 0) {
            answer[i] += amount - ((amount) / 10);
            return referral[i];
        }
    }
}
int* solution(const char* enroll[], size_t enroll_len, const char* referral[], size_t referral_len, const char* seller[], size_t seller_len, int amount[], size_t amount_len) {
    int* answer = (int*)malloc(sizeof(int) * enroll_len);
    memset(answer, 0, sizeof(int) * enroll_len);
    for (int i = 0; i < seller_len; i++) {
        char* name = seller[i];
        int price = amount[i] * 100;
        while (1) {
            name = getReferral(name, enroll_len, enroll, referral, answer, price);
            if (name == "-")
                break;
            price = (price / 10);
        }
    }

    return answer;
}