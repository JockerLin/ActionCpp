#pragma once
#define NOMINMAX
#include <Windows.h>
#include <iostream>
#include <algorithm>

#define ParamsNum 100;

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

struct ParamStrOld
{
	int p_int_1 = 9;
	int p_int_2 = 9;
	int p_int_3 = 9;
	int p_int_4 = 9;

	double p_float_1 = 9;
	double p_float_2 = 9;
	double p_float_3 = 9;
	double p_float_4 = 9;
	double p_float_5 = 9;
	double p_float_6 = 9;
	double p_float_7 = 9;
	double p_float_8 = 9;
	double p_float_9 = 9;
	double p_float_10 = 1.2;
	double p_float_11 = 1.32;
	double p_float_12 = 1.2;
	double p_float_13 = 1.32;
	double p_float_14 = 1.42;
	double p_float_15 = 1.12;
	double p_float_16 = 1.2;
	double p_float_17 = 1.32;
	double p_float_18 = 1.42;

	float p_f_1 = 9;
	float p_f_2 = 3.1415926;
	float p_f_3 = 3.1415926;
	float p_f_4 = 3.1415926;
	float p_f_5 = 3.1415926;

	float p_f_6 = 9;
	float p_f_7 = 3.1415926;
	float p_f_8 = 3.1415926;
	float p_f_9 = 3.1415926;
	float p_f_10 = 3.1415926;

	char p_char_1[40] = "old";
	char p_char_2[40] = "old";
	char p_char_3[40] = "old";
	char p_char_4[40] = "old";
	char p_char_5[40] = "old";
	char p_char_6[40] = "old";
	char p_char_7[40] = "old";
	char p_char_8[40] = "old";
	char p_char_9[40] = "old";
	char p_char_10[40] = "old";
	char p_char_11[40] = "old";
	char p_char_12[40] = "old";
	char p_char_13[40] = "old";
	char p_char_14[40] = "old";
	char p_char_15[40] = "old";
	char p_char_16[40] = "old";
	char p_char_17[40] = "old";
	char p_char_18[40] = "old";
	char p_char_19[40] = "old";
	char p_char_20[40] = "old";
};

struct ParamStr1
{
	int p_int_1 = 0;
	int p_int_2 = 0;
	int p_int_3 = 0;
	int p_int_4 = 0;

	double p_float_1 = 1.12;
	double p_float_2 = 1.2;
	double p_float_3 = 1.32;
	double p_float_4 = 1.42;
	double p_float_5 = 1.12;
	double p_float_6 = 1.2;
	double p_float_7 = 1.32;
	double p_float_8 = 1.42;
	double p_float_9 = 1.12;
	double p_float_10 = 1.2;
	double p_float_11 = 1.32;
	double p_float_12 = 1.2;
	double p_float_13 = 1.32;
	double p_float_14 = 1.42;
	double p_float_15 = 1.12;
	double p_float_16 = 1.2;
	double p_float_17 = 1.32;
	double p_float_18 = 1.42;

	float p_f_1 = 3.1415926;
	float p_f_2 = 3.1415926;
	float p_f_3 = 3.1415926;
	float p_f_4 = 3.1415926;
	float p_f_5 = 3.1415926;

	float p_f_6 = 3.1415926;
	float p_f_7 = 3.1415926;
	float p_f_8 = 3.1415926;
	float p_f_9 = 3.1415926;
	float p_f_10 = 3.1415926;

	char p_char_1[40] = "new";
	char p_char_2[40] = "new";
	char p_char_3[40] = "new";
	char p_char_4[40] = "new";
	char p_char_5[40] = "new";
	char p_char_6[40] = "new";
	char p_char_7[40] = "new";
	char p_char_8[40] = "new";
	char p_char_9[40] = "new";
	char p_char_10[40] = "new";
	char p_char_11[40] = "new";
	char p_char_12[40] = "new";
	char p_char_13[40] = "new";
	char p_char_14[40] = "new";
	char p_char_15[40] = "new";
	char p_char_16[40] = "new";
	char p_char_17[40] = "new";
	char p_char_18[40] = "new";
	char p_char_19[40] = "new";
	char p_char_20[40] = "new";

	char p_char_31[40] = "new";
	char p_char_32[40] = "new";
	char p_char_33[40] = "new";
	char p_char_34[40] = "new";
	char p_char_35[40] = "new";

};

class windowAPI
{
public:
	
	std::string file_name = "my_param_data.vmd";
	ParamStr1 params[100], params_restore[100];;
	ParamStrOld params_old[100];
	void saveFile();
	void restoreFile();

	void prepare();
	void exec();
};

