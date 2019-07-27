package shared

import (
	"flag"
)

var FlagM *bool

func InitFlags() {
	FlagM = flag.Bool("m", false, "Will test for makefiles")
	flag.Parse()
}

// var gopherType string
//
// func init() {
//     const (
//         defaultGopher = "pocket"
//         usage         = "the variety of gopher"
//     )
//     flag.StringVar(&gopherType, "gopher_type", defaultGopher, usage)
//     flag.StringVar(&gopherType, "g", defaultGopher, usage+" (shorthand)")
// }
