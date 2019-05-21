package shared

import (
	"flag"
)

var FlagM *bool

func InitFlags() {
	FlagM = flag.Bool("m", false, "Will test for makefiles")
	flag.Parse()
}
