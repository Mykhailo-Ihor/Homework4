#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class City
{
private:
	string country;
	string name;
	int population;
public:
	City(string country = "", string name= "", int population = 0) : country(country), name(name), population(population) {}
	City(const City& city) : country(city.country), name(city.name), population(city.population) {}
	string getCountry() const { return country; }
	string getName() const { return name; }
	int getPopulation() const { return population; }
	friend ostream& operator<<(ostream& os, const City& city);
	friend istream& operator>>(istream& is, City& city);
	bool operator<(const City& city) const;
	
};

vector<City> readCitiesFromFile(ifstream& is);
vector<City> concatenate(const vector<City>& cities1, const vector<City>& cities2,const vector<City>& cities3);
vector<City> OneCountry(const vector<City>& cities, string country);
int countPopulation(const vector<City>& cities);
void getInfo(const vector<City>& v);