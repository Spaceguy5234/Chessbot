#include <iostream>
#include <bitset>

#include "lib/board.hpp"

int main(){
    Board board;
    std::cout << std::endl;
    std::string output = std::bitset<64>(board.getPawns()).to_string();
    for (int i=0; i < output.length(); i++){
        if (i%8 == 0){
            std::cout << std::endl;
        }
        std::cout << output[i];
    }
    
}