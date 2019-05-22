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
		{"../ft_ssl foobar", "ft_ssl: Error: 'foobar' is an invalid command.\n\nStandard commands:\n\nMessage Digest commands:\nmd5\nsha256\n\nCipher commands:\n", true},
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
		} {
			t.Run(fmt.Sprintf("%d", i), func(t *testing.T) {
				shared.ExecTestSuccess(t, test.cmd, test.expected)
			})
		}


		shared.ExecSafe(t, "rm file")
		shared.ExecSafe(t, "rm big_smoke_order_remix")
	}
}
