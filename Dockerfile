FROM ubuntu:latest

WORKDIR /app

COPY . /app

RUN apt update
RUN apt upgrade -y
RUN apt install -y qtcreator qtbase5-dev qt5-qmake cmake telnet g++
RUN qmake EchoServer.pro 
RUN make

CMD ["./EchoServer"]

