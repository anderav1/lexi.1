// addmsg function
// create a new data_t struct and insert it at the end of the log list
int addmsg(const time_t time, const char type, const char* msg) {
	// create a new data_t struct
	data_t msgstruct;
	msgstruct.time = time;
	msgstruct.type = type;
	msgstruct.string = msg;

	// insert the struct at the end of the log list
}
