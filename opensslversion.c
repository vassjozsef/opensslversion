// OSX:  clang opensslversion.c -I /usr/local/opt/openssl/include -L /usr/local/opt/openssl/lib -lssl -lcrypto
// OSX uses brewed openssl
// Linux: clang-7 opensslversion.c -lssl -lcrypto
#include <openssl/ssl.h>
#include <openssl/hmac.h>
#include <openssl/sha.h>

int main(void) {

  printf("OpenSSL version: 0x%lx\n", OPENSSL_VERSION_NUMBER);
  printf("OpenSSL version: %s\n", OPENSSL_VERSION_TEXT);

#if OPENSSL_VERSION_NUMBER < 0x10100000L
  SSL_library_init();
#else
  OPENSSL_init_ssl(0, NULL);
#endif

#if OPENSSL_VERSION_NUMBER < 0x10100000L
  HMAC_CTX stackctx;
  HMAC_CTX *ctx = &stackctx;
  HMAC_CTX_init (ctx);
#else
  HMAC_CTX *ctx = HMAC_CTX_new ();
#endif /* OPENSSL_VERSION_NUMBER */

  return 0;
}
