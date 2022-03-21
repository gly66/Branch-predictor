#include "lib.h"




int main(int argc, char *argv[]) {

	//可统计一波文件行数，算/n的个数。cal_line()
	string  model_name = argv[1];
	int mispredictions = 0;
	Trace_gcc trace;
	init_trace(trace);
	if (model_name == "bimodal")
	{
		int M1 = atoi(argv[2]);
		int BHT_size = pow(2,M1);
		if(M1<=0 || M1>=30){
			cout<<"选取PC的位数不合适！！"<<endl;
			return -1;
		}
		string file_name = argv[3];
		string f = file_name;
		file_name = "../traces/" + file_name;
		//初始化BHT，为2
		BHT bht1;
		init_BHT(bht1,BHT_size);
    	ifstream in(file_name);

	    ///for 每次读取trace一行(read_line())，根据PC的 2-M1+1位访问BHT对应的predict，根据trace实际跳转结果，更新BHT（bht和predict）,同时比对predict和实际，若predict错误则统计。
		for(int i=0;i<line_number;i++){
        	string s;
        	getline(in,s);
			read_line(trace.PC,trace.result,s);
			//将字符串PC转化为int
			uint32_t N_PC = stoi(("0x" + trace.PC),0,0);
			uint32_t addr = (N_PC << (30-M1))>>(32-M1);
			int R_result;
			//根据PC的2-M1位访问bht
			if (trace.result == "n")
			{
				R_result = 0;
			}
			else{
				R_result = 1; 
			}
			
			//预测错误
			if(R_result != bht1.predict[addr]){
				mispredictions++;
			}
			//bht更新
			if(R_result == 1 && bht1.bht[addr] < 3){
				bht1.bht[addr]++;
			}
			else if(R_result == 0 && bht1.bht[addr] > 0){
				bht1.bht[addr]--;
			}
			//predict根据brt值更新
			if(bht1.bht[addr]>=2){
				bht1.predict[addr] = 1;
			}
			else{
				bht1.predict[addr] = 0;
			}
		}
		
		print_result(bht1,mispredictions,BHT_size,model_name,M1,0,f);
		
	}
	else if (model_name == "gshare")
	{
		int M2 = atoi(argv[2]);
		if(M2<=0 || M2>=30){
			cout<<"选取PC的位数不合适！！"<<endl;
			return -1;
		}
		int BHT_size = pow(2,M2);
		int N = atoi(argv[3]);
		if(N<=0 || N>M2){
			cout<<"选取GBHR的位数不合适！！"<<endl;
			return -1;
		}
		string file_name = argv[4];
		string f = file_name;
		file_name = "../traces/" + file_name;
		uint32_t GBHR=0;
		BHT bht2;
		init_BHT(bht2,BHT_size);
    	ifstream in(file_name);
		for(int i=0;i<line_number;i++){
        	string s;
        	getline(in,s);
			read_line(trace.PC,trace.result,s);
			//将字符串PC转化为int
			uint32_t N_PC = stoi(("0x" + trace.PC),0,0);
			uint32_t addr = (N_PC << (30-M2))>>(32-M2);
			uint32_t M2_a = GBHR << (M2-N);
			addr = addr ^ M2_a; 

			int R_result;
	
			if (trace.result == "n")
			{
				R_result = 0;
			}
			else{
				R_result = 1; 
			}
			
			//预测错误
			if(R_result != bht2.predict[addr]){
				mispredictions++;
			}
			//bht,GBHR更新
			if(R_result == 1 ){
				if(bht2.bht[addr] < 3){
					bht2.bht[addr]++;
				}
				uint32_t pos = 1<<(N-1);
				GBHR = GBHR>> 1;
				GBHR |= pos;

			}
			else if(R_result == 0){
				if(bht2.bht[addr] > 0){
					bht2.bht[addr]--;
				}
				GBHR >>= 1;

			}
			//predict根据brt值更新
			if(bht2.bht[addr]>=2){
				bht2.predict[addr] = 1;
			}
			else{
				bht2.predict[addr] = 0;
			}

		}
		print_result(bht2,mispredictions,BHT_size,model_name,M2,N,f);
	}
	else{
		cout<<"输入参数错误！！,请输入bimodal或gshare"<<endl;
		return -1;
	}
	
	

}
