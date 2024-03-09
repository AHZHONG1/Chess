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

    void update(double&);

    bool getUpdate();

    void setUpdate(bool);

private:
    std::vector<std::string> histories;

    double eval;

    bool isUpdate;

    //std::thread* T;

};