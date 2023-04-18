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
#include "phone.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "message.h"

Phone::Phone(const std::string& owner) : owner_(owner) {}
std::string Phone::GetOwner() const { return owner_; }
std::shared_ptr<Message> Phone::AuthorMessage(const std::string& message) {
  std::shared_ptr<Message> message1 =
      std::make_shared<Message>(message, owner_);
  return message1;
}
void Phone::AcceptMessage(std::shared_ptr<Message> message) {
  messages_.push_back(message);
}
void Phone::PrintMessages() {
  for (auto& index : messages_) {
    std::cout << index->GetSender() << ": " << index->GetMessage() << "\n";
  }
}
