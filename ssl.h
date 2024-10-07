#ifndef SSL_H
#define SSL_H
#include "iostream"

bool md5(const std::string &input, std::string &res);

std::string byteArrayToHexString(const unsigned char *str);

enum class EncType {
  MD5,
  SHA1,
};

class Crypto {
public:
  Crypto(EncType enctype);
  ~Crypto();
  void setEncType(EncType enctype);
  bool enc(const std::string &, std::string &);

private:
  EncType _enctype;
  bool (*_enc_func)(const std::string &, std::string &);
};

#endif // !SSL_H
