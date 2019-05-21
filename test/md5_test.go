package test

import (
	"./shared"
	"testing"
)

func TestSubject(t *testing.T) {
	make_out, make_err := cmd.ExecSafe(t, "make -C ..")

	t.Logf("%s", make_out)
	if (make_err == nil) {
		out, _ := cmd.ExecSafe(t, "../ft_ssl")
		t.Logf("%s", out)
	}
}
