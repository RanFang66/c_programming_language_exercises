#include <stdio.h>

#define MAXHIST		30
#define MAXWORD		15
#define IN			1
#define OUT			0

void draw_hori_histogram(int wl[], int max_hist);
void draw_verti_histogram(int wl[], int max_hist);
int main(void)
{
	int c, i, nc, state;
	int len;
	int maxvalue;
	int ovflow;
	int wl[MAXWORD];
	
	state = OUT;
	nc = 0;
	ovflow = 0;
	for (i = 0; i < MAXWORD; i++) {
		wl[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (nc > 0) {
				if (nc < MAXWORD)
					++wl[nc];
				else
					++ovflow;
			}
			nc = 0;
		} else if (state == OUT) {
			state = IN;
			nc = 1;
		} else {
			nc++;
		}
	}
	printf("---- horizontal histogram ----\n");
	draw_hori_histogram(wl, MAXHIST);

	printf("---- vertical histogram ----\n");
	draw_verti_histogram(wl, MAXHIST);

	if (ovflow > 0)
		printf("There are %d words >= %d\n", ovflow, MAXWORD);
}

void draw_hori_histogram(int wl[], int max_hist)
{
	int maxvalue = 0;
	int i = 0;
	int len = 0;

	for (i = 1; i < MAXWORD; ++ i) {
		if (wl[i] > maxvalue) {
			maxvalue = wl[i];
		}
	}

	for (i = 1; i < MAXWORD; i++) {
		printf("%5d - %5d : ", i, wl[i]);
		if (wl[i] > 0) {
			if ((len = wl[i] * max_hist / maxvalue) <= 0) {
				len = 1;
			}
		} else {
			len = 0;
		}
		while (len > 0) {
			putchar('*');
			len--;
		}
		putchar('\n');
	}
}

void draw_verti_histogram(int wl[], int max_hist)
{
	int maxvalue = 0;
	int i = 0;
	int j = 0;
	int len = 0;

	for (i = 1; i < MAXWORD; ++ i) {
		if (wl[i] > maxvalue) {
			maxvalue = wl[i];
		}
	}

	for (i = max_hist; i > 0; --i) {
		for (j = 0; j < MAXWORD; ++j) {
			if (wl[j] * max_hist / maxvalue >= i)
				printf("  *  ");
			else
				printf("     ");
		}
		putchar('\n');
	}

	for (i = 1; i < MAXWORD; ++i)
		printf("%4d ", i);
	putchar('\n');
	for (i = 1; i < MAXWORD; ++i)
		printf("%4d ", wl[i]);
	putchar('\n');
}
