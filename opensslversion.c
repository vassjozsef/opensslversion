// OSX:  clang opensslversion.c -I /usr/local/opt/openssl/include -L /usr/local/opt/openssl/lib -lssl
// OSX uses brewed openssl
#include "openssl/ssl.h"

int main(void) {
  
  printf("OpenSSL version: 0x%lx\n", OPENSSL_VERSION_NUMBER);
  printf("OpenSSL version: %s\n", OPENSSL_VERSION_TEXT);

#if OPENSSL_VERSION_NUMBER < 0x10100000L
    SSL_library_init();
#else
    OPENSSL_init_ssl(0, NULL);
#endif

  return 0;
}
