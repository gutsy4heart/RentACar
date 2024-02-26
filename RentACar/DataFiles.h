void saveDataToFile(Car* carMenu, Client* clientMenu, Contract* contractMenu, int& lengthCars, int& lengthClients, int& lengthContracts) {
	FILE* fileCar;
	if (fopen_s(&fileCar, "cars_data.dat", "wb") == 0) {
		fwrite(carMenu, sizeof(Car), lengthCars, fileCar);
		fclose(fileCar);
	}

	FILE* fileClient;
	if (fopen_s(&fileClient, "clients_data.dat", "wb") == 0) {
		fwrite(clientMenu, sizeof(Client), lengthClients, fileClient);
		fclose(fileClient);
	}

	FILE* fileContract;
	if (fopen_s(&fileContract, "contracts_data.dat", "wb") == 0) {
		fwrite(contractMenu, sizeof(Contract), lengthContracts, fileContract);
		fclose(fileContract);
	}
}

void loadDataFromFile(Car* carMenu, Client* clientMenu, Contract* contractMenu, int& lengthCars, int& lengthClients, int& lengthContracts) {
	FILE* fileCar;
	if (fopen_s(&fileCar, "cars_data.dat", "rb") == 0) {
		fread(carMenu, sizeof(Car), lengthCars, fileCar);
		fclose(fileCar);
	}

	FILE* fileClient;
	if (fopen_s(&fileClient, "clients_data.dat", "rb") == 0) {
		fread(clientMenu, sizeof(Client), lengthClients, fileClient);
		fclose(fileClient);
	}

	FILE* fileContract;
	if (fopen_s(&fileContract, "contracts_data.dat", "rb") == 0) {
		fread(contractMenu, sizeof(Contract), lengthContracts, fileContract);
		fclose(fileContract);
	}
}