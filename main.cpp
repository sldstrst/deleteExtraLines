#include <fstream>  //Для файловых потоков
#include <iostream> 
#include <string>   //Для контейнера string
#include <vector>  //Для контейнера vector
#include <iterator> //Для вывода элементов вектора  на экран с помощью алгоритма copy

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian_Russia.1251"); //для платформы win разрешение вывода русского языка в консоль
	string s;  //Это строка, она в примере будет абзацем
	vector<string> v; //Вектор строк 

	const char *FName = "C:\\pr\\prog.txt";  //Путь к файлу. У вас свой. Файл должен существовать.
	ifstream in(FName);     //открыли для чтения  файл
							//Считаем текст с форматированием
	std::ofstream file_out;
	file_out.open("C:\\pr\\prog1.txt", std::ios::trunc | std::ios::binary); //открыть и обрезать
	int ch = 0;  //Это переменная, в которую нужно считывать символы
	while (getline(in, s))  // если символ считываемый не равен концу файла
	{
		if (s == "")
		{
			s.clear();
		}

		else {
			v.push_back(s); //Если текущий символ перенос, то записываем строку в вектор
			file_out << s<<"\r\n"; // без "/r" перевод на следующую строку игнорируется и не осуществляется
			s.clear(); //Очищаем строку
		}
	}
	v.push_back(s); //Дописываем последнюю строку в вектор.
	in.close(); //Закрываем файл

				//cout<<v.at(0)<<"\n\n";  //Можете посмотреть первую строку, чтобы убедиться, что абзацы разделились.
	copy(v.begin(), v.end(), std::ostream_iterator<string>(cout, "\n"));  //Вывожу вектор на экран
	file_out.close();
	system("pause");
	return (EXIT_SUCCESS);
}
