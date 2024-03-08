#pragma once
#include <iostream>
#include <vector>
#include <thread>

class Stockfish
{
public:
    Stockfish();

    ~Stockfish();

    void run(std::string line, std::string position);

    void update(std::string&);

private:
    std::vector<std::string> histories;

    std::string eval;

    //std::thread* T;

};