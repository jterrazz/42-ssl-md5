package shared

import (
	"flag"
)

var FlagM *t_bool

func InitFlags() {
	FlagM = flag.t_bool("m", false, "Will test for makefiles")
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
