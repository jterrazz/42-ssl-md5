> Hey there, app enthusiasts! 👋 Ready to dive into the world of game-changing apps? At [jterrazz.com](https://jterrazz.com), I'm all about crafting useful applications and sharing the journey! Discover coding insights, self-improvement hacks, and sneak peeks of my latest projects (psst... my next app is all about leveling up in life! 🚀). Come along for the ride - you might just find the spark for your next big idea! 💡💻

# ft_ssl - md5 & sha256

Custom C implementation of the OpenSSL Library, with the md5 and sha256 functions. Since both functions are relatively similar, most of the internal functions are created for a general usage.

Creates an executable `ft_ssl`.

## How does it work ?

[Please refer to the medium article of this projet here.](https://www.jterrazz.com/articles/2-sha-256-md5-in-c-complete-hashing-guide)

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

# command: md5, sha1, sha224, sha256, sha512, sha384
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
