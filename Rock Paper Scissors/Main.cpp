#include <iostream>
#include "Game.h"
#include "Player.h"

int main(){
    std::string Player1,Player2;
    int mode,rounds;

    std::cout<<"=============================================================================================\n";
    std::cout<<"                          WELCOME TO ROCK,PAPER,SCISSORS \n";
    std::cout<<"=============================================================================================\n";

    std::cout<<" Player 1 give your name:";
    std::cin>>Player1;
    
    std::cout<<"";
    std::cout<<"\n Choose mode: (1) vs Player, (2) vs Computer: ";
    while(true){
        std::cin>>mode;
        if(mode ==1 || mode ==2)break;
        std::cout <<" Wrong input.Try again\n";
    }
    std::cout<<"\n";
    std::cout<<" Choose (1) for best of (3) for best of 3 and (5) for best of 5: ";
    while(true){ 
        std::cin>>rounds;
        if(rounds ==1 || rounds ==3 || rounds ==5)break;
        std::cout <<" Wrong input.Try again\n";
    }
    
    std::cout<<"\n";
    
    Player* player1 = new Human(Player1);
    Player* player2 = nullptr;

    if(mode ==1){
        std::cout<<" Player 2 give your name: ";
        std::cin>>Player2;
        player2 = new Human(Player2);
    }else{
        player2 = new Computer();
    }

    Game game(player1 ,player2,rounds);
    game.play();

  //  delete player1;
  //  delete player2;

    return 0;
}