


#include "Stockfish.h"
#include <cstdarg>
#include <string>
#include <fstream>
#include <memory>
#include <cstdio>
#include <future>


using namespace std;

Stockfish::Stockfish() : eval("") {

    
}

Stockfish::~Stockfish() {

}

std::string exec(const char *cmd) {
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while (!feof(pipe.get())) {
        if (fgets(buffer, 128, pipe.get()) != NULL)
            result += buffer;
    }
    return result;
}

void Stockfish::run(string line, string position) {
    histories.push_back(position);

    string commandLine = "position startpos move ";
    for (std::string history : histories) {
        commandLine.append(history + " ");
    }
    commandLine.append("\nd\ngo depth 20\n");

    std::ofstream myFile;
    myFile.open("command.txt");
    myFile << commandLine;
    myFile.close();

    string execLine = "( cat command.txt; sleep 3; ) | stockfish/stockfish-ubuntu-x86-64-avx2";
    //T = new std::thread(exec, execLine.c_str());

    

    auto future = std::async(exec, execLine.c_str());

    std::string result = future.get();

    std::cout << "Initial: " << result << std::endl;

    string ans = result;
    while (ans.find("score ") != std::string::npos) {
        ans = ans.substr(ans.find("score ") + 6, 100000);
    }

    if (ans[0] == 'c' && ans[1] == 'p') {
        char val[4] = {ans[3], ans[4], ans[5], '\0'};
        eval = val;
        std::cout << val << std::endl;
    }

    if (ans[0] == 'm' && ans[1] == 'a', ans[2] == 't' && ans[3] == 'e') {
        char val[3] = {ans[5], ans[6], '\0'};
        eval = val;
        std::cout << val << std::endl;
    }
    
    std::cout << "Output" << ans << std::endl;
    
    

}

void Stockfish::update(std::string& outEval) {
    outEval = eval;
}
