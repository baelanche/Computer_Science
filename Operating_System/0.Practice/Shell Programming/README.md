# Shell Programming

1. exec
2. fork

## exec()

프로그램을 실행하는 함수이다. exec() 를 실행한 프로그램은 종료된다.

* 헤더 : unistd.h
* 리턴 : 실패일때 -1

exec 는 variants 들이 존재하며, 적절히 가져다 사용하면 되겠다.

```.c
int execl(const char *path, const char *arg, ...);
int execlp(const char *file, const char *arg, ...);
int execle(const char *path, const char *arg, ..., char *const envp[]);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execve(const char *filename, char *const argv[], char *const envp[]);
```

각 함수를 정리하면 아래와 같다.

|함수 이름|프로그램 지정|명령라인 인수|환경 설정 여부|
|---|---|---|---|
|execl|디렉토리와 파일 이름이 합친 전체 이름|인수 리스트|환경 설정 불가|
|execlp|파일 이름|인수 리스트|환경 설정 불가|
|execle|디렉토리와 파일 이름이 합친 전체 이름|인수 리스트|환경 설정 가능|
|execv|디렉토리와 파일 이름이 합친 전체 이름|인수 배열|환경 설정 불가|
|execvp|파일 이름|인수 배열|환경 설정 불가|
|execve|전체 경로 명|인수 배열|환경 설정 가능|

1. l, v : argv인자를 넘겨줄 때 사용한다. (l일 경우는 char *로 하나씩 v일 경우에는 char *[]로 배열로 한번에 넘겨줌) 
2. e : 환경변수를 넘겨줄 때 사용한다. (e는 위에서 v와 같이 char *[]로 배열로 넘겨준다.)
3. p : 환경변수 PATH를 참조하기 때문에 절대경로를 입력하지 않아도 된다.

### 예시

```.c
execl(ls, ls, NULL); (X) // 디렉토리가 있어야 한다
execl("/bin/ls", "/bin/ls", NULL); (O)
```

```.c
execlp("ls", "ls", NULL); (O)
```

### Parameter

첫번째 인수는 실행한 프로그램의 전체 이름이다.  
두번째 인수부터 실행할 내용을 써주면 된다. l 이 들어간 함수는 더 이상 넣을 매개변수가 없다면 NULL 을 입력해주어야 한다.

### 예제

* evecvp

```.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  char *c[32] = {"ls", "al"};
  pid_t pid;
  int status;
  if ((pid = fork()) == 0) {
		execvp(c[0], c);
		fprintf(stderr, "Unable to execute %s\n", c[0]);
		exit(0);
	} else {
		waitpid(pid, &status, 0);
	}
}
```

사실 exec() 류의 함수들을 실행할 때는 필히 fork() 가 따라온다.  
exec() 로 다른 프로그램을 실행한다면 실행한 프로세스는 기존에 가지고 있던 자원을 모두 잃고 새 프로그램의 자원으로 덮어 쓰이게 된다.  
기존의 자원을 잃으니 당연히 프로그램은 붕괴될 것이다.

## fork()

컴퓨터는 부팅될 때 init 프로세스가 제일 먼저 켜지고 이 프로세스는 모든 프로세스의 부모 프로세스가 된다.  
위에 예제에 써놓았듯이 프로세스가 다른 프로그램을 호출(exec)하면 기존 프로세스가 죽어버리게 되는데,  
init 프로세스는 fork() 를 통하여 자신과 똑같은 자식 프로세스를 만들어내고 자식 프로세스에서 exec() 를 실행시킨다.  
이를 통해 부모 프로세스가 죽지 않고 프로그램을 호출할 수 있게 되는 것이다.

* 부모 프로세스의 pid = 생성된 자식 프로세스의 pid
* 자식 프로세스의 pid = 0
 
## exit()

프로세스를 종료할 때 호출한다. 할 일이 끝난 자식 프로세스들은 좀비 프로세스가 되지 않게 종료시켜 주는게 좋다.
 
## wait(), waitpid()

자식 프로세스가 종료될 때 까지 부모 프로세스는 block 상태로 기다린다.

## pipe()

프로세스 간 통신을 하기 위한 방법이다. 단방향, 양방향이 있으며 실습은 단방향으로 진행한다.

* 헤더 : unistd.h
* 형태 : int pipe(int filedes[2])
* 인수 : infiledes[2] : 파이프의 입출력 디스크립터
* 리턴 : 0 = 성공, -1 = 실패

파이프는 프로세스가 아니라 커널에 생성되며 프로세스에는 파이프를 다룰 수 있는 파일 디스크립터만 제공한다.  
이 디스크립터는 입출력 방향이 정해져 있다.

```.c
int filedes[2];
pipe(filedes);
filedes[0]; // 읽기 전용
filedes[1]; // 쓰기 전용
```

### Example

```.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define READ 0
#define WRITE 1

int main() {
  int fd[2];
  pid_t pid;
  pipe(fd);
  char buf[256];
  pid = fork();
  if (pid == 0) {
    close(fd[WRITE]);
    read(fd[READ], buf, 256);
    printf("child : %s\n", buf);
    exit(0);
  } else {
    close(fd[READ]);
    strcpy(buf, "i'm parent");
    write(fd[WRITE], buf, strlen(buf));
    sleep(2);
    wait(0);
  }
}
```

부모 프로세스에서는 read 를 닫아주고 write 에만 작업했다.  
반대로 자식 프로세스에서는 write 를 닫아주고 받은 데이터를 read 했다.

## dup(), dup2()

* 헤더 : unistd.h  
* int dup(int oldfd);  
* int dup2(int oldfd, int newfd);  
* 리턴 : 새로운 파일 디스크립터, -1 = 실패

dup : 함수는 입력 인자로 열려진 파일 디스크립터를 전달하면 같은 물리적 파일을 연 새로운 파일 디스크립터를 반환한다.  
dup2 : 첫 번째 인자로 열려진 파일 디스크립터를 전달하고 두 번째 인자로 파일 디스크립터를 전달하면 첫 번째 인자로 열려진 파일 디스크립터가 참조하는 파일 테이블 엔트리를 두 번째 전달한 파일 디스크립터도 참조한다. 만약 두 번째 인자로 전달한 파일 디스크립터가 열려진 파일 디스크립터일 때는 먼저 닫고 난 후에 복제한다.

[이중 파이프와 dup2를 사용한 예제](https://git.ajou.ac.kr/baegyu3/os-pa1-implement/-/blob/main/pa1.c) : 112 ~ 144 line
