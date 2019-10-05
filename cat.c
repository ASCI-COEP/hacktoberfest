/* Unix cat simple implementation */
#include <stdio.h>

int main(int argc, char* argv[]){
	register FILE *inputFile = NULL;
	register char symbol;

	while (--argc > 0) {
        ++argv;
		if ((inputFile = fopen(*argv, "r")) == NULL) {
			fprintf(stderr, "can't open %s\n", *argv);
			continue;
		}
		while ((symbol = getc(inputFile)) != EOF) {
			putchar(symbol);
        }
        fclose(inputFile);
	}
	return 0;
}
