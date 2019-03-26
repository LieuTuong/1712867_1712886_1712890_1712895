#define _CRT_SECURE_NO_WARNINGS
#include"xuLiString.h"
#include"QInt.h"
#include"QFloat.h"
#include<fstream>
#include<vector>
#include<cstring>

//Ham tach token cua 1 string khi doc tu FILE
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


//Ham xu li dieu kien co 2 chi thi p, chu yeu la chuyen doi he co so
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

//Kiem tra co phai nhung toan tu ( +, -, *, /, &, |, ^ ) khong
bool LaTinhToan_AND_OR_XOR(string x)
{
	return (x == "+" || x == "-" || x == "*" || x == "/" || x == "&" || x == "|" || x == "^");
}


//Kiem tra co phai nhung toan tu ( <<, >>, rol, ror) khong
bool LaDichXoayBit(string x)
{
	return (x == "<<" || x == ">>" || x == "rol" || x == "ror");
}

//Xu li tinh toan khi gap nhung toan tu (<<, >>, rol, ror) 
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

//Xu li tinh toan khi gap nhung toan tu ( +, -, *, /, &, |, ^ ) 
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


//Ham xu li dieu kien 1 chi thi p
string _1_chi_thi_p_QInt(vector<string> strArr)
{
	QInt a, b, resQInt;
	string heSo = strArr[0];
	string num1 = strArr[1];
	string toanTu = strArr[2];
	string num2 = strArr[3];
	if (heSo == "2")//Neu la tu he 2, chuyen so sang he 10 de tinh toan
	{
		num1 = BinToDec(num1);
		num2 = BinToDec(num2);
	}
	else if (heSo == "16")// chuyen tu he 16 sang he 10 de tinh toan
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
		long long int bit = toInt(num2);
		resQInt = tinhToanDichXoayBit(a, bit, toanTu);
	}
	else// la toan tu ~
	{
		resQInt = ~a;
	}

	string res = QInt_To_Arr(resQInt);
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


//Ham xu li khi doc FILE QInt
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


//Ham xu li khi doc FILE QFloat
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

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		cout << "\nNhap khong hop le!!!" << endl;
		cout << "\nCau truc nhap: <MSSV1_MSSV2_MSSV3.exe> <input.txt> <output.txt> <type>" << endl;
	}

	string input_name = argv[1];
	string output_name = argv[2];
	string type = argv[3];

	
	if (input_name.rfind(".txt") == string::npos)//Neu nguoi dung quen nhap .txt sau ten file, thi chuong trinh tu them vao
	{
		input_name.append(".txt");
	}
	if (output_name.rfind(".txt") == string::npos)//Neu nguoi dung quen nhap .txt sau ten file, thi chuong trinh tu them vao
	{
		output_name.append(".txt");
	}
	
	cout <<"\nTen FILE nhap: "<<input_name << endl;
	cout <<"\nTen FILE xuat:  "<<output_name << endl;
	cout <<"\nType "<< type << endl;

	ifstream fi(input_name);
	ofstream fo(output_name);
	
	if (fi.fail()||fo.fail())
	{
		cout << "\nKhong the mo FILE.";
		system("pause");
		return 0;
	
	}



	string tmp;
	string res;
	vector<string> strArr;
	while (!fi.eof())
	{
		getline(fi, tmp);
		if (tmp.length() == 0) break;

		strArr.clear();
		strArr = tachToken(tmp);

		if (type.compare("1")==0)
		{
			res = xuLiFile_QInt(strArr);
		}
		else if (type.compare("2")==0)
		{
			res = xuLiFile_QFloat(strArr);
		}
		fo << res << endl;
	}

	fo.close();
	fi.close();




	system("pause");
	return 0;

}