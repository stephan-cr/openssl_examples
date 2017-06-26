cmake_minimum_required(VERSION 3.0.2)

include(CheckSymbolExists)

find_package(OpenSSL 1.0.1 REQUIRED)

find_file(OPENSSL_CMAC_HEADER openssl/cmac.h OPENSSL_INCLUDE_DIR)
if (NOT OPENSSL_CMAC_HEADER)
  message(FATAL_ERROR "${OPENSSL_INCLUDE_DIR}/openssl/cmac.h not found")
endif (NOT OPENSSL_CMAC_HEADER)

add_definitions(-Wall -Wextra -Werror -O2)
add_executable(aes_example
  src/aes_example.c)
target_link_libraries(aes_example ${OPENSSL_LIBRARIES})

set(CMAKE_REQUIRED_INCLUDES "${OPENSSL_INCLUDE_DIR}")
set(CMAKE_REQUIRED_LIBRARIES "${OPENSSL_LIBRARIES}")

check_symbol_exists("EVP_aes_128_gcm" "openssl/evp.h"
  EVP_AES_128_GCM_PROTOTYPE)
if (EVP_AES_128_GCM_PROTOTYPE)
  add_executable(aes_gcm_example
    src/aes_gcm_example.c)
  target_link_libraries(aes_gcm_example ${OPENSSL_LIBRARIES})
else (EVP_AES_128_GCM_PROTOTYPE)
  message(FATAL_ERROR "EVP_aes_128_gcm prototype does not exist")
endif (EVP_AES_128_GCM_PROTOTYPE)

add_executable(cmac_example
  src/cmac_example.c)
target_link_libraries(cmac_example ${OPENSSL_LIBRARIES})
