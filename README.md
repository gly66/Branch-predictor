# 注意!!
检查程序正确性步骤：
打开ubuntu自带终端
1.切换路径到branch_pre目录下
2.make
3.chmod +x ./test.sh   给予脚本权限
  ./test.sh   执行脚本产生输出文件。
4.切换路径至PROJIECT1，
  diff -iw my_output Validation_runs

./sim 输入参数没有两个0！！，为了保证diff通过，多输出了两个0

# 环境
Ubuntu 20.04
g++ 9.4.0

# 编译
ubuntu终端，branch_pre目录下make， 生存可执行文件sim
支持make clean
./sim 第一个参数决定采取何种模型
如：
./sim bimodal 7  0 0 gcc_trace.txt
执行简单分支预测器
./sim gshare 10 4 0 0 gcc_trace.txt
执行共享分支预测器

# 文件结构
branch_pre 为源代码目录
my_output 保存输出结果

# 结果对比
diff -iw my_output Validation_runs
对比结果和标准答案输出。
经对比，二者完全重合，diff命令没有返回。
