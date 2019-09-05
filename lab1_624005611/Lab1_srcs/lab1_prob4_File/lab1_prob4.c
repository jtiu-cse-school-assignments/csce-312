#include <stdio.h>
#include <math.h>

unsigned int sensor_inputs;
unsigned int actuator_outputs = 0b00000001;


void read_inputs_from_ip_if(){

	FILE* in = fopen("lab1_prob4_input.txt","r");
   
    fscanf (in, "%i", &sensor_inputs);

	fclose(in);
	
    int  binary_val, decimal_val = 0, base = 1, rem;

    binary_val = sensor_inputs;
    while (sensor_inputs > 0)
    {
        rem = sensor_inputs % 10;
        decimal_val = decimal_val + rem * base;
        sensor_inputs = sensor_inputs / 10 ;
        base = base * 2;
    }
    
    sensor_inputs = decimal_val;
	

}

void write_output_to_op_if(){

	int remainder; 
 	long binary = 0, i = 1;
  
    while(actuator_outputs != 0) {
        remainder = actuator_outputs%2;
        actuator_outputs = actuator_outputs/2;
        binary = binary + (remainder*i);
        i = i*10;
    }
    
    actuator_outputs = binary;
    
    FILE* out = fopen("lab1_prob4_output.txt", "w");
    
    if(out != NULL) {
		fprintf(out, "Actuator Output in binary: %i", actuator_outputs);
	}
    
    fclose(out);
}


void control_action(){
	
	if((sensor_inputs & 0b10000000)) {
		// set brakes bit = 1 with bit manipulation
		actuator_outputs = actuator_outputs | 0b00000100;
	} 
	
	if(sensor_inputs & 0b00100000) {
		// set DLA bit = 1 with bit manipulation
		actuator_outputs = actuator_outputs | 0b00000010;
	} 
	else if (sensor_inputs & 0b00100001) {
		// set DLA bit = 1 with bit manipulation
		actuator_outputs = actuator_outputs | 0b00000010;
	}
	else if (sensor_inputs & 0b00110001) {
		// set DLA bit = 1 with bit manipulation
		actuator_outputs = actuator_outputs | 0b00000010;
	}
	
	if((sensor_inputs & 0b00001110)) {
		// set bell bit = 0 with bit manipulation
		actuator_outputs = actuator_outputs ^ 0b00000001;
	}
	

}

/* ---     You should not have to modify anything below this line ---------*/

int main(int argc, char *argv[])
{
	
// 	The main control loop which keeps the system alive and responsive for ever, 
// 	until the system is powered off */
	for (;;)
	{
		read_inputs_from_ip_if();
		control_action();
		write_output_to_op_if();

	}
	
	return 0;
}
