
// driver program
int main(int argc, char* argv[]) {
	char c;
	int sec;
	while ((c = getopt(argc, argv, "ht:")) != -1) {
		switch (c) {
		case 'h':
			// display help message

			// terminate
			exit(1);
		case 't':
			// assign time interval variable
			sec = atoi(optarg);
			break;
		default:
			break;
		}
	}	
}
