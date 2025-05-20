#pragma once
#include <string>

class Player{
protected: 
    std::string name;
    std::string choice;
public:
    Player(std::string PlayerName);
    virtual void MakeChoice() = 0;
    std::string Choice() const;
    std::string getName() const;

};

class Human : public Player{
public:
    Human(std::string PlayerName);
    void MakeChoice() override;
};

class Computer :public Player{
public:
    Computer();
    void MakeChoice() override;
};