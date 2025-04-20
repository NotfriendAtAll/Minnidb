#pragma once
#include "global.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class InputBuffer {
public:
  InputBuffer() : op(std::make_shared<Global_::MeteOperation>()) {}
  ~InputBuffer() = default;

  std::vector<std::string> Parse_command(const std::string &input); // 解析命令
  std::shared_ptr<Global_::CommandResult>
  Process_command(std::vector<std::string> &); // 处理(执行)命令
  Global_::CommandStatus HandleCommandResult(
      std::shared_ptr<Global_::CommandResult>); // 命令结果处理
  std::string Buffer;
  std::vector<std::string> CommandSet;
  std::unordered_map<std::string, int> target;
  std::shared_ptr<Global_::MeteOperation> op;
};