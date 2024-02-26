#include<iostream>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#include"Structs.h"
#include"MemoryAllocation.h"
#include"DisplayInfo.h"
#include"Search.h"
#include"Add.h"
#include"DeleteData.h"
#include"Enum&Animation.h"
#include"DataFiles.h"
using namespace std;

// Struktura v kotorom xranatsa infa pro mashinu
struct Car;
// Structura v kotorom xranatsa infa pro klienta(FIO)
struct Client;
// Struktura xranit v sebe ukazateli na strukturi Car o Client
struct Contract;
// struktura zadoljnostey
struct Arrers;

// Funkcii dlya vidileniye mesto v dinamichesckoy pomyati, dlya sozdaniye mashini
Car* createCarArray(int size);
// Funkcii dlya vidileniye mesto v dinamichesckoy pomyati, dlya novoqo kontrakta
Client* createClientArray(int size);

// Funkciya qde xranyatsya infa pro mashinu(brend,marka,cvet i t.d)
void displayCarInfo(Car& information);
// Funkciya qde xranyatsya infa pro clienta(FIO)
void displayClientInfo(Client& information);
// Funkciya qde xranyatsya infa pro kontrakt
void displayContractInfo(Car& car, Contract& information);

// Funkciya poiska po brendu mashini
void searchCarsByBrand(Car* cars, const char* user, int length);
// Funkciya poiska po cvetu mashini
void searchCarsByColor(Car* cars, const char* user, int length);
// Funkciya poiska po reqistracionnomu nomeru mashini
void searchCarsByRegisterNumber(Car* cars, const char* user, int length);
// Funkciya poiska po qodu proizvodstva mashini
void searchCarsByYearOfProduction(Car* cars, int user, int length);
// Funkciya poiska po arendatoru mashini
void searchContractsByTenant(Client* search_client, char* userName, char* userSurname, char* userIdentifyCode, int& length);
// Funkciya poiska po cenovomu diapazonu mashini
void searchCarsByPriceRange(Car* cars, short start_range, short end_range, int length);
// Funkciya poiska po kontraktu mashini
void searchContractByClient(Contract* contract, Car* cars, char* userName, char* userSurname, char* userIdentifyCode, int& length);

// Funkciya dlya dobavlenii mashin
Car* addCar(Car* cars, int& length);
// Funkciya dlya dobavlenii clienta
Client* addClient(Client* clients, int& length);
// Funkciya dlya dobavlenii kontrakta
Contract* addContract(Contract* contracts, Car* cars, Client* clients, int& lengthContracts, int lengthCars, int lengthClients);

// Funkciya dlya udalenii mahini
Car* deleteCar(Car* car, int& length);
// Funkciya dlya udalenii klienta
Client* deleteClient(Client* clients, int& length);
// Funkciya dlya udalenii vsex dannix

void deleteAllData(Car* allcars, Client* allclients, Contract* allcontracts, int& lengthCars, int& lengthClients, int& lengthContracts);
// Funkciya zadoljnostey klienta
short currentDebt(Contract* contracts, Client* clients, Car* cars, int lengthContracts, int lengthClients, int lengthCars, char* name, char* surname, char* middleName, short inputDays) {
	short calculatedDebt = 0;

	for (int i = 0; i < lengthContracts; ++i) {
		if (_stricmp(contracts[i].name, name) == 0 && _stricmp(contracts[i].surname, surname) == 0 && _stricmp(contracts[i].middleName, middleName) == 0) {

			int carIndex = -1;
			for (int j = 0; j < lengthCars; ++j) {
				if (strcmp(contracts[i].registrationNumber, cars[j].registrationNumber) == 0) {
					carIndex = j;
					break;
				}
			}
			if (carIndex != -1) {
				if (inputDays < contracts[i].rentDays) {
					calculatedDebt += inputDays * cars[carIndex].rentalPricePerDay;
				}
				else {
					calculatedDebt += contracts[i].totalRentalPrice;
				}
			}
		}
	}

	return calculatedDebt;
}
// Animaciya Rent A Car
void displayRentACarAnimation();
// Animaciya pri vixode iz proqrammi
void displayExitAnimation();

// Funkciya dlya zapisi dannix
void saveDataToFile(Car* carMenu, Client* clientMenu, Contract* contractMenu, int& lengthCars, int& lengthClients, int& lengthContracts);
// Funkciya dlya cteniye dannix
void loadDataFromFile(Car* carMenu, Client* clientMenu, Contract* contractMenu, int& lengthCars, int& lengthClients, int& lengthContracts);
// Funkciya menu
void displayMainMenu(Car* carMenu, Client* clientMenu, Contract* contractMenu, int& lengthCars, int& lengthClients, int& lengthContracts)
{
	int choice = 1; // start opciya
	while (true)
	{
		displayRentACarAnimation();
		cout << '\n';
		for (int i = 1; i <= 6; i++)
		{
			if (i == choice)
			{
				cout << "\t\t\t\t\t\t\t  " << "> " << i << ". ";
			}
			else
			{
				cout << "\t\t\t\t\t\t\t    " << i << ". ";
			}
			switch (i) {
			case 1:
				cout << "Search for information." << endl;
				break;
			case 2:
				cout << "Adding information." << endl;
				break;
			case 3:
				cout << "Deleting information." << endl;
				break;
			case 4:
				cout << "The current debt of a particular client for today." << endl;
				break;
			case 5:
				cout << "Show all information" << endl;
				break;
			case 6:
				cout << "Exit the program" << endl;
				break;
			}
		}
		char key = _getch();
		if (key == UP)
		{
			choice--; // esli najata UP to choice umenshaetsya na 1
			if (choice < 1) // usloviye proveryayet ne stalo li choice menshe 1
			{
				choice = 6;// ctobi prodoljit naviqaciyu vverx mi choice = 6 predpoloqaya cto u nas 6 opcii
			}

		}
		else if (key == DOWN)
		{
			choice++; // esli najata UP to choice uvelicevayetsya na 1
			if (choice > 6)  // usloviye proveryayet ne stalo li choice bolshe 6
			{
				choice = 1; // ctobi prodoljit naviqaciyu vniz mi choice = 1 
			}
		}
		else if (key == ENTER) {
			// case1
			char inputColor[20];
			char inputBrand[25];
			char userInputRegisterNumber[25];
			int inputYearOfProduction{};
			short start_range{};
			short end_range{};
			// case 2
			char inputName[10];
			char inputSurname[30];
			char inputIMiddleNameClient[7];
			// case 3
			char inputContarctName[10]{ '\0' };
			char inputContarctSurname[30]{ '\0' };
			char inputMiddleName[8]{ '\0' };
			// case 4
			char inputNameArrer[10];
			char inputSurnameArrer[10];
			char inputMiddleNameArrer[10];
			short inputCurrentDay{};
			short clientDebt = 0;
			// inputi casesov
			int caseChoice{};
			int case2Search{};
			int case3Search{};
			int case4Search{};
			system("cls");
			switch (choice)
			{
#pragma region case1
			case 1:
				cout << "1. By brand" << endl;
				cout << "2. By color" << endl;
				cout << "3. By register number" << endl;
				cout << "4. By year of realase" << endl;
				cout << "5. By tenant" << endl;
				cout << "6. By contract" << endl;
				cout << "7. By price range" << endl;
				cout << "Enter your choice: ";
				cin >> caseChoice;
				if (caseChoice == 1)
				{
					system("cls");
					cout << "Enter the brand of car: ";
					cin >> inputBrand;
					bool brandFound = false;
					for (int i = 0; i < lengthCars; i++) {
						if (_stricmp(inputBrand, carMenu[i].carBrand) == 0) {

							displayCarInfo(carMenu[i]);
							brandFound = true;
						}
					}
					if (!brandFound) {
						cout << "No cars with such brand were found." << endl;
					}
					system("pause");
					break;

				}

				else if (caseChoice == 2) {
					system("cls");
					cout << "Enter the color of car: ";
					cin >> inputColor;
					bool colorFound = false;
					for (int i = 0; i < lengthCars; i++) {
						if (_stricmp(inputColor, carMenu[i].color) == 0) {

							displayCarInfo(carMenu[i]);
							colorFound = true;
						}
					}
					if (!colorFound) {
						cout << "No cars with such color were found." << endl;
					}
					system("pause");
					break;
				}
				else if (caseChoice == 3) {
					system("cls");
					cout << "Enter the registration number of car: ";
					cin >> userInputRegisterNumber;
					bool registerNumbFound = false;
					for (int i = 0; i < lengthCars; i++) {
						if (_stricmp(userInputRegisterNumber, carMenu[i].registrationNumber) == 0) {

							displayCarInfo(carMenu[i]);
							registerNumbFound = true;
						}
					}
					if (!registerNumbFound) {
						cout << "No cars with such registration number were found." << endl;
					}
					system("pause");
					break;
				}
				else if (caseChoice == 4) {
					system("cls");
					cout << "Enter the year of production of the car : ";
					cin >> inputYearOfProduction;
					bool yearofproductionfound = false;
					for (int i = 0; i < lengthCars; i++) {
						if (inputYearOfProduction == carMenu[i].yearOfProduction) {

							displayCarInfo(carMenu[i]);
							yearofproductionfound = true;
						}
					}
					if (!yearofproductionfound) {
						cout << "No cars with such productiom year were found." << endl;
					}
					system("pause");
					break;

				}
				else if (caseChoice == 5) {
					system("cls");
					cout << "Enter the name of tenant: ";
					cin >> inputName;
					cout << "Enter the surname of tenant: ";
					cin >> inputSurname;
					cout << "Enter the middle name of tenant: ";
					cin >> inputIMiddleNameClient;

					bool tenantFound = false;
					for (int i = 0; i < lengthClients; i++) {
						if (_stricmp(inputName, clientMenu[i].name) == 0 &&
							_stricmp(inputSurname, clientMenu[i].surname) == 0 &&
							_stricmp(inputIMiddleNameClient, clientMenu[i].middleName) == 0) {
							displayClientInfo(clientMenu[i]);
							tenantFound = true;
						}
					}
					if (!tenantFound) {
						cout << "No clients with such a tenant were found." << endl;
					}
					system("pause");
					break;
				}
				else if (caseChoice == 6) {
					system("cls");
					cout << "Enter the name of contract: ";
					cin >> inputContarctName;
					cout << "Enter the surname of contract: ";
					cin >> inputContarctSurname;
					cout << "Enter the middle name of contract: ";
					cin >> inputMiddleName;

					bool contractFound = false;
					for (int i = 0; i < lengthContracts; i++) {
						if (_stricmp(inputContarctName, contractMenu[i].name) == 0 &&
							_stricmp(inputContarctSurname, contractMenu[i].surname) == 0 &&
							_stricmp(inputMiddleName, contractMenu[i].middleName) == 0) {
							displayContractInfo(carMenu[i], contractMenu[i]);
							contractFound = true;
						}
					}
					if (!contractFound) {
						cout << "No clients with such a contract were found." << endl;
					}

					system("pause");
					break;
				}
				else if (caseChoice == 7) {
					system("cls");
					cout << "Enter the start price range: ";
					cin >> start_range;
					cout << "Enter the end of price range: ";
					cin >> end_range;
					system("cls");

					bool found = false;

					for (int i = 0; i < lengthCars; i++) {
						if (carMenu[i].rentalPricePerDay >= start_range && carMenu[i].rentalPricePerDay <= end_range) {
							cout << "Car " << i + 1 << " information" << endl;
							displayCarInfo(carMenu[i]);
							found = true;
						}
					}

					if (!found) {
						cout << "No results found in the specified price range." << endl;
					}
				}

				system("pause");

				break;

#pragma endregion
#pragma region case2
			case 2:
				system("cls");
				cout << "1.Add a new car" << endl;
				cout << "2.Add new client" << endl;
				cout << "3.Add new contract" << endl;
				cout << "Choose the option: ";
				cin >> case2Search;
				if (case2Search == 1)
				{
					system("cls");
					carMenu = addCar(carMenu, lengthCars);
				}
				else if (case2Search == 2) {
					system("cls");
					clientMenu = addClient(clientMenu, lengthClients);
				}
				else if (case2Search == 3) {
					system("cls");
					contractMenu = addContract(contractMenu, carMenu, clientMenu, lengthContracts, lengthCars, lengthClients);
				}

				system("pause");
				break;
#pragma endregion
#pragma region case3
			case 3:
				system("cls");
				cout << "1. Deleting a car" << endl;
				cout << "2. Deleting a client" << endl;
				cout << "3. Deleting a contract" << endl;
				cout << "4. Deleting all information" << endl;
				cout << "Choose the option: ";
				cin >> case3Search;

				if (case3Search == 1) {
					char confirm1{};
					system("cls");
					cout << "Are you sure you want to delete a car? (y/n): ";
					cin >> confirm1;
					if (confirm1 == 'y' || confirm1 == 'Y') {
						carMenu = deleteCar(carMenu, lengthCars);
					}
					else {
						cout << "Deletion canceled." << endl;
					}
					system("pause");
					break;
				}
				else if (case3Search == 2) {
					char confirm2{};
					system("cls");
					cout << "Are you sure you want to delete a client? (y/n): ";
					cin >> confirm2;
					if (confirm2 == 'y' || confirm2 == 'Y') {
						clientMenu = deleteClient(clientMenu, lengthClients);
					}
					else {
						cout << "Deletion canceled." << endl;
					}
					system("pause");
					break;
				}
				else if (case3Search == 3) {
					char confirm3{};
					system("cls");
					cout << "Are you sure you want to delete a contract? (y/n): ";
					cin >> confirm3;
					if (confirm3 == 'y' || confirm3 == 'Y') {
						contractMenu = deleteContract(contractMenu, lengthContracts);
					}
					else {
						cout << "Deletion canceled." << endl;
					}
					system("pause");
					break;
				}

				else if (case3Search == 4) {
					system("cls");
					cout << "Are you sure you want to delete all information? (y/n): ";
					char confirm4{};
					cin >> confirm4;
					if (confirm4 == 'y' || confirm4 == 'Y') {
						lengthCars = 0;
						lengthClients = 0;
						lengthContracts = 0;
						deleteAllData(carMenu, clientMenu, contractMenu, lengthCars, lengthClients, lengthContracts);

					}
					else {
						cout << "Deletion canceled. All data is preserved." << endl;
					}
					system("pause");
					break;
				}

#pragma endregion
#pragma region case4
			case 4:
				system("cls");
				cout << "Enter the name of the client: ";
				cin >> inputNameArrer;

				cout << "Enter the surname of the client: ";
				cin >> inputSurnameArrer;

				cout << "Enter the middle name of the client: ";
				cin >> inputMiddleNameArrer;

				cout << "enter for how many days you want to find out the debt ";
				cin >> inputCurrentDay;

				clientDebt = currentDebt(contractMenu, clientMenu, carMenu, lengthContracts, lengthClients, lengthCars, inputNameArrer, inputSurnameArrer, inputMiddleNameArrer, inputCurrentDay);

				for (int i = 0; i < lengthContracts; i++) {
					if (_stricmp(contractMenu[i].name, inputNameArrer) == 0 &&
						_stricmp(contractMenu[i].surname, inputSurnameArrer) == 0 &&
						_stricmp(contractMenu[i].middleName, inputMiddleNameArrer) == 0) {
						contractMenu[i].totalRentalPrice = clientDebt;
					}
					cout << "Client: " << inputNameArrer << " " << inputSurnameArrer << " " << inputMiddleNameArrer << " owes " << clientDebt << " in total." << endl;
					break;
				}

				system("pause");
				break;
#pragma endregion
#pragma region case 5
			case 5:
				system("cls");
				for (int i = 0; i < lengthCars; i++) {
					cout << "Car " << i + 1 << " information:" << endl;
					displayCarInfo(carMenu[i]);
					cout << "--------------------------" << endl;
					cout << '\n';
					cout << "#############################" << endl;
					cout << '\n';
				}
				cout << '\n';
				for (int i = 0; i < lengthClients; i++)
				{
					cout << "Client " << i + 1 << endl;
					displayClientInfo(clientMenu[i]);
					cout << "--------------------------" << endl;
					cout << '\n';
					cout << "#############################" << endl;
					cout << '\n';
				}
				cout << '\n';
				for (int i = 0; i < lengthContracts; i++)
				{
					cout << "Contract " << i + 1 << endl;
					displayContractInfo(carMenu[i], contractMenu[i]);
					cout << "--------------------------" << endl;
					cout << '\n';
					cout << "#############################" << endl;
					cout << '\n';
				}

				system("pause");
				break;

#pragma endregion
#pragma region case6
			case 6:
				displayExitAnimation();
				break;

#pragma endregion
			}
		}
		system("cls");
		saveDataToFile(carMenu, clientMenu, contractMenu, lengthCars, lengthClients, lengthContracts);
		loadDataFromFile(carMenu, clientMenu, contractMenu, lengthCars, lengthClients, lengthContracts);

	}

}

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int backColor = GREEN;
	int foreColor = WHITE;
	WORD wcolor(((backColor & 0x0f) << 4) + (foreColor & 0x0F));

	FILE* file;

	int lengthCars = 5;
	Car* carMenu = createCarArray(lengthCars + 1);
	carMenu[0] = { "BMW", "328", "Pink", "99-XX-001", 2016, 2.0f, 100 };
	carMenu[1] = { "Mitsubishi", "Pajero", "White", "90-XX-956", 2008, 3.0f, 70 };
	carMenu[2] = { "Mercedes", "E-350", "Silver", "50-XX-111", 2009, 3.5f, 60 };
	carMenu[3] = { "Audi", "Q8", "Green", "99-XX-596", 2021, 3.0f, 90 };
	carMenu[4] = { "Ford", "Fusion", "Blue", "90-BG-579", 2007, 1.4f, 40 };


	int lengthClients = 2;
	Client* clientMenu = createClientArray(lengthClients + 1);
	clientMenu[0] = { "Murad", "Nurmammadli", "Azad" };
	clientMenu[1] = { "Sherlock", "Holmes", "Arthur" };


	int lengthContracts = 0;
	Contract* contractMenu = createContractArray(lengthContracts + 1);




	saveDataToFile(carMenu, clientMenu, contractMenu, lengthCars, lengthClients, lengthContracts);
	loadDataFromFile(carMenu, clientMenu, contractMenu, lengthCars, lengthClients, lengthContracts);

	displayMainMenu(carMenu, clientMenu, contractMenu, lengthCars, lengthClients, lengthContracts);

	delete[] carMenu;
	delete[] clientMenu;
	delete[] contractMenu;

	return 0;
}