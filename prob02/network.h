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

#include <map>
#include <memory>

#include "message.h"
#include "phone.h"

class Network {
  // ======================= YOUR CODE HERE =======================
  // Write the Network class here. Refer to the README for the member
  // variables, constructors, and member functions needed.
  //
  // If you were the "driver" for the Phone class, then switch roles
  // with your lab partner and act as the "navigator" for this class.
  // ===============================================================
private: 
std::map<std::string, std::shared_ptr<Phone>> phonebook_;

public:

void AddPhone(std::shared_ptr<Phone> add){
  phonebook_.insert({add->GetOwner(), add});
}

void SendMessage(std::shared_ptr<Message> send, const std::string &person);

void SendMessage(std::shared_ptr<Message> send, const std::vector<std::string> vector);

};