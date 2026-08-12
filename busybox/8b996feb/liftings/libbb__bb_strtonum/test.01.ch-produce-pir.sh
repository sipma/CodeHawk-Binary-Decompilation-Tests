echo "Produce PIR file for functions listed"
source ./vars.sh

chkx results ast $BINARY --hide_globals -log WARNING --hints $USERDATA -o pir_ast --functions $FNS_AST > generated_liftings.txt
