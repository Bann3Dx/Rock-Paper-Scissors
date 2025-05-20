#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>

class Player{
protected: 
    std::string name;
    std::string choice;
public:
    Player(std::string PlayerName) :name(PlayerName){}
    virtual void MakeChoice() = 0;
    std::string Choice() const;
    std::string getName() const;

};

std::string Player::getName() const {
    return name;}
std::string Player::Choice() const {
    return choice;}


class Human : public Player{
public:
    Human(std::string PlayerName) :Player(PlayerName){}
    void MakeChoice() override{
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
};

class Computer :public Player{
public:
    Computer() : Player("Computer"){
        std::srand(std::time(0)); //αρχικοποιηση για την rand
    }
void MakeChoice() override {
    int RandChoice = std::rand() % 3;
    if (RandChoice == 0) choice ="rock";
    else if (RandChoice ==1)choice ="paper";
    else choice ="scissors";

    std::cout <<"Computer chose:"<< choice<<"\n";
}
};

class Game{
private:
    Player* player1;
    Player* player2;
    int score1,score2,rounds,cround;
public:
    Game(Player* p1,Player*p2,int Totalrounds) 
    :player1(p1),player2(p2),score1(0),score2(0),rounds(Totalrounds),cround(1){}
    void play(){
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
       std::cout <<"==========================================Final Score==========================================\n";
       std::cout << player1->getName()<<" : "<<score1 <<"\n";
       std::cout << player2->getName()<<" : "<<score2 <<"\n";
       
       
       std::cout<<"=============================================================================================\n";
       if (score1 > score2) {
            std::cout << player1->getName() << ": Won the game\n";
       } else if (score2 > score1) {
            std::cout << player2->getName() << ": Won the game\n";
       } else {
            std::cout << " Game was a Tie\n";}
    }
};


void Hidden(std::string& input);


int main(){
    std::string Player1,Player2;
    int mode,rounds;

    std::cout<<"=============================================================================================\n";
    std::cout<<"                          WELCOME TO ROCK,PAPER,SCISSORS \n";
    std::cout<<"=============================================================================================\n";

    std::cout<<" Player 1 give your name:";
    std::cin>>Player1;
    
    std::cout<<"";
    std::cout<<"\n Choose (1) if you want to play with another player or (2) to play with the computer: ";
    while(true){
        std::cin>>mode;
        if(mode ==1 || mode ==2)break;
        std::cout <<" Wrong input.Try again\n";
    }
    std::cout<<"\n";
    std::cout<<" Choose (1)for best of 1 (3)for best of 3 and (5)for best of 5: ";
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