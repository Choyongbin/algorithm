#include <string>
#include <vector>
#include <iostream>

using namespace std;

//programmers JoyStick

int answer = 0;

int change(char a) {
    if (a - 'A' >= 14) {
        return 'Z' - a + 1;
    }
    else {
        return a - 'A';
    }

}

int move(int index, string name, string temp) {
    int left = 0;
    int right = 0;
    int temp_move = 0;

    temp_move = index;
    for (int i = 0; i < temp.length(); i++) {
        if (temp_move < 0)
            temp_move = temp.length() - 1;
        if (left == temp.length())
            break;
        if (temp[temp_move] == name[temp_move]) {
            left++;
            temp_move--;
        }
        else
            break;
    }
    temp_move = index;
    for (int i = 0; i < temp.length(); i++) {
        if (temp_move > temp.length())
            temp_move = 0;
        if (right == temp.length())
            break;
        if (temp[temp_move] == name[temp_move]) {
            right++;
            temp_move++;
        }
        else
            break;
    }
    if (left < right) {
        answer += left;
        if (index - left < 0) {
            int num = left - index;
            return temp.length() - num;
        }
        else
            return index - left;
    }
    else {
        answer += right;
        if (index + right >= temp.length()) {
            return index + right - temp.length();
        }
        else
            return index + right;
    }
    
    
}

int solution(string name) {
    int i = 0;
    string temp(name.length(), 'A');
    while (true) {
        if (temp == name)
            break;
        if (temp[i] == name[i]) {
            i = move(i, name, temp);
        }
        else {
            answer += change(name[i]);
            temp[i] = name[i];
        }
    }
    cout << answer;
    return answer;
}

int main() {
    string name = "CAACN";
    solution(name);
    return 0;
}