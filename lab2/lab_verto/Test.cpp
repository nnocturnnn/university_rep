#include "Database.h"

int main() {
	Database db;
	if (!db.LoadFromFile("input.csv"))
		cout << "Error input file";
	else {
		db.DisplayAll();
		db.ArrangeSubordinates();
		db.DisplayAll();
	}
}
