#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Elem {
  public:
    Elem(string inputKey);
    int hash() const;
    bool operator>(const Elem& compElement) const;
    bool operator<(const Elem& compElement) const;
    bool operator>=(const Elem& compElement) const;
    bool operator<=(const Elem& compElement) const;
    bool operator==(const Elem& compElement) const;
    bool operator!=(const Elem& compElement) const;
    friend ostream& operator<<(ostream& os, const Elem& element);
  private:
    string key;
};

Elem::Elem(string inputKey) {
  key = inputKey;
}

int Elem::hash() const {
  int length = key.length();
  int hashVal = 19;
  int xOrVal = 53;
  for (int i = 0; i < length; i++) {
    hashVal = (hashVal*37) + key.at(i);
    xOrVal = xOrVal ^ key.at(length - 1 - i);
  }
  hashVal *= xOrVal;
  return abs(hashVal);
}

bool Elem::operator>(const Elem& compElement) const
{
  if (this->key > compElement.key) {
    return true;
  }
  else {
    return false;
  }
}

bool Elem::operator<(const Elem& compElement) const 
{
  if (this->key < compElement.key) {
    return true;
  }
  else {
    return false;
  }
}

bool Elem::operator>=(const Elem& compElement) const
{
  if (this->key >= compElement.key) {
    return true;
  }
  else {
    return false;
  }
}

bool Elem::operator<=(const Elem& compElement) const 
{
  if (this->key <= compElement.key) {
    return true;
  }
  else {
    return false;
  }
}

bool Elem::operator==(const Elem& compElement) const
{
  if (this->key == compElement.key) {
    return true;
  }
  else {
    return false;
  }
}

bool Elem::operator!=(const Elem& compElement) const
{
  if (this->key != compElement.key) {
    return true;
  }
  else {
    return false;
  }
}

std::ostream& operator<<(ostream& os, const Elem& element)
{
	os << element.key << endl;
	
	return os;
}

vector<int> testHashFunction(string fileName) {
  string line;
  int slots = 1000;
  vector<int> slotNumbers(1000);
  for (int i = 0; i < 1000; i++) {
      slotNumbers.at(i) = 0;
  }
  ifstream input(fileName);
  while(getline(input, line)) 
  {
    Elem word(line);
    int slot = word.hash() % slots;
    slotNumbers.at(slot) += 1;
  }
  input.close();
  return slotNumbers;
}

int minimum(vector<int> input) {
    int minNumber = 1000;
    int minSlot;
    for (int i = 0; i < input.size(); i++) {
        if (input.at(i) <= minNumber) {
            minNumber = input.at(i);
            minSlot = i;
        }
    }
    return minNumber;
}

int maximum(vector<int> input) {
    int maxNumber = 0;
    int maxSlot;
    for (int i = 0; i < input.size(); i++) {
        if (input.at(i) >= maxNumber) {
            maxNumber = input.at(i);
            maxSlot = i;
        }
    }
    return maxNumber;
}

int sDev(vector<int> input) {
    int n = input.size();
    int sum = 0;
    for (int i = 0; i < input.size(); i++) {
        sum += input.at(i);
    }
    int mean = sum / n;
    int total = 0;
    for (int i = 0; i < input.size(); i++) {
        total += ((input.at(i) - mean)*(input.at(i) - mean));
    }
    int result = sqrt(total / n);
    return result;
}

int testHashFunc() {
  vector<int> results = testHashFunction("words");  
  
  cout << "The minimum amount of words assigned to a slot " << minimum(results) << endl;

  cout << "The maximum amount of words assigned to a slot: " << maximum(results) << endl;

  cout << "The Standard Deviation: " << sDev(results) << endl;
}
