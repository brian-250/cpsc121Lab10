// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>
//
// Lab 10-2
// If it is a pair programming lab please specify partner below.
// Partner: @peteranteater

#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "message.h"

class Phone {
  // ======================= YOUR CODE HERE =======================
  // Write the Phone class here. Refer to the README for the member
  // variables, constructors, and member functions needed.
  //
  // Select one among you and your lab partner to be the "driver"
  // and the other to be the "navigator". The driver should write
  // the code, while the navigator reviews the code. Both of you
  // should communicate and share thoughts as you go along.
  // ===============================================================
private:
std::string owner_;
std::vector<std::shared_ptr<Message>> messages_; 

public:

Phone(std::string owner){
  owner_ = owner;
}

  std::string GetOwner()const { return owner_;}

  std::shared_ptr<Message> AuthorMessage(const std::string &mess){
    std::shared_ptr<Message> message1 = std::make_shared<Message>(mess, owner_);
    return message1; 
  }

  void AcceptMessage(std::shared_ptr<Message> accept){ messages_.push_back(accept);}

  void PrintMessage(){
    std::cout << "sender: ";
  };

};