echo "Test Description: Produce pir file for functions listed"
source ./vars.sh

chkx results ast $BINARY --hide_globals -log WARNING --hints $USERDATA -o pir_ast --functions $FNS_LIFTED > generated_liftings.txt
