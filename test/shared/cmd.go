package shared

import (
	"os/exec"
	"strings"
	"testing"
	"github.com/andreyvit/diff"
)

func Exec(command string) (string, error) {
	cmd := exec.Command("bash", "-c", command)
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

// Replace the any md5 to ../ft_ssl !
func ExecTestCompare(t *testing.T, command string) {
	out, err := Exec(strings.Replace(command, "md5", "../ft_ssl md5", -1))
	off_out, off_err := Exec(command)

	if (off_err != nil || err != nil || strings.Compare(out, off_out) != 0) {
		t.Errorf("%s:\nOutput:\n\"%s\"\nWanted:\n\"%s\"", command, out, off_out)
		t.Errorf("diff\n%v", diff.LineDiff(off_out, out))
	}
}

// TODO More generic function
func ExecTestSuccess(t *testing.T, command, expected string) {
	out, err := Exec(command)

	if (err != nil || strings.Compare(out, expected) != 0) {
		t.Errorf("%s:\nOutput:\n\"%s\"\nWanted:\n\"%s\"", command, out, expected)
		t.Errorf("diff\n%v", diff.LineDiff(expected, out))
	}
}

func ExecTestFailure(t *testing.T, command, expected string) {
	out, err := Exec(command)

	if (err == nil || strings.Compare(out, expected) != 0) {
		t.Errorf("%s:\nOutput:\n\"%s\"\nWanted:\n\"%s\"", command, out, expected)
		t.Errorf("diff\n%v", diff.LineDiff(expected, out))
	}
}
