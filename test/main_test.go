package test

import (
	"./shared"
	"testing"
	"os"
	"fmt"
)

// Add sha256 support
func TestMain(m *testing.M) {
	shared.InitFlags()

	out, err := shared.Exec("make -C ..")

	if (err == nil) {
		os.Exit(m.Run())
	} else {
		fmt.Printf("%s", out)
	}
}
