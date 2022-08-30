#include <iostream>
using namespace std;

const int MX = 1000000;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

//순회 함수
void traverse(){
    int cur = nxt[0];
    while(cur != -1){
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert(int addr, int num){
    dat[unused] = num;
    nxt[unused] = nxt[addr];
    pre[unused] = addr;

    nxt[addr] = unused;
    pre[nxt[addr]] = unused;

    unused++;
}

void erase(int addr){
    nxt[pre[addr]] = nxt[addr];
    pre[nxt[addr]] = pre[addr];

    dat[addr] = 0;
    nxt[addr] = -1;
    pre[addr] = -1;

}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void){
    fill_n(pre, MX, -1);
    fill_n(nxt, MX, -1);
    insert_test();
    erase_test();
}