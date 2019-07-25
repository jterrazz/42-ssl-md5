package test

import (
	"./shared"
	"fmt"
	"testing"
)

func TestSubjectCommands(t *testing.T) {
	t.Parallel()
	for i, test := range []struct {
		cmd, expected string
		isFailure bool
	}{
		{"../ft_ssl", "usage: ft_ssl command [command opts] [command args]\n", true},
		{"../ft_ssl foobar", "ft_ssl: Error: 'foobar' is an invalid command.\n\nStandard commands:\n\nMessage Digest commands:\nmd5\nsha224\nsha256\nsha384\nsha512\n\nCipher commands:\n", true},
		{"echo \"pickle rick\" | ../ft_ssl md5", "c5e433c1dbd7ba01e3763a9483e74b04\n", false},
		{"cd .. && echo \"Do not pity the dead, Harry.\" | ./ft_ssl md5 -p", "Do not pity the dead, Harry.\n2d95365bc44bf0a298e09a3ab7b34d2f\n", false},
		{"echo \"Pity the living.\" | ../ft_ssl md5 -q -r", "e20c3b973f63482a778f3fd1869b7f25\n", false},
	} {
		t.Run(fmt.Sprintf("%d", i), func(t *testing.T) {
			if test.isFailure {
				shared.ExecTestFailure(t, test.cmd, test.expected)
			} else {
				shared.ExecTestSuccess(t, test.cmd, test.expected)
			}
		})
	}
}

func TestSubjectCommandsWithFile(t *testing.T) {
	_, file_err := shared.ExecSafe(t, "echo \"And above all,\" > file")
	// TODO Secure
	shared.ExecSafe(t, "echo \"https://www.youtube.com/watch?v=w-5yAtMtrSM\" > big_smoke_order_remix")

	if file_err == nil {
		t.Parallel()
		for i, test := range []struct {
			cmd, expected string
		}{
			{"../ft_ssl md5 file", "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a\n"},
			{"../ft_ssl md5 -r file", "53d53ea94217b259c11a5a2d104ec58a file\n"},
			{"../ft_ssl md5 -s \"pity those that aren't following baerista on spotify.\"", "MD5 (\"pity those that aren't following baerista on spotify.\") = a3c990a1964705d9bf0e602f44572f5f\n"},
			{"echo \"be sure to handle edge cases carefully\" | ../ft_ssl md5 -p file", "be sure to handle edge cases carefully\n3553dc7dc5963b583c056d1b9fa3349c\nMD5 (file) = 53d53ea94217b259c11a5a2d104ec58a\n"},
			{"echo \"some of this will not make sense at first\" | ../ft_ssl md5 file", "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a\n"},
			{"echo \"but eventually you will understand\" | ../ft_ssl md5 -p -r file", "but eventually you will understand\ndcdd84e0f635694d2a943fa8d3905281\n53d53ea94217b259c11a5a2d104ec58a file\n"},
			{"echo \"GL HF let's go\" | ../ft_ssl md5 -p -s \"foo\" file", "GL HF let's go\nd1e3cc342b6da09480b27ec57ff243e2\nMD5 (\"foo\") = acbd18db4cc2f85cedef654fccc4a4d8\nMD5 (file) = 53d53ea94217b259c11a5a2d104ec58a\n"},
			{"echo \"one more thing\" | ../ft_ssl md5 -r -p -s \"foo\" file -s \"bar\"", "one more thing\na0bd1876c6f011dd50fae52827f445f5\nacbd18db4cc2f85cedef654fccc4a4d8 \"foo\"\n53d53ea94217b259c11a5a2d104ec58a file\nft_ssl: md5: -s: No such file or directory\nft_ssl: md5: bar: No such file or directory\n"},
			{"echo \"just to be extra clear\" | ../ft_ssl md5 -r -q -p -s \"foo\" file", "just to be extra clear\n3ba35f1ea0d170cb3b9a752e3360286c\nacbd18db4cc2f85cedef654fccc4a4d8\n53d53ea94217b259c11a5a2d104ec58a\n"},
			{"../ft_ssl sha256 -s \"wubba lubba dub dub\"", "SHA256 (\"wubba lubba dub dub\") = 23a0944d11b5a54f1970492b5265c732044ae824b7d5656acb193e7f0e51e5fa\n"},
			{"../ft_ssl sha256 -q big_smoke_order_remix", "a8dc621c3dcf18a8a2eddae1845e8e5f6498970a867056ac5f7121ac3d66cfd9\n"},
			{"../ft_ssl sha224 -s \"wubba lubba dub dub\"", "SHA224 (\"wubba lubba dub dub\") = 9153def540f0777ce66aebcd493327e1ab84e4d601631a53f7a25f36\n"},
			{"../ft_ssl sha224 -q big_smoke_order_remix", "abe47d133991621601248ca56b52cbef51090270d540f5fa8486a605\n"},
			{"../ft_ssl sha224 -q -s ''", "d14a028c2a3a2bc9476102bb288234c415a2b01f828ea62ac5b3e42f\n"},
			{"../ft_ssl sha384 -s \"wubba lubba dub dub\"", "SHA384 (\"wubba lubba dub dub\") = 2364751717f1ac5d6d022b75b63f7b42d19fbb487a090f98b7523fd5fd5dbc4a1f85d3ef8a1641502e7358541c23f0fd\n"},
			{"../ft_ssl sha384 -q big_smoke_order_remix", "e1393075706c91ac92f6cc0fbbfa381e8f0025f33c47337c7d2eac9da12f610b4f4e2b1a3866485f12314158f800c0ce\n"},
			{"../ft_ssl sha384 -q -s ''", "38b060a751ac96384cd9327eb1b1e36a21fdb71114be07434c0cc7bf63f6e1da274edebfe76f65fbd51ad2f14898b95b\n"},
			{"../ft_ssl sha1 -s \"wubba lubba dub dub\"", "SHA1 (\"wubba lubba dub dub\") = a8115d9daa64d89c37dbc4904e3a32811a6c9136\n"},
			{"../ft_ssl sha1 -q big_smoke_order_remix", "ebb7cc7975da3fd4f02fa901a32022925f239ed4\n"},
			{"../ft_ssl sha1 -q -s ''", "da39a3ee5e6b4b0d3255bfef95601890afd80709\n"},
			{"../ft_ssl sha512 -s \"wubba lubba dub dub\"", "SHA512 (\"wubba lubba dub dub\") = 15bdc800550f22c2eded20fb842783683f647c785595ce2da41d72a8fa6c4f3de23df1877ee443f49a881cc66b19a7dbd604772b223ecc36ce4990ba69d8a9e7\n"},
			{"../ft_ssl sha512 -q big_smoke_order_remix", "a2427fdfe745a82e36f8f95ddde1b951b442bd58e37371c43069c2041cbdc923e3b96a2831a37ad6ce580e75ea3ef9fb0c8528bfa9c62e6cccd36f8c8ca88036\n"},
			{"../ft_ssl sha512 -q -s ''", "cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e\n"},
		} {
			t.Run(fmt.Sprintf("%d", i), func(t *testing.T) {
				shared.ExecTestSuccess(t, test.cmd, test.expected)
			})
		}


		shared.ExecSafe(t, "rm file")
		shared.ExecSafe(t, "rm big_smoke_order_remix")
	}
}
