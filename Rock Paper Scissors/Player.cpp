#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Player::Player(std::string PlayerName) :name(PlayerName){}

std::string Player::getName() const {
    return name;}
std::string Player::Choice() const {
    return choice;} 

Human::Human(std::string PlayerName) :Player(PlayerName){}
    
void Human::MakeChoice() {
        std::string input; 
        std::cout<<name<<": Choose rock,paper or scissors:";
        while(true)
        {
            std::cin>>input;
            if(input=="rock" || input=="paper" || input=="scissors"){
                choice =input;
                break;}
            else{
                std::cout <<"\n Wrong iput.Please choose again:";
            }
        }
}

Computer::Computer():Player("Computer"){
    std::srand(std::time(0)); //αρχικοποιηση για την rand
}
void Computer::MakeChoice(){
    int RandChoice = std::rand() % 3;
    if (RandChoice == 0) choice ="rock";
    else if (RandChoice ==1)choice ="paper";
    else choice ="scissors";

   // std::cout <<"Coptuter chose:"<< choice<<"\n";
}