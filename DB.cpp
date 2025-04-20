#include "Include/InputBuffer.h"
#include "Include/global.h"
#include <exception>
#include <iostream>
#include <string>

int main() {
  try {
    auto newbuffer = new InputBuffer();
    while (true) {
      std::string user_input;
      Global_::Promote();
      std::getline(std::cin, user_input);
      Global_::Prepare(user_input);
      newbuffer->CommandSet = newbuffer->Parse_command(user_input);
      auto new_result = newbuffer->Process_command(newbuffer->CommandSet);
      if (newbuffer->HandleCommandResult(new_result) ==
          Global_::CommandStatus::EXIT) {
        break;
      }
    }
  } catch (std::exception &error) {
    std::cerr << "the error is " << error.what();
  }
}