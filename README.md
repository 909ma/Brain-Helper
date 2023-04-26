# Memory Helper
Memory Helper는 사용자들이 학습하고 싶은 내용을 쉽게 테스트하고, 해당 내용을 복습하는 데 도움을 주는 어플리케이션입니다.  
프로젝트 개발 기간은 2023년 04월 27일부터 시작입니다.  

# 프로젝트 팀 구성원
[김신혁](https://github.com/909ma)  
[배성근](https://github.com/tsk04191)  

# 프로젝트 개요  
반복 학습에 도움이 되는 어플리케이션을 만드는 것이 목표입니다. 현재 계획으로는 CLI 기반 인터페이스로 서비스를 제공하며, 동시에 웹으로도 사용할 수 있게 만들어 이동 중에도 빠른 반복 학습을 도움케 할 계획입니다.

## 목표 요구사항
1. 사용자는 회원가입하여 로그인할 수 있다.
2. 사용자는 등록된 내용을 CRUD 할 수 있다.
3. 사용자는 등록한 내용에 대해 복습 주기를 설정할 수 있다.
4. 등록한 내용은 설정한 주기에 따라 주기적으로 복습할 수 있다.
5. 사용자는 복습한 내용에 대한 기록을 남길 수 있다.
6. 사용자는 등록된 내용을 검색할 수 있다.

## 프로젝트 기대 효과
1. 학습 효율 증대
* 기존에는 복습 주기를 관리하기 위해 별도의 알림 설정이나 메모장 등을 이용하여 관리하는 경우가 많습니다. Memory Helper는 등록된 내용을 주기적으로 복습함으로써 사용자의 학습 효율을 높일 수 있습니다.
2. 사용자 친화적인 UI
* Memory Helper는 사용자가 직관적으로 등록, 검색, 복습할 수 있는 UI를 제공합니다. 또한, 사용자가 등록한 내용에 대한 자동 복습 기능을 제공함으로써, 사용자의 편의성을 높입니다.

## 프로젝트 결과
* 결과1
<img src="/ppt/5. 실시간 매핑 모습.gif" width="45%" height="" title="" alt="1번 이미지"></img>
* 결과2
<img src="/ppt/5. 실시간 매핑 모습.gif" width="45%" height="" title="" alt="1번 이미지"></img>
* 결과3
<img src="/ppt/5. 실시간 매핑 모습.gif" width="45%" height="" title="" alt="1번 이미지"></img>
* 결과4
<img src="/ppt/5. 실시간 매핑 모습.gif" width="45%" height="" title="" alt="1번 이미지"></img>

<details>
    <summary>프로젝트 진행 문서</summary>

## 요구사항 정의서
<img src="/ppt/5. 실시간 매핑 모습.gif" width="45%" height="" title="" alt="1번 이미지"></img>

## 테이블 정의서
<img src="/ppt/5. 실시간 매핑 모습.gif" width="45%" height="" title="" alt="1번 이미지"></img>

<img src="/ppt/5. 실시간 매핑 모습.gif" width="45%" height="" title="" alt="1번 이미지"></img>

## ERD 개체 관계 다이어그램
<img src="/ppt/5. 실시간 매핑 모습.gif" width="45%" height="" title="" alt="1번 이미지"></img>

## TABLE Model
<img src="/ppt/5. 실시간 매핑 모습.gif" width="45%" height="" title="" alt="1번 이미지"></img>

## CRUD 매트릭스
<img src="/ppt/5. 실시간 매핑 모습.gif" width="45%" height="" title="" alt="1번 이미지"></img>

## 트랜잭션 분석서
<img src="/ppt/5. 실시간 매핑 모습.gif" width="45%" height="" title="" alt="1번 이미지"></img>

<img src="/ppt/5. 실시간 매핑 모습.gif" width="45%" height="" title="" alt="1번 이미지"></img>

## Gantt Chart
<img src="/ppt/5. 실시간 매핑 모습.gif" width="45%" height="" title="" alt="1번 이미지"></img>

## 프로젝트 일정 관리
<img src="/ppt/5. 실시간 매핑 모습.gif" width="45%" height="" title="" alt="1번 이미지"></img>

</details>
<br><br>

## 프로젝트 개선점
* ANSI만 사용이 가능하다.  
  프로젝트에서 사용되는 tsv 형식의 데이터베이스는 OS의 text editor로 읽을 때, Windows, Linux, Mac OS 계열이 사용하는 ANSI와 UTF-8의 줄바꿈 처리 문제로 인해 ANSI 형식만 사용 가능합니다. 이에 대한 대응책을 마련해야 합니다.  

* 서식 스타일이 제한적이다.  
  문제의 설명에서 '.', '?' 등의 특수 문자가 포함되면 한 줄 띄워져 출력되기 때문에, 제한적인 서식 양식을 가지고 있습니다. 단, 정답란에서는 문제가 없습니다. 이에 대한 해결책이 필요합니다.  

> 예시. 문제에서 '.'을 써야 하는 경우 극복 방법.  
>
>   >No. 162	 correct : 0,	 incorrect : 0
>   >Q : 다음은 네트워크 관련 신기술 중 하나에 대한 설명이다.  
>   > 일반 블루투스와 동일한 2。4GHz 주파수 대역을 사용하지만 연결되지 않은 대기 상태에서는 절전모드를 유지하는 기술.  
>   >
>   >Answer 1 : 저전력 블루투스 기술  
>   >Answer 2 : BLE  
>   >Answer 3 : Bluetooth Low Energy

> 예시. 정답에서 '.'을 써야 하는 경우에선 문제가 없음.  
>   > No. 139	 correct : 0,	 incorrect : 1  
>   > Q : 다음은 네트워크 액세스 계층의 주요 프로토콜 중 하나에 대한 설명이다.  
>   >  패킷 교환망을 통한 DTE와 DCE 간의 인터페이스를 제공하는 프로토콜.  
>   >  
>   > Answer 1 : X.25  


* 백업 경로가 미흡하다.
백업 경로가 제한적이어서 데이터의 보존이 어렵습니다. 이에 대한 대책을 마련해야 합니다.  
  
* 매트릭스, 그래프 등의 정보를 담지 못한다.  
현재 프로젝트는 단순 텍스트 출력만을 다루기 때문에, 매트릭스, 그래프 등의 정보를 담을 수 없습니다. 다양한 정보를 담을 수 있는 대안책이 필요합니다.  

## 개발 환경
* Windows 10
* Dev C++
* C Language
* HTML
* CSS
* Java Script