# ft_ssl - md5 & sha256

Custom C implementation of the OpenSSL Library, with the md5 and sha256 functions. Since both functions are relatively similar, most of the internal functions are created for a general usage.

Creates an executable `ft_ssl`.

## How does it work ?

[Please refer to the medium article of this projet here.](https://medium.com/a-42-journey/implementing-the-sha256-and-md5-hash-functions-in-c-78c17e657794?postPublishedType=initial)

## Commands

### Build

```bash
make
make clean # Clean temporary built files
make fclean # Clean all built files
```

### Usage

``` bash
usage: ft_ssl command [command opts]

# command: md5, sha224, sha256, sha512, sha384
# command opts:
	# -p: echo STDIN to STDOUT and append the checksum to STDOUT
	# -q: quiet mode
	# -r: reverse the format of the output.
	# -s <string>: print the sum of the given string
```

### Testing

``` bash
sh test/test.sh
```
