#define _CRT_SECURE_NO_WARNINGS
#include"xuLiString.h"
#include"QInt.h"
#include"QFloat.h"
#include<fstream>
#include<vector>
#include<cstring>


vector<string> tachToken(string x)
{
	vector<string> res;
	int len = x.length();

	char* cstr = new char[len + 1];
	strcpy(cstr, x.c_str());
	char* token;
	token = strtok(cstr, " ");
	while (token != 0)
	{
		res.push_back(string(token));
		token = strtok(NULL, " ");
	}
	return res;
}

string _2_chi_thi_p_QInt(vector<string>strArr)
{
	string res;
	if (strArr[0] == "2")
	{
		if (strArr[1] == "10")// yeu cau chuyen tu he 2 -> he 10
		{
			res = BinToDec(strArr[2]);
		}
		else if (strArr[1] == "16")// yeu cau chuyen tu he 2 -> he 16
		{
			res = BinToHex(strArr[2]);
		}
	}

	else if (strArr[0] == "10")
	{
		if (strArr[1] == "2")// He 10 -> he 2
		{
			res = DecToBin(strArr[2]);
		}
		else if (strArr[1] == "16")//He 10 -> He 16
		{
			res = DecToHex(strArr[2]);
		}
	}


	else if (strArr[0] == "16")
	{
		if (strArr[1] == "2")
		{
			res = HexToBin(strArr[2]);
		}
		else if (strArr[1] == "10")
		{
			res = HexToDec(strArr[2]);
		}
	}

	return remove0(res);
}

bool LaTinhToan_AND_OR_XOR(string x)
{
	return (x == "+" || x == "-" || x == "*" || x == "/" || x == "&" || x == "|" || x == "^");
}

bool LaDichXoayBit(string x)
{
	return (x == "<<" || x == ">>" || x == "rol" || x == "ror");
}

QInt tinhToanDichXoayBit(QInt a, int b, string toanTu)
{
	QInt res;
	if (toanTu == "<<")
		res = a << b;
	else if (toanTu == ">>")
		res = a >> b;
	else if (toanTu == "rol")
		res = rol(a, b);
	else if (toanTu == "ror")
		res = ror(a, b);

	return res;
}

QInt tinhToan_AND_OR_XOR(QInt a, QInt b, string toanTu)
{
	QInt res;
	if (toanTu == "+") 
		res = a + b;
	else if (toanTu == "-")
		res = a - b;
	else if (toanTu == "*")
		res = a * b;
	else if (toanTu == "/")
		res = a / b;
	else if (toanTu == "&")
		res = a & b;
	else if (toanTu == "|")
		res = a | b;
	else if (toanTu == "^")
		res = a ^ b;
	return res;
}

string _1_chi_thi_p_QInt(vector<string> strArr)
{
	QInt a, b, resQInt;
	string heSo = strArr[0];
	string num1 = strArr[1];
	string toanTu = strArr[2];
	string num2 = strArr[3];
	if (heSo == "2")
	{
		num1 = BinToDec(num1);
		num2 = BinToDec(num2);
	}	
	else if (heSo=="16")
	{
		num1 = HexToDec(num1);
		num2 = HexToDec(num2);
	}


	ScanQInt(a, num1);
	if (LaTinhToan_AND_OR_XOR(toanTu))
	{
		ScanQInt(b, num2);
		resQInt = tinhToan_AND_OR_XOR(a, b, toanTu);
	}
	else if (LaDichXoayBit(toanTu))
	{
		int bit = toInt(num2);
		resQInt = tinhToanDichXoayBit(a, bit, toanTu);
	}
	else// la toan tu ~
	{
		resQInt = ~a;
	}

	string res= QInt_To_Arr(resQInt);
	if (heSo == "10")
		res = BinToDec(res);
	else if (heSo == "16")
	{
		res = BinToHex(res);
		res = remove0(res);
	}
		
	else //heSo 2
		res = remove0(res);
	return res;
}

string xuLiFile_QInt(vector<string> strArr)
{
	string res;
	if (strArr.size() == 3)
	{
		res = _2_chi_thi_p_QInt(strArr);
	}
	else
		res = _1_chi_thi_p_QInt(strArr);
	return res;
}

string xuLiFile_QFloat(vector<string> strArr)
{
	string res;
	string he1 = strArr[0];
	QFloat f;
	string num = strArr[2];

	if (he1 == "10")//tuhe 10 -> he 2
	{
		ScanQFloat(f, num);
		res = QFloat_To_Arr(f);
	}
	else //tu he 2 -> he 10
	{
		res = BinToDec_QFloat(num);
	}
		

	return res;

}

int main()
{

	ifstream fi("QFloat.txt");
	ofstream fo("resQFloat.txt");
	if (fi.fail()||fo.fail())
	{
		cout << "\nKhong the mo FILE.";
		return 0;
	}

	string tmp;
	string res;
	vector<string> strArr;
	while (!fi.eof())
	{
		getline(fi, tmp);
		if (tmp.length() == 0) return 0;

		strArr.clear();
		strArr = tachToken(tmp);
		
		res = xuLiFile_QFloat(strArr);
		fo << res << endl;	
	}

	fo.close();
	fi.close();

	
	


	system("pause");
	return 0;

}