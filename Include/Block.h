#pragma once
#ifndef BLOCK_H
#define BLOCK_H

#include<string>

class Block {
private:
	uint32_t _id;
	int64_t _nonce;
	uint32_t _amt;
	std::string _sender;
	std::string _reciever;
	
	std::string _CalculateHash() const;
public:
	Block(uint32_t i, uint32_t a, const std::string& s, const std::string& r);

	std::string _prevHash;
	std::string _hash;

	void Mine(uint32_t nDifficulty);
	uint32_t getindex();
	uint32_t getAmt();
	std::string getS();
	std::string getR();
	int64_t getnonce();
};

#endif 
