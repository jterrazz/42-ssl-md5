Maths.h
Custom implementations of:
Pow using a O(log n) time complexity

Why initialize to the start
https://crypto.stackexchange.com/questions/10829/why-initialize-sha1-with-specific-buffer

## MD5
// Explainations: a chunk is 64 bits or 512 bits // A chunk is a 512 bits part
// of the buffer;
// https://crypto.stackexchange.com/questions/10829/why-initialize-sha1-with-specific-buffer
// Append 1 bit to the message + length so its 4 bits (int) + 4 bits (int)
// Test and compare with length from 0 to 512 + try sending empty files
// Take the wikipedia algorythm to explain
// MD5 uses a buffer that is made up of four words that are each 32 bits long =>
// 4 bytes => int

Current issues
// Choose a -ssssss string comportment
// make && ./a.out md5 -s arg1 -sss arg2 -s arg3

Testing
``` bash
sh test/test.sh
```

stdint.h
For int8_t
uint8_t
etc
