#include "../Include/global.h"
#include <algorithm>
#include <cctype>
#include <iostream>

void Global_::Promote() { std::cout << "DB:>" << std::endl; }

void Global_::Prepare(std::string &input) {
  input.erase(input.begin(),
              std::find_if(input.begin(), input.end(), [](int index) {
                return !std::isspace(index);
              })); // 处理command前的空格
  input.erase(std::find_if(input.rbegin(), input.rend(),
                           [](int index) { return !std::isspace(index); })
                  .base(),
              input.end()); // 处理command后的空格
}
void Global_::MeteOperation::Put(std::string &key, std::string &value) {
  db->Put(key, value);
  std::cout << "Put key: " << key << ", value: " << value << std::endl;
}
void Global_::MeteOperation::Delete(std::string &key) {
  cout++;
  std::cout << "Delete key: " << key << std::endl;
}
void Global_::MeteOperation::Get(std::string &key) {
  cout++;
  auto res = db->Get(key);
  if (res.has_value()) {
    std::cout << "Get key: " << key << ", value: " << res.value() << std::endl;
  } else {
    std::cout << "Key not found: " << key << std::endl;
  }
}
void Global_::MeteOperation::Get_All() {
  std::cout << "Get all data" << std::endl;
}