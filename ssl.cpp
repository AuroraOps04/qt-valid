#include "iostream"
#include "ssl.h"
#include "openssl/md5.h"
#include <cstring>
#include <sstream>
using namespace std;

unsigned char * md5(const string& input){
  MD5_CTX ctx;
  MD5_Init(&ctx);
  
  MD5_Update(&ctx, input.c_str(), input.size());
  unsigned char * res = new unsigned char[16];
  MD5_Final(res, &ctx);
  return res;
}

static const char kHex[] = "0123456789abcdef";
std::string byteArrayToHexString(const unsigned char * str){
  std::string res;
  const unsigned char * head = str;
  while(*head != '\0'){
    res += kHex[*head >> 4]; 
    res += kHex[*head & 0x0F];
    head++;
  }
  return res;
}

