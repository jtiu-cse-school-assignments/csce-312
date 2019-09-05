#include <stdio.h>
#include <sys/time.h>

int main() {

	FILE *my_file_pointer;
	if ( (my_file_pointer = fopen("lab1_prob2_out.txt", "w")) == NULL)
	{
		printf("Error opening the file, so exiting\n");
		exit(1);
	}
	
	unsigned int u_int;
	double doub;
	long lon;
	long long lon2;
	char charmander;
	float boat;
	struct timeval tim;
	double tim2;
	
	tim2 = tim.tv_sec;
	
	fprintf(my_file_pointer, "unsigned int data type is %d bytes or %d bits long\n",sizeof(u_int), sizeof(u_int)*8 );
	fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(doub), sizeof(doub)*8 );
	fprintf(my_file_pointer, "long data type is %d bytes or %d bits long\n",sizeof(lon), sizeof(lon)*8 );
	fprintf(my_file_pointer, "long long data type is %d bytes or %d bits long\n",sizeof(lon2), sizeof(lon2)*8 );
	fprintf(my_file_pointer, "char data type is %d bytes or %d bits long\n",sizeof(charmander), sizeof(charmander)*8 );
	fprintf(my_file_pointer, "float data type is %d bytes or %d bits long\n",sizeof(boat), sizeof(boat)*8 );
	fprintf(my_file_pointer, "struct timeval data type is %d bytes or %d bits long\n",sizeof(tim2), sizeof(tim2)*8 );
	
	fclose(my_file_pointer);

	return 0;
}