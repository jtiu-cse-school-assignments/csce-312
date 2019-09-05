// CSCE312: Lab-1 Problem-3 framework

/* ***   README   **** */

/*
This example program sounds the bell when driver is on seat 
AND haven't closed the doors. Use the general framework and the function 
shells, replace the code inside  the control_action() function with your 
own code to do problems 3 and 4.

Note: This code is designed to run in an infinite loop to mimic a real control system. 
If you prefer to read the inputs from a file, modify the code appropriately to terminate the
loop when all the inputs have been processed.

Turning in this file without your code will result in zero points being awarded for this problem.

run this file as : gcc filename.c -o executableName

*/


#include <stdio.h> //This is useful to do i/o to test the code 

unsigned int driver_on_seat;
unsigned int doors_closed;
unsigned int bell;

unsigned int driver_seat_belt_fastened;
unsigned int engine_running;

unsigned int key_in_car;
unsigned int door_lock_actuator;

unsigned int brake_pedal;
unsigned int car_moving;
unsigned int brake_actuator;


void read_inputs_from_ip_if(){

	//place your input code here
	//to read the current state of the available sensors
	
	FILE* in = fopen("lab1_prob3_input.txt","r");

// 	if(in != NULL) {
//       char line [ 128 ];
//       while ( fgets ( line, sizeof line, in ) != NULL )
//       {
//       
//       	fscanf (in, "%i %i %i %i %i %i %i", &engine_running, &driver_seat_belt_fastened, &doors_closed, &driver_on_seat, &key_in_car, &brake_pedal, &car_moving);
// //       	 fscanf(in, "%i", &engine_running);
// //          fscanf(in, "%i", &driver_seat_belt_fastened);
// //          fscanf(in, "%i", &doors_closed);
// //          fscanf(in, "%i", &driver_on_seat);
// //          fscanf(in, "%i", &key_in_car);
// //          fscanf(in, "%i", &brake_pedal);
// //          fscanf(in, "%i", &car_moving);
//       }
//    }
   
   fscanf (in, "%i %i %i %i %i %i %i", &engine_running, &driver_seat_belt_fastened, &doors_closed, &driver_on_seat, &key_in_car, &brake_pedal, &car_moving);
	
	
	fclose(in);
	

}

void write_output_to_op_if(){

	//place your output code here
    //to display/print the state of the 3 actuators (DLA/BELL/BA)
    
    FILE* out = fopen("lab1_prob3_output.txt", "w");
    
    if(out != NULL) {
		fprintf(out, "*** ACTUATOR STATUS ***");
		fprintf(out, "\nBell = %i\nDoor Locked = %i\nBrake = %i", bell, door_lock_actuator, brake_actuator);
		fprintf(out, "\n\nengine_running = %i\ndriver_seat_belt_fastened = %i\ndoor_closed = %i \ndriver_on_seat = %i\nkey_in_car = %i \nbrake_pedal = %i \ncar_moving = %i", engine_running, driver_seat_belt_fastened, doors_closed, driver_on_seat, key_in_car, brake_pedal, car_moving);
	} else {
		printf("Could not open output file.");
	}
    
    fclose(out);
}


//The code segment which implements the decision logic
void control_action(){

	/*
	The code given here sounds the bell when driver is on seat 
	AND hasn't closed the doors. (Requirement-2)
 	Replace this code segment with your own code to do problems 3 and 4.

	if (driver_on_seat && !doors_closed)
		bell = 1;
	else bell = 0;
	
	*/
	
	//printf("Actuators Status: ");
	
	// conditional regarding bell actuator 
	if(engine_running == 1 && !driver_seat_belt_fastened == 1 && !doors_closed == 1) {
		bell = 1;
		//printf("Bell = 1");
	} else if (engine_running == 1 && !doors_closed == 1 && driver_seat_belt_fastened == 1) {
		bell = 1;
		//printf("Bell = 1");
	} else if (engine_running == 1 && doors_closed == 1 && !driver_seat_belt_fastened == 1) {
		bell = 1;
		//printf("Bell = 1");
	} else if (engine_running == 1 && !doors_closed == 1 && !driver_seat_belt_fastened == 1) {
		bell = 1;
		//printf("Bell = 1");
	} else if ((engine_running == 1 && driver_seat_belt_fastened == 1) && (engine_running == 1 && doors_closed == 1) ) {
		bell = 0;
		//printf("Bell = 0");
	} else {
		bell = 0;
		//printf("Bell = 0");
	}
	
	// conditional regarding door locked actuator
	if(!driver_on_seat == 1 && key_in_car == 1) {
		door_lock_actuator = 0;
		//printf(" Doors locked = 0");
	} else {
		door_lock_actuator = 1;
		//printf(" Doors locked = 1");
	}
	
	// conditional regarding brake actuator
	if(brake_pedal == 1 && car_moving == 1) {
		brake_actuator = 1;
		printf(" Brakes = 1");
	} else {
		brake_actuator = 0;	
		//printf(" Brakes = 0");
	}
	
// 	printf("\nEngine Running: %i", engine_running);
// 	printf("\nDriver Seat Belt fastened: %i", driver_seat_belt_fastened);
// 	printf("\nDoor closed: %i", doors_closed);
// 	printf("\nDriver on seat: %i", driver_on_seat);
// 	printf("\nkey in car: %i", key_in_car);
// 	printf("\nbrake_pedal: %i", brake_pedal);
// 	printf("\ncar moving: %i", car_moving);
	

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
	
// 		read_inputs_from_ip_if();
// 		control_action();
// 		write_output_to_op_if();
	
	return 0;
}
