#ifndef _LIB_H_
#define _LIB_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

using namespace std;

#define line_number 2000000

struct Trace_gcc
{
	string PC;
	string result;
};

struct BHT
{
	int* bht;
	int* predict; //0 or 1
};


void init_BHT(BHT &bht1,int M);
void init_trace(Trace_gcc &trace);
void read_line(string &a,string &b,string s);
void print_result(BHT bht1,int mis,int BHT_size,string model_name,int M,int N,string filename);


#endif
