# File Systems

## File

* storage 에 관계된 정보들의 모임을 저장해 놓은 것
* type 을 가지고 있다.
* window 는 name 으로 encode 한다. (e.g., .com, .exe ...)
* UNIX 는 magic number 로 encode 한다.
* 요즘 OS 는 encoding 방식을 너도나도 섞어쓴다.

### File Operations

* <b>Open</b>
  * open file 은 Open-file table 에 저장한다.
  * 각 process 는 open files 에 대한 자신만의 file descriptor table 을 가진다.
  * file descriptor table 은 fork() 시에 복제된다.

![file](https://user-images.githubusercontent.com/48989903/145988729-c6bd9222-0bf9-4397-abca-c541d37d028f.png)

* <b>Access</b>
  * process 는 각 open file 별 file pointer 를 가진다.
  * read(), write() 는 자동적으로 file pointer 를 변하게 한다.
  * 요청한 범위 만큼 읽고/쓰고 마지막 위치에 file pointer 를 위치시킨다.
  * lseek() : file pointer 의 위치를 바꾼다.

## Directories

![tree](https://user-images.githubusercontent.com/48989903/145992081-67351659-b513-4b75-9b4c-dc32b98d2d4d.png)

* 관련 file 혹은 directory 들의 묶음을 일컫는다.
* 사실, directory 는 단지 file 이다.
  * directory 라는 file 은 file 의 이름, file 이 가리키는 위치(데이터 저장 위치) 등을 가진 file 이다. (= metadata)
* 일반적으로 unordered 이다.
* When open("/spell/mail/exp")
  * open "/"
  * search "spell", get "spell"
  * open "spell", search "mail", get "mail"
  * open "mail", search "exp", get "exp"
  * open "exp"
* directory path 를 찾아가는데 시간이 걸리기 때문에 open(), read(), write() 가 분리되어 있다.

## Links

* Hard link : id 로 link
  * reference count 를 통해 몇 개의 파일이 해당 id 를 link 하고 있는지 기록한다.
  * count = 0 이면 메모리를 회수한다.
* symbolic link : path 로 link (e.g., ./unhex/hex)

## Implementing a File System

![fsdata](https://user-images.githubusercontent.com/48989903/146005697-17e787e8-5ef6-409e-84fe-d2664da8d964.png)

* (filename, metadata, data) -> (a set of blocks)
* 핵심은 block 에 데이터를 어떤 방식으로 저장하는가 이다.  
 
### FAT : File Allocation Table

* 단순하고 구현이 쉽다.
* 파일이 이곳 저곳 흩어지게 된다.

### EXT4

* 4번 확장된 file system
* UNIX/linux 의 표준 file system 이다.
* FAT 보다 유연하고 효과적인 구조를 가짐

## Virtual File System

![fsin](https://user-images.githubusercontent.com/48989903/146009395-dcef0d03-9998-48c7-9504-dc7022278c34.png)

OS 는 아래 내용에 관해서만 관리한다.

* Superblock : 전체 file system 에 대한 내용
* Dentry : directory (file name -> inode number)
* Inode : object(file or directory)

### Virtual File System Operation

* 디스크가 켜지면 VFS 는 file system 의 내용을 superblock 에 쓴다.
* file 에 접근하기 위해 VFS 는 directory 를 아래 방향으로 반복해서 내려간다. 이 때 dentry 에 FS 의 내용을 쓴다.
* VFS 는 빠르게 파일에 접근하기 위해 <dentry, inode> 를 캐시한다.

### Page Cache

* file 에 접근하면 VFS 는 file data 를 free page frames 에 저장한다.
* system 의 memory 가 부족하다면 page cache 는 덧씌워진다.

