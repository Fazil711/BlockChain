#include<iostream>
#include "../Include/Blockchain.h"


int main() {
	Blockchain Smolcoin;

	std::cout << "Mining Coin 1..." << std::endl;
	Smolcoin.addBlock(Block(1, 200, "Fazil", "Person1"));

	std::cout << "Mining Coin 2..." << std::endl;
	Smolcoin.addBlock(Block(2, 300, "Person2", "Fazil"));

	Smolcoin.printchain();

	return 0;
}
