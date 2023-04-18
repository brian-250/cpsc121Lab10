// Brian Milian
// CPSC 121L-01
// 2023-04-04
// brianmilian@csu.fullerton.edu
// @brian-250
//
// Lab 10-2
// Pair Programming Lab
// Partner: @abledaniel
//
// This program creates a network class that connects smart pointer phone
// objects together to allow for communication within the owners of the phones
//

#include "network.h"

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "message.h"
#include "phone.h"

void Network::AddPhone(std::shared_ptr<Phone> phone) {
  phonebook_.insert({phone->GetOwner(), phone});
}
void Network::SendMessage(std::shared_ptr<Message> message,
                          const std::string& recipient) {
  for (auto const& index : phonebook_) {
    if (index.first == recipient) {
      index.second->AcceptMessage(message);
    }
  }
}
void Network::SendMessage(std::shared_ptr<Message> message,
                          const std::vector<std::string>& recipients) {
  for (auto const& index : phonebook_) {
    for (auto const& person : recipients) {
      if (index.first == person) {
        index.second->AcceptMessage(message);
      }
    }
  }
}
