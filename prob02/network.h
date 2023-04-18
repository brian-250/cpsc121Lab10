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

#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "message.h"
#include "phone.h"

class Network {
 public:
  void AddPhone(std::shared_ptr<Phone> phone);
  void SendMessage(std::shared_ptr<Message> message,
                   const std::string& recipient);
  void SendMessage(std::shared_ptr<Message> message,
                   const std::vector<std::string>& recipients);

 private:
  std::map<std::string, std::shared_ptr<Phone>> phonebook_;
};
