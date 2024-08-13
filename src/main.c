
// int main2() {
// 	printf("Testing for possible incorrect use of arithmetic operato\n");
//
// 	printf("Initialising random Operators\n");
//     srand(time(NULL));
//     const Index rIndexes = { rand() % 3, rand() % 3, rand() % 3 };
//
//     printf("Test1: Confirm \"C=A-5\" with A=0 & B=1\n");
//     switch (test_me(&rIndexes, 0, 1)) {
// 		case -4:
// 			printf("Confirm it's not \"C=+5\".\n");
// 			break;
//
// 		case 5:
// 			printf("Test Fail: wrongfully implemented as \"C=A+5\".");
// 			break;
//
// 		default:
// 			break;
// 	}
//
//     printf("Test1: ");
//     switch (test_me(&rIndexes, 5, 0)) {
// 		case 12:
// 			break;
//
// 		default:
// 			break;
// 	}
//
//     return 0;
// }
#include <stdio.h>
#include <stdbool.h>

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
    // Get the operations based on indices
    Operation op1 = AllOperations[(*indx)[0]];
    Operation op2 = AllOperations[(*indx)[1]];
    Operation op3 = AllOperations[(*indx)[2]];

    int lA = op1(op2(A, B), B);
    return op3(lA, 5);
}

bool run(int A, int B) {
	int results[27];

	bool allUnique = true;
	int  copyCounter = 0;


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                Index rIndexes = {i, j, k};
                int C = test_me(&rIndexes, A, B);
				const int index = k+(j*3)+(i*9);

				for (int l = 0; l < index; l++) {
					if (results[l] == C) {
						allUnique = false;
						copyCounter++;
						// printf("*");
					}
				}
				results[index] = C;
            }
        }
    }

	if (copyCounter == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for(int k = 0; k < 3; k++) {
					const int index = k+(j*3)+(i*9);
					int C = results[index];

					printf("C = ((A %c B) %c B) %c 5 = %d\t",
						OpType[i], OpType[j], OpType[k], C
					);
				}
				printf("\n");
			}
		}

		// printf("Unique Values = %s\n", allUnique ? "true" : "false");
		printf("A = %d. Non-unique values: %d\n---\n", A, copyCounter);
	}

	return allUnique;
}

int main() {
	int uniqueCounter = 0;
	int uniqueA[200];

	for (int A = -100; A < 101; A++) {
		if (run(A, 2)) {
			uniqueA[++uniqueCounter] = A;
		}
	}

	printf("---\nunique counter = %d\n", uniqueCounter);

	for (int i = 0; i < uniqueCounter; i++) {
		printf("A is not valid for %d\n", uniqueA[i]);
	}

	return 0;
}
