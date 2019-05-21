if ! type "go" > /dev/null; then
  echo "You need to install go";
  exit 1;
fi

# Install dependencies
if [ ! -d "$HOME/go/src/github.com/kyoh86/richgo" ]; then
    go get -u github.com/kyoh86/richgo;
fi
if [ ! -d "$HOME/go/src/github.com/andreyvit/diff" ]; then
    go get -u github.com/andreyvit/diff
fi

# Run tests
go run ~/go/src/github.com/kyoh86/richgo/main.go test -v
