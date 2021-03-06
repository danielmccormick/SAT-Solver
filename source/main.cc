#include "sat.cc"

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv) {
	if (argc == 1) {
		cout << "Usage: ./satSolver file1 file2 .... file n\n";
		return 0;
	} else {
		sat::formula dimacsFormula;
		for (int i = 1; i < argc; i++) {
			dimacsFormula.readFromFile(argv[i]);
			if (sat::isSat(dimacsFormula)) { cout << "SAT\n"; }
			else { cout << "UNSAT\n"; }
			dimacsFormula.clear();
		}
	}
	return 0;
}
