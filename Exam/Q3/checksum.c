#include <stdio.h>
#include <stdbool.h>

struct Packet {
	short int opcode;
	int address;
	int info[10];
	short int checksum;
} ; 

typedef struct Packet packet;

bool checkPacket(packet *pkt) ;

int main () {
	packet goodpkt = {0x201F, 0xFF2E8801, {0x59472952, 0x17273828, 0xA3472B39, 0xC3822579, 0x39A081EB, 0x5732D967, 0xFEEDBEED, 0x213759CC, 0xEE32495E, 0x01839511}, 0xAF6D};
	packet badpkt = {0x201F, 0xFF2E8801, {0x59472952, 0x172F3828, 0xA3472B39, 0xC3822579, 0x39A081EB, 0x5732D967, 0xFEEDBEED, 0x213759CC, 0xEE32495E, 0x01839511}, 0xAF6D};
	
	if (checkPacket(&goodpkt)) {
		printf("Packet 1 is good!\n");
	} else {
		printf("Packet 1 is bad!\n");
	}
	
	if (checkPacket(&badpkt)) {
		printf("Packet 2 is good!\n");
	} else {
		printf("Packet 2 is bad!\n");
	}
}
