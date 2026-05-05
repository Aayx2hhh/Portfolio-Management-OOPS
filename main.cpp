#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Asset {
protected:
    string name;
    double value;
public:
    Asset(string n = "", double v = 0.0) : name(n), value(v) {}
    virtual void display() { cout << "Asset: " << name << " | Value: $" << value << endl; }
    virtual ~Asset() {}
    virtual string toString() { return name + "," + to_string(value); }
};

class Stock : public Asset {
private:
    string ticker;
public:
    Stock(string n, double v, string t) : Asset(n, v), ticker(t) {}
    void display() override {
        cout << "Stock: [" << ticker << "] " << name << " | Value: $" << value << endl;
    }
    string toString() override {
        return "STOCK," + ticker + "," + name + "," + to_string(value);
    }
};

class PortfolioManager {
private:
    string filename;
public:
    PortfolioManager(string fname) : filename(fname) {}
    void saveAsset(Asset* a) {
        ofstream outFile(filename, ios::app);
        if (outFile.is_open()) {
            outFile << a->toString() << endl;
            outFile.close();
            cout << "Data saved to file!\n";
        }
    }
    void loadAssets() {
        ifstream inFile(filename);
        string line;
        cout << "\n--- Current Portfolio Records ---\n";
        if (inFile.is_open()) {
            while (getline(inFile, line)) { cout << line << endl; }
            inFile.close();
        } else {
            cout << "No existing records found. Creating new file on first save.\n";
        }
    }
};

int main() {
    PortfolioManager myManager("portfolio.txt");
    int choice;
    do {
        cout << "\n1. Add Stock\n2. View Portfolio\n3. Exit\nEnter Choice: ";
        cin >> choice;
        if (choice == 1) {
            string name, ticker;
            double price;
            cout << "Enter Ticker: "; cin >> ticker;
            cout << "Enter Name: "; cin.ignore(); getline(cin, name);
            cout << "Enter Price: "; cin >> price;
            Stock* newStock = new Stock(name, price, ticker);
            myManager.saveAsset(newStock);
            delete newStock;
        } else if (choice == 2) {
            myManager.loadAssets();
        }
    } while (choice != 3);
    return 0;
}
