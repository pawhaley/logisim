#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>


using namespace std;

int num(string s){
    if(s.size()!=3){
        return -1;
    }
    int ret=0;
    for(int i=0;i<3;i++){
        ret*=256;
        ret+=s[i];
    }
    return ret;
}



int instruct(string s){
    switch (num(s)){
    case 'add':
        return 1;
    case 'sub':
        return 2;
    case 'mul':
        return 3;
    case 'div':
        return 4;
    case 'mov':
        return 5;
    case 'jmp':
        return 6;
    case 'jle':
        return 7;
    }
    return 0;
}

int reg(char c){
    if(c=='!'){
        return 0;
    }
    return c-'A'+1;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("done.txt");
    int num;
    char c1;
    char c2;
    char c0;
    char tempc;
    int inst;
    string temps;
    int numrep[4];
    while(!in.eof()){
        in>>num;
        for(int i=0;i<4;i++){
            numrep[3-i]=num%16;
            num/=16;
        }
        in>>c1;
        in>>c2;
        temps.clear();
        for(int i=0;i<3;i++){
            in>>tempc;
            temps.push_back(tempc);
        }
        inst=instruct(temps);
        in>>c0;
        for(int i=0;i<4;i++){
            out<<hex<<numrep[i];
        }
        out<<hex<<reg(c1);
        out<<hex<<reg(c2);
        out<<hex<<inst;
        out<<hex<<reg(c0);
        out<<" ";
    }
}
