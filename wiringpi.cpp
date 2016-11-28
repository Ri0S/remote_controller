#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <unistd.h>
#include <iostream>
#include <list>

#define BUF_LEN   256

#define LENGTH 7
#define HEAD 7400
#define TAIL 42000
#define ZERO 950
#define ONE 3450
#define GREEN 1
#define RED 2
using namespace std;

list<int>  writepinList;

int selectcolor = 0;
int first=0;
int Hz = 38;
int duty_num = 1;
int duty_denomi = 3;
int unit = 26;
int duty_high = 9;
int duty_low = 17;
int repeat = 1;

void high(int on_time){
    int j;
    int count = on_time/unit;
    for(j=0; j<count; j++)
    {
        for(list<int>::iterator i = writepinList.begin();i != writepinList.end() ;i++)
            digitalWrite(*i, 1);
        delayMicroseconds(duty_high);

        for(list<int>::iterator i = writepinList.begin();i != writepinList.end() ;i++)
            digitalWrite(*i, 0);
        delayMicroseconds(duty_low);
    }
}

void output(int on_time, int off_time){
    high(on_time);
    for(list<int>::iterator i = writepinList.begin();i != writepinList.end() ;i++)
        digitalWrite(*i, 0);
    delayMicroseconds(off_time);
}

void readAndSend(int command){
    int i, j, length = 9;
    int on[9], off[9];

    on[0] = HEAD;off[0] = ONE;
    on[8] = ZERO;off[8] = TAIL;

    int mask = 64;
    for(i=1; i<=LENGTH; i++){
        on[i] = ZERO;
        if(command & mask)
            off[i] = ONE;
        else
            off[i] = ZERO;
        mask /= 2;
    }

    for(j=0; j<repeat; j++){
        for(i=0; i<length; i++){
            output(on[i], off[i]);
        }
        usleep(50000);
    }
}

void send(int command){
    if(!first){
        if(wiringPiSetup() == -1){
            exit(1);
        }
        first=1;
    }
    unit = (1.0f / (Hz * 1000)) * 1000000;
    duty_high = roundf(((float)unit / duty_denomi) * duty_num);
    unit = (int)unit;
    duty_low = unit - duty_high;

    readAndSend(command);
}
