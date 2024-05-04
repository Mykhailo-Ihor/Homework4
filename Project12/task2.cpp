#include "task2.h"
#include <numeric>
#include <iomanip>
ostream& operator<<(ostream& os, const City& city)
{
    os <<  setw(10) << left << "Country: " << setw(15) << left << city.getCountry()
        << setw(10) << left << "Name: " << setw(15) << left << city.getName()
        << setw(10) << left << "Population: " << setw(10) << right << city.getPopulation();
    return os;
}
istream& operator>>(istream& is, City& city)
{   
    getline(is, city.country, ',');
    getline(is, city.name, ',');
    is >> city.population;
    is.get();
    return is;
}

vector<City> readCitiesFromFile(ifstream& is)
{
    if (!is.is_open())
    {
        throw invalid_argument("File is not open");
    }
    vector<City> cities;
    while (!is.eof()) 
    {
        copy(istream_iterator<City>(is), istream_iterator<City>(), back_inserter(cities));
    }
    return cities;
}

vector<City> concatenate(const vector<City>& cities1, const vector<City>& cities2, const vector<City>& cities3)
{
    vector<City> cities(cities1);
    cities.insert(cities.begin(), cities2.begin(), cities2.end());
    cities.insert(cities.end(), cities3.begin(), cities3.end());
	return cities;
}

vector<City> OneCountry(const vector<City>& cities, string country)
{
    vector<City> citiesOneCountry;
	copy_if(cities.begin(), cities.end(), back_inserter(citiesOneCountry), [country](const City& city) {return city.getCountry() == country; });
	return citiesOneCountry;
}

int countPopulation(const vector<City>& cities)
{
    return accumulate(cities.begin(), cities.end(), 0, [](int sum, const City& city) {return sum + city.getPopulation(); });
}

void getInfo(const vector<City>& v)
{
    for (const City& city : v)
    {
		cout << city << endl;
	}
    cout << " Total population: " << countPopulation(v) << endl;
}

bool City::operator<(const City& city) const
{
    return population < city.population;
}
