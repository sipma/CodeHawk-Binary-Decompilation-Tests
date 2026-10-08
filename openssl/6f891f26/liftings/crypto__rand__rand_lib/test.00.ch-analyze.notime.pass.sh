echo "Test Description: Analyze functions listed"
source ./vars.sh

cp $ORIGINAL_BINARY binary

chkx analyze --reset $BINARY --hints $USERDATA --headers $HEADERS --fns_include $FNS_INCLUDE --fail_on_function_failure
