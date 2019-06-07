# ft_ssl - md5 & sha256

Custom C implementation of the OpenSSL Library, with the md5 and sha256 functions. Since both functions are relatively similar, most of the internal functions are created for a general usage.

Creates the executable `ft_ssl`.

[You can access here the medium article of this project.](https://medium.com/a-42-journey/implementing-the-sha256-and-md5-hash-functions-in-c-78c17e657794?postPublishedType=initial)

## Commands

### Build

```bash
make
make clean # Clean temporary built files
make fclean # Clean all built files
```

### Usage

``` bash
usage: ft_ssl command [command opts] [command args]

# command opts:
# md5
# sha256
```

### Testing

``` bash
sh test/test.sh
```
