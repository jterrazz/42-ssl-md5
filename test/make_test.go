package test

import (
	"./shared"
	"fmt"
	"testing"
)

// TODO Test if .o files are still here
func TestMake(t *testing.T) {
	if *shared.FlagM == false {
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
