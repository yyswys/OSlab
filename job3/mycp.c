#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#define maxsize 65536

void panic(char *message) {
	perror(message);
	exit(EXIT_FAILURE);
}
int main(int argc,char *argv[]) {
	char *src = argv[1];
	char *dst = argv[2];
	char buffer[maxsize];

	int fd = open(src,O_RDONLY);
	if(fd < 0)	
		panic("open");

	int count = read(fd,buffer,sizeof(buffer));
	if(count < 0)	
		panic("read");

	close(fd);

	int fd_cp = open(dst,O_CREAT|O_WRONLY|O_TRUNC);
	if(fd_cp < 0)
		panic("open");

	int count_cp = write(fd_cp,buffer,count);
	if(count_cp < 0)
		panic("write");
	close(fd_cp);
	
	return 0;
}
