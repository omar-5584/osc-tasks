//#include<iostream>
//#include<string>
//#include<iterator>
//using namespace std;
//
//
//int numOfRepeating(string& s,size_t indexOfBracet,short& cntOfDigits )
//{
//	int res = 0;
//	while (isdigit(s[indexOfBracet]))
//	{
//		res += (s[indexOfBracet]-'0') * pow(10, cntOfDigits);
//		cntOfDigits++;
//		if (indexOfBracet==0)
//		{
//			break;
//		}
//			indexOfBracet--;
//	}
//	return res;
//
//}
//string decodeString(string& s) {
//
//	string result="";
//	size_t start,end;
//
//	while (s.find_last_of('[') != string::npos)
//	{
//	short cntOfDigits = 0;
//		int repeating = 0;
//		string str_2_replace="";
//
//		start= s.find_last_of('[');
//		
//		end=  s.find_first_of(']',start);
//		
//		string str_2_repeat=s.substr(start+1,end-start-1);
//		repeating = numOfRepeating(s, start - 1,cntOfDigits);
//		
//		
//		while (repeating--)
//		{
//			str_2_replace += str_2_repeat;
//		}
//		
//		s.replace(start-cntOfDigits,end-start+cntOfDigits+1,str_2_replace);
//		
//		str_2_repeat.clear();
//		
//
//
//	}
//		return s;
//}
//
//
//
//int main()
//{
//	string s;
//	cin >> s;
//	cout << decodeString(s);
//
//}