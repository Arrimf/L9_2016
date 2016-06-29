// ���������� STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

#include <algorithm>
#include <iostream>
#include <tchar.h>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>

#include <iterator>
#include "myString.h"
#include "Shape.h"
#include "Point.h"
#include "Templs.h"
#include <ctime>
#include <iostream>

using namespace std;

#define stop __asm nop
#define  _SP system("pause");

int _tmain(int argc, _TCHAR* argv[])
{
	std::srand(time(0));
	setlocale(LC_ALL, "Russian");
	
	//�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
	//�������� �������� �� ��, ��� ���������� ������������� ������ ������ ��� 
	//��������� ��������
	
	stack<MyString> st1;
	st1.push("BOO!");
	st1.push("ku");
	st1.push("hell");
	st1.push("oy");
	//PrintStdC(st1);
	//_SP
	queue<MyString>que1;
	que1.push("BOO!");
	que1.push("ku");
	que1.push("hell");
	que1.push("oy");
	//PrintStdC(que1);
 	//_SP
	priority_queue<MyString>queP1;
	queP1.push("BOO!");
	queP1.push("ku");
	queP1.push("hell");
	queP1.push("oy");
	
	//PrintStdC(queP1);
	//_SP
		////////////////////////////////////////////////////////////////////////////////////
		//stack

		//�������� ���� ����� �������, �����
		//�) �������� ����� ����� ������� ��������� �������
		//�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 


	vector<char>vChar2;
	vChar2.push_back('q');
	vChar2.push_back('w');
	vChar2.push_back('e');
	vChar2.push_back('r');
	vChar2.push_back('t');
	vChar2.push_back('y');

	vector<char>::reverse_iterator itb = vChar2.rbegin();
	vector<char>::reverse_iterator ite = vChar2.rend();
	
	stack<char>st2;
	while (itb != ite){
		st2.push(*itb);
		++itb;
	}
	
	//PrintStdC(st2);
	//_SP


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//�������� �������, ������� �������� ��������� �� ������� ���� Point,
	//��� ���� ���� ������� ������� ���������.													////?			
	//�������� �������� ������� � ���������� ��������� ����������� front() � back()
	//���������, ��� ��������� ������� ��� ����������� ����� �������?
	
	deque<Point*>	ptList1;
	ptList1.push_back(new Point(2, 2));
	ptList1.push_back(new Point(3, 2));
	ptList1.push_back(new Point(5, 1));
	ptList1.push_front(new Point(4, 5));
	ptList1.push_front(new Point(3, 7));
	ptList1.push_front(new Point(1, 2));

	queue<Point*>que2(std::move(ptList1));
	//PrintStdC(que2);
	//_SP

		CleanPoinerAdapter(que2);
//	_SP



	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
	//�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
	//�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
	//		��� ������������ ��� �������? - -  ������

		const char* arStr[] = {"qwe","asd","zxc","boo"};

		priority_queue<const char*> words(arStr, arStr + 4);
		//PrintStdC(words);
		//_SP;




	
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
	//		� ������ Point (� ����� �������)
	//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������
	//�) ���������� �������� ����� ��������...
	//�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
	//		���� int, �� ���������� � ������ �������
	//�) �������� � ����� ��������� �������� ��������� �� ������ �������
	//	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?)

		deque<Point>ptList2;
		ptList2.push_back(Point(2, 2));
		ptList2.push_back(Point(3, 2));
		ptList2.push_back(Point(5, 1));
		ptList2.push_front(Point(4, 5));
		ptList2.push_front(Point(3, 7));
		ptList2.push_front(Point(1, 2));


		set<Point> poiSet(ptList2.begin(), ptList2.end());
		//Print(poiSet);
		//_SP
			//ptList2.begin() = Point(2, 3);
			set<Point> poiSet2(ptList2.rbegin(), ptList2.rend());
		//Print(poiSet2);
		//_SP

		std::vector<Point>vPoint2(3, Point(1, 1));
	

		 poiSet2.insert(vPoint2.rbegin(), vPoint2.rend());
		// Print(poiSet2);
		// _SP

			 ////////////////////////////////////////////////////////////////////////////////////
			 //map, multiset
			 //�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
			 //	��� ���� ������ �������� ���������� ����������
			 //�) ��������� ��������� ���������� ����������� operator[] � insert()
			 //�) ������������ ����������

			 //�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")

			 map<const char*, int> jurMap;
		 jurMap["Ivanov"] = 200;
		 jurMap.emplace("Petrov", 230);
		 jurMap.insert(pair<const char*, int>("Petrova", 230));
		 jurMap.emplace("�������", 230);
		 jurMap.emplace("Sidorov", 235);

		 Print(jurMap);
		 _SP

			 jurMap.insert(jurMap.erase(jurMap.find("Petrova")), pair<const char*, int>("Sidorova",120));

		// jurMap.at("Petrova") = ("Sidorova",120);
	
		// Print(jurMap);
 		 //_SP

	
		
		//�) ����������� ����� �������� ������ � ���������� ���� string.
		//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
		//��������� ������������� �� �������� ������ �
		//���������� ���������� ������ ������ � �������
	
		 vector<string> vStr;
		 vStr.push_back("privet");
		 vStr.push_back("ku-ku");
		 vStr.push_back("BOOO");
		 vStr.push_back("privet");
		 vStr.push_back("Ayka");
		 vStr.push_back("chashechka");
		 vStr.push_back("BOOO");
		 vStr.push_back("privet");

		 map<string, int>strs;

		 //size_t Vsize = strs.size();

		 for_each(vStr.begin(), vStr.end(),[&strs](string str) {
				 strs[str] += 1;
			 });
		 Print(strs);
		 _SP


		//�) 
		//����� ������:
		const char* wordss[] = {"Abba", "Alfa", "Beta","BOOO", "Beauty" ,"privet","ku-ku","BOOO","Ayka","chashechka" };
		//�������� map, � ������� ������ ����� ����� ��������������� ������������ 
		//��������������� ������������� ����, ������������ � ���� �����.
		//���������: �� ����� ������� ����� ����� � ��� �� ������
	
		//'A' -  "Abba" "Alfa"
		//'B' -  "Beauty" "Beta"  ...
		//...

		 map<char, map<string,int>> Words;
		 
		 for_each(wordss, wordss + 10, [&Words](string str) {Words[str.front()][str] += 1;});
		 
		/// Print(Words);
		 _SP

			 //�)
			 //�������� ��������� ������, ������� ����� ������� ���������� � ������������ �������.
			 //��� ������ ������ ������ �������� ������� ��������� (�� ��������). ��� ���� 
			 //������� ����� �������������
			 //���� ������ ���� ������ ���� ����������� �� ������
			 //
			 //������ 

			 map<int, multiset<string>>GroupsMap;    //... =)))


	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
	//		��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
	//�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
	//		���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
	//�) �������� ��� ���������� ������� �� �����
	//�) �������� �� ����� ������ �������� "���������" ��� ��������� �����. ���������: ��� ���������� ���������
	//		���������� ����� ������������ ������ lower_bound() � upper_bound()

		 multimap<string, string>DictMap;
		 
		 pair<string, string> pairs[] = {
			 {"strange","��������"},
			 { "well","�������" },
			 { "strange","�����" },
			 { "room","�����" },
			 { "strange","������" },
			 { "fire","�����" },
			 { "free","���������" },
			 { "fire","���������" },
			 { "right","�����" },
			 { "bank","����" },
			 { "right","�����" },
			 { "crane","�������" },
			 { "like","��������" },
			 { "well","������" },
			 { "free","����������" },
			 { "room","�������" },
			 { "like","���������" },
			 { "crane","����" },
			 { "bank","�����" },
		 };

		 for_each(pairs, pairs + 19, [&DictMap](pair<string, string> val) {
			 DictMap.insert(val);
		 });
		 //Print(DictMap);
		 Print(DictMap.equal_range("crane"));
		 _SP
  stop

	return 0;
}

