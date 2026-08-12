echo "Analyze functions listed"
source ./vars.sh

cp $ORIGINAL_BINARY $BINARY

chkx analyze --reset $BINARY --hints $USERDATA --headers $HEADERS --fns_include $FNS_INCLUDE --fail_on_function_failure --construct_all_functions
