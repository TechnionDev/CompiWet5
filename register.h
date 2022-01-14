#ifndef COMPIWET5__REGISTER_H_
#define COMPIWET5__REGISTER_H_
#include <string>
#include <map>
#include "Semantics.h"
using namespace std;

class RegisterManager {
  public:
	int counter = 0;
	int stringCounter = 0;
	map<string, string> varName2Register;
	map<string, string> varName2Stack;
	RegisterManager() = default;
	string getCurrentRegisterName();
	string getNextRegisterName();
	string getVarRegister(string var);
	void createRegister(Node *node, string value, string id); //for declaring or reassigning a variable
	string createArithmeticOp(Node *left_node, Node *right_node, string op); // MUL,DIV,PLUS,MINUS
	string loadVar(string var);
	string storeVar(string var, string varValue);


};

#endif //COMPIWET5__REGISTER_H_
