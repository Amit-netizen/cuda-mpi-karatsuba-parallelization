#include <stdio.h>
#include <math.h>
#include <time.h>

// Function to calculate the number of digits in a number
int numDigits(long long n) {
	int count = 0;
	while (n != 0) {
		n /= 10;
		count++;
	}
	return count;
}

// Karatsuba multiplication function

int main() {
	long long x;
	long long y;
	unsigned long long C[100000];

	FILE *file1 = fopen("X_100000.txt", "r");
	if (file1 == NULL) {
        printf("Failed to open the file for reading.\n");
        return 1;
    }
    long long A[100000];
    int num_elements_A = 0;

    // Read integers from the file and store them in an array
    while (fscanf(file1, "%lld", &A[num_elements_A]) != EOF) {
        num_elements_A++;
    }

    int num_of_elements = num_elements_A;

    FILE *file2 = fopen("Y_100000.txt", "r");
	if (file2 == NULL) {
        printf("Failed to open the file for reading.\n");
        return 1;
    }
    long long B[100000];
    int num_elements_B = 0;

    // Read integers from the file and store them in an array
    while (fscanf(file2, "%lld", &B[num_elements_B]) != EOF) {
        num_elements_B++;
    }

    clock_t start_time = clock();

    for(int i=0; i<num_of_elements; i++){
    	x=A[i];
    	y=B[i];
		
		if (x < 10 || y < 10) {
			C[i] = x * y;
		}else{
			// Calculate the number of digits in the two numbers and divide by 2
			int n = fmax(numDigits(x), numDigits(y));
			int n2 = (n / 2);

			// Split the numbers into two parts

			long long x_h = x / (long long)pow(10, n2);
			long long x_l = x % (long long)pow(10, n2);
			long long y_h = y / (long long)pow(10, n2);
			long long y_l = y % (long long)pow(10, n2);

			// Recursively calculate the three products
			long long high_prod = x_h * y_h;
			long long low_prod = x_l * y_l;
			long long inter_prod = ((x_h + x_l) * (y_h + y_l));
			long long subtract = inter_prod - high_prod - low_prod;

			// Calculate and return the final result
			C[i] = (high_prod * (long long)pow(10, 2 * n2)) + (subtract * (long long)pow(10, n2)) + low_prod;
		}
	}

	clock_t end_time = clock();

	FILE *file3 = fopen("seqproduct_100000.txt", "w");
    if (file3 == NULL) {
        printf("Failed to open the file for writing.\n");
        return 1;
    }
    for (int i = 0; i < num_of_elements; i++) {
        fprintf(file3, "%llu\n", C[i]);
    }
    printf("Product values are available in file seqproduct_100000.txt\n");
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;
	printf("Execution Time: %.6f Milli seconds\n", elapsed_time);
	fclose(file1);
	fclose(file2);
	fclose(file3);
	return 0;
}


//Maximum product we can get is 0 to 18,446,744,073,709,551,615 for unsigned long long integer
//Max:9999999999*999999999