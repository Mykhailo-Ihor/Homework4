#include "task1.h"
#include "task2.h"
using namespace std;

int main()
{
	vector<double> v1 = { 1.0, 2.0, 3.0 };
	vector<double> v2 = { 4.0, 5.0, 6.0 };

	try {
		cout << "Scalar product: " << scalarProduct(v1, v2) << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Error: " << e.what() << endl;
	}
	vector<vector<double>> m = {
		{1.0, 2.0, 3.0},
		{4.0, 5.0, 6.0},
		{7.0, 8.0, 9.0}
	};

	try {
		cout << "Matrix: " << endl;
		vector<double> result = multiplyVectorByMatrix(v1, m);
		cout << "Result: ";
		for (double d : result) {
			cout << d << " ";
		}
		cout << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Error: " << e.what() << endl;
	}
	system("pause");
	system("cls");
	ifstream file("cities1.txt");
	auto cities1 = readCitiesFromFile(file);
	file.close();
	file.open("cities2.txt");
	auto cities2 = readCitiesFromFile(file);
	file.close();
	file.open("cities3.txt");
	auto cities3 = readCitiesFromFile(file);
	file.close();
	auto allCities = concatenate(cities1, cities2, cities3);
	sort(allCities.begin(), allCities.end());
	cout << "All cities: " << endl;
	for (const City& city : allCities)
	{
		cout << city << endl;
	}
	cout << "\nCities from one country: " << endl;
	getInfo(OneCountry(allCities, "USA"));
    getInfo(OneCountry(allCities, "Canada"));
    getInfo(OneCountry(allCities, "Mexico"));
	getInfo(OneCountry(allCities, "Brazil"));
	getInfo(OneCountry(allCities, "Argentina"));
	getInfo(OneCountry(allCities, "Italy"));
	getInfo(OneCountry(allCities, "Spain"));
	getInfo(OneCountry(allCities, "United Kingdom"));
	getInfo(OneCountry(allCities, "Japan"));
	getInfo(OneCountry(allCities, "China"));
	getInfo(OneCountry(allCities, "India"));
	getInfo(OneCountry(allCities, "Ukraine"));
	getInfo(OneCountry(allCities, "Poland"));
	getInfo(OneCountry(allCities, "France"));
	getInfo(OneCountry(allCities, "Germany"));
	return 0;
}