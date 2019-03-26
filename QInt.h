#pragma once
#ifndef __QINT_H__
#define __QINT_H__
#include "xuLiString.h"
#include <bitset>
#include<vector>
#include<fstream>
#include<cstring>
#define MAX 128



// do ko chac unsigned int luon la 4 bytes, nen dung unit32_t
struct QInt
{
	uint32_t data[4] = { 0 };

	//struct tu dong gan cai nay r, k can ham nay
	/*QInt& operator=(const QInt &number2)
	{
		if (this != &number2)
		{
			for (int i = 0; i < 4; i++)
			{
				data[i] = number2.data[i];
			}
		}
		return *this;
	}*/

	QInt& operator=(const int &number2);

};


// Ham lay bu 1
string bu1(string a);



//Ham lay bu 2
string bu2(string a);



//Ham chuyen tu QInt sang mang int a[MAX]
string QInt_To_Arr(const QInt& number);



//Ham chuyen tu mang a sang Qint
QInt Arr_To_QInt(const string& binArr);

//he 10 -> he 2
string DecToBin(string userInputStr);


// he 2 -> he 10
string BinToDec(string bit);

//ham chuyen (bo 4 bit) Bin sang gia tri HEX tuong ung
char nibbles(string binVal);

// he 2 -> he 16
string BinToHex(string bin);


// he 10 -> he 16
string DecToHex(string dec);


//chuyen tu chu cai tu hex sang bin tuong ung
string tu16_2(char x);


//he 16 -> he 2
string HexToBin(string HexStr);

// he 16 -> he 10
string HexToDec(string HexStr);


//Ham nhap so QInt, con thieu cai doc File, ko biet cho 2 tham so co dc ko
void ScanQInt(QInt &number, string userInputStr);

//ham xuat so QInt, xuat ra so he thap phan
void PrintQInt(QInt number);



//=============================  CAC TOAN TU <, >, >=, <= , ==, =
bool IsNegative(string num);


bool IsEqual(const QInt& N1, const QInt& N2);


bool IsLess(const QInt& N1, const QInt& N2);

bool IsGreater(const QInt& N1, const QInt& N2);

bool operator < (const QInt& N1, const QInt& N2);

bool operator > (const QInt& N1, const QInt& N2);

bool operator <= (const QInt& N1, const QInt& N2);

bool operator >= (const QInt& N1, const QInt& N2);

bool operator == (const QInt& N1, const QInt& N2);

//==================================================================================

// ===================TOAN TU &, |, ^, ~ , << , >>
QInt AND(const QInt& a, const QInt& b);

QInt operator & (const QInt& a, const QInt& b);

QInt operator & (const QInt& a, const int& b);



QInt OR(const QInt& a, const QInt& b);

QInt operator | (const QInt& a, const int& b);

QInt operator | (const QInt& a, const QInt& b);



QInt XOR(const QInt& a, const QInt& b);

QInt operator ^ (const QInt& a, const int& b);

QInt operator ^ (const QInt& a, const QInt& b);



QInt operator ~ (const QInt& a);


string dichPhai(const string& a, int bit);

string dichTrai(const string& b, int bit);


QInt operator >> (const QInt& a, unsigned int bit);


QInt operator << (const QInt& a, int bit);



QInt rol(const QInt& a, int bit);



QInt ror(const QInt& a, int bit);

//===================================================================================================


//================================ TOAN TU + - * /
string CongBit(const string& a, const string& b);



string TruBit(const string& n1, const string& n2);

QInt operator + (const QInt& n1, const QInt& n2);


QInt operator - (const QInt& n1, const QInt& n2);



//Thieu xu li tran so
QInt operator * (const QInt& m, const QInt& q);

//================================================/////////////////////
QInt operator / (const QInt& number1, const QInt& number2);



#endif
