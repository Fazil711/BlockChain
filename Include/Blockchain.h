#pragma once
#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include <vector>

class Blockchain {
public:
	Blockchain();

	void addBlock(Block bNew);
	void printchain();

private:
	uint32_t nDifficulty;
	std::vector<Block> chain;
	Block getlastblock() const;
};

#endif
