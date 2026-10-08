echo "Produce PIR file for functions listed"
source ./vars.sh
mkdir -p logs

chkx results ast $BINARY --hide_globals -log WARNING --jlogfilename logs/error_log.json --hints $USERDATA -o pir_ast --functions $FNS_PENDING_ERRORS > generated_liftings_errors.txt
