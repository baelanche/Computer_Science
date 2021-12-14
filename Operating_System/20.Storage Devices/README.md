# Storage Devices

* main memory 가 아닌 것을 모두 storage 라 한다.
* fixed-size block 단위로 읽고 쓴다. (not byte addressable)
* <b>운영체제는 target block 을 어떻게 읽는 것일까?</b>

## HDD : Hard Disk Drive

![hdd](https://user-images.githubusercontent.com/48989903/145980241-62a632fe-5e3a-44fd-b991-031f92b4b8ad.png)

* ARM 이 가리키는 선을 따라 동심원이 형성되는데 이것을 track 이라 한다.
* track 의 일부 구간을 sector 라 한다.
* 각 ARM 은 같은 방향으로 3가지 디스크를 가리키고 있다.
* 이 디스크가 층으로 쌓인 모양을 cylinder 라 한다.

![hdd2](https://user-images.githubusercontent.com/48989903/145980738-ce8294d8-4697-4e66-8f90-087e62de3f4a.png)

* 도식화하면 이런 모습이다.
* 데이터를 읽으려면 arm assembly 를 해당하는 sector 가 있는 track 을 가리킨다.

### HDD Performance Factors

* Seek time
  * arm assembly 를 올바른 cylinder 로 옮기는 시간
  * cylinder distance 에 좌우된다.
* Rotational delay
  * 디스크는 원을 그리며 돌기 때문에 sector 가 arm 과 겹쳐질 때까지의 시간이 더 걸린다.
* Transfer time
  * data 가 전송되는 시간
* 영향 : Rotation > Seek > Transfer
* 디스크는 초당 120회 정도 회전하는데 열이 발생하기 때문에 무한하게 빠르게 돌릴수는 없다.

하드디스크는 SSD 에 비해 성능이 현저히 떨어지지만 data density 가 정말 높아서 꾸준히 사용되고 있다.

## SSD : Solid State Disks

![ssd](https://user-images.githubusercontent.com/48989903/145983172-0fcad016-faad-4d74-bfd7-c85b2891c483.png)

* SSD Controller : 요청을 받으면 데이터를 찾는다.
* DRAM
* Flash Memory : 알고리즘을 통해 데이터 저장 (전자를 통해 0, 1 로 저장한다)
  * memory 를 까보면 cell 로 구성이 되어있다.

### cell

![cell](https://user-images.githubusercontent.com/48989903/145983185-9a5d7dc8-cb0a-42b2-bf0a-ff11c4c831f4.png)

* cell 은 제품 종류에 따라 저장할 수 있는 비트의 수가 다르다.
* SLC(1), MLC(2), TLC(3), QLC(4)
* floating gate 에 전자가 있고 없고에 (-> 전기가 흐름, 흐르지 않음) 따라 0, 1 의 상태를 띄게 된다.

### NAND Flash Memory

![flash](https://user-images.githubusercontent.com/48989903/145984243-a8465d17-600e-43b5-8e46-d7bff1a9f158.png)

* cell 들의 모음을 page 라 한다.
* page 들의 모음을 block 이라 한다.
* 한 cell 단위로 읽지는 못한다.
* Read : page 단위로 읽는다.
* Write(= program) : page 단위로 쓰며 한번 쓸 수 있다. (overwrite 가 안된다)
* Erase : write 를 하려면 erase 를 반드시 해야한다. block 단위로 erase 한다.

### FTL : Flash Transition Layer

![ftl](https://user-images.githubusercontent.com/48989903/145984798-a0a9b54e-0c06-4221-b6ee-da99b31dec78.png)

* flash memory 의 성질과 기존의 file system 의 성질이 맞지 않아서 둘을 연결하는 소프트웨어를 일컫는다.
* flash memory 는 집적도를 올리면 성능이 향상될 수 있지만 FTL 을 짜는것은 어려운 일이다.

## Interfacing 

### Cylinder-Head-Sector (CHS) scheme

* 각 block 은 <Cylinder #, Head #, Sector #> 로 addressing 되어 있다.
* OS 는 모든 디스크의 이 'geometry' 매개변수를 알아야한다.
* 회사가 디스크를 어떻게 구성하는지 공개되기 때문에 이 방법을 사용하기를 꺼려했다.

### Logical block addressing (LBA) scheme

![lba](https://user-images.githubusercontent.com/48989903/145986711-19fa25cf-76cf-4c06-9b9a-abd40007114c.png)

* 수많은 block 으로 이루어져 있고 block 의 주소를 통해 값을 읽는다.
* 물리적인 위치값은 OS 에 기록되지 않는다.
* 모든 회사는 LBA 방식으로 storage 를 만든다.

