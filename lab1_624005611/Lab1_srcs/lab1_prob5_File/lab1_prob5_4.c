//CSCE 312: Lab-1 Problem-5 framework
// This is version-2; bugfix for timediff
/* ***   README   **** */
/*This file is a framework: i.e. there is no actual code whose execution time will be
measured. You need to populate the appropriate functions with the code that you wrote 
for the previous problems in order to get useful data. 

Turning in this file without your code will result in zero points being awarded for this problem.

run this file as: gcc FileName.c -o ExecutableName -lrt 

*/




#include <stdio.h>
#include <time.h>

// Macro definitions to ensure portablity between both sun.cs and linux.cs

#if defined(sun)
    #define CLOCKNAME CLOCK_HIGHRES
        
#else
    #define CLOCKNAME CLOCK_PROCESS_CPUTIME_ID
#endif

unsigned int sensor_inputs;
unsigned int actuator_outputs = 0b00000001;

inline void read_inputs_from_ip_if(){

	//place your input code here
	//to read the current state of the available sensors
	
	FILE* in = fopen("lab1_prob5_input4.txt","r");
   
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

inline void write_output_to_op_if(){

	//place your output code here
    //to display/print the state of the 3 actuators (DLA/BELL/BA)
    
    int remainder; 
 	long binary = 0, i = 1;
  
    while(actuator_outputs != 0) {
        remainder = actuator_outputs%2;
        actuator_outputs = actuator_outputs/2;
        binary = binary + (remainder*i);
        i = i*10;
    }
    
    actuator_outputs = binary;
    
    FILE* out = fopen("lab1_prob5_output4.txt", "w");
    
    if(out != NULL) {
		fprintf(out, "Actuator Output in binary: %i", actuator_outputs);
	}
    
    fclose(out);
	

}

//The code segment which implements the decision logic
inline void control_action(){

// Put your control/decision logic code segments inside this function
// This is the actual code whose execution time which is being measure
	
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

/*timespec diff from
http://www.guyrutenberg.com/2007/09/22/profiling-code-using-clock_gettime/
*/
struct timespec diff(struct timespec start, struct timespec end)
 {
    struct timespec temp;
    //the if condition handles time stamp end being smaller than than 
    //time stamp start which could lead to negative time.

     if ((end.tv_nsec-start.tv_nsec)<0) {
          temp.tv_sec = end.tv_sec-start.tv_sec-1;
          temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
      } else {
          temp.tv_sec = end.tv_sec-start.tv_sec;
          temp.tv_nsec = end.tv_nsec-start.tv_nsec;
      }
  return temp;
 }

int main(int argc, char *argv[])
{
	unsigned int cpu_mhz;
	unsigned long long int begin_time, end_time;
	struct timespec timeDiff,timeres;
    struct timespec time1, time2, calibrationTime;
	
    clock_gettime(CLOCKNAME, &time1);
	clock_gettime(CLOCKNAME, &time2);
	calibrationTime = diff(time1,time2); //calibration for overhead of the function calls
    clock_getres(CLOCKNAME, &timeres);  // get the clock resolution data
	
    read_inputs_from_ip_if(); // get the sensor inputs
	
	clock_gettime(CLOCKNAME, &time1); // get current time
	control_action();                 // process the sensors
	clock_gettime(CLOCKNAME, &time2);   // get current time

	write_output_to_op_if();    // output the values of the actuators
	
	timeDiff = diff(time1,time2); // compute the time difference

	printf("Timer Resolution = %u nanoseconds \n ",timeres.tv_nsec);
	printf("Calibrartion time = %u seconds and %u nanoseconds \n ", calibrationTime.tv_sec, calibrationTime.tv_nsec);
    printf("The measured code took %u seconds and ", timeDiff.tv_sec - calibrationTime.tv_sec);
	printf(" %u nano seconds to run \n", timeDiff.tv_nsec - calibrationTime.tv_nsec);
	
	return 0;
}
