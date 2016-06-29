// Контейнеры STL: 
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
	
	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений
	
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

		//Создайте стек таким образом, чтобы
		//а) элементы стека стали копиями элементов вектора
		//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 


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

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.													////?			
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
	
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
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке? - -  адреса

		const char* arStr[] = {"qwe","asd","zxc","boo"};

		priority_queue<const char*> words(arStr, arStr + 4);
		//PrintStdC(words);
		//_SP;




	
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)

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
			 //а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
			 //	при этом строки задаются строковыми литералами
			 //б) заполните контейнер значениями посредством operator[] и insert()
			 //в) распечатайте содержимое

			 //г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")

			 map<const char*, int> jurMap;
		 jurMap["Ivanov"] = 200;
		 jurMap.emplace("Petrov", 230);
		 jurMap.insert(pair<const char*, int>("Petrova", 230));
		 jurMap.emplace("Ышвщкщм", 230);
		 jurMap.emplace("Sidorov", 235);

		 Print(jurMap);
		 _SP

			 jurMap.insert(jurMap.erase(jurMap.find("Petrova")), pair<const char*, int>("Sidorova",120));

		// jurMap.at("Petrova") = ("Sidorova",120);
	
		// Print(jurMap);
 		 //_SP

	
		
		//д) Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
	
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


		//е) 
		//задан массив:
		const char* wordss[] = {"Abba", "Alfa", "Beta","BOOO", "Beauty" ,"privet","ku-ku","BOOO","Ayka","chashechka" };
		//создайте map, в котором каждой букве будет соответствовать совокупность 
		//лексиграфически упорядоченных слов, начинающихся с этой буквы.
		//Подсказка: не стоит хранить дубли одной и той же строки
	
		//'A' -  "Abba" "Alfa"
		//'B' -  "Beauty" "Beta"  ...
		//...

		 map<char, map<string,int>> Words;
		 
		 for_each(wordss, wordss + 10, [&Words](string str) {Words[str.front()][str] += 1;});
		 
		/// Print(Words);
		 _SP

			 //ж)
			 //создайте структуру данных, которая будет хранить информацию о студенческих группах.
			 //Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
			 //фамилии могут дублироваться
			 //Сами группы тоже должны быть упорядочены по номеру
			 //
			 //номера 

			 map<int, multiset<string>>GroupsMap;    //... =)))


	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()

		 multimap<string, string>DictMap;
		 
		 pair<string, string> pairs[] = {
			 {"strange","странный"},
			 { "well","колодец" },
			 { "strange","чужой" },
			 { "room","место" },
			 { "strange","чудной" },
			 { "fire","огонь" },
			 { "free","свободный" },
			 { "fire","увольнять" },
			 { "right","верно" },
			 { "bank","банк" },
			 { "right","право" },
			 { "crane","журавль" },
			 { "like","походить" },
			 { "well","хорошо" },
			 { "free","бесплатный" },
			 { "room","комната" },
			 { "like","нравиться" },
			 { "crane","кран" },
			 { "bank","берег" },
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

