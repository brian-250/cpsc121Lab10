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
#include <iostream>
#include <memory>
#include <map>
#include <vector>

#include "message.h"
#include "phone.h"
#include "network.h"
// ========================= YOUR CODE HERE =========================
// This implementation file (network.cc) is where you should implement
// the member functions declared in the header (network.h), only
// if you didn't implement them inline within network.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the Network class.
// ===================================================================

void Network::SendMessage(std::shared_ptr<Message> send, const std::string &person){
  if(phonebook_.count(person) == 0){
  }
  else {
    Phone net(person);
    net.AcceptMessage(send);
  }
}

void Network::SendMessage(std::shared_ptr<Message> send, const std::vector<std::string> vector){
    for(int i = 0; i < vector.size(); i++){
        if(phonebook_.count(vector.at(i)) == 0){

    }
    else {
    Phone net(vector.at(i));
    net.AcceptMessage(send);
    }
    }
}