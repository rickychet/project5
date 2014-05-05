#include <stdio.h>
#include "udp.h"
#include "mfs.h"

#define BUFFER_SIZE (4096)

int
main(int argc, char *argv[])
{
    int sd = UDP_Open(11614);
    assert(sd > -1);

    printf("                                SERVER:: waiting in loop\n");

    while (1) {
	struct sockaddr_in s;
	Package_t buffer;
	int rc = UDP_Read(sd, &s, &buffer, BUFFER_SIZE);
	if (rc > 0) {
	    printf("                                SERVER:: read %d bytes (message: '%s')\n", rc, buffer.name);
	    //Package_t reply;
	    strcpy(buffer.name, "Reply");
	    rc = UDP_Write(sd, &s, &buffer, BUFFER_SIZE);
	}
    }

    return 0;
}


