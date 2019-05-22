package test

import (
	"./shared"
	"fmt"
	"os"
	"testing"
)

// Parcourir toutes les erreurs et les ajouter ici
// Adapt function to add ft_ssl: before
// Good but
// "md5 -",
// "md5 -s",
// "md5 shared",
// "md5 - y",
// "md5 -j",

// Not the same result but its exepected
// "md5 -s \"do\" -dd -s \"do\"  Makef",
// "md5 -s \"do\" -d Makefile",
// "md5 -s yo -s ww -r -s 22",
// "md5 -s yo -r",
// "md5 -s -r -rs -r",
func TestCustomCommandsWithFile(t *testing.T) {
	commands := []string{
		"md5 -s \"yo\"",
		"md5 -s \"\"",
		"echo \"\" | md5",
		"echo \"\" | md5 -p",
		"echo \"yoo\nwwwwww\n\" | md5 -p",
		"md5 ex_empty",
		"echo \"1223456\" | md5",
	}

	shared.ExecSafe(t, "touch ex_empty")

	// Secure that
	str := shared.RandomString(25000)
	f, _ := os.Create("ex_big")
	f.WriteString(str)

	t.Parallel()

	for i, test := range commands {
		t.Run(fmt.Sprintf("%d", i), func(t *testing.T) {
			shared.ExecTestCompare(t, test)
		})
	}

	shared.ExecSafe(t, "rm ex_big ex_empty")
}
