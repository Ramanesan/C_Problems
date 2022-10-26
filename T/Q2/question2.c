#include <stdio.h>

long long unsigned int powertower(long long unsigned int x, long long unsigned int y, long long unsigned int z){
    int val = 0;
    if ((x==0) && (y==0)){
        return (z + 3);
    }
    else if (x == 0){
        return (powertower(x,y-1,z+y));
        
    }
    else{
        return (powertower(x-1,y+2*x,z+powertower(x-1,y-1,z-1)));
    }

}

int main() {
    printf("Expected: 1740066768. Returned: %llu\n", powertower(5, 30, 80));
    printf("Expected: 301097. Returned: %llu\n", powertower(4, 15, 33));
	printf("Expected: 2430658. Returned: %llu\n", powertower(4,50,44));
    return 0;
}
