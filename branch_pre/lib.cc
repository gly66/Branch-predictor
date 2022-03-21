#include "lib.h"

void init_BHT(BHT &bht1,int a){
    
    bht1.bht = (int*)malloc(sizeof(int)*a);
    bht1.predict = (int*)malloc(sizeof(int)*a);
    for(int i=0;i<a;i++){
        bht1.bht[i]=2;
        bht1.predict[i]=1;
    }

}
void init_trace(Trace_gcc &trace){
    
    trace.PC ="";
    trace.result ="";

}

void read_line(string &a,string &b,string s){
    stringstream word(s);
    word >> a;
    word >> b;
}

void print_result(BHT bht1,int mis,int BHT_size,string model_name,int M,int N,string filename){
    string Output_filename;
    if(model_name == "bimodal" && M == 7 && N==0){
        Output_filename = "val_bimodal_1.txt";
    }
    else if(model_name == "bimodal" && M == 10 && N==0){
        Output_filename = "val_bimodal_2.txt";
    }
    else if(model_name == "bimodal" && M == 5 && N==0){
        Output_filename = "val_bimodal_3.txt";
    }
    else if(model_name == "bimodal" && M == 6 && N==0){
        Output_filename = "val_bimodal_4.txt";
    }
    else if(model_name == "gshare" && M == 10 && N==4){
        Output_filename = "val_gshare_1.txt";
    }
    else if(model_name == "gshare" && M == 14 && N==9){
        Output_filename = "val_gshare_2.txt";
    }
    else if(model_name == "gshare" && M == 11 && N==5){
        Output_filename = "val_gshare_3.txt";
    }
    else if(model_name == "gshare" && M == 10 && N==6){
        Output_filename = "val_gshare_4.txt";
    }
    Output_filename = "../my_output/" + Output_filename;        
    ofstream outfile(Output_filename,ios::trunc);
    outfile << "COMMAND"<<endl;
    outfile << "./sim " << model_name <<" "<<M<<" ";
    if(N!=0){
    outfile << N;
    }
    outfile << " "<<"0 "<<"0 "<<filename<<endl;
    outfile << "OUTPUT"<<endl;
    outfile << "number of predictions:  "<<line_number<<endl;
    outfile << "number of mispredictions:  "<<mis<<endl;
    outfile <<"misprediction rate:  "<<fixed<<setprecision(2)<<(1.0*mis/line_number)*100<<"%"<<endl;
    outfile <<"FINAL ";
    if (model_name == "bimodal")
    {
        outfile << "BIMODAL ";
    }
    else if (model_name == "gshare")
    {
        outfile << "GSHARE ";
    }
    outfile <<"CONTENTS"<<endl;
	for (int i = 0; i < BHT_size; i++)
	{
		outfile <<i<<"  "<< bht1.bht[i]<<endl;
    }
}
