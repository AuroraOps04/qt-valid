#include "ssl.h"
#include "iostream"
#include "openssl/md5.h"
#include <fstream>
#include <string>

bool md5(const std::string &filepath, std::string &res) {
  std::ifstream file(filepath, std::ios::in | std::ios::binary);
  if (!file.good()) {
    file.close();
    return false;
  }
  MD5_CTX ctx;
  MD5_Init(&ctx);
  char buf[4096];
  while (!file.eof()) {
    file.read(buf, sizeof(buf));
    MD5_Update(&ctx, buf, file.gcount());
  }
  file.close();
  unsigned char *tmp = new unsigned char[16];
  MD5_Final(tmp, &ctx);
  std::cout << "size: " << sizeof(tmp) << std::endl;
  res = byteArrayToHexString(tmp);
  delete[] tmp;
  return true;
}

static const char kHex[] = "0123456789abcdef";
std::string byteArrayToHexString(const unsigned char *str) {
  std::string res;
  const unsigned char *head = str;
  for (int i = 0; i < 16; i++) {
    res += kHex[str[i] >> 4];
    res += kHex[str[i] & 0x0F];
  }
  return res;
}

Crypto::Crypto(EncType enctype) { this->setEncType(enctype); }

void Crypto::setEncType(EncType enctype) {
  this->_enctype = enctype;
  switch (this->_enctype) {
  case EncType::MD5:
    this->_enc_func = md5;
    break;
  case EncType::SHA1:
    break;
  default:
    break;
  }
}
bool Crypto::enc(const std::string &input, std::string &res) {
  if (this->_enc_func == nullptr) {
    return false;
  }
  return this->_enc_func(input, res);
}
Crypto::~Crypto() {}

int main(int argc, char *argv[]) {
  Crypto c(EncType::MD5);
  std::string str;
  std::cout << c.enc(argv[1], str) << std::endl
            << str << "\t" << str.size() << std::endl;

  return 0;
}
