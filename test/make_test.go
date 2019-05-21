package test

import (
	"./shared"
	"flag"
	"fmt"
	"testing"
)

// TODO Test if .o files are still here
func TestMake(t *testing.T) {
	test_make := flag.Bool("m", false, "Will test for makefiles")

	if *test_make == false {
		t.Skip("Skip")
	}
	for i, test := range []struct {
		cmd string
	}{
		{"make re -C .."},
		{"make clean -C .."},
		{"make fclean -C .."},
		{"make -C .."},
	} {
		t.Run(fmt.Sprintf("%d", i), func(t *testing.T) {
			shared.ExecSafe(t, test.cmd)
		})
	}

}
