cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)

include(FindOpenSSL)
if (NOT OPENSSL_FOUND)
  message(FATAL_ERROR "openssl not found")
endif (NOT OPENSSL_FOUND)

find_file(OPENSSL_CMAC_HEADER openssl/cmac.h OPENSSL_INCLUDE_DIR)
if (NOT OPENSSL_CMAC_HEADER)
  message(FATAL_ERROR "${OPENSSL_INCLUDE_DIR}/openssl/cmac.h not found")
endif (NOT OPENSSL_CMAC_HEADER)

add_definitions(-Wall -Wextra -Werror -O2)
add_executable(cmac_example
  src/cmac_example.c)
target_link_libraries(cmac_example ${OPENSSL_LIBRARIES})
