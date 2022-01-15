#include "../Include/Block.h"
#include "../Include/sha256.h"
#include <sstream>
#include <iostream>

Block::Block(uint32_t i, uint32_t a, const std::string& s, const std::string& r) {
	_nonce = 0;
	_hash = _CalculateHash();
    _id = i;
    _amt = a;
    _sender = s;
    _reciever = r;
    _prevHash = "0000000000000000000000000000000000000000000000000000000000000000";
}

void Block::Mine(uint32_t nDifficulty)
{
    char cstr[5];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    std::string str(cstr);

    do
    {
        _nonce++;
        _hash = _CalculateHash();
    } while (_hash.substr(0, nDifficulty) != str);

    std::cout << "Block mined: " << _id << std::endl;
    std::cout << std::endl;
}

inline std::string Block::_CalculateHash() const
{
    std::stringstream ss;
    ss << _id << _prevHash << _amt << _sender << _reciever << _nonce;

    return sha256(ss.str());
}

uint32_t Block::getindex() {
    return _id;
}

uint32_t Block::getAmt() {
    return _amt;
}

std::string Block::getS() {
    return sha256(_sender);
}

std::string Block::getR() {
    return sha256(_reciever);
}

int64_t Block::getnonce() {
    return _nonce;
}
