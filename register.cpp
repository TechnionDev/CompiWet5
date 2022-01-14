#include "register.h"

RegisterManager registerManager;

string RegisterManager::getCurrentRegisterName() {
	return "%t_" + to_string(this->counter);
}

string RegisterManager::getNextRegisterName() {
	this->counter++;
	return "%t_" + to_string(this->counter);
}

string RegisterManager::getVarRegister(string var) {
	if (isIdentifierExists(var)) {
		return this->varName2Register[var];
	}
	return "";
}

void RegisterManager::createRegister(Node *node, string value, string id) {
	//for declaring or reassigning a variable
}

string RegisterManager::createArithmeticOp(Node *left, Node *right, string op) {
	//le
}