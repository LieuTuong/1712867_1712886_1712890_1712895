#pragma once
#pragma once
#ifndef __XULISTRING_H__
#define __XULISTRING_H__
#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;

int stringToNum(char c);
char numToString(int n);
string toString(long long n);
long long int toInt(string s);
bool IsSign(string num);
void setSign(string& num, bool s);
string absolute(string num);
string remove0(const string& number);
string chia2(string bigInt);
string reverse(string a);
bool equals(string n1, string n2);
bool Less(string n1, string n2);
bool Greater(string a, string b);
string add(string number1, string number2);
string subtract(string number1, string number2);
void canBang2Chuoi(string& a, string& b);
string _x_mu_n(int coSo, int soMu);
bool operator > (string a, string b);
bool operator < (string a, string b);
string operator + (string a, string b);
string operator - (string a, string b);
string operator * (string bigNumber, int x);
#endif


