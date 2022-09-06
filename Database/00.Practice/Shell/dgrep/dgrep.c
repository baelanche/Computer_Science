#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

struct arg_struct {
  char *arg1;
  char *arg2;
};

void *dgrep(void *arguments) {
  struct arg_struct *args = arguments;
  execlp("grep", "grep", "-r", "-n", "--color=auto", args->arg1, args->arg2, NULL);
  exit(0);
}

int main(int argc, char* argv[]) {
  pid_t pid;
  pthread_t thread[2];
  int status;
  if ((pid = fork()) == 0) {
    struct arg_struct args;
    args.arg1 = argv[1];
    args.arg2 = argv[2];

    pthread_create(&thread[0], NULL, dgrep, (void *)&args);
    pthread_create(&thread[1], NULL, dgrep, (void *)&args);

    for(int i=0; i<2; i++) {
      pthread_join(thread[i], NULL);
    }
  } else {
      waitpid(pid, &status, 0);
  }

}
