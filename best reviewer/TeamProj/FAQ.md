### 1. gcovr 이 아래와 같은 에러를 냅니다.
```
   $ gcovr ./
     Traceback (most recent call last):
     File "/usr/bin/gcovr", line 7, in
     from gcovr.main import main
     ModuleNotFoundError: No module named 'gcovr'
```
  - python -V  를 이용해 python 버전이 3.6.x 인지 확인
```
  $ python -V
    Python 3.6.13
```
  - /usr/sbin/update-alternatives --config python  으로 python 3.6 버전 선택
```
$ /usr/sbin/update-alternatives --config python

There are 2 programs which provide 'python'.

  Selection    Command
-----------------------------------------------
   1           /usr/bin/python2.7
*+ 2           /usr/bin/python3.6

Enter to keep the current selection[+], or type selection number:
```
  - setup-x86_64.exe  (cygwin 설치파일) 로  mirror.kernel.org 서버를 이용하여 gcovr, python 재설치
  
  ![image](https://media.github.ecodesamsung.com/user/4731/files/f4645c7f-e989-4291-afca-1168e69b284b)
  ![image](https://media.github.ecodesamsung.com/user/4731/files/cc84694b-079e-49bb-8e7c-62c6d2558a2e)
   ( 위 이미지는 이미 설치된 환경에서 캡쳐한 것이므로, 버전이 맞는지 확인하시고 설치하시기 바랍니다)
   
  - /etc/alterantives 의 python 링크를 확인한다.
```
문제가 있을때
$ ls -al python*
lrwxrwxrwx 1  xxxxxxxxxxxxxx 18 Mar 29 12:06 python -> /usr/bin/python3.6
lrwxrwxrwx 1  xxxxxxxxxxxxxx 18 Mar 29 12:04 python3 -> /usr/bin/python3.9


수정
$ ls -al python*
lrwxrwxrwx 1 xxxxxxxxxxxxxxx 18 Mar 29 12:06 python -> /usr/bin/python3.6
lrwxrwxrwx 1 xxxxxxxxxxxxxxx 18 Mar 29 12:33 python3 -> /usr/bin/python3.6
```
   
### 2. 채팅 서버와 클라이언트를 하나의 컴이 아닌 별도로 실행하고 싶습니다.

- 윈도에서 서버 운영시 윈도 방화벽 해제의 절차가 필요합니다.


### 3. cygwin 환경이 아닌 ubuntu, MSL의 환경에서 빌드가 가능할까요?

- 관련한 모듈을 MSL, ubuntu 에 맞게 설치하셔야 합니다.
  ( libjsoncpp-dev, libcurl4-openssl-dev 등 )
- cmake 의 아래 패키지 체커를 제거하고 실행해보시기 바랍니다.
```
find_package(CURL REQUIRED)
if(NOT(CURL_FOUND))
    message(FATAL_ERROR "Could not find CURL")
endif()

find_package(Jsoncpp REQUIRED)
if(NOT(Jsoncpp_FOUND))
    message(FATAL_ERROR "Could not find LibJsoncpp")
endif()
```
- #include <json/json.h> 가 에러를 내는 경우 #include <jsoncpp/json/json.h> 로 변경해보시기 바랍니다.
