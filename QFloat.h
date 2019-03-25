#pragma once
#pragma once
#ifndef __QFLOAT_H__
#define __QFLOAT_H__
#include<iostream>
#include<string>
using namespace std;
#define MAX 128

typedef struct
{
	uint32_t data[4];
}QFloat;

bool isSign(string num);

char NumToString(int n);

int StringToNum(char c);

string mult(string bigNumber, int x);

string remove_0(const string& number);

string chia_2(string bigInt);

string Reverse(string a);

string Dec_To_Bin(string userInputStr);

int SoPhanTuSauDauCham(string phanThapPhan);

string Float_1(int n);

void canBang2Chuoi_ThemVaoDau(string& a, string& b);

string CongBit_QFloat(string a, string b);

void tachQFloat(string bigFloat, string& phanNguyen, string& phanThapPhan);

void chuanHoaQFloat(string &number, int &soMu);

QFloat Arr_To_QFloat(const string& binArr);

string DecToBin_QFloat(string number);

void ScanQFloat(QFloat &x, string number);

string QFloat_To_Arr(const QFloat& number);

string _X_mu_N(int coSo, int soMu);

string congString(string a, string b);

string truString(string a, string b);


string Bin_To_Dec(string bit);

void canBang2Chuoi_ThemVaoCuoi(string &a, string &b);

string _2_Mu_Tru_N(int n);

string BinToDec_PhanThapPhan(string str);

void xoa_0_Cuoi_String(string &str);

string BinToDec_QFloat(string arr);

void PrintQfloat(QFloat number);





#endif
