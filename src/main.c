
#include <stdio.h>

// Function definitions
int add(int num1, int num2)      { return num1 + num2; }
int subtract(int num1, int num2) { return num1 - num2; }
int multiply(int num1, int num2) { return num1 * num2; }

typedef int Index[3];
typedef int (*Operation)(int, int);
Operation AllOperations[] = { add, subtract, multiply };
char OpType[] = { '+', '-', '*' };

// Function to test operations
int test_me(const Index* indx, int A, int B) {
    Operation op1 = AllOperations[(*indx)[0]];
    Operation op2 = AllOperations[(*indx)[1]];
    Operation op3 = AllOperations[(*indx)[2]];

    int lA = op1(op2(A, B), B);
    return op3(lA, 5);
}

void run(int A, int B) {
	int result[27];

	int copyCounter = 0;
	int sameAsResult = 0;
	
    Index rIndexes = {0, 2, 1};
	const int cResult = test_me(&rIndexes, A, B);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
				if (i == 0 && j == 2 && k == 1) {
					printf("^C = ((A + B) * B) - 5 = %-8d", cResult);
					continue;
				}

				const int index = k + (j*3) + (i*9);

				rIndexes[0] = i, rIndexes[1] = j, rIndexes[2] = k;
                int C = test_me(&rIndexes, A, B);

				printf(" C = ((A %c B) %c B) %c 5 = %-8d",
					OpType[i], OpType[j], OpType[k], C
				);

				for (int l = 0; l < index; l++) {
					if (result[l] == C) {
						copyCounter++;
					}
				}

				if (cResult == C) {
					sameAsResult++;
				}

				result[index] = C;
            }
			printf("\n");
        }
    }

	printf("Testing for A = %-8d & B = %-8d | ", A, B);
	printf("%-2d same values as result. | ", sameAsResult);
	printf("%-2d repeated values.\n", copyCounter);
}

int main() {
	for (int A = -1000; A < 1001; A++)
		// for (int B = -1000; B < 1001; B++)
			run(A, 2);

	
	return 0;
}

