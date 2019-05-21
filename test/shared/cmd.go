package cmd

import (
	"os/exec"
	"strings"
	"testing"
)

func Exec(command string) (string, error) {
	args := strings.Split(command, " ")
	cmd := exec.Command(args[0], args[1:]...)
	out, err := cmd.CombinedOutput()

	return string(out), err
}

func ExecSafe(t *testing.T, command string) (string, error) {
	out, err := Exec(command)
	if (err != nil) {
		t.Errorf("%s", out)
	}
	return out, err
}
