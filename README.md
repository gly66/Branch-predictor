# 注意!!
文件路径采用相对路径，
尽量在保持整个文件目录结构完整的情况下，在branch_pre路径下make
./sim 输入参数没有两个0！！，为了保证diff通过，多输出了两个0

# 环境
Ubuntu 20.04
g++ 9.4.0

# 编译
ubuntu终端，branch_pre目录下make， 生存可执行文件sim
make clean
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
