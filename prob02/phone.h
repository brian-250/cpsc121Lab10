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

#include <memory>
#include <string>
#include <vector>

#include "message.h"

class Phone {
 public:
  Phone(const std::string& owner);
  std::string GetOwner() const;
  std::shared_ptr<Message> AuthorMessage(const std::string& message);
  void AcceptMessage(std::shared_ptr<Message> message);
  void PrintMessages();  // Should we make this function const?

 private:
  std::string owner_;
  std::vector<std::shared_ptr<Message>> messages_;
};
