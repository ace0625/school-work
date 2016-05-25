#include <inttypes.h>
#include <stdio.h>
 
inline uint32_t combine(uint32_t x, uint32_t y) {
  return (y & 0xffffff00) | (x & 0xff);
}
 
main() {
  printf("0x%" PRIx32 "\n", combine(0x89ABCDEF, 0x76543210));
  return 0;
}
