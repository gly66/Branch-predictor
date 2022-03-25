#!/bin/bash
# chmod +x ./test.sh


./sim bimodal 7 gcc_trace.txt
./sim bimodal 10 gcc_trace.txt
./sim bimodal 5 jpeg_trace.txt
./sim bimodal 6 perl_trace.txt

./sim gshare 10 4 gcc_trace.txt
./sim gshare 14 9 gcc_trace.txt
./sim gshare 11 5 jpeg_trace.txt
./sim gshare 10 6 perl_trace.txt
echo "已产生输出在my_output中"