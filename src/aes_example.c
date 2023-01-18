/*
 * OpenSSL AES-128 in ECB mode example
 *
 * the example data is taken from:
 *
 * "Announcing the ADVANCED ENCRYPTION STANDARD (AES)". Federal
 * Information Processing Standards Publication 197. United States
 * National Institute of Standards and Technology (NIST). November 26,
 * 2001. Retrieved October 2, 2012.
 *
 * http://csrc.nist.gov/publications/fips/fips197/fips-197.pdf
 */

#include <stdio.h>

#include "openssl/aes.h"
#include "openssl/evp.h"

static const unsigned char key[AES_BLOCK_SIZE] =
  "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f";
static const unsigned char plain[AES_BLOCK_SIZE] =
  "\x00\x11\x22\x33\x44\x55\x66\x77\x88\x99\xaa\xbb\xcc\xdd\xee\xff";
static unsigned char cipher[AES_BLOCK_SIZE];

int main(void)
{
  int out_length;
  unsigned char garbage[AES_BLOCK_SIZE];

  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

  EVP_EncryptInit(ctx, EVP_aes_128_ecb(), key, NULL);
  EVP_EncryptUpdate(ctx, cipher, &out_length, plain, sizeof(plain));
  EVP_EncryptFinal(ctx, garbage, &out_length);

  EVP_CIPHER_CTX_cleanup(ctx);
  EVP_CIPHER_CTX_free(ctx);

  printf("expected: 69c4e0d8 6a7b0430 d8cdb780 70b4c55a\n"
         "got:      ");
  size_t index;
  for (index = 0; index < sizeof(cipher) - 1; ++index) {
    printf("%02x", cipher[index]);
    if ((index + 1) % 4 == 0) {
      printf(" ");
    }
  }
  printf("%02x\n", cipher[sizeof(cipher) - 1]);

  return 0;
}
