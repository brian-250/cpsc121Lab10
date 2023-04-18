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

#include <iostream>
#include <memory>
#include <vector>

#include "message.h"
#include "network.h"
#include "phone.h"

int main() {
  Network csuf_network;
  // =================== YOUR CODE HERE ===================
  // 1. Create 3 objects of type `std::shared_ptr<Phone>`.
  //    `phone1`: a pointer to a Phone owned by Anna
  //    `phone2`: a pointer to a Phone owned by Raf
  //    `phone3`: a pointer to a Phone owned by JC
  // ======================================================
  std::shared_ptr<Phone> phone1 = std::make_shared<Phone>("Anna");
  std::shared_ptr<Phone> phone2 = std::make_shared<Phone>("Raf");
  std::shared_ptr<Phone> phone3 = std::make_shared<Phone>("JC");

  // =================== YOUR CODE HERE ===================
  // 2. Add each phone to the Network, `csuf_network`.
  // ======================================================
  csuf_network.AddPhone(phone1);
  csuf_network.AddPhone(phone2);
  csuf_network.AddPhone(phone3);

  // =================== YOUR CODE HERE ===================
  // 3. Send the message "Sup" to Raf over the network,
  //    authored on Anna's phone.
  // ======================================================
  std::shared_ptr<Message> message1 =
      std::make_shared<Message>("Sup", phone1->GetOwner());
  phone1->AuthorMessage(message1->GetMessage());
  csuf_network.SendMessage(message1, phone2->GetOwner());

  // =================== YOUR CODE HERE ===================
  // 4. Send the message "Lol" to Anna over the network,
  //    authored on Raf's phone.
  // ======================================================
  std::shared_ptr<Message> message2 =
      std::make_shared<Message>("Lol", phone2->GetOwner());
  phone2->AuthorMessage(message2->GetMessage());
  csuf_network.SendMessage(message2, phone1->GetOwner());

  // =================== YOUR CODE HERE ===================
  // 5. Create a vector of strings containing "Anna" and
  //    "Raf" called `jcs_class`. Call the SendMessage
  //     overload to author a message on JC's phone and send
  //     the message "Hi class!" to everyone in `jcs_class`.
  // ======================================================
  std::vector<std::string> jcs_class{phone1->GetOwner(), phone2->GetOwner()};
  std::shared_ptr<Message> message3 =
      std::make_shared<Message>("Hi class!", phone3->GetOwner());
  phone3->AuthorMessage(message3->GetMessage());
  csuf_network.SendMessage(message3, jcs_class);

  // =================== YOUR CODE HERE ===================
  // 6. Send the message "Hi Prof!" to JC over the network,
  //    authored on Anna's phone.
  // ======================================================
  Message message4("Hi Prof!", phone1->GetOwner());
  csuf_network.SendMessage(phone1->AuthorMessage(message4.GetMessage()),
                           phone3->GetOwner());

  // =================== YOUR CODE HERE ===================
  // 7. Send the message "help how do C++" to JC over the
  //    network, authored on Raf's phone.
  // ======================================================
  Message message5("help how do C++", phone2->GetOwner());
  csuf_network.SendMessage(phone2->AuthorMessage(message5.GetMessage()),
                           phone3->GetOwner());

  // =================== YOUR CODE HERE ===================
  // 8. Complete the std::cout statements below to display
  //    the messages on Anna's phone, Raf's phone, and JC's
  //    phone in that order. Follow the README for an example.
  // ======================================================
  std::cout << "Printing messages sent to Anna: \n";
  phone1->PrintMessages();

  std::cout << "\n";
  std::cout << "Printing messages sent to Raf: \n";
  phone2->PrintMessages();

  std::cout << "\n";
  std::cout << "Printing messages sent to JC: \n";
  phone3->PrintMessages();
}
