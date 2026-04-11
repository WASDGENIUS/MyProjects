#include <iostream>
#include <fstream>
using namespace std;

enum GameType { RPG, STRATEGY, RACING, FLIGHT_SIM };

struct Game {
    char title[50];
    char studio[50];
    double price;
    int players;
    char platforms[50];
    GameType type;
};

bool areStringsEqual(const char* str1, const char* str2) {
    int i = 0;
    // Проходим по обоим массивам, пока символы совпадают и не достигнут конец строки
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false; 
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

void updatePricesFromFile(Game* arr, int n, const char* filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Файл настроек не найден." << endl;
        return;
    }

    char filePlatform[50];
    double filePrice;

    while (fin >> filePlatform >> filePrice) {
        for (int i = 0; i < n; i++) {
            if (areStringsEqual(arr[i].platforms, filePlatform)) {
                arr[i].price = filePrice;
                cout << "Цена обновлена для: " << arr[i].title << " (" << filePlatform << ")" << endl;
            }
        }
    }
    fin.close(); 
}


void saveToBinary(Game* arr, int n, const char* filename) {
    ofstream out(filename, ios::binary | ios::out);
    if (out.is_open()) {
        out.write((char*)arr, sizeof(Game) * n); // Записываем массив структур целиком [cite: 10]
        out.close();
        cout << "Данные сохранены в бинарный файл." << endl;
    }
}



void wrapperDisplay(Game *g) {
    const char* genreNames[] = {"RPG", "Strategy", "Racing", "Flight Sim"};
    
    cout << "------------------------------------" << endl;
    cout << "Игра: " << (*g).title << " | Студия: " << (*g).studio << endl;
    cout << "Цена: " << (*g).price << " | Аудитория: " << (*g).players << endl;
    cout << "Жанр: " << genreNames[(*g).type] << " | Платформы: " << (*g).platforms << endl;
}

void editGame(Game* g, double newPrice) {
    (*g).price = newPrice;
}

void bubbleSortByPlatform(Game *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Сравниваем первую букву строки платформ
            if (arr[j].platforms[0] > arr[j + 1].platforms[0]) {
                Game temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortByPrice(Game *g, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (g[j].price < g[j + 1].price) {
                Game temp = g[j];
                g[j] = g[j + 1];
                g[j + 1] = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    const int N = 20;
    Game *g = new Game[N]{
        {"The Witcher 3", "CDPR", 1200, 2000000, "PC, Gamepad", RPG},
        {"MS Flight Sim", "Asobo", 3500, 1500000, "PC, Gamepad", FLIGHT_SIM},
        {"Starcraft 2", "Blizzard", 0, 800000, "PC", STRATEGY},
        {"War Thunder", "Gaijin", 0, 1300000, "PC, Mobile", FLIGHT_SIM},
        {"DCS World", "Eagle", 4000, 1100000, "PC", FLIGHT_SIM},
        {"Age of Empires", "MS", 2500, 950000, "PC", STRATEGY},
        {"Forza Horizon 5", "Playground", 4000, 3000000, "Gamepad, PC", RACING},
        {"X-Plane 12", "Laminar", 4500, 400000, "PC", FLIGHT_SIM},
        {"Civilization VI", "Firaxis", 1999, 1200000, "PC, Mobile", STRATEGY},
        {"Cyberpunk 2077", "CDPR", 2000, 5000000, "PC, Gamepad", RPG},
        {"Skyrim", "Bethesda", 1500, 8000000, "Gamepad, PC", RPG},
        {"Elden Ring", "FromSoft", 3999, 12000000, "Gamepad, PC", RPG},
        {"F1 23", "EA Sports", 5000, 500000, "Gamepad", RACING},
        {"Stellaris", "Paradox", 1200, 700000, "PC", STRATEGY},
        {"HoI IV", "Paradox", 1100, 600000, "PC", STRATEGY},
        {"Elite Dangerous", "Frontier", 999, 1150000, "PC, Gamepad", FLIGHT_SIM},
        {"Total War", "Creative", 3200, 250000, "PC", STRATEGY},
        {"Assetto Corsa", "Kunos", 450, 1000000, "PC, Gamepad", RACING},
        {"IL-2 Sturmovik", "1C", 2000, 200000, "PC", FLIGHT_SIM},
        {"SimCity", "EA", 800, 300000, "PC", STRATEGY}
    };

    cout << "АВИАСИМУЛЯТОРЫ (ОТ 1 МЛН ИГРОКОВ)" << endl;
    Game *flightSims = new Game[N];
    int fsCount = 0;
    for (int i = 0; i < N; i++) {
        if (g[i].type == FLIGHT_SIM && g[i].players >= 1000000) {
            flightSims[fsCount++] = g[i];
        }
    }
    bubbleSortByPlatform(flightSims, fsCount);
    for (int i = 0; i < fsCount; i++) wrapperDisplay(&flightSims[i]);

    updatePricesFromFile(g, N, "/Users/wasdgenius/VScodeMiscProjects/Lab_09/setup.txt");
    saveToBinary(g, N, "result.dat");

    cout << "\nТОП-3 САМЫХ ДОРОГИХ ИГР" << endl;
    sortByPrice(g, N);
    for (int i = 0; i < 3; i++) wrapperDisplay(&g[i]);


    cout << "\nСТРАТЕГИИ ДЛЯ PC" << endl;
    Game *pcStrategies = new Game[N];
    int stratCount = 0;
    for (int i = 0; i < N; i++) {
        if (g[i].type == STRATEGY && g[i].platforms[0] == 'P') {
            pcStrategies[stratCount++] = g[i];
        }
    }
    for (int i = 0; i < stratCount; i++) wrapperDisplay(&pcStrategies[i]);


    delete[] g;
    delete[] flightSims;
    delete[] pcStrategies;

    return 0;
}
