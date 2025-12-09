
#include <vector> // импортируем библиотеку для двухмерного массива
#include <string> // импортируем библиотеку для использования строк
#include <iostream> // импортируем библиотеку для ввода-вывода
#include <windows.h> // импортируем библиотеку для установки кодировки консоли

	char currentPlayer = 'X';  // символ нынешнего игрока
	int rows = 0; // переменная для строк
	int cols = 0; // переменная для столбцов

	std::vector<std::string> gamezone = { // рисуем наше поле для крестиков-ноликов
				"#####",
				"#...#",
				"#...#",
				"#...#",
				"#####"
	};

void DrawGameZone() {
	system("cls");
	for (int i = 0; i < gamezone.size(); i++)
		std::cout << gamezone[i] << std::endl;
}

void PlayerInput() {

	while (true) {
		std::cout << "\nХодит игрок под символом " << currentPlayer << std::endl; // вывод текста
		std::cout << "Введите номер строки и столбца куда хотите поставить " << currentPlayer << ": " << std::endl; // вывод текста
		std::cin >> rows >> cols; // инпут для пользователя

		if (rows < 1 || rows > 3 || cols < 1 || cols > 3) { // проверка выходят ли указаные координаты игрока за пределы поля, если да то
			std::cout << "Произошла ошибка вы вышли за пределы поля!" << std::endl; // выводится это сообщение
			continue; // используем для того чтобы код не крашнулся, после вывода сообщения об ошибке, отправляем цикл вновь в начало
		}

		if (gamezone[rows][cols] == '.') { // если в поле по указаным координатам стоит '.', то ничего не делаем
		}
		else { // в остальном
			std::cout << "Выбранная точка уже занята! Попробуйте еще раз "; // выводим сообщение что это место занята
			continue; // отправляем игрока в начало цикла
		}

		gamezone[rows][cols] = currentPlayer; // если все проверики прошли успешно, то в координатах поля ставим символ нынешнего игрока (либо Х либо О)
		break;
	}
}

bool CheckDraw() {
		for (int i = 0; i < gamezone.size(); i++) {
			for (int j = 0; j < gamezone[i].size(); j++) {
				if (gamezone[i][j] == '.') {
					return false;
				}
			}
		}
	std::cout << "\nПоздравляем с ничьей!" << std::endl;
	return true;
}


	bool CheckWin() {
		bool gameWon = false;
		if (gamezone[1][1] == currentPlayer && gamezone[1][2] == currentPlayer && gamezone[1][3] == currentPlayer) gameWon = true;
		else if (gamezone[2][1] == currentPlayer && gamezone[2][2] == currentPlayer && gamezone[2][3] == currentPlayer) gameWon = true;
		else if (gamezone[3][1] == currentPlayer && gamezone[3][2] == currentPlayer && gamezone[3][3] == currentPlayer) gameWon = true;
		else if (gamezone[1][1] == currentPlayer && gamezone[2][1] == currentPlayer && gamezone[3][1] == currentPlayer) gameWon = true;
		else if (gamezone[1][2] == currentPlayer && gamezone[2][2] == currentPlayer && gamezone[3][2] == currentPlayer) gameWon = true;
		else if (gamezone[1][3] == currentPlayer && gamezone[2][3] == currentPlayer && gamezone[3][3] == currentPlayer) gameWon = true;
		else if (gamezone[1][1] == currentPlayer && gamezone[2][2] == currentPlayer && gamezone[3][3] == currentPlayer) gameWon = true;
		else if (gamezone[1][3] == currentPlayer && gamezone[2][2] == currentPlayer && gamezone[3][1] == currentPlayer) gameWon = true;
		
		if (gameWon) {
			std::cout << "\nПоздравляем! Игрок под символом " << currentPlayer << " победил!" << std::endl;
			return true;
		}

		return false;
	}

	void SwitchPlayers() {

		if (currentPlayer == 'X') { // смена хода, если символ нынешнего игрока Х, то
			currentPlayer = 'O'; // меняем его на О
		}
		else { // в остальном
			currentPlayer = 'X'; // символ меняется вновь на Х
		}
	}


int main() // главная функция программы
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	while (true) { // создаем бесконечный цикл для отрисовки и проверок
		DrawGameZone();
		PlayerInput();
		if (CheckWin()) {
			break;
		}
		if (CheckDraw()) {
			break;
		}
		SwitchPlayers();
	}

	return 0; // конец главной функции программы
}
