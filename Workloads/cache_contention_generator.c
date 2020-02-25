#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>

/* 
 * MEM_INTENSITY is a tunable parameter
 * which means ratio of memory instructions to arithmetic instructions
 * MEM_INTENSITY == 1: the ratio is set to 1:15
 * MEM_INTENSITY == 2: the ratio is set to 1:10
 * MEM_INTENSITY == 3: the ratio is set to 1:5
 * MEM_INTENSITY == 4: the ratio is set to 1:1
 */
#define MEM_INTENSITY 4
#define ITERATION 1000

int main(int argc, char* argv[]) {
	int i, j, k;
	// Dynamic memory allocation
	double * m1 = malloc(sizeof(double)*1024*1024*16);//16*8MB
	memset(m1, 0, sizeof(double)*1024*1024*16);
	double * m2 = malloc(sizeof(double)*1024*1024*16);//16*8MB
	memset(m2, 1.2, sizeof(double)*1024*1024*16);

	for(k = 0; k < ITERATION; k++){
#pragma omp parallel for
		// Initialize registers
		__asm__ __volatile__("fmov d1, 1.0");
		__asm__ __volatile__("fmov d2, 2.0");
		__asm__ __volatile__("fmov d3, 2.0");
		__asm__ __volatile__("fmov d4, 2.0");
		__asm__ __volatile__("fmov d5, 2.0");
		__asm__ __volatile__("fmov d6, 2.0");
		__asm__ __volatile__("fmov d7, 2.0");
		__asm__ __volatile__("fmov d8, 2.0");
		__asm__ __volatile__("fmov d9, 2.0");
		__asm__ __volatile__("fmov d10, 2.0");
		__asm__ __volatile__("fmov d11, 2.0");
		__asm__ __volatile__("fmov d12, 2.0");
		__asm__ __volatile__("fmov d13, 2.0");
		__asm__ __volatile__("fmov d14, 2.0");
		__asm__ __volatile__("fmov d15, 2.0");
		__asm__ __volatile__("fmov d16, 2.0");
		__asm__ __volatile__("fmov d17, 2.0");
		__asm__ __volatile__("fmov d18, 2.0");
		__asm__ __volatile__("fmov d19, 2.0");
		__asm__ __volatile__("fmov d20, 2.0");
		__asm__ __volatile__("fmov d21, 2.0");
		__asm__ __volatile__("fmov d22, 2.0");
		__asm__ __volatile__("fmov d23, 2.0");
		__asm__ __volatile__("fmov d24, 2.0");
		__asm__ __volatile__("fmov d25, 2.0");
		__asm__ __volatile__("fmov d26, 2.0");
		__asm__ __volatile__("fmov d27, 2.0");
		__asm__ __volatile__("fmov d28, 2.0");
		__asm__ __volatile__("fmov d29, 2.0");
		__asm__ __volatile__("fmov d30, 2.0");
		__asm__ __volatile__("fmov d31, 2.0");

		__asm__ __volatile__("mov x1, 1");
		__asm__ __volatile__("mov x2, 2");
		__asm__ __volatile__("mov x3, 2");
		__asm__ __volatile__("mov x4, 2");
		__asm__ __volatile__("mov x5, 2");
		__asm__ __volatile__("mov x6, 2");
		__asm__ __volatile__("mov x7, 2");
		__asm__ __volatile__("mov x8, 2");
		__asm__ __volatile__("mov x9, 2");
		__asm__ __volatile__("mov x10, 2");
		__asm__ __volatile__("mov x11, 2");
		__asm__ __volatile__("mov x12, 2");
		__asm__ __volatile__("mov x13, 2");
		__asm__ __volatile__("mov x14, 2");
		__asm__ __volatile__("mov x15, 2");
		__asm__ __volatile__("mov x16, 2");
		__asm__ __volatile__("mov x17, 2");
		__asm__ __volatile__("mov x18, 2");
		__asm__ __volatile__("mov x19, 2");
		__asm__ __volatile__("mov x20, 2");
		__asm__ __volatile__("mov x21, 2");
		__asm__ __volatile__("mov x22, 2");
		__asm__ __volatile__("mov x23, 2");
		__asm__ __volatile__("mov x24, 2");
		__asm__ __volatile__("mov x25, 2");
		__asm__ __volatile__("mov x26, 2");
		__asm__ __volatile__("mov x27, 2");
		__asm__ __volatile__("mov x28, 2");

		for(i = 0; i < 1024*1024*16; i+=16) {
#if(MEM_INTENSITY==1)
			// Arithmetic instructions
			for (j = 0 ; j < 6; j++) {
				__asm__ __volatile__("fadd d1, d1, d1");
				__asm__ __volatile__("fadd d2, d2, d2");

				__asm__ __volatile__("fadd d3, d3, d3");
				__asm__ __volatile__("fadd d4, d4, d4");

				__asm__ __volatile__("fadd d5, d5, d5");
				__asm__ __volatile__("fadd d6, d6, d6");

				__asm__ __volatile__("fadd d7, d7, d7");
				__asm__ __volatile__("fadd d8, d8, d8");

				__asm__ __volatile__("fadd d9, d9, d9");
				__asm__ __volatile__("fadd d10, d10, d10");

				__asm__ __volatile__("fadd d11, d11, d11");
				__asm__ __volatile__("fadd d12, d12, d12");

				__asm__ __volatile__("fadd d13, d13, d13");
				__asm__ __volatile__("fadd d14, d14, d14");

				__asm__ __volatile__("fadd d15, d15, d15");
				__asm__ __volatile__("fadd d16, d16, d16");

				__asm__ __volatile__("fadd d17, d17, d17");
				__asm__ __volatile__("fadd d18, d18, d18");

				__asm__ __volatile__("fadd d19, d19, d19");
				__asm__ __volatile__("fadd d20, d20, d20");

				__asm__ __volatile__("fadd d21, d21, d21");
				__asm__ __volatile__("fadd d22, d22, d22");

				__asm__ __volatile__("fadd d23, d23, d23");
				__asm__ __volatile__("fadd d24, d24, d24");
			}
			// Memory instructions
			m1[i] = m2[i] + m2[i+8];
#elif(MEM_INTENSITY==2)
			// Arithmetic instructions
			for (j = 0 ; j < 4; j++) {
				__asm__ __volatile__("fadd d1, d1, d1");
				__asm__ __volatile__("fadd d2, d2, d2");

				__asm__ __volatile__("fadd d3, d3, d3");
				__asm__ __volatile__("fadd d4, d4, d4");

				__asm__ __volatile__("fadd d5, d5, d5");
				__asm__ __volatile__("fadd d6, d6, d6");

				__asm__ __volatile__("fadd d7, d7, d7");
				__asm__ __volatile__("fadd d8, d8, d8");

				__asm__ __volatile__("fadd d9, d9, d9");
				__asm__ __volatile__("fadd d10, d10, d10");

				__asm__ __volatile__("fadd d11, d11, d11");
				__asm__ __volatile__("fadd d12, d12, d12");

				__asm__ __volatile__("fadd d13, d13, d13");
				__asm__ __volatile__("fadd d14, d14, d14");

				__asm__ __volatile__("fadd d15, d15, d15");
				__asm__ __volatile__("fadd d16, d16, d16");

				__asm__ __volatile__("fadd d17, d17, d17");
				__asm__ __volatile__("fadd d18, d18, d18");

				__asm__ __volatile__("fadd d19, d19, d19");
				__asm__ __volatile__("fadd d20, d20, d20");

				__asm__ __volatile__("fadd d21, d21, d21");
				__asm__ __volatile__("fadd d22, d22, d22");

				__asm__ __volatile__("fadd d23, d23, d23");
				__asm__ __volatile__("fadd d24, d24, d24");
				__asm__ __volatile__("fadd d26, d26, d26");

				__asm__ __volatile__("fadd d27, d27, d27");
			}

			// Memory instructions
			m1[i] = m2[i] + m2[i+8];

#elif(MEM_INTENSITY==3)
			// Arithmtic instructions
			for (j = 0 ; j < 2; j++) {
				__asm__ __volatile__("fadd d1, d1, d1");
				__asm__ __volatile__("fadd d2, d2, d2");

				__asm__ __volatile__("fadd d3, d3, d3");
				__asm__ __volatile__("fadd d4, d4, d4");

				__asm__ __volatile__("fadd d5, d5, d5");
				__asm__ __volatile__("fadd d6, d6, d6");

				__asm__ __volatile__("fadd d7, d7, d7");
				__asm__ __volatile__("fadd d8, d8, d8");

				__asm__ __volatile__("fadd d9, d9, d9");
				__asm__ __volatile__("fadd d10, d10, d10");

				__asm__ __volatile__("fadd d11, d11, d11");
				__asm__ __volatile__("fadd d12, d12, d12");

				__asm__ __volatile__("fadd d13, d13, d13");
				__asm__ __volatile__("fadd d14, d14, d14");

				__asm__ __volatile__("fadd d15, d15, d15");
				__asm__ __volatile__("fadd d16, d16, d16");

				__asm__ __volatile__("fadd d17, d17, d17");
				__asm__ __volatile__("fadd d18, d18, d18");

				__asm__ __volatile__("fadd d19, d19, d19");
				__asm__ __volatile__("fadd d20, d20, d20");

				__asm__ __volatile__("fadd d21, d21, d21");
				__asm__ __volatile__("fadd d22, d22, d22");

				__asm__ __volatile__("fadd d23, d23, d23");
				__asm__ __volatile__("fadd d24, d24, d24");
				__asm__ __volatile__("fadd d25, d25, d25");
				__asm__ __volatile__("fadd d26, d26, d26");

				__asm__ __volatile__("fadd d27, d27, d27");
				__asm__ __volatile__("fadd d1, d1, d1");
				__asm__ __volatile__("fadd d2, d2, d2");

				__asm__ __volatile__("fadd d3, d3, d3");
				__asm__ __volatile__("fadd d4, d4, d4");

				__asm__ __volatile__("fadd d5, d5, d5");
				__asm__ __volatile__("fadd d6, d6, d6");

				__asm__ __volatile__("fadd d7, d7, d7");
				__asm__ __volatile__("fadd d8, d8, d8");

				__asm__ __volatile__("fadd d9, d9, d9");
				__asm__ __volatile__("fadd d10, d10, d10");

				__asm__ __volatile__("fadd d11, d11, d11");
				__asm__ __volatile__("fadd d12, d12, d12");

				__asm__ __volatile__("fadd d13, d13, d13");
				__asm__ __volatile__("fadd d14, d14, d14");

				__asm__ __volatile__("fadd d15, d15, d15");
				__asm__ __volatile__("fadd d16, d16, d16");

				__asm__ __volatile__("fadd d17, d17, d17");
				__asm__ __volatile__("fadd d18, d18, d18");

				__asm__ __volatile__("fadd d19, d19, d19");
				__asm__ __volatile__("fadd d20, d20, d20");

				__asm__ __volatile__("fadd d21, d21, d21");
				__asm__ __volatile__("fadd d22, d22, d22");

				__asm__ __volatile__("fadd d23, d23, d23");
				__asm__ __volatile__("fadd d24, d24, d24");
				__asm__ __volatile__("fadd d25, d25, d25");
				__asm__ __volatile__("fadd d26, d26, d26");

				__asm__ __volatile__("fadd d27, d27, d27");
			}
			// Memory instructions
			m1[i] = m2[i] + m2[i+8];

#elif(MEM_INTENSITY==4)
			// Memory instructions
			m1[i] = m2[i] + m2[i+8];
#else
#endif
		}
	}
	return 0;
}

