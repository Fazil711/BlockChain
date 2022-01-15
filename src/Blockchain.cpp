#include "../Include/Blockchain.h"
#include <iostream>

Blockchain::Blockchain()
{
    chain.emplace_back(Block(0, 0, "Genesis", "Genesis"));
    nDifficulty = 4;
}

void Blockchain::addBlock(Block bNew)
{
    bNew._prevHash = getlastblock()._hash;
    bNew.Mine(nDifficulty);
    chain.push_back(bNew);
}

Block Blockchain::getlastblock() const
{
    return chain.back();
}

void Blockchain::printchain() {
    std::vector<Block>::iterator it;
    for (it = chain.begin(); it != chain.end(); it++) {
        Block currentBlock = *it;
        std::cout << "Block ===================================" << std::endl;
        std::cout << "Block Id:        " << currentBlock.getindex() << std::endl;
        std::cout << "Block Amt:       " << currentBlock.getAmt() << std::endl;
        std::cout << "Block Sender:    " << currentBlock.getS() << std::endl;
        std::cout << "Block Reciever:  " << currentBlock.getR() << std::endl;
        std::cout << "Block nonce:     " << currentBlock.getnonce() << std::endl;
        std::cout << "Block Hash:      " << currentBlock._hash << std::endl;
        std::cout << "Block prev:      " << currentBlock._prevHash << std::endl;
        std::cout << std::endl;
    }
}
