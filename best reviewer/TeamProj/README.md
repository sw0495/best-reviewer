
# Team Project (C++)

## C++ 프로젝트 basic template
 - 기본적인 http request 기능
 - 기본적인 json parsing, writing 기능
 - 테스트 케이스

## Build Environment

#### Windows 10 with Cygwin
1. Run Cygwin installer (https://cygwin.com/setup-x86_64.exe)
   
2. Install required packages : **gcc-g++, gcc-core, cmake, make, libcurl-devel, libjsoncpp-devel, gcovr, python36**   

    ![cygwin_select_pkg](https://media.github.ecodesamsung.com/user/3415/files/9ff54879-8682-4c04-ab84-82a87bfe09fd)
   
3. Change Python version on Cygwin    
    * Select python3.6
        ```
        $ /usr/sbin/update-alternatives --config python

        There are 2 programs which provide 'python'.

        Selection    Command
        -----------------------------------------------
        1           /usr/bin/python3.6
        *+ 2           /usr/bin/python3.9

        Enter to keep the current selection[+], or type selection number: 1
        ``` 

        ```
        $ /usr/sbin/update-alternatives --config python3

        There are 2 programs which provide 'python3'.

        Selection    Command
        -----------------------------------------------
        1           /usr/bin/python3.6
        *+ 2           /usr/bin/python3.9

        Enter to keep the current selection[+], or type selection number: 1
        ``` 
    * Check python version
        ```
        $ python -V
        Python 3.6.15

        $ python3 -V
        Python 3.6.15
        
        $ ls -al /etc/alternatives/python*
        lrwxrwxrwx 1 CORP+andy.shlee CORP+Domain Users 18 Jun 22 16:07 /etc/alternatives/python -> /usr/bin/python3.6
        lrwxrwxrwx 1 CORP+andy.shlee CORP+Domain Users 18 Jun 22 16:11 /etc/alternatives/python3 -> /usr/bin/python3.6
        ```

4. Install GoogleTest on Cygwin (https://github.com/google/googletest/archive/master.zip)
    ```
    CORP+andy.shlee@andy-shlee01 /cygdrive/d/test/googletest-master
    $ mkdir build

    CORP+andy.shlee@andy-shlee01 /cygdrive/d/test/googletest-master
    $ cd build

    CORP+andy.shlee@andy-shlee01 /cygdrive/d/test/googletest-master/build
    $ cmake ..
    -- The C compiler identification is GNU 7.4.0
    :

    CORP+andy.shlee@andy-shlee01 /cygdrive/d/test/googletest-master/build
    $ make
    Scanning dependencies of target gtest
    [ 12%] Building CXX object CMakeFiles/gtest.dir/src/gtest-all.cc.o
    :

    CORP+andy.shlee@andy-shlee01 /cygdrive/d/test/googletest-master/build
    $ make install

    $ cp /usr/local/lib/libgtest* /usr/lib/
    ```

## How to build
```
CORP+andy.shlee@andy-shlee01 /cygdrive/d/TeamProj/cpp/TeamProj_CPP
$ mkdir build

CORP+andy.shlee@andy-shlee01 /cygdrive/d/TeamProj/cpp/TeamProj_CPP
$ cd build/

CORP+andy.shlee@andy-shlee01 /cygdrive/d/TeamProj/cpp/TeamProj_CPP/build
$ cmake ..
  :
-- Configuring done
-- Generating done
-- Build files have been written to: /cygdrive/d/TeamProj/cpp/TeamProj_CPP/build

CORP+andy.shlee@andy-shlee01 /cygdrive/d/TeamProj/cpp/TeamProj_CPP/build
$ make
Scanning dependencies of target ChatClient
[ 16%] Building CXX object src/CMakeFiles/ChatClient.dir/hardtoname.cc.o
[ 33%] Linking CXX static library libChatClient.a
  :
[100%] Linking CXX executable ChatClientTest.exe
[100%] Built target ChatClientTest
```

## How to run & test
1. Run the Chat Server 
    * Extract chatServer_XX.zip 
    * Run chat_server.exe in **Windows PowerShell**
        ```
        PS F:\Workspace\chatServer_0.9> .\chat_server.exe localhost 34568
        [2022-06-22 15:10:48.539] [info] Complete to open the chat server.
        [2022-06-22 15:10:48.541] [info] Listening for requests at: http://localhost:34568/chat
        [2022-06-22 15:10:48.541] [info] Press ENTER to exit.
        ```
   
2. Run the execution program in **Cygwin terminal**
    ```
    CORP+andy.shlee@andy-shlee01 /cygdrive/d/TeamProj/cpp/TeamProj_CPP/build
    $ ./src/chat_client.exe
    11.welcome_simpleJson, 12.parse json, 13.assemble json
    21.welcome_arrayJson, 22.parse json, 33.assemble json
    Enter command(q for quit) : 11
    OK to curl : 200, {"message":"Welcome to Best Reviewer"}

    11.welcome_simpleJson, 12.parse json, 13.assemble json
    21.welcome_arrayJson, 22.parse json, 33.assemble json
    Enter command(q for quit) : 12
    Welcome to Best Reviewer
    11.welcome_simpleJson, 12.parse json, 13.assemble json
    21.welcome_arrayJson, 22.parse json, 33.assemble json
    Enter command(q for quit) : 13
    Easy to compose JSON string
    {
            "message" : "Easy to compose JSON string"
    }
    11.welcome_simpleJson, 12.parse json, 13.assemble json
    21.welcome_arrayJson, 22.parse json, 33.assemble json
    Enter command(q for quit) : 21
    [{"message":"Welcome to Best Reviewer 0"},{"message":"Welcome to Best Reviewer 1"},{"message":"Welcome to Best Reviewer 2"}]
    11.welcome_simpleJson, 12.parse json, 13.assemble json
    21.welcome_arrayJson, 22.parse json, 33.assemble json
    Enter command(q for quit) :
    ```

3. Run the google test in **Cygwin terminal**
    ```
    CORP+andy.shlee@andy-shlee01 /cygdrive/d/TeamProj/cpp/TeamProj_CPP/build
    $ ./test/ChatClientTest.exe
    Running main() from /cygdrive/d/TeamProj/googletest-master/googletest-master/googletest/src/gtest_main.cc
    [==========] Running 6 tests from 1 test suite.
    [----------] Global test environment set-up.
    [----------] 6 tests from HttpRequestTest
    [ RUN      ] HttpRequestTest.getSimpleJsonbyHttpRequest
    [       OK ] HttpRequestTest.getSimpleJsonbyHttpRequest (0 ms)
    [ RUN      ] HttpRequestTest.parseSimpleJson
    [       OK ] HttpRequestTest.parseSimpleJson (0 ms)
    [ RUN      ] HttpRequestTest.composeSimpleJson
    [       OK ] HttpRequestTest.composeSimpleJson (0 ms)
    [ RUN      ] HttpRequestTest.getArrayJsonbyHttpRequest
    [       OK ] HttpRequestTest.getArrayJsonbyHttpRequest (11 ms)
    [ RUN      ] HttpRequestTest.parseArrayJson
    {
            "message" : "Welcome to Best Reviewer 0"
    }
    detailed message with forLoop: Welcome to Best Reviewer 0
    {
            "message" : "Welcome to Best Reviewer 1"
    }
    detailed message with forLoop: Welcome to Best Reviewer 1
    {
            "message" : "Welcome to Best Reviewer 2"
    }
    detailed message with forLoop: Welcome to Best Reviewer 2
    0: {
            "message" : "Welcome to Best Reviewer 0"
    }
    detailed message with ItrLoop: Welcome to Best Reviewer 0
    1: {
            "message" : "Welcome to Best Reviewer 1"
    }
    detailed message with ItrLoop: Welcome to Best Reviewer 1
    2: {
            "message" : "Welcome to Best Reviewer 2"
    }
    detailed message with ItrLoop: Welcome to Best Reviewer 2
    [       OK ] HttpRequestTest.parseArrayJson (0 ms)
    [ RUN      ] HttpRequestTest.composeArrayJson
    [       OK ] HttpRequestTest.composeArrayJson (0 ms)
    [----------] 6 tests from HttpRequestTest (11 ms total)

    [----------] Global test environment tear-down
    [==========] 6 tests from 1 test suite ran. (11 ms total)
    [  PASSED  ] 6 tests.
    ```

## How to measure coverage using gcovr
1. Check gcno and gcda files **after build and test**

    ```
    CORP+andy.shlee@andy-shlee01 /cygdrive/d/TeamProj/cpp/TeamProj_CPP
    $ find . -name *gcda -print
    ./build/src/CMakeFiles/ChatClient.dir/hardtoname.cc.gcda
    ./build/src/CMakeFiles/chat_client.dir/main.cc.gcda

    CORP+andy.shlee@andy-shlee01 /cygdrive/d/TeamProj/cpp/TeamProj_CPP
    $ find . -name *gcno -print
    ./build/src/CMakeFiles/ChatClient.dir/hardtoname.cc.gcno
    ./build/src/CMakeFiles/chat_client.dir/main.cc.gcno
    ```
2. Run gcovr in the project **root directory**
    ```
    CORP+andy.shlee@andy-shlee01 /cygdrive/d/TeamProj/cpp/TeamProj_CPP
    $ gcovr
    ------------------------------------------------------------------------------
                            GCC Code Coverage Report
    Directory: .
    ------------------------------------------------------------------------------
    File                                       Lines    Exec  Cover   Missing
    ------------------------------------------------------------------------------
    src/hardtoname.cc                             35      34    97%    [* 38]
    src/main.cc                                   53      52    98%   67
    ------------------------------------------------------------------------------
    TOTAL                                         88      86    97%
    ------------------------------------------------------------------------------
    ```
