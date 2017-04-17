#include "ent.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <random>


//px Probability of 1
double px[] = { 1.0000, 0.9991, 0.9980, 0.9969, 0.9957, 0.9944, 0.9930, 0.9916, 0.9901, 0.9886, //0.01 to 0.09
		0.9879, 0.9854, 0.9837, 0.9820, 0.9803, 0.9785, 0.9766, 0.9747, 0.9728, 0.9709,
		0.9689, 0.9668, 0.9648, 0.9627, 0.9605, 0.9583, 0.9561, 0.9538, 0.9515, 0.9491,
		0.9468, 0.9443, 0.9419, 0.9394, 0.9368, 0.9342, 0.9315, 0.9289, 0,9262, 0.9234,
		0.9206, 0.9177, 0.9149, 0.9119, 0.9089, 0.9059, 0.9028, 0.8997, 0.8965, 0.8933,
		0.8899, 0.8866, 0.8832, 0.8798, 0.8763, 0.8727, 0.8691, 0.8654, 0.8616, 0.8578,
		0.8539, 0.8499, 0.8459, 0.8418, 0.8376, 0.8333, 0.8290, 0.8246, 0.8200, 0.8154,
		0.8107, 0.8059, 0.8010, 0.7959, 0.7908, 0.7855, 0.7801, 0.7745, 0.7689, 0.7630,
		0.7570, 0.7508, 0.7444, 0.7378, 0.7310, 0.7239, 0.7166, 0.7090, 0.7010, 0.6927,
		0.6840, 0.6747, 0.6650, 0.6545, 0.6432, 0.6309, 0.6172, 0.6016, 0.5831, 0.5588, 0.5000
		};


int genData(char* fileName, double entropy) {
	
//	if(entropy <=0.98) entropy += 0.02; // balancing
	int ent = (int)(entropy*100);
	int pInt =(int)(px[ent]*10000);
	int idx = 0;
	char buf[BUFSIZE];
	FILE *fp;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,10000);

	if((fp = fopen(fileName, "w")) == NULL) {
		printf("'%s' open error\n", fileName);
		return -1;
	}

	memset(buf, 0, BUFSIZE);
	idx = 0;
	for(int i=0; i< BUFSIZE; i++) {
		char bit = 0x01;
		for(int j=0; j<8; j++) {
			int n =distribution(generator);
			if(n < pInt) {
				buf[idx] +=bit;
			}
			bit = bit<<1;
		}
		idx++;
	}
	fwrite(buf, 1, BUFSIZE, fp);
	fclose(fp);
	//	printf("make '%s', %.2fMiB\n", fileName, (double)BUFSIZE*NR_PAGE/(1024*1024));
	return 0;
}
