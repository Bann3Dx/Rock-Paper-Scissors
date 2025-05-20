#include "Game.h"
#include <iostream>

Game::Game(Player* p1,Player* p2,int Totalrounds)
    :player1(p1),player2(p2),score1(0),score2(0),rounds(Totalrounds),cround(1){}

void Game::play(){
        while(cround<=rounds){
         
        std::cout<<"\n";
        std::cout <<"==========================================Round"<< cround<<"=============================================\n";
        std::cout<<"\n";

        player1 -> MakeChoice();
        player2 -> MakeChoice();

        
        std::cout<<"=============================================================================================\n";
        std::string c1 = player1->Choice();
        std::string c2 = player2->Choice();
     

        std::cout << player1->getName()<<": Chose "<<c1<<"\n";
        std::cout << player2->getName()<<": Chose "<<c2<<"\n";
        
        std::cout <<"\n";
        if (c1==c2){
            std::cout <<" This round is a tie\n";
        }else if ((c1=="rock" && c2 =="scissors") ||
                  (c1=="scissors" && c2=="paper") ||
                  (c1=="paper" && c2=="rock")){
            std::cout << player1->getName()<<": Won this round\n";
            score1++;
        }else {
            std::cout << player2->getName()<<": Won this round\n";
            score2++;
        }
        cround++;
    }
       std::cout <<"==========================================Final Score========================================\n";
       std::cout << player1->getName()<<" : "<<score1 <<"\n";
       std::cout << player2->getName()<<" : "<<score2 <<"\n";
       
       
       std::cout<<"=============================================================================================\n";
       if (score1 > score2) {
            std::cout << player1->getName() << ": Won the game\n";
       } else if (score2 > score1) {
            std::cout << player2->getName() << ": Won the game\n";
       } else {
            std::cout << ": Game was a Tie\n";}
    }