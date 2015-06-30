SCRIPT=`realpath $0`
SCRIPTPATH=`dirname $SCRIPT`

env GOROOT=$SCRIPTPATH/godist
env GOPATH=$SCRIPTPATH
env GOBIN=$SCRIPTPATH/bin

$SCRIPTPATH/bin/goxc -n=xmppctl -pv=0.1.0 -d=$SCRIPTPATH/release/ -goroot=$SCRIPTPATH/godist -tasks-=go-test -wd=$SCRIPTPATH/src/xmppctl -main-dirs-exclude=$SCRIPTPATH/src/github.com,$SCRIPTPATH/src/code.google.com -max-processors=2
