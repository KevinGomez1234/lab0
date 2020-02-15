static const char nonPrintables [34][6] = 
{
	"NUL  ", "SOH  ", "STX  ", "ETX  ", "EOT  ", "ENQ  ", "ACK  ", "BEL  ", 
	"BS   ", "HT   ", "LF   ", "VT   ", "FF   ", "CR   ", "SO   ", "SI   ", 
	"DLE  ", "DC1  ", "DC2  ", "DC3  ", "DC4  ", "NAK  ", "SYN  ", "ETB  ",
	"CAN  ", "EM   ", "SUB  ", "ESC  ", "FS   ", "GS   ", "RS   ", "US   ","SPACE","DEL  "
};
void logic(int argc, char* argv []);
void printInformation(int file_descriptor, int terminator);
void printArgsInformation(int argc, char* argv[]);
