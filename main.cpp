#include <iostream>
#include "test.pb.h"

int main() {
  Test message;

  message.set_message("Hello, protobuf!");
  std::cout << message.message() << std::endl;
}