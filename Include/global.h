#pragma once
#include "../Include/Btree.h"
#include <cstdint>
#include <memory>
#include <string>
namespace Global_ {
enum class CommandStatus {
  SUCCESS,           // 成功
  UNKNOWN_COMMAND,   // 未知命令
  INVALID_ARGUMENTS, // 参数错误
  STORAGE_ERROR,     // 存储错误
  DUPLICATE_KEY,     // 主键冲突
  EXIT,
  INSERT,
  DELETE,
  GET,
  FINSHED,
};

enum class BlockType {
  BLOCK_TYPE_DATA,  // 数据块
  BLOCK_TYPE_INDEX, // 索引块
  BLOCK_TYPE_META,  // 元数据块
};
enum class BlockStatus {
  BLOCK_STATUS_first,  //
  BLOCK_STATUS_middle, //
  BLOCK_STATUS_last,   //
};
class MeteNumber {
public:
  static const int MAX_BLOCK_SIZE = 4096; // 块大小
  static const int MAX_BLOCK_COUNT = 100; // 块数量
};

// 统一的返回结果结构体
class CommandResult {
public:
  CommandStatus status; // 命令状态
  std::string message;  // 附加信息
};

void Promote();
void Prepare(std::string &input);
constexpr int MAX_LEVEL = 16;
constexpr int MAX_MEMTABLE_SIZE = 1024 * 1024;               // 1MB
constexpr int MAX_MEMTABLE_SIZE_PER_TABLE = 1024 * 1024 * 4; // 4MB
class MeteOperation {
public:
  MeteOperation() : cout(0) {
    db = std::make_shared<BPlusTree>("test.db");
  } // 初始化;
  void Put(std::string &key, std::string &value);
  void Delete(std::string &key);
  void Get(std::string &key);
  void Get_All();
  int cout;
  std::shared_ptr<BPlusTree> db;
};

} // namespace Global_
