#include<string>
#include<iostream>
#include<stdio.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <boost/beast/core/detail/base64.hpp>

// OpenSSL 1.1.1

int main(){
    std::string key = "example key^&$&@%";
    std::string msg = "example msg";
    unsigned char hash[32];
    auto *hmac = HMAC_CTX_new();
    HMAC_Init_ex(hmac, &key[0], key.length(), EVP_sha256(), NULL);
    HMAC_Update(hmac, (unsigned char*)&msg[0], msg.length());
    unsigned int len = 32;
    HMAC_Final(hmac, hash, &len);
    HMAC_CTX_free(hmac);
    for(int i=0; i<len ;i++)
        printf("%d encode: %.2x %d\n", i, hash[i], (int)hash[i]);
    char b64_hash[64];
    boost::beast::detail::base64::encode(b64_hash, hash, len);
    std::cerr << "base64 hash:: " << b64_hash << std::endl;

    unsigned char origin_hash[64];
    boost::beast::detail::base64::decode(origin_hash, b64_hash, 64);
    for(int i=0; i<len ;i++)
        printf("%d encode: %.2x %d\n", i, origin_hash[i], (int)origin_hash[i]);
    std::cerr << "len: " << len << std::endl;
    std::cerr << "128: " << char(127) << std::endl;

}
