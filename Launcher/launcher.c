#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_LEN 1000000

int main(int argc, void *argv[]) {
	int i;
	FILE *fd;
	char sysfs_path[MAX_LEN];
	char str_debugging[MAX_LEN];
	char cmd_debugging[MAX_LEN];
	char app_cmd[MAX_LEN];
	char *iter;

	if ((argc < 4) || (strcmp(argv[1], "-ibsr"))) {
		printf("Usage> $%s -ibsr [list of IBSRs] [command] [arguments]\n", (char *) argv[0]);
		printf("Example> $%s -ibsr 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29 ./darknet detector demo cfg/coco.data cfg/yolov3-tiny.cfg yolov3-tiny.weights ~/Downloads/project_video.mp4\n", (char *) argv[0]);

		return -1;
	}

	// Get the file path to set IBSR
	sprintf(sysfs_path, "/proc/%d/ibsr", getpid());

	// Open the file
	fd = fopen(sysfs_path, "w+");
	if (fd == NULL) {
		printf("Error, file is not opened\n");
		return -1;
	}

	// Send the list of IBSR to the kernel
	fwrite(argv[2], 1, strlen((char *)argv[2]), fd);
	fclose(fd);

	// Read a command to run QoS application
	iter = &app_cmd[0];
	for (i = 3; i < argc; i++) {
		iter += sprintf(iter, "%s ", (char *)argv[i]);
	}

	// Run the command
	system(app_cmd);
	return 1;
}
