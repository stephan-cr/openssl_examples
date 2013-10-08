/*
 * OpenSSL AES-128 in GCM (galios counter mode)
 * the example data is taken from:
 *
 * D. McGrew, J. Viega, The Galois/Counter Mode of Operation (GCM),
 * Natl. Inst. Stand. Technol.
 *
 * http://www.csrc.nist.gov/groups/ST/toolkit/BCM/documents/
 * proposedmodes/gcm/gcm-revised-spec.pdf
 */

#include <stdio.h>

#include <openssl/aes.h>
#include <openssl/evp.h>

static EVP_CIPHER_CTX ctx;

static const unsigned char key[AES_BLOCK_SIZE] =
  "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";
static const unsigned char plain[] =
  "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";
static const unsigned char iv[] =
  "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";
static unsigned char cipher[AES_BLOCK_SIZE];

int main(void)
{
  int out_length;
  unsigned char garbage[AES_BLOCK_SIZE];

  EVP_EncryptInit(&ctx, EVP_aes_128_gcm(), key, iv);
  EVP_EncryptUpdate(&ctx, cipher, &out_length, plain, sizeof(plain));
  EVP_EncryptFinal(&ctx, garbage, &out_length);

  EVP_CIPHER_CTX_cleanup(&ctx);

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
