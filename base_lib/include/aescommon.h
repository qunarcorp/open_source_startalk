#pragma once
#include <QString>

bool Aes_CbC_PKCS7_Encrypt(const QString&key, const QString&data, QString&base64encrypt);

bool Aes_CbC_PKCS7_Decrypt(const QString&key, const QString&base64encrypt, QString& dedata);

typedef unsigned char uint8_t;

class Aes256
{
public:
	Aes256(void);
	~Aes256();
public:
	void makeKey(const char *input, char *key);
	void AES_CBC_Encode_auto_bytes(uint8_t **output, int *outLen, const uint8_t *input, const int length, const char iv[32], const char key[32]);
	int AES_CBC_Encode_auto_bytes(const uint8_t *input, const int length, const char *password, uint8_t **bytesOutput);
	int AES_CBC_Encode(uint8_t *bytesOutput, const uint8_t *input, const int length, const char *password);
	void AES_CBC_Encode(const uint8_t *input, const int length, const char *password, char **base64Output);
	int AES_CBC_Decode_base64(char *output, const int inputLen, const char *input, const int length, const char *password);
	int AES_CBC_Encode_base64(char *base64Output, const int outlen, const uint8_t *input, const int length, const char *password);
	void AES_CBC_Decode(const char *base64Input, const int length, const char *password, char **output);
	int AES_CBC_Decode(char *output, const int inputLen, const uint8_t *input, const int length, const char *password);
	void AES_CBC_Decode(const uint8_t *input, const int length, const char *password, char **output);
	int AES_CBC_Decode_auto_bytes(const uint8_t *input, const int length, const char *password, char **output);
	void AES_CBC_Decode_auto_bytes(char **output, int *outLen, const uint8_t *input, const int length, const char iv[32], const char key[32]);
	int AES_CBC_Encode_base(uint8_t *output, const uint8_t *input, const int length, const char iv[32], const char key[32]);
	int AES_CBC_Decode_base(char *output, const uint8_t *input, const int length, const char iv[32], const char key[32]);
	int AES_CBC_Decode_bytes(char *output, const int inputLen, const uint8_t *input, const int length, const char *password);
};