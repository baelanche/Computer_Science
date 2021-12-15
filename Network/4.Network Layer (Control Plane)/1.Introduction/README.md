# Introduction

* data plane : forwarding
* control plane : routing

## Per-router control plane

* 각 router 별로 라우팅 알고리즘을 수행한다.
* router 는 서로의 forwarding table 을 통해 상호작용한다.

## Logically centralized control plane

<img width="978" alt="centralized" src="https://user-images.githubusercontent.com/48989903/146170561-80b01b89-a334-45ee-8b67-b1e5c10b060b.png">

* 각 router 별 CA(control agents) 를 가지며 이들로부터 정보를 받아 Remote Controller 가 알고리즘을 처리한다.
