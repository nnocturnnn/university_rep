#include <iostream>
#include <string>
#include <fstream> 



void menu_user();
void menu_manager();
void search_man();

void regin() {
	std::string login;
	std::string passwd;
	std::cout << "Пожалуйста, введите логин и пароль: \n";
	std::getline(std::cin, login);
	std::getline(std::cin, passwd);
	std::cout << "Please, enter your manager or user: \n";
	std::getline(std::cin, login);
	std::ofstream myfile;
	myfile.open("logdata.txt", std::ios_base::app);
	myfile << passwd + " " + login + "\n";
	myfile.close();
}

void login() {
	std::string login;
	std::string passwd;
	std::cout << "Пожалуйста, введите логин и пароль: \n";
	std::getline(std::cin, login);
	std::getline(std::cin, passwd);

	std::ifstream file("logdata.txt");
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			if (line.rfind(passwd, 0) == 0) {
				if (line.find("user") < 1000) {
					menu_user();
				}
				else if (line.find("manager") < 1000) {
					menu_manager();
				}
			}
		}
		std::cout << "Неверный логин или пароль\n";
		file.close();
	}
}

void get_zak(std::string nik) {
	int variant;
	int count = 1;

	std::string passwd;
	std::cout << "Пожалуйста, введите название заказа: \n";
	std::getline(std::cin, passwd);

	
		std::ifstream file("all.txt");
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				if (passwd.rfind(passwd, 0) == 0) {
					std::getline(std::cin, passwd);
					std::cout << "Заказ взят. \n";

					std::ofstream myfile;
					myfile.open(nik + ".txt", std::ios_base::app);
					myfile << passwd;
					break;
				}
					
			
			}
			file.close();
		}
	
}
void all_zak(std::string nik) {
	int i = 1;
	std::ifstream file("all.txt");
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			std::cout << i << "\n" << line << std::endl;
			i++;
		}
		file.close();
	}
	int variant;
	std::cout << "1.Поиск заказа\n2.Взять заказ\n";
	std::cin >> variant;
	if (variant == 1) {
		search_man();
	}
	else if (variant == 2) {
		get_zak(nik);
	}
	else if (variant == 3) {
		exit(1);
	}

}
void my_zak(std::string nik) {
	int i = 1;
	std::ifstream file(nik + ".txt");
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			std::cout << i << "\n" << line << std::endl;
			i++;
		}
		file.close();
	}
	int variant;
	std::string passwd;
	std::cout << "1.Вернуться к заказам\n2.Выход\n";
	std::cin >> variant;
	if (variant == 1) {
		all_zak(passwd);
	}
	else if (variant == 2) {
		exit(1);
	}

}


void red_zak(std::string nik) {
	int i = 1;
	std::string passwd;
	std::string buffer;
	std::ifstream file(nik + ".txt");
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			std::cout << i << line;
		}
		file.close();
	}
	
	int variant;
	int count = 1;
	std::cout << "Если хотите редактировать заказ введите его номер либо 0 чтобы выйти\n";
	std::getline(std::cin, passwd);
	std::cin >> variant;

	if (variant == 0) {
		exit(1);
	}
	else {
		std::ifstream file(nik + ".txt");
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
					std::cout << "Новое имя и статус заказа\n";
					std::getline(std::cin, line);
				}
				buffer += line;
			}
			file.close();
		}
		std::ofstream myfile;
		myfile.open(nik + ".txt");
		myfile << buffer;
	}

void menu_user() {
	std::string passwd;
	std::cout << "Пожалуйста, введите никней на английском: \n";
	std::getline(std::cin, passwd);

	while (1) {
		int variant;
		std::cout << "Выберите нужное действие :\n1.Все заказы\n2.Мои заказы\n3.Редактировать статус заказа\n3.Выход\n";
		std::cin >> variant;
		if (variant == 1) {
			all_zak(passwd);
		}

		else if (variant == 2) {
			my_zak(passwd);
		}
		else if (variant == 3) {
			red_zak(passwd);
		}
		else if (variant == 4) {
			exit(1);
		}
		else {
			std::cout << "Неверный вариант!";
		}
	}
}





void search_man() {
	int k=0;
	std::string passwd;
	std::cout << "Пожалуйста, введите название заказа: \n";
	std::getline(std::cin, passwd);

	std::ifstream file("all.txt");
	if (file.is_open()) {
		std::string line;
		std::getline(std::cin, passwd);
		while (std::getline(file, line)) {
			if (line.rfind(passwd, 0) == 0) {
				std::cout << "Заказ найден: \n";
				std::cout << line << std::endl;
				 k = 1;
			}
			
			
		}
		if (k==1)
		{
			int variant;
			std::cout << "1.Редактировать заказ\n2.Взять заказ\n";
			std::cin >> variant;
			if (variant == 1) {
				red_zak(passwd);
			}
			else if (variant == 2) {
				get_zak(passwd);
			}
			else if (variant == 3) {
				exit(1);
			}
		}
		if (k==0)
		{
			std::cout << "Неверный заказ\n";
		}
		
	
		
	}
	
}

void add_man() {
	std::string login;
	std::string passwd,pass,pas;
	std::cout << "Введите название заказа, заказчика и его статус: \n";
	std::getline(std::cin, login);
	std::getline(std::cin, passwd);
	std::getline(std::cin, pass);
	std::getline(std::cin, pas);
	std::ofstream myfile;
	myfile.open("all.txt", std::ios_base::app);
	myfile << passwd + "\n";
	myfile << pass + "\n";
	myfile << pas + "\n";
	myfile.close();
}

void menu_manager() {
	while (1) {
		int variant;
		std::cout << "Выберите нужное действие :\n1.Поиск\n2.Добавить новое\n3.Выход\n";
		std::cin >> variant;
		if (variant == 1) {
			
			search_man();
			
		}
		else if (variant == 2) {
			add_man();
		}
		else if (variant == 3) {
			exit(1);
		}
		else {
			std::cout << "Неверный вариант!";
		}
	}
}


int main() {
	setlocale(LC_ALL, "Russian"); 
	while (1) {
		int variant;
		std::cout << "Выберите нужное действие :\n1.Регистрация\n2.Авторизация\n3.Выход\n";
		std::cin >> variant;
		if (variant == 1) {
			regin();
		}
		else if (variant == 2) {
			login();
		}
		else if (variant == 3) {
			exit(1);
		}
		else {
			std::cout << "Неверный вариант!";
		}
	}
}