//스택(Stack) 직접 구현
#include <iostream>
using namespace std;

const int MX = 1000005;
// 스택 자료구조 생성 -> dat
int dat[MX];
// pos는 다음에 원소를 추가할 곳이면서 현재 스택 내의 원소 수
int pos = 0;

void push(int x){
    dat[pos] = x;
    pos++;
}

void pop(){
    pos--;
    dat[pos] = 0; 
}

int top(){
    return dat[pos-1];
}

void test(){
    push(5); push(4); push(3);
    cout << top() << '\n'; // 3
    pop(); pop();
    cout << top() << '\n'; // 5
    push(10); push(12);
    cout << top() << '\n'; // 12
    pop();
    cout << top() << '\n'; // 10
}

int main(void){
	test();
}