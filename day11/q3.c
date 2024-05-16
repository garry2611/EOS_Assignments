#include <stdio.h>
#include <signal.h>
#include <unistd.h>

	char ch = 'a';
	int arr[2], ret , s ;
	int count = 0;

void sigint_handler(int sig) {
	close(arr[1]);
	close(arr[0]);
	_exit(0);
	}

int main(){
		ret = pipe(arr);
		if( ret < 0 ){
				perror("pipe() failed");
				_exit(1);

			}

		ret = sigaction(SIGINT ,&ch , NULL);

		while(1){
			write(arr[1] , &ch , 1);
			count++;
			printf("bytes written : %d\n" , count);

		}

		return 0;
}		
			
