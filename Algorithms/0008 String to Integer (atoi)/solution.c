#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int myAtoi(char* str) {
    
    long num = 0;
	int sign = 1,numcount = 0;
	
	// Check each character and calculate
	for(int i=0,signcount = 0,length = strlen(str), numhit = false,signhit = false;i<length && signcount < 2;i++)
		if(str[i] >= '0' && str[i] <= '9'){
			numhit = true;
			num = (10 * num + str[i] - '0');
			numcount++;
        }
		else if(str[i] == '+'){
			signcount++;
			signhit = true;
		}
		else if(str[i] == '-'){
			sign *= -1;
			signcount++;
			signhit = true;
		}
		else if(str[i] == ' '){
			if(numhit == true || signhit == true)
				break;
		}
		else break;
	
	// Check integer upperbound
	if(sign == 1 && numcount > 10 | num > INT_MAX)
	    return INT_MAX;
	    
	// Check integer lowerbound
	if(sign == -1 && numcount > 10 | num + INT_MIN > 0)
	    return INT_MIN;
	
	// Return integer
	return num * sign;
}