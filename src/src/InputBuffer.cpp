#include "../Include/InputBuffer.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <memory>
#include <regex>
#include <string>
#include <vector>

std::vector<std::string> InputBuffer::Parse_command(const std::string &input) {
  std::vector<std::string> parts;
  // 匹配所有非空字符序列（自动跳过空格）

  std::regex reg(R"(\S+)");
  // 用迭代器提取所有匹配项
  auto words_begin = std::sregex_iterator(input.begin(), input.end(), reg);
  auto words_end = std::sregex_iterator();

  for (auto it = words_begin; it != words_end; ++it) {
    parts.push_back(it->str());
  }
  return parts;
}

std::shared_ptr<Global_::CommandResult>
InputBuffer::Process_command(std::vector<std::string> &input) {
  auto Command_Result =
      std::make_shared<Global_::CommandResult>(Global_::CommandResult());
  auto str = input[0];
  std::transform(str.begin(), str.end(), str.begin(), [](unsigned char char_) {
    return static_cast<char>(::tolower(char_));
  }); // 将大写命令转成小写

  if (input[0] == "./exit") {
    Command_Result->status = Global_::CommandStatus::EXIT;
    Command_Result->message = "EXIT successfully";
    return Command_Result;
  } else if (input[0] == "insert") {
    Command_Result->status = Global_::CommandStatus::INSERT;
    op->Put(input[1], input[2]);
    Command_Result->message = "Insert successfully";
    return Command_Result;
  } else if (input[0] == "delete") {
    Command_Result->status = Global_::CommandStatus::INSERT;
    Command_Result->message = "Delete successfully";
    return Command_Result;
  } else if (input[0] == "get") {
    Command_Result->status = Global_::CommandStatus::GET;
    op->Get(input[1]);
    Command_Result->message = "Get successfully";
    return Command_Result;
  }
  Command_Result->status = Global_::CommandStatus::UNKNOWN_COMMAND;
  Command_Result->message = input[0];
  return Command_Result;
}
Global_::CommandStatus InputBuffer::HandleCommandResult(
    std::shared_ptr<Global_::CommandResult> Result) {
  if (Result->status == Global_::CommandStatus::EXIT) {
    std::cout << Result->message << '\n';
    return Global_::CommandStatus::EXIT;
  }
  if (Result->status == Global_::CommandStatus::UNKNOWN_COMMAND) {
    std::cout << Result->message << '\n';
  }
  return Global_::CommandStatus::FINSHED;
}
